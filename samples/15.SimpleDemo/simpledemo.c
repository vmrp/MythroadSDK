#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_aux.h"
#include "..\..\modules\mrc_bmp.h"
#include "Simpledemo.h"

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
uint8 MusicSetting;
uint8 MusicStatus;




//��Ϸ���洰���¼�����
static void WinHandler(int32 data,int32 eventId)
{
	mrc_printf("data=%d, eventId=%d", data, eventId);
	switch(eventId)
	{
   	case WIN_EVENT_SHOW:
		{
			WinHandler(data, WIN_EVENT_REFRESH);
			break;
		}
   	case WIN_EVENT_PAUSE:
		break;
   	case WIN_EVENT_REFRESH:
		//ˢ����Ļ��
		mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
   	case WIN_EVENT_EXIT:
		break;
   	default:
		break;
	}
}

//��Ϸ�����µ��¼�������
static void KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
	BMP *Himage;
	//���ڱ������ǰ״̬����ʱ�������
	//DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
	//DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
	if(type == MR_KEY_RELEASE)
   	{
		switch(p1)
		{
		case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
			break;
		case MR_KEY_1:			//���� 1
			mrc_clearScreen(128,128,128);
			mrc_drawText("Hello", 0, 0, 255, 158, 80, 0, MR_FONT_BIG);
			mrc_winWinEvent(WIN_EVENT_REFRESH);			
			break;
		case MR_KEY_2:          //����2
			mrc_clearScreen(128,128,128);
			mrc_bitmapLoad(0, "man.bmp", 0, 0, 63, 173, 63);
			mrc_bitmapShow(0, 20, 80, BM_COPY, 0, 0, 63, 173);
			mrc_bitmapLoad(0, "*", 0, 0, 63, 173, 63);
			mrc_winWinEvent(WIN_EVENT_REFRESH);			
			break;
		case MR_KEY_3:          //����3			
			mrc_clearScreen(128,128,128);
			Himage = mrc_bmpLoadFromMrp( "man.bmp16");
			if (NULL == Himage)
			{
				mrc_drawText("Error", 0, 0, 255, 158, 80, 0, MR_FONT_BIG);
			}else
			{
				mrc_drawText("SUCCESS", 0, 0, 255, 158, 80, 0, MR_FONT_BIG);
				mrc_bmpShow(Himage,0,0,63,173,BM_COPY,0,0);
			}
			mrc_winWinEvent(WIN_EVENT_REFRESH);		
			break;
		case MR_KEY_4:			//����4	
			mrc_clearScreen(128,128,128);
			if (mrc_soundSet(0, "background.mid", 0) == MR_SUCCESS)
			{
				mrc_soundPlay(0,1);
				MusicSetting=1;
				MusicStatus=1;
			}			
			break;
		case MR_KEY_5:
			if(1==MusicStatus)
			{
				mrc_soundStop(0);
				MusicSetting=0;				
				MusicStatus=0;
			}
			break;
		default:
            break;
		}       
   	}
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
   mrc_clearScreen(0, 0, 0);
	//�������˵�
	main_menu=0;
	MusicSetting=0;
	draw_WinHandle=0;
	draw_WinHandle=mrc_platWinNew(0, WinHandler, KeyHandler);
   mrc_clearScreen(128, 128, 128);

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
	if(MusicSetting &&MusicStatus)
	{
		mrc_soundStop(0);
		MusicStatus=0;
	}
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
	mrc_clearScreen(0, 0, 0);
	mrc_drawText("���Ժ�", SCREEN_WIDTH/3,SCREEN_HEIGHT/3, 255, 255, 255, 0,MR_FONT_BIG);	
	mrc_winResume();	
	mrc_winWinEvent(WIN_EVENT_REFRESH);
	if(MusicSetting)
	{
		mrc_soundPlay(0,1);
		MusicStatus=1;
	}	
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


