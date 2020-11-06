#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_bmp.h"

#ifdef DEMO_DEBUG
#define DBG_PRINTF(a) mrc_printf a
#else
#define DBG_PRINTF(a) 
#endif

/*
������ȫ�ֱ���������
��mythroadƽ̨�£�ȫ�ֱ��������ڶ����ʱ���ʼ��
���磬���µ�ȫ�ֱ������巽ʽ�ǲ�֧�ֵ�:
int32 main_menu = 0;
��ȫ�ֱ�����ʹ�ù���ͬ�������ھ�̬�ֲ�������
*/

//������˵����
int32 main_menu;
int32 draw_WinHandle;
int32 Game_timer;
int32 timeBegin;
uint16 Offset;
uint16 YOffset;
uint8 demo_r,demo_g,demo_b;
mr_bitmapSt ScreenInfo;//λͼ��������Ϣ��Mythroadƽ̨Ŀǰ��30��
//λͼ������������IdΪ30�Ļ���������Ļ��������

/*
Ӧ�õ�ˢ�º���
*/
static void white_refresh(int32 data);
void main_ShowMenu(void);

//ˢ����Ļ
static void white_refresh(int32 data)
{
	mrc_refreshScreen(0, 0, 240, 320);
	return;
}

void timer_proc_normal(int32 data)
{
	uint32 entertime,curTime,timePass,newOffset;
	entertime=curTime=mrc_getUptime();
	Offset+=(entertime-data)/10;
	if(Offset>=ScreenInfo.w)
	{
		Offset=Offset%ScreenInfo.w;
		YOffset+=10;
		if(YOffset>=ScreenInfo.h)
		{
			YOffset=10;
			mrc_clearScreen(0, 0, 0);
		}
	}
	while((curTime-entertime)<200)
	{
		//ģ�ⶨʱ������һЩҵ����Ҫ200���롣
		curTime=mrc_getUptime();
	}
	timePass=(curTime-entertime)/10;
	newOffset=Offset+timePass;
	if(newOffset>=ScreenInfo.w)
		newOffset=ScreenInfo.w-1;
	
   	demo_r=demo_g;
   	demo_g=demo_b;
   	demo_b=curTime%256;			
	mrc_drawLine(Offset, YOffset, newOffset, YOffset, demo_r, demo_g, demo_b);	
	Offset+=timePass;
	mrc_winWinEvent(WIN_EVENT_REFRESH);;
	
	//200������ٴ�������ʱ����
	mrc_timerStart(Game_timer,100,mrc_getUptime(),timer_proc_normal,0);
		
	return ;
}




void timer_proc_rob(int32 data)
{
	uint32 entertime,curTime,timePass,newOffset;
	//200������ٴ�������ʱ����
	mrc_timerStart(Game_timer,100,0,timer_proc_rob,0);	
	entertime=curTime=mrc_getUptime();
	Offset+=(entertime-timeBegin)/10;
	if(Offset>=ScreenInfo.w)
	{
		Offset=Offset%ScreenInfo.w;
		//Offset=0;
		YOffset+=10;
		if(YOffset>=ScreenInfo.h)
		{
			YOffset=10;
			mrc_clearScreen(0, 0, 0);
		}
	}
	while((curTime-entertime)<200)
	{
		//ģ�ⶨʱ������һЩҵ����Ҫ200���롣
		curTime=mrc_getUptime();
	}
	timePass=(curTime-entertime)/10;
	newOffset=Offset+timePass;
	if(newOffset>=ScreenInfo.w)
		newOffset=ScreenInfo.w-1;
		
	mrc_drawLine(Offset, YOffset, newOffset, YOffset, demo_r, demo_g, demo_b);	
	DBG_PRINTF(("Timer:Enter=%d,Offset=%d,TimePass=%d",entertime,Offset,timePass));
	Offset+=timePass;
	mrc_winWinEvent(WIN_EVENT_REFRESH);;		
   	demo_r=demo_g;
   	demo_g=demo_b;
   	demo_b=curTime%256;	
	timeBegin=mrc_getUptime();
	return;
}


//��Ϸ�����µ��¼�������
static void KeyHandler_normal(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
         	if(Game_timer)
         	{
         		//mrc_timerStop(Game_timer);
         		mrc_timerDelete(Game_timer); 
         		Game_timer=0;
			}         		
			mrc_winCloseNotShow();
			mrc_winClose();
         	break;
         case MR_KEY_SOFTLEFT:
         	Offset=0;
         	YOffset=10;
         	demo_r=240;
         	demo_g=180;
         	demo_b=120;
			Game_timer=mrc_timerCreate();
			mrc_timerStart(Game_timer,100,mrc_getUptime(),timer_proc_normal,0);
			mrc_clearScreen(0, 0, 0);
			mrc_winWinEvent(WIN_EVENT_REFRESH);;
         	break;         	
         default:
            break;
      }       
   	}

}



static void WinHandler_normal(int32 data,int32 eventId)
{
   mrc_printf("WinHandler_normal:data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_normal(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//��ѭ��
static void KeyHandler_dead(int32 data, int32 type,int32 p1,int32 p2)
{
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT://�ⲿ�ִ�����ʵ�ǲ�����ִ�е��ġ�
			mrc_winCloseNotShow();
			mrc_winClose();
         	break;
         case MR_KEY_SOFTLEFT:
         	for(;;)//��ѭ��
         	{
         	
         	}
         	break;         	
         default:
            break;
      }       
   	}

}



//��Ϸ���洰���¼�����
static void WinHandler_dead(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_dead(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}



//��ռ�����µļ����¼�������
static void KeyHandler_rob(int32 data, int32 type,int32 p1,int32 p2)
{
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
         	if(Game_timer)
         	{
         		//mrc_timerStop(Game_timer);
         		mrc_timerDelete(Game_timer);
         		Game_timer=0;
         	}         	
			mrc_winCloseNotShow();
			mrc_winClose();
         	break;
         case MR_KEY_SOFTLEFT:
         	Offset=0;
         	YOffset=10;
         	demo_r=240;
         	demo_g=180;
         	demo_b=120;
			Game_timer=mrc_timerCreate();
			timeBegin=mrc_getUptime();
			mrc_timerStart(Game_timer,100,0,timer_proc_rob,0);
			mrc_clearScreen(0, 0, 0);
			mrc_winWinEvent(WIN_EVENT_REFRESH);;
			break;
         default:
            break;
      }       
   	}

}



static void WinHandler_rob(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_rob(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}



void Demo_normal(int32 data)
{
	char buftemp[256],bufout[256];
	mrc_memset(buftemp,0,sizeof(buftemp));
	mrc_memset(bufout,0,sizeof(bufout));
	Game_timer=0;
   draw_WinHandle=mrc_platWinNew(0, WinHandler_normal, KeyHandler_normal);
   mrc_clearScreen(0, 0, 0);
   mrc_sprintf(buftemp,"���������ʼ��ʾ�����������!");
   mrc_strcat(bufout,buftemp);
   mrc_drawText(bufout, 0, 100, 255, 255, 255, 0, MR_FONT_BIG);   
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

void Demo_dead(int32 data)
{
   char buftemp[256],bufout[256];
	mrc_memset(buftemp,0,sizeof(buftemp));
	mrc_memset(bufout,0,sizeof(bufout));
	draw_WinHandle=mrc_platWinNew(0, WinHandler_dead, KeyHandler_dead);	
	mrc_clearScreen(0, 0, 0);
	mrc_sprintf(buftemp,"���������ʼ��ʾ��");
	mrc_strcat(bufout,buftemp);
	mrc_drawText(bufout, 0, 60, 255, 255, 255, 0, MR_FONT_BIG);  
	mrc_memset(buftemp,0,sizeof(buftemp));
	mrc_memset(bufout,0,sizeof(bufout));
	mrc_sprintf(buftemp,"��������˳���ʾ��");
	mrc_strcat(bufout,buftemp);
	mrc_drawText(bufout, 0, 100, 255, 255, 255, 0, MR_FONT_BIG);  
	mrc_memset(buftemp,0,sizeof(buftemp));
	mrc_memset(bufout,0,sizeof(bufout));
	mrc_sprintf(buftemp,"��ʾ�������ֻ�����!");
	mrc_strcat(bufout,buftemp);
	mrc_drawText(bufout, 0, 140, 255, 255, 255, 0, MR_FONT_BIG); 
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

void Demo_rob(int32 data)
{
   char buftemp[256],bufout[256];
	mrc_memset(buftemp,0,sizeof(buftemp));
	mrc_memset(bufout,0,sizeof(bufout));
	Game_timer=0;
   draw_WinHandle=mrc_platWinNew(0, WinHandler_rob, KeyHandler_rob);
   mrc_clearScreen(0, 0, 0);
   mrc_sprintf(buftemp,"���������ʼ��ʾ�����������!");
   mrc_strcat(bufout,buftemp);
   mrc_drawText(bufout, 0, 100, 255, 255, 255, 0, MR_FONT_BIG);  
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

void main_normal(int32 data)
{
   mrc_platTextNew("\x5b\x9a\x65\xf6\x8c\x3\x5e\xa6", "\x6f\x14\x79\x3a\x5b\x9a\x65\xf6\x56\x68\x76\x84\x5e\x38\x89\xc4\x4f\x7f\x75\x28\x65\xb9\x6c\xd5\xff\x1a\x6b\xcf\x96\x94\x0\x31\x0\x30\x0\x30\x0\x6d\x0\x73\x62\x67\x88\x4c\x4e\x0\x6b\x21\x80\x17\x65\xf6\x0\x32\x0\x30\x0\x30\x6b\xeb\x79\xd2\x76\x84\x64\xcd\x4f\x5c\x30\x2\x8b\xf7\x63\x9\x78\x6e\x8b\xa4\x95\x2e\x5f\x0\x59\xcb\x6f\x14\x79\x3a\x0\x21", 
   	MR_DIALOG_OK_CANCEL, 0, Demo_normal, NULL);
	return;
}

void main_dead(int32 data)
{//��ѭ��
   mrc_platTextNew("\x6b\x7b\x5f\xaa\x73\xaf", "\x6b\x7b\x5f\xaa\x73\xaf\xff\x1a\x4e\x0\x4e\x9b\x97\x0\x89\x81\x5f\xaa\x73\xaf\x59\x4\x74\x6\x30\x1\x62\x6b\x63\xcf\x76\x84\x5e\x94\x75\x28\x5e\xc\x67\x1b\x4f\x7f\x75\x28\x6b\x7b\x5f\xaa\x73\xaf\x30\x2\x4f\x46\x66\x2f\xff\xc\x59\x82\x67\x9c\x4e\xe3\x78\x1\x4e\x2d\x51\xfa\x73\xb0\x6b\x7b\x5f\xaa\x73\xaf\xff\xc\x62\x4b\x67\x3a\x5c\x6\x65\xe0\x6c\xd5\x54\xcd\x5e\x94\x59\x16\x90\xe8\x75\x35\x8b\xdd\x54\x7c\x53\xeb\xff\xc\x51\xfa\x73\xb0\x6b\x7b\x67\x3a\x30\x1\x59\xd\x4f\x4d\x7b\x49\x60\xc5\x51\xb5\x30\x2\x77\x1f\x76\x84\x89\x81\x6f\x14\x79\x3a\x4e\x48\xff\x1f\x8b\xf7\x63\x9\x78\x6e\x8b\xa4\x95\x2e\x5f\x0\x59\xcb\x6f\x14\x79\x3a\x6b\x7b\x5f\xaa\x73\xaf\xff\x1", 
   	MR_DIALOG_OK_CANCEL, 0, Demo_dead, NULL);
	return;
}

void main_rob(int32 data)
{
   mrc_platTextNew("\x62\xa2\x53\x60\x8c\x3\x5e\xa6\x6a\x21\x62\xdf\x6b\x7b\x5f\xaa\x73\xaf",
"\x6f\x14\x79\x3a\x5b\x9a\x65\xf6\x56\x68\x62\xa2\x53\x60\x8c\x3\x5e\xa6\xff\x1a\x5f\x53\x5e\xc\x67\x1b\x5f\x97\x52\x30\x6a\x21\x62\xdf\x6b\x7b\x5f\xaa\x73\xaf\x76\x84\x65\x48\x67\x9c\xff\xc\x4f\x46\x66\x2f\x53\xc8\x4e\xd\x81\xf3\x4e\x8e\x65\xe0\x6c\xd5\x54\xcd\x5e\x94\x75\x35\x8b\xdd\x4e\x8b\x4e\xf6\x65\xf6\xff\xc\x90\x1a\x5e\x38\x97\x0\x89\x81\x4f\x7f\x75\x28\x5b\x9a\x65\xf6\x56\x68\x62\xa2\x53\x60\x8c\x3\x5e\xa6\x30\x2\x57\x28\x62\xa2\x53\x60\x8c\x3\x5e\xa6\x4e\x2d\xff\xc\x5b\x9a\x65\xf6\x65\xf6\x95\xf4\x52\x30\x54\xe\xff\xc\x51\x48\x54\x2f\x52\xa8\x4e\xb\x4e\x0\x4e\x2a\x5b\x9a\x65\xf6\x56\x68\x51\x8d\x59\x4\x74\x6\x4e\x1a\x52\xa1\x64\xcd\x4f\x5c\xff\xc\x5e\x76\x4e\x14\x90\x1a\x8f\xc7\x90\x9\x62\xe9\x60\x70\x5f\x53\x76\x84\x5b\x9a\x65\xf6\x65\xf6\x95\x7f\xff\x8\x7e\xcf\x8f\xc7\x7a\xb\x5e\x8f\x54\x58\x76\x84\x8b\xa1\x7b\x97\x54\x8c\x8b\xd5\x9a\x8c\xff\x9\xff\xc\x60\x3b\x66\x2f\x57\x28\x67\x2c\x6b\x21\x4e\x1a\x52\xa1\x64\xcd\x4f\x5c\x59\x4\x74\x6\x62\x11\x5b\x8c\x6b\xd5\x52\x4d\xff\xc\x4e\xb\x4e\x0\x4e\x2a\x5b\x9a\x65\xf6\x56\x68\x53\x73\x5d\xf2\x7e\xcf\x8d\x85\x65\xf6\x30\x2\x75\x31\x4e\x8e\x0\x4d\x0\x79\x0\x74\x0\x68\x0\x72\x0\x6f\x0\x61\x0\x64\x5e\x73\x53\xf0\x66\x2f\x53\x55\x7e\xbf\x7a\xb\x76\x84\x4e\x14\x4e\xd\x65\x2f\x63\x1\x62\xa2\x53\x60\x5f\xf\x52\x65\x59\x3a\xff\xc\x62\x40\x4e\xe5\x57\x28\x59\x4\x74\x6\x4e\x1a\x52\xa1\x64\xcd\x4f\x5c\x67\x1f\x95\xf4\xff\xc\x53\x73\x4f\x7f\x4e\xb\x4e\x0\x4e\x2a\x5b\x9a\x65\xf6\x56\x68\x5b\x9a\x65\xf6\x65\xf6\x95\xf4\x52\x30\x4e\x86\xff\xc\x4e\x5f\x5f\xc5\x98\x7b\x7b\x49\x5f\x85\x73\xb0\x67\x9\x64\xcd\x4f\x5c\x5b\x8c\x6b\xd5\x30\x1\x7c\xfb\x7e\xdf\x7a\x7a\x95\xf2\x54\xe\x62\x4d\x88\xab\x0\x4d\x0\x79\x0\x74\x0\x68\x0\x72\x0\x6f\x0\x61\x0\x64\x8c\x3\x5e\xa6\x30\x2\x57\x28\x62\xa2\x53\x60\x8c\x3\x5e\xa6\x67\x1f\x95\xf4\xff\xc\x60\xa8\x53\xef\x4e\xe5\x75\x28\x51\x76\x4e\xd6\x62\x4b\x67\x3a\x62\xe8\x62\x53\x67\x2c\x62\x4b\x67\x3a\xff\xc\x5c\x6\x80\xfd\x59\x1f\x62\x10\x52\x9f\x76\x84\x63\xa5\x54\x2c\x75\x35\x8b\xdd\x30\x2\x63\x9\x78\x6e\x8b\xa4\x95\x2e\x5f\x0\x59\xcb\
x6f\x14\x79\x3a\xff\x1", 
   	MR_DIALOG_OK_CANCEL, 0, Demo_rob, NULL);
	return;
}

void main_info(int32 data)
{//��ʾ������Ϣ�����Ƕ�ʱ�����ȵ���ʾDEMO��
   mrc_platTextNew("\x5e\x2e\x52\xa9", "\x8f\xd9\x66\x2f\x5b\x9a\x65\xf6\x56\x68\x8c\x3\x5e\xa6\x76\x84\x6f\x14\x79\x3a\x0\x44\x0\x45\x0\x4d\x0\x4f\xff\x1", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
	return;
}

//���˵����˳�Ӧ��
void main_exit(int32 data){
   mrc_winClose();//�ر����˵����˳�Ӧ��
}


void Game_exit(int32 data)
{
	mrc_winCloseNotShow();//�رյ�ǰ�Ի���/�Զ��崰��
	mrc_winCloseNotShow();//�رմ�ǰ�����˵�
	main_ShowMenu();//�����������˵���
	return;
}

void main_ShowMenu(void)
{
   mrc_clearScreen(0, 0, 0);
	//�������˵�
	main_menu=0;
	draw_WinHandle=0;
	main_menu = mrc_platMenuNew("\x5b\x9a\x65\xf6\x56\x68\x8c\x3\x5e\xa6",5);             // ��ʱ������
	if (main_menu != MR_FAILED)
	{
	   mrc_platMenuSetItem(main_menu, "\x5b\x9a\x65\xf6\x8c\x3\x5e\xa6", 0, main_normal, 0);   // ��ʱ����
	   mrc_platMenuSetItem(main_menu, "\x6b\x7b\x5f\xaa\x73\xaf", 1, main_dead, 0);   //��ѭ��
	   mrc_platMenuSetItem(main_menu, "\x62\xa2\x53\x60\x8c\x3\x5e\xa6\x6a\x21\x62\xdf\x6b\x7b\x5f\xaa\x73\xaf", 2, main_rob, 0);   // ��ռ����ģ����ѭ��
	   mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 3, main_info, 0);   // ����	   
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 4, main_exit, 0);   // ������ؼ����˳���Ϸ         
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 5, main_exit, 0);   // ������ؼ����˳���Ϸ         	   
	   mrc_platMenuShow(main_menu);	   
	}
	else
	{
	   return;
	}
	return;
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
   mrc_winInit();
	main_ShowMenu();
	mrc_bitmapGetInfo(30,&ScreenInfo);//��Ļ�������ǵ�30��BMP���塣
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


