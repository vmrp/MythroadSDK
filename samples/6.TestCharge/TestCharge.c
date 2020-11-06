#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_payment.h"

#include "unicodeSTR.h"
#include "TestCharge.h"



enum{
INFO_BUY_ORDER,
INFO_BUY_GOOD,
INFO_BUY_CHARGED,
INFO_BUY_CHARGEFAILED,
INFO_NO_NETWORK,
INFO_HELP
}ENUM_INFO;

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320


//������˵����
int32 main_menu;
int32 GameWinHandle;

void ShowInfo(int32 data);
int32 GameStart(char *info);


	//�û�ѡ�񶨹������ͼƷѶ��š�
	//�����Ƿ���3�����Զ��ţ����8�룻
	//ֻҪ��һ�����Զ��ŷ��ͳɹ���
	//����Ϊ�Ʒѳɹ���д��ǩ���ļ���
void ShowInfo_YES(int32 data)
{
	if(mrc_ChargeEx(1,PAYMENT_TEST,30)==MR_SUCCESS)
	{
		mrc_winClose();
		//������Ϸ״̬
		GameStart(STR_PAYSUCCEED);
	}
	else
	{
		mrc_winClose();
		//��ʾ����ʧ�ܡ�
		ShowInfo(INFO_BUY_CHARGEFAILED);
	}
}

void ShowInfo_NO(int32 data)
{
	mrc_winClose();
	//�ص����˵�
}

void ShowInfo_CHARGEFAILED(int32 data)
{
	mrc_winClose();
	//��ʾ�Ʒ�ʧ��
}

void ShowInfo_EXIT_APP(int32 data)
{
	mrc_winClose();
	mrc_exit();
}


void ShowInfo(int32 data)
{
	switch(data)
	{
   	case INFO_BUY_ORDER://����
    	if(mrc_checkCharge()!=MR_SUCCESS)
    	{
   			mrc_platTextNew(STR_INFO,STR_BUY_ORDER,
   				MR_DIALOG_OK_CANCEL, 0, ShowInfo_YES, ShowInfo_NO);   		
    	}
    	else
    		GameStart(STR_PAYED);
   		break;
   	case INFO_BUY_CHARGED:
			GameStart(STR_PAYED);
   		break;
   	case INFO_BUY_CHARGEFAILED://���ŷ���ʧ�ܡ�
   		mrc_platTextNew(STR_INFO,STR_BUY_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_CHARGEFAILED);     		
   		break;   			   	
   	case INFO_NO_NETWORK://�����磬�Ʒѳ�ʼ��ʧ�ܡ�
   		mrc_platTextNew(STR_TITLE_HELP,STR_INIT_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_EXIT_APP);     		
   		break;
   	case INFO_HELP:
   	default://����
   		mrc_platTextNew(STR_TITLE_HELP,STR_BUY_HELP,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_NO);  
	}
}



//��Ϸ�����µ��¼�������
static void Game_KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
   if(type == MR_KEY_PRESS)
   {
		//�����������¼���   
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }      
   }
   else if(type == MR_KEY_RELEASE)
   	{
   		DBG_PRINTF(("KEY %d  Press.",p1));
			//�����������¼���
   	}
	else   if(type==MR_MOUSE_DOWN)
   {
			//������갴���¼���
   }  
	else if(type==MR_MOUSE_UP)
	{
			//������굯���¼���
	}
}


//��Ϸ���洰���¼�����
static void Game_WinHandler(int32 data,int32 eventId)
{
   DBG_PRINTF(("data=%d, eventId=%d", data, eventId));
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           Game_WinHandler(data, WIN_EVENT_REFRESH);
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



int32 GameStart(char *info)
{

	GameWinHandle=mrc_platWinNew(0, Game_WinHandler, Game_KeyHandler);  
	if(GameWinHandle==MR_FAILED)
		return MR_SUCCESS;
	mrc_clearScreen(0, 0, 0);	
	mrc_drawText(info,0,0,180,150, 120,0,MR_FONT_BIG);
	mrc_winWinEvent(WIN_EVENT_REFRESH);
	return MR_SUCCESS;
}

void main_menuExit(int32 data){
	mrc_winClose();
}

int32 main_init(void)
{
   mrc_winInit();
   mrc_clearScreen(0, 0, 0);
    //�������˵�
    main_menu = mrc_platMenuNew("\x8b\xa1\x8d\x39\x6d\x4b\x8b\xd5", 2); 
    if (main_menu != MR_FAILED){
       mrc_platMenuSetItem(main_menu, "\x65\x36\x53\xd6\x8d\x39\x75\x28", 0, ShowInfo, INFO_BUY_ORDER);//��һ���˵���:��ʼ��Ϸ
       mrc_platMenuSetItem(main_menu,STR_TITLE_HELP, 1, ShowInfo, INFO_HELP);//����
       mrc_platMenuSetItem(main_menu, NULL, 2, main_menuExit, 0);   // �����û�����ѡ�񡢵��"����"�¼���
       mrc_platMenuShow(main_menu);       
    }
    else
    {
       return MR_FAILED;
    }
    return MR_SUCCESS;
}

/*
Ӧ�ó�ʼ������(��ڵ㺯��)
�ú�����Ӧ�ó�ʼ���ڼ䱻mythroadƽ̨���ã����������
�����н���ȫ�ֱ����ĳ�ʼ���ȹ�����
����ֵ:
MR_SUCCESS  Ӧ�ó�ʼ���ɹ�
MR_FAILED      Ӧ�ó�ʼ��ʧ��
*/
int32 mrc_init(void)
{
	if(mrc_initCharge()==MR_SUCCESS)	//
		return main_init();
	else
	{
		mrc_winInit();
		mrc_clearScreen(0, 0, 0);		
		ShowInfo(INFO_NO_NETWORK);
	}
	return MR_FAILED;	
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
	mrc_releaseCharge();
  return 0;
}
