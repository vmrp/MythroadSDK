

#include "mrc_base.h"
#include "mrc_win.h"

//T_FRAME_EVENT frame_event_map[MAX_FRAME_EVENT];
T_FRAME_WIN *win_stack[MAX_WIN_NO];
PtrKeyEvent gKeyEvent;
PtrWinEvent gWinEvent;
int32 win_index;
int32 VMStat;                        /*最低位 为1表示VM in 否则VM out 次低位为1表示VM run 否则VM pause */


void mrc_winInit(void)
{
	gWinEvent = NULL;
	gKeyEvent = NULL;
	win_index = -1;
	VMStat = 0x03;
	mrc_memset(win_stack,0,sizeof(win_stack));
}

int32 mrc_winNew(int32 data,PtrWinEvent winEvent,PtrKeyEvent keyEvent)
{
	T_FRAME_WIN *pWin = NULL;

	if(win_index < MAX_WIN_NO)
	{
		pWin = (T_FRAME_WIN *)mrc_malloc(sizeof(T_FRAME_WIN));

		if(pWin == NULL)
		{
			return MR_FAILED;
		}
		else
		{
			if(gWinEvent)
				gWinEvent(((T_FRAME_WIN*)(win_stack[win_index]))->data,WIN_EVENT_PAUSE);

			win_index ++;
			pWin->data = data; 
			pWin->id = win_index;
			pWin->keyCb = gKeyEvent = keyEvent;
			pWin->winCb = gWinEvent = winEvent;
			win_stack[win_index] = pWin;
			
			if(gWinEvent)
				gWinEvent(pWin->data,WIN_EVENT_SHOW);
			
			return win_index;
		}
	}
	else
	{
		return MR_FAILED;
	}
}

int32 mrc_winClose(void)
{
	T_FRAME_WIN *pWin;
      if(win_index>=0)
         pWin = win_stack[win_index];
      else
         return MR_FAILED;
	
	if(pWin == NULL)
		return MR_FAILED;
	else
	{
		win_stack[win_index--] = NULL;
		
		if(pWin->winCb)
			pWin->winCb(pWin->data,WIN_EVENT_EXIT);

		mrc_free(pWin);
		
		if(win_index >= 0)
		{
			pWin = (win_stack[win_index]);
			gKeyEvent = pWin->keyCb;
			gWinEvent = pWin->winCb;
			
			if(gWinEvent)
				gWinEvent(pWin->data,WIN_EVENT_REFRESH);
			
			return MR_SUCCESS;
		}
		else
		{
			gKeyEvent = NULL;
			gWinEvent = NULL;
                //mrc_exit();
			return MR_SUCCESS;			
		}
		
	}
}

int32 mrc_winCloseNotShow(void)
{
	T_FRAME_WIN *pWin;
      if(win_index>=0)
         pWin = win_stack[win_index];
      else
         return MR_FAILED;
	
	if(pWin == NULL)
		return MR_FAILED;
	else
	{
		win_stack[win_index--] = NULL;
		
		if(pWin->winCb)
			pWin->winCb(pWin->data,WIN_EVENT_EXIT);

		mrc_free(pWin);
		
		if(win_index >= 0)
		{
			pWin = (win_stack[win_index]);
			gKeyEvent = pWin->keyCb;
			gWinEvent = pWin->winCb;			
			return MR_SUCCESS;
		}
		else
		{
			gKeyEvent = NULL;
			gWinEvent = NULL;
			return MR_SUCCESS;			
		}
		
	}
}

int32 mrc_winCloseById(int32 id)
{
	int32 i = 0;
	int32 j =0;
	T_FRAME_WIN * pWin = NULL;
	
	for(i = 0;i<= win_index;i++)
	{
		if((win_stack[i])->id == id)
			break;
	}

	if(i == win_index)
		return mrc_winClose();
	else if (i < win_index)
	{
		pWin = win_stack[i];

		if(pWin->winCb)
			pWin->winCb(pWin->data,WIN_EVENT_EXIT);
		
		mrc_free(pWin);
		
		for(j = i;j<win_index;j++)
		{
			win_stack[j] = win_stack[j+1];
		}
		
		win_stack[win_index--] = NULL;

		return MR_SUCCESS;
		
	}else{
	     return MR_FAILED;
     }
}


int32 mrc_getWinDataById(int32 id, int32* data)
{
	int32 i = 0;
	T_FRAME_WIN *pWin = NULL;
	
	for(i = 0;i <= win_index;i++)
	{
		pWin = (T_FRAME_WIN *)(win_stack[i]);

		if(pWin->id == id){
            *data = (pWin->data);
            return MR_SUCCESS;
          }
			
	}
	
	return MR_FAILED;
}

int32 mrc_getActiveWinId(void)
{	
	if(win_index < 0)
		return MR_FAILED;
     if (win_stack[win_index])
	  return  (win_stack[win_index])->id;
     else
        return MR_FAILED;
}

int32 mrc_winGetActiveWinData(int32* data)
{
	if(win_index < 0)
		return MR_FAILED;
     if (win_stack[win_index]){
	  *data =  (win_stack[win_index])->data;
        return MR_SUCCESS;
      }
     else
        return MR_FAILED;
}

int32 mrc_sendEventTo(int32 winId,int32 eventId)
{
	int i;
	T_FRAME_WIN *pWin = NULL;

	for(i = 0;i <= win_index;i++)
	{
		if((win_stack[i])->id == winId)
		{
			pWin = win_stack[i];
			break;
		}
	}

	if(pWin == NULL)
		return MR_FAILED;
	
	if(pWin->winCb)
	{
		pWin->winCb(pWin->data,eventId);
		return MR_SUCCESS;
	}
	
	return MR_FAILED;
	
}

int32 mrc_winEvent(int32 type, int32 p1, int32 p2)
{
   int32 data;
   if(mrc_winGetActiveWinData(&data) == MR_SUCCESS){
      if(gKeyEvent)
         gKeyEvent(data, type, p1, p2);
   }
   return MR_SUCCESS;
}

int32 mrc_winKeyEvent(int32 type, int32 p1, int32 p2)
{
   int32 data;
   if(mrc_winGetActiveWinData(&data) == MR_SUCCESS){
      if(gKeyEvent)
         gKeyEvent(data, type, p1, p2);
   }
   return MR_SUCCESS;
}

int32 mrc_winWinEvent(int32 eventId)
{
   int32 data;
   if(mrc_winGetActiveWinData(&data) == MR_SUCCESS){
      if(gWinEvent)
         gWinEvent(data, eventId);
   }
   return MR_SUCCESS;
}


int32 getVMStat(void)
{
	return VMStat;
}

int32 setVMStat(int32 stat)
{
	VMStat = stat;
	return 0;
}

int32 mrc_isTheWinCreated(int32 winId)
{
	int32 i = 0;
	T_FRAME_WIN *pWin = NULL;
	
	for(i = 0;i <= win_index;i++)
	{
		pWin = (T_FRAME_WIN *)(win_stack[i]);

		if(pWin->id == winId)
			return TRUE;
			
	}
	
	return FALSE;
}

int32 isVMIn(void)
{
	if(VMStat&0x01)
		return TRUE;
	else
		return FALSE;
}

void mrc_winResume(void)
{
	T_FRAME_WIN *pWin = NULL;
	
	if(isVMIn())
	{
		if(win_index >= 0)
		{
			pWin = win_stack[win_index];
			
			if(pWin)
			{
				if(pWin->winCb)
				{
					pWin->winCb(pWin->data,WIN_EVENT_REFRESH);
				}
			}
		}
	}
}


#if 0

void drawAirRect(int32 x,int32 y,int32 w,int32 h,uint8 r,uint8 g,uint8 b)
{
	drawLine(x, y, x, y+h-1,r,g,b);
	drawLine(x, y, x+w-1, y, r, g,b);
	drawLine(x+w-1, y,x+w-1, y+h-1,r,g,b);
	drawLine(x, y+h-1, x+w-1, y+h-1,r,g,b);
}

void drawLine(int32 x1,int32 y1,int32 x2,int32 y2,uint8 r,uint8 g,uint8 b)
{
	uint16 color = ((r&0xf8)<<8)+((g&0xfc)<<3)+((b&0xf8)>>3);
	int i;
	
	if(x1 == x2)
	{
		for(i = y1;i<=y2;i++)
			_DrawPoint(x1,i,color);
	}
	else if(y1 == y2)
	{
		for(i = x1;i<= x2;i++)
			_DrawPoint(i,y1,color);
	}
}

BOOL isRightKey(int32 x,int32 y)
{
	if(y > (LCD_HEIGHT - CH_HEIGHT-5))
	{
		if(x > (LCD_WIDTH - CH_HEIGHT- CH_HEIGHT-5))
		{
			return TRUE;
		}
	}
	
	return FALSE;
}

BOOL isLeftKey(int32 x,int32 y)
{
	if(y > (LCD_HEIGHT - CH_HEIGHT-5))
	{
		if(x < CH_HEIGHT+CH_HEIGHT+5)
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL isMiddleKey(int32 x,int32 y)
{
	if(y > (LCD_HEIGHT - CH_HEIGHT-5))
	{
		if((x > LCD_WIDTH/2-CH_HEIGHT) &&(x < LCD_WIDTH/2+CH_HEIGHT))
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL isMouseInArea(int32 x,int32 y,int32 x1,int32 y1,int32 w,int32 h)
{
	if((x >= x1)&&(x <= (x1+w)))
	{
		if((y >= y1) && (y<= (y1+h)))
			return TRUE;
	}

	return FALSE;
}
#endif
