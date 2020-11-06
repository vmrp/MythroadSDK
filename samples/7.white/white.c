
#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"

#include "white.h"
#include "board.h"
#include "white_aux.h"


/*
������ȫ�ֱ���������
��mythroadƽ̨�£�ȫ�ֱ��������ڶ����ʱ���ʼ��
���磬���µ�ȫ�ֱ������巽ʽ�ǲ�֧�ֵ�:
int32 main_menu = 0;
��ȫ�ֱ�����ʹ�ù���ͬ�������ھ�̬�ֲ�������
*/

//������˵����
int32 main_menu;
//Ӧ��ʹ�õĶ�ʱ�����
int32 main_timer;

//��Ϸ�е�ѡ"����"�󵯳��˵��ľ��
int32 main_game_menu;

//���ڱ�����Ϸ�����Լ�״̬���������
//32�ֽڵ�״̬��Ϣ��64�ֽڵĵ�ǰ���״̬��64�ֽڵĵ�ǰ���
//��������ӣ�1�ֽڵİ��������������64�ֽڵĺ�������ӣ�
// 1�ֽڵĺ��������������
int8 white_state[32+64+64+64];

//���ڱ������ǰ״̬���������
int8 white_back_state[32+64+64+64];

//������ָ��
int8* white_board;

//���ڱ�����Ч�������������
int8 white_valid_stones[4+64];

//���ڱ�����Ϸ����ַ����ı���
char white_result_string[1024];

//���ڴ�����Ϸ������ʾ�ı���
int8 white_payment;

//������Ϸ������ȫ�ֱ���
int32 white_GameWinHandle;
//ȫ�ֱ����������

/*
Ӧ�õ�ˢ�º���
*/
static void white_refresh(int32 data);

char   *myitoa(   int   value,   char   *str,   int   radix   )   
  {   
  	//static   char   szMap[]   =   {   //ƽ̨��֧�־�̬�ֲ�������ȫ�ֱ���������ʱ��ֵ��
  	char   szMap[]   =   {   
  	'0',   '1',   '2',   '3',   '4',   '5',   
  	'6',   '7',   '8',   '9',   'a',   'b',   
  	'c',   'd',   'e',   'f',   'g',   'h',   
  	'i',   'j',   'k',   'l',   'm',   'n',   
  	'o',   'p',   'q',   'r',   's',   't',   
  	'u',   'v',   'w',   'x',   'y',   'z'   
  	}; //   �ַ�ӳ���   
  	int   nCount   =   -1,   nIndex;   
  	char   *pStr   =   str,   nTemp;   
  	unsigned   int   nValue   =   *(unsigned*)&value;
  	if   (   radix   >=   2   &&   radix   <=   36   )   
  	{   //   ����radix������2��36֮��   
  		if   (   value   <   0   &&   radix   ==   10   )   
  		{   //   ����Ǹ���������λ��Ӹ��ţ������ַ���ǰ��   
  			*pStr++   =   '-';   
  			value   =   -value;   //תΪ������   
  		}   
  		do   { //   ѭ��ת��ÿһ�����֣�ֱ������   
 			 pStr[   ++nCount   ]   =   szMap[   nValue   %   radix   ];   
  			nValue   /=   radix;   
  		}   while(   nValue   >   0   );   //   ת���������ַ����Ƿ���   
  		nIndex   =   (   nCount   +   1   )   /   2;   //   �����һ��ĳ���   
  		while(   nIndex--   >   0   )   {   //   ���ַ������ַ���ת   
  			nTemp   =   pStr[   nIndex   ];   
  			pStr[   nIndex   ]   =   pStr[   nCount   -   nIndex   ];   
  			pStr[   nCount   -   nIndex   ]   =   nTemp;   
  		}   
  	}   
  	pStr[   nCount   +   1   ]   =   '\0';   //   �ý�����   
  	return   str;   
  }   


/*
������Ϸ״̬
*/
void main_save(void){
   int32 f; 
   f = mrc_open("white.sav", MR_FILE_RDWR+MR_FILE_CREATE);
   if (f){
      mrc_seek(f, 0, MR_SEEK_SET);
      mrc_write(f, white_state, sizeof(white_state));          
      mrc_close(f);
   }
}

/*
��ȡ��Ϸ״̬
*/
int32 main_read(void)
{
   int32 ret,f;

   ret = mrc_fileState("white.sav");
   if((ret != MR_IS_FILE))
   {
     return MR_FAILED;
   }

   f = mrc_open("white.sav", MR_FILE_RDONLY );
   if (f == 0)
   {
     return MR_FAILED;
   }    
   mrc_seek(f, 0, MR_SEEK_SET);
   ret=mrc_read(f, white_state, sizeof(white_state));
   if(ret!=sizeof(white_state))
   	{
   		mrc_close(f);
   		return MR_FAILED;
   	}
   mrc_close(f);
   return MR_SUCCESS;

}

/*
��Ϸ��������ʾ�Ľ�������"����"  ���ص�����
*/
void white_gameOverCB(int32 data)
{
   //main_save();//�������ʤ���ľ���û��̫�����塣
   mrc_timerDelete(main_timer);
   main_timer=0;
   mrc_winCloseNotShow();//�رս������
   white_GameWinHandle=MR_FAILED;     
   mrc_winCloseNotShow();//�ر�����
   mrc_winCloseNotShow();//�ر����˵���
   mrc_init();
}

/*
��Ϸ�����ص�����
*/
void white_gameOverTimer(int32 data)
{
   int8 blacks,whites;
   int32 str_len=0;
   
   mrc_memset(white_result_string, 0, sizeof(white_result_string));

   white_countPieces(white_board , &blacks, &whites);

   //������Ϸ����ַ���ǰ���������ո�(unicode)
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x20;
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x20;

   //�������ͺ���һ����
   if(blacks == whites){
      mrc_strcpy(&white_result_string[str_len], "\x5e\x73\x5c\x40\x30\x2"); //ƽ�֡�
      str_len += mrc_strlen(&white_result_string[str_len]);
   }else{
      //��������
      if(blacks > whites){
         mrc_strcpy(&white_result_string[str_len], "\x9e\xd1"); //��
      }else{
         mrc_strcpy(&white_result_string[str_len], "\x76\x7d"); //��
      }
      str_len += mrc_strlen(&white_result_string[str_len]);
      
      mrc_strcat(&white_result_string[str_len],
         "\x68\xcb\x80\xdc\x30\x2\x51\x76\x4e\x2d\xff\xc\x9e\xd1\x68\xcb\xff\x1a");
      str_len += mrc_strlen(&white_result_string[str_len]);
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+blacks/10;
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+blacks%10;
      
      mrc_strcat(&white_result_string[str_len],
         "\xff\x1b\x76\x7d\x68\xcb\xff\x1a");
      str_len += mrc_strlen(&white_result_string[str_len]);
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+whites/10;
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+whites%10;
   }
   //����unicode�ַ����Ľ�����
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x0;

   //����һ��������ʾ���������Text����
   mrc_platTextNew("\x6b\xd4\x8d\x5b\x7e\xd3\x67\x9c"/*��Ϸ���*/, 
      white_result_string, 
      MR_DIALOG_CANCEL, 0, NULL, white_gameOverCB);
}

//���˵����˳�Ӧ��
void main_exit(int32 data){
	if(main_timer)
	   mrc_timerDelete(main_timer);
   mrc_winClose();
}

//��Ϸ�е�ѡ"����"�󵯳��˵���"������Ϸ"
void main_back(int32 data){
   mrc_winClose();
}

//��Ϸ�е�ѡ"����"�󵯳��˵���"���ؼ�"
void main_game_Esc(int32 data){
   mrc_winClose();
}

//��Ϸ�е�ѡ"����"�󵯳��˵���"�˳���Ϸ"
void main_game_exit(int32 data){
   main_save();
   mrc_timerDelete(main_timer);
   main_timer=0;   
   mrc_winCloseNotShow();//�ر�"�������˳��˵�"
   white_GameWinHandle=MR_FAILED;     
   mrc_winCloseNotShow();//�ر����� 
   mrc_winCloseNotShow();//�ر����˵���
   mrc_init();
}

//��Ϸ�е�ѡ"����"�󵯳��˵���"����"
void main_game_roll_bak(int32 data){
   mrc_memcpy(white_state, white_back_state, sizeof(white_state));
   //���ܻ���һ�Σ������Ի���״̬����Ϊ��
   white_can_back = FALSE;
   white_boardHasChanged();
   white_moveCursorToNext();
   mrc_winClose();
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

//��Ϸ�����µ��¼�������
static void white_KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   int8 white_Temp_state[32+64+64+64];
   int32 ItemType=0,ItemX=0,ItemY=0;
   int32 ret ;
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_PRESS)
   {
      switch(p1)
      {
         case MR_KEY_UP:
         case MR_KEY_LEFT:
            white_moveCursorToPre();
            mrc_winWinEvent(WIN_EVENT_REFRESH);
            break;
         case MR_KEY_DOWN:
         case MR_KEY_RIGHT:
            white_moveCursorToNext();
            mrc_winWinEvent(WIN_EVENT_REFRESH);
            break;
         case MR_KEY_SOFTLEFT:
         case MR_KEY_SELECT:
            {               
               //����
               //Ϊ������׼����ֻ�е�ǰ���ӵ�����ʱ������Ҫ���档
			    mrc_memcpy(white_Temp_state ,white_state, sizeof(white_state));      
               //���ӡ�
               ret = white_makeMove(white_cursor_x, white_cursor_y, white_board);
               if(ret != WHITE_FAILED)
               {
                  //���ӳɹ�
                  //DBG_PRINTF(("New:�û�����:(%d,%d)",white_cursor_x,white_cursor_y));                  
                  mrc_memcpy(white_back_state ,white_Temp_state, sizeof(white_state));  
                  white_can_back = TRUE;
                  //��ַ����仯�����µ�ǰ�����ӵ�λ�á�
                  white_boardHasChanged();
                  //�ƶ���굽һ�������ӵ�λ�á�
                  white_moveCursorToNext();
                  mrc_winWinEvent(WIN_EVENT_REFRESH);
               }
                  //��Ϸ�Ѿ�����?
				   if (white_IsGameOver(white_board))
				   	{
				      //��Ϸ����������Ӧ�õ�״̬Ϊ   "���ɼ�����Ϸ"
				      white_can_continue = FALSE;
				      white_can_back = FALSE;
				      mrc_timerStart(main_timer, 50, 0, white_gameOverTimer, 0);      
				   }               
            }
            break;
         case MR_KEY_SOFTRIGHT:
            //��������״̬���Ի���
            if (white_can_back){
                  //��Ϸ�е�ѡ"����"�󵯳��˵�
                  main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);            
                  if (main_game_menu != MR_FAILED){
                     mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // ������Ϸ
                     mrc_platMenuSetItem(main_game_menu, "\x60\x94\x68\xcb", 1, main_game_roll_bak, 0);   //����
                     mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_game_exit, 0);    // �˳���Ϸ
                     mrc_platMenuShow(main_game_menu);
                     
                  }else{
                     return;
                  }
            }else{
               //��Ϸ�е�ѡ"����"�󵯳��˵�
               main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 2);            
               if (main_game_menu != MR_FAILED){
                  mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // ������Ϸ
                  mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 1, main_game_exit, 0);   // �˳���Ϸ
                  mrc_platMenuShow(main_game_menu);
               }else{
                  return;
               }
            }
            break;
         default:
            break;
      }
   }

   //����Ƿ��д����������¼������Դ���
   if(type==MR_MOUSE_DOWN)
   {
	//����Ҫ���㰴ѹ��λ�á�
	if(white_MouseToItem(SCREEN_STATUS_GAME,p1,p2,&ItemType,&ItemX,&ItemY)<0)
		return;
      switch(ItemType)
      {
      	case SCREEN_ITEM_STONE:      		
      		//�û��ƶ�������ӣ�����Ϊת��������������±ꡣ
            {
               int32 ret ;
               //����
               //Ϊ������׼����ֻ�е�ǰ���ӵ�����ʱ������Ҫ���档
	           mrc_memcpy(white_Temp_state ,white_state, sizeof(white_state));      
               ret = white_makeMove((int8)ItemX, (int8)ItemY, white_board);
               if(ret != WHITE_FAILED)
               {
                  //���ӳɹ�
                  white_cursor_x=(int8)ItemX;
                  white_cursor_y=(int8)ItemY;
                  //DBG_PRINTF(("New:�û�����:(%d,%d)",white_cursor_x,white_cursor_y));                     
                  mrc_memcpy(white_back_state ,white_Temp_state, sizeof(white_state));  
                  white_can_back = TRUE;
                  //��ַ����仯�����µ�ǰ�����ӵ�λ�á�
                  white_boardHasChanged();
                  //�ƶ���굽һ�������ӵ�λ�á�
                  white_moveCursorToNext();
                  mrc_winWinEvent(WIN_EVENT_REFRESH);          
               }
                  //��Ϸ�Ѿ�����?
				   if (white_IsGameOver(white_board))
				   	{
				      //��Ϸ����������Ӧ�õ�״̬Ϊ   "���ɼ�����Ϸ"
				      white_can_continue = FALSE;
				      white_can_back = FALSE;
				      mrc_timerStart(main_timer, 50, 0, white_gameOverTimer, 0);      
				   }                
            }
            break;      		
      	case SCREEN_ITEM_BOTTEM:
      		//�û��ײ���ѡ��˵��
      		if(ItemX==1&&ItemY==0)
      		{
            		//��������״̬���Ի���
            		if (white_can_back)
            		{
                  		//��Ϸ�е�ѡ"����"�󵯳��˵�
                  		main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);            
                  		if (main_game_menu != MR_FAILED)
                  		{
                     		mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // ������Ϸ
                     		mrc_platMenuSetItem(main_game_menu, "\x60\x94\x68\xcb", 1, main_game_roll_bak, 0);   //����
                     		mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_game_exit, 0);    // �˳���Ϸ
                     		mrc_platMenuShow(main_game_menu);                     
	                  	}else
	                  	{
                     		return;
                  	    	}
            		}else
            		{
               		//��Ϸ�е�ѡ"����"�󵯳��˵�
              	 	main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 2);            
               		if (main_game_menu != MR_FAILED)
               		{
                  			mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // ������Ϸ
                  			mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 1, main_game_exit, 0);   // �˳���Ϸ
                  			mrc_platMenuShow(main_game_menu);
               		}else
               		{
                  			return;
               		}
            		}      		
      		}
      		break;
      	default:
      		break;
      	}
   }
}

//�������ӹ��
static void white_drawCursor(void)
{
   if (	(white_cursor_x >= 0)&&
   		(white_cursor_x < BOARD_WIDTH) &&
		(white_cursor_y >= 0)&&
   		(white_cursor_y < BOARD_HEIGHT)   		){
      mrc_spriteDraw(BOARD_BMP_ID, 
                            (uint16)BOARD_SPID_CURSOR, 
                            BOARD_OFFSET_X + white_cursor_x * BOARD_STONE_WIDTH, 
                            BOARD_OFFSET_Y + white_cursor_y * BOARD_STONE_HEIGHT, 
                            BM_TRANSPARENT);
   }
}

//���ƿ��ܵ����ӵ�
static void white_drawValid(void)
{
   int8 x,y;
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
         if (white_valid_stones[ BOARD_POS(x, y) ])
         {
            mrc_spriteDraw(BOARD_BMP_ID, 
                                  (uint16)BOARD_SPID_VALID_POINT, 
                                  BOARD_OFFSET_X + x * BOARD_STONE_WIDTH, 
                                  BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT, 
                                  BM_TRANSPARENT);
         }
      }
   }
}


//������Ϸ����ĵײ���
static void white_drawBottom(void)
{
   mrc_drawRect(0, SCREEN_GAME_BOTTEM_Y, SCREEN_WIDTH, 3, white_bottom_line_rgb);
   mrc_drawRect(0, SCREEN_GAME_BOTTEM_Y+3, SCREEN_WIDTH, (SCREEN_HEIGHT-SCREEN_GAME_BOTTEM_Y-3), white_bottom_rgb);
   mrc_drawLine(SCREEN_WIDTH/2, SCREEN_GAME_BOTTEM_Y, SCREEN_WIDTH/2, SCREEN_HEIGHT, white_bottom_line_rgb);   
   mrc_drawText("ѡ��",  SCREEN_WIDTH*5/8, SCREEN_GAME_BOTTEM_Y+4, 0, 0, 0, 0, MR_FONT_BIG);   
}

//������Ϸ����Ķ�����
static void white_drawTitle(void)
{
   int8 spid;
   mrc_drawRect(0, 0, SCREEN_WIDTH, SCREEN_GAME_TOP_Y-3, white_top_rgb);
   mrc_drawRect(0, SCREEN_GAME_TOP_Y-3, SCREEN_WIDTH, 3, white_bottom_line_rgb);
   mrc_drawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_GAME_TOP_Y-3, white_bottom_line_rgb);      
   if (white_turn(white_board) == BOARD_SAVE_BLACK){
      spid = BOARD_SPID_BLACK_NEXT;
      mrc_drawText("���������", 4, 3, 255, 255, 255, 0, MR_FONT_BIG);
   }else{
      spid = BOARD_SPID_WHITE_NEXT;
      mrc_drawText("���������", 4, 3, 255, 255, 255, 0, MR_FONT_BIG);
   }
   //���ƴ������ӣ���������
   mrc_spriteDraw(BOARD_BMP_ID, 
                         (uint16)spid, 
                         SCREEN_WIDTH-BOARD_STONE_WIDTH-1, 
                         1, 
                         BM_COPY);
   if (white_waiting_ai){
      mrc_drawText("���Ժ�",  SCREEN_WIDTH/2+4, 3, 255, 255, 255, 0, 0);
   }
}

//������Ϸ�������������߿�
static void white_drawSide(void)
{

  if(BOARD_OFFSET_X>0)
  {
	  mrc_drawRect(0, SCREEN_GAME_TOP_Y, BOARD_OFFSET_X, SCREEN_GAME_BOTTEM_Y-SCREEN_GAME_TOP_Y, white_bottom_line_rgb);
      mrc_drawRect(SCREEN_WIDTH-BOARD_OFFSET_X, SCREEN_GAME_TOP_Y, BOARD_OFFSET_X, SCREEN_GAME_BOTTEM_Y-SCREEN_GAME_TOP_Y, white_bottom_line_rgb);
  	}
   
}

//��Ϸ����ˢ��
static void white_refresh(int32 data)
{
	white_boardPaint(white_board+4);
	white_drawCursor();
	white_drawValid();
   white_drawTitle();
   white_drawSide();
   white_drawBottom();
   
   mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//��Ϸ���洰���¼�����
static void white_WinHandler(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           white_WinHandler(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//��ʼ��Ϸ
void white_start(int32 data)
{
   white_GameWinHandle=-1;
   white_GameWinHandle=mrc_platWinNew(0, white_WinHandler, white_KeyHandler);
   white_can_back = FALSE;
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

//����Ϸ
void main_new(int32 data){ 
   white_new(data);
   white_boardHasChanged();
   white_moveCursorToNext();
   white_start(data);
}

//������Ϸ
void main_load(int32 data){
   white_boardHasChanged();
   white_moveCursorToNext();
   white_start(data);
}

//����
void main_help(int32 data){
   mrc_platTextNew("\x5e\x2e\x52\xa9", "\x4e\xb\x68\xcb\x89\xc4\x52\x19\xff\x1a\x0\xa\x0\x31\x30\x1\x5f\x53\x65\x3e\x4e\xb\x76\x84\x68\xcb\x5b\x50\x57\x28\x6a\x2a\x30\x1\x7a\xd6\x30\x1\x65\x9c\x51\x6b\x4e\x2a\x65\xb9\x54\x11\x51\x67\x67\x9\x4e\x0\x4e\x2a\x67\x2c\x65\xb9\x76\x84\x68\xcb\x5b\x50\xff\xc\x52\x19\x88\xab\x59\x39\x57\x28\x4e\x2d\x95\xf4\x76\x84\x5b\xf9\x62\x4b\x68\xcb\x5b\x50\x51\x68\x90\xe8\x4f\x1a\x88\xab\x54\x3\x63\x89\xff\xc\x63\x62\x62\x10\x67\x2c\x65\xb9\x76\x84\x68\xcb\x5b\x50\x30\x2\x0\xa\x0\x32\x30\x1\x53\xea\x67\x9\x57\x28\x53\xef\x4e\xe5\x54\x3\x5b\xf9\x65\xb9\x68\xcb\x5b\x50\x76\x84\x57\x30\x65\xb9\x62\x4d\x53\xef\x4e\xe5\x4e\xb\x5b\x50\x30\x2\x0\xa\x0\x33\x30\x1\x59\x82\x67\x9c\x68\xcb\x76\xd8\x4e\xa\x6c\xa1\x67\x9\x57\x30\x65\xb9\x53\xef\x4e\xe5\x4e\xb\x5b\x50\xff\xc\x52\x19\x5b\xf9\x62\x4b\x8f\xde\x4e\xb\x30\x2\x0\xa\x0\x34\x30\x1\x53\xcc\x65\xb9\x90\xfd\x6c\xa1\x67\x9\x68\xcb\x5b\x50\x53\xef\x4e\xe5\x4e\xb\x65\xf6\x68\xcb\x5c\x40\x7e\xd3\x67\x5f\xff\xc\x68\xcb\x5b\x50\x59\x1a\x76\x84\x4e\x0\x65\xb9\x83\xb7\x80\xdc\x30\x2", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
}

/*
Ӧ�ó�ʼ������
�ú�����Ӧ�ó�ʼ���ڼ䱻mythroadƽ̨���ã����������
�����н���ȫ�ֱ����ĳ�ʼ���ȹ�����
����ֵ:
MR_SUCCESS  Ӧ�ó�ʼ���ɹ�
MR_FAILED      Ӧ�ó�ʼ��ʧ��
*/
int32 mrc_init(void)
{
   int32 ret;
   mrc_memset(white_state, 0, sizeof(white_state));
   mrc_memset(white_back_state, 0, sizeof(white_back_state));
   mrc_memset(white_valid_stones, 0, sizeof(white_valid_stones));
   mrc_winInit();
   
   //�����̴���Ϸ״̬����ĵ�28���ֽڿ�ʼ
   white_board = &white_state[28];
   white_boardInit();
   mrc_clearScreen(0, 0, 0);
   
   //������ʱ��
   main_timer=0;
   main_timer = mrc_timerCreate();

	ret=main_read();
   if (ret == MR_SUCCESS){
      
   }
   else
   {
		//��һ��������Ϸ��û�д��̼�¼��Ĭ������£�
		//���û�ִ���ӣ�����ִ���ӡ�
	   white_ai=AI_HUMAN;
	   black_ai=AI_HUMAN;	   
	   white_ai_seting=AI_HUMAN;
   		white_stone_seting=BOARD_SAVE_BLACK;
   }

   //���ϴ��˳�ʱ״̬Ϊ���Լ�����Ϸ
   if (white_can_continue){
      //�������˵�
      main_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 4);             // �ڰ���
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x65\xb0\x6e\x38\x62\xf", 0, main_new, 0);   // ����Ϸ      	
         mrc_platMenuSetItem(main_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 1, main_load, 0);   // ������Ϸ
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 2, main_help, 0);   // ����
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 3, main_exit, 0);   // �˳���Ϸ         
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 4, main_exit, 0);   // ������ؼ����˳���Ϸ
         mrc_platMenuShow(main_menu);
         
      }else{
         return MR_FAILED;
      }
   }else{
      main_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);             // �ڰ���
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x65\xb0\x6e\x38\x62\xf", 0, main_new, 0);   // ����Ϸ
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 1, main_help, 0);   // ����
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_exit, 0);   // �˳���Ϸ         
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 3, main_exit, 0);   // ������ؼ����˳���Ϸ
         mrc_platMenuShow(main_menu);
         
      }else{
         return MR_FAILED;
      }
   }
   return MR_SUCCESS;
}

/*
Ӧ���¼�����
�ú�����Ӧ�������ڼ䣬ÿ��mythroadƽ̨�յ��¼�ʱ
������
����:
code:
      code�Ŀ���ȡֵ����:
enum {
   MR_KEY_PRESS,           //���������¼�
   MR_KEY_RELEASE,        //�����ͷ��¼�
   MR_MOUSE_DOWN,       //����������꣩�����¼�
   MR_MOUSE_UP,            //����������̧꣩��/�ͷ��¼�
   MR_MENU_SELECT,       //�˵�ѡ���¼�
   MR_MENU_RETURN,       //�˵������¼�
   MR_DIALOG_EVENT,      // �Ի���/�༭��/�ı����¼�
   MR_EVENT02,             //VM�������벻Ҫʹ��
   MR_EXIT_EVENT,           //Ӧ���˳��¼�
   MR_EVENT03,                 //VM�������벻Ҫʹ��
   MR_LOCALUI_EVENT         //���ػ��ӿ��¼�
};

param0:
   ��codeΪMR_KEY_PRESS��MR_KEY_RELEASEʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_KEY_0,               //���� 0
   MR_KEY_1,               //���� 1
   MR_KEY_2,               //���� 2
   MR_KEY_3,               //���� 3
   MR_KEY_4,               //���� 4
   MR_KEY_5,               //���� 5
   MR_KEY_6,               //���� 6
   MR_KEY_7,               //���� 7
   MR_KEY_8,               //���� 8
   MR_KEY_9,               //���� 9
   MR_KEY_STAR,            //���� *
   MR_KEY_POUND,           //���� #
   MR_KEY_UP,              //���� ��
   MR_KEY_DOWN,            //���� ��
   MR_KEY_LEFT,            //���� ��
   MR_KEY_RIGHT,           //���� ��
   MR_KEY_POWER,           //���� �һ���
   MR_KEY_SOFTLEFT,        //���� �����
   MR_KEY_SOFTRIGHT,       //���� �����
   MR_KEY_SEND,            //���� ������
   MR_KEY_SELECT,          //���� ȷ��/ѡ����������м���ȷ�ϼ���������Ϊ�ü���
   MR_KEY_VOLUME_UP,          //���� �����
   MR_KEY_VOLUME_DOWN,          //���� �����
   MR_KEY_NONE             //���� ����
};
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param0Ϊ��Ļ��x���ꣻ
��codeΪMR_MENU_SELECTʱ��param0Ϊ�˵�index��
��codeΪMR_DIALOG_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_DIALOG_KEY_OK,         //�Ի���/�ı���ȵ�"ȷ��"�������(ѡ��)
   MR_DIALOG_KEY_CANCEL  //�Ի���/�ı���ȵ�"ȡ��"("����")�������(ѡ��)
};

��codeΪMR_LOCALUI_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_LOCALUI_KEY_OK,       //���ؿؼ���"ȷ��"�������(ѡ��)
   MR_LOCALUI_KEY_CANCEL//���ؿؼ���"ȡ��"("����")�������(ѡ��)
};

param1:
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param1Ϊ��Ļ��y���ꣻ

����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_event(int32 code, int32 param0, int32 param1)
{
   mrc_winEvent(code, param0, param1);
   return MR_SUCCESS;
}

/*
Ӧ����ͣ����
�ú�����Ӧ�ñ���ͣʱ���е绰���¼���ͣӦ�ã�
��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_pause(void)
{
   return 0;
}

/*
�ú�����Ӧ�ûָ�����ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_resume(void)
{
   mrc_winResume();
   return 0;
}

/*
�ú�����Ӧ���˳�ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_exitApp(void)
{
   return 0;
}

