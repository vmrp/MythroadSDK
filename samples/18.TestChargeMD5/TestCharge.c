#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_payment.h"

#include "encode.h"
#include "sendsms.h"
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

typedef struct{
	char* text;
	int32 type;
	PtrHilight hOk;
	PtrHilight hCancel;
}DIALOG_DATA_T;


#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define TOOLBAR_HEIGHT   26


//������˵����
int32 g_mainMenu;
int32 g_gameWinHandle;
DIALOG_DATA_T g_dialog;
char *g_pString;

void ShowInfo_BaseUi(int32 data);
int32 GameStart(char *info);
void CreateDialog(char* text,int32 type,PtrHilight hOk, PtrHilight hCancel);
void DialogWinKeyEvent(int32 data, int32 type,int32 p1,int32 p2);
void DialogWinWinEvent(int32 data,int32 eventId);
void dialogWinRefresh(int32 data);
void PicWinKeyEvent(int32 data, int32 type, int32 p1, int32 p2);
void PicWinWinEvent(int32 data,int32 eventId);



//�û�ѡ�񶨹������ͼƷѶ��š�
//�����Ƿ���3�����Զ��ţ����8�룻
//ֻҪ��һ�����Զ��ŷ��ͳɹ���
//����Ϊ�Ʒѳɹ���д��ǩ���ļ���
void ShowInfo_YES(int32 data)
{
//	if(MR_SUCCESS == mrc_ChargeEx(1,PAYMENT_TEST,30))
// 	int32 oldTime = mrc_getUptime();
//	int32 curTime = 0;
	if (MR_SUCCESS == SendSms(0, REG_VALUE))
	{
// 		curTime = mrc_getUptime();
// 		mrc_printf("-----%d-----",curTime-oldTime);
		mrc_winClose();
		//������Ϸ״̬
		GameStart(STR_PAYSUCCEED);
	}
	else
	{
		mrc_winClose();
		//��ʾ����ʧ�ܡ�
		ShowInfo_BaseUi(INFO_BUY_CHARGEFAILED);
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

void ShowPicFace(int32 type, PtrHilight hOk, PtrHilight hCancel)
{
	int32 winId;
	memset(&g_dialog, 0, sizeof(g_dialog));

	g_dialog.text = NULL;
	g_dialog.type = type;
	g_dialog.hOk = hOk;
	g_dialog.hCancel = hCancel;

	winId = mrc_platWinNew(0, PicWinWinEvent, PicWinKeyEvent);
	if(MR_FAILED == winId)
	{
		mrc_printf("winNew Error!");
	}
}

void PicWinRefresh(int32 data)
{
	char* lStr, *rStr;
	int32 width, font_h;

	mrc_clearScreen(128, 128, 128);
	
	if(MR_SUCCESS == mrc_bitmapLoad(0, "charge.bmp", 0, 0, 230, 107, 230))
		mrc_bitmapShow(0, (SCREEN_WIDTH - 230)/2, (SCREEN_HEIGHT - TOOLBAR_HEIGHT - 107)/2, 
				BM_COPY, 0, 0, 230, 107);

	lStr = rStr = NULL;
	if(g_dialog.type  == MR_DIALOG_OK_CANCEL)
	{
		lStr = "\x78\x6e\x5b\x9a";	//ȷ��
		rStr = "\x53\xd6\x6d\x88";	//ȡ��
	}

	//�·�toolbar������
	mrc_drawRect(0, SCREEN_HEIGHT -TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(lStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);
	mrc_drawText(lStr, 0, 
			SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
			0, 0, 0, 1,	MR_FONT_MEDIUM);//ȷ��
	mrc_drawText(rStr, SCREEN_WIDTH - width, 
			SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
			0, 0, 0, 1, MR_FONT_MEDIUM);//ȡ��
		
	mrc_bitmapLoad(0, "*", 0, 0, 230, 107, 230);//�ͷſռ䡣

	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void PicWinWinEvent(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_SHOW:
		PicWinRefresh(data);
		break;
	case WIN_EVENT_REFRESH:
		PicWinWinEvent(data, WIN_EVENT_SHOW);
		break;
	case WIN_EVENT_EXIT:
		break;
	}
}

void PicWinKeyEvent(int32 data, int32 type, int32 p1, int32 p2)
{
	if(type == MR_KEY_RELEASE)
	{
		switch(p1)
		{
		case MR_KEY_SOFTRIGHT:
			if(g_dialog.hCancel)
				g_dialog.hCancel(data);
			break;
		case MR_KEY_SOFTLEFT:
			if(g_dialog.hOk)
				g_dialog.hOk(data);
			break;
		default:
			break;
		}
	}
	else if(type==MR_MOUSE_DOWN)
	{
		//������갴���¼���
	}  
	else if(type==MR_MOUSE_UP)
	{
		//������굯���¼�.
	}
}

void CreateDialog(char* text, int32 type, PtrHilight hOk, PtrHilight hCancel)
{
	int32 winId,len;
	
	memset(&g_dialog, 0, sizeof(g_dialog));

	len = mrc_wstrlen((char*)text);
	g_dialog.text = (char*)malloc(len + 2);
	if(g_dialog.text == NULL)
	{
		mrc_exit();
		return;
	}	
	memset(g_dialog.text, 0, len+2);
	memcpy(g_dialog.text, text, len+2);
	
	g_dialog.type = type;
	g_dialog.hOk = hOk;
	g_dialog.hCancel = hCancel;

	winId = mrc_platWinNew(0, DialogWinWinEvent, DialogWinKeyEvent);
	
	if(winId == MR_FAILED)
	{
		mrc_printf("winNew Error!");
	}
}

void dialogWinRefresh(int32 data)
{
	int32 width, font_h;
	uint16 baseX, baseY;
	uint16 totalHeight, lineWidth ;
	uint8 lines;
	mr_screenRectSt rect;
	mr_colourSt colorst = {255, 255, 255};
	char *lStr, *rStr;

	mrc_clearScreen(128, 128, 128);

	baseX = 5;
	mrc_textWidthHeight(g_dialog.text, 1, MR_FONT_MEDIUM, &width, &font_h);
	lineWidth = 240 - 5*2 - 4*2;
	lines = (width + lineWidth -1) / lineWidth;
	if(lines > 8)
		lines = 8;
	totalHeight = (font_h+1)*lines + 14;
	baseY = (SCREEN_HEIGHT- TOOLBAR_HEIGHT - totalHeight) / 2;
	
	mrc_drawRect(baseX, baseY, SCREEN_WIDTH - baseX*2, totalHeight, 100, 100, 100);

	if(lines == 1)
	{
		rect.x = (SCREEN_WIDTH- width) /2;
	}
	else
		rect.x = baseX + 4;
	rect.y = baseY + 6;
	rect.w = lineWidth;
	rect.h = totalHeight - 8 ;
	
	//���ο�����д�շ���ʾ������Ϣ
	mrc_drawTextEx(STR_BUY_ORDER, rect.x, rect.y, rect, colorst, 
			DRAW_TEXT_EX_IS_UNICODE|DRAW_TEXT_EX_IS_AUTO_NEWLINE, 
			MR_FONT_MEDIUM);

	lStr = rStr = NULL;
	if(g_dialog.type  == MR_DIALOG_OK_CANCEL)
	{
		lStr = "\x78\x6e\x5b\x9a";	//ȷ��
		rStr ="\x53\xd6\x6d\x88";	//ȡ��
	}

	//�·�toolbar������
	mrc_drawRect(0, SCREEN_HEIGHT - TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(lStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);
	mrc_drawText(lStr, 0, SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//ȷ��
	mrc_drawText(rStr, SCREEN_WIDTH -width, 
		SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//ȡ��

	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//�Ի������¼�
void DialogWinWinEvent(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_SHOW:
		dialogWinRefresh(data);
		break;
	case WIN_EVENT_PAUSE:
		break;
	case WIN_EVENT_REFRESH:
		DialogWinWinEvent(data, WIN_EVENT_SHOW);
		break;
	case WIN_EVENT_EXIT:
		if(g_dialog.text)
			mrc_free(g_dialog.text), g_dialog.text = NULL;	
		break;
	default:
		break;
	}
}

//�Ի��򰴼��¼�
void DialogWinKeyEvent(int32 data, int32 type, int32 p1, int32 p2)
{
	if(type == MR_KEY_RELEASE)
	{
		switch(p1)
		{
		case MR_KEY_SOFTLEFT: 
			if(g_dialog.hOk)
				g_dialog.hOk(data);
			break;
		case MR_KEY_SOFTRIGHT:
			if(g_dialog.hCancel)
				g_dialog.hCancel(data);
			break;
		default:
			break;
		}
	}
	else if(type == MR_MOUSE_DOWN)
	{
		//������갴���¼���
	}  
	else if(type == MR_MOUSE_UP)
	{
		//������굯���¼���
	}
}

/************************************************************************/
/*ʹ��ͼƬ����ʾ�շѽ��棬�������շ���Ϣ��ͼƬ��ʾ���û����˷�����      */
/*mrc_drawTextEx��������ʾ����Ƚ����ۣ�ȱ��������ռ�õ��ڴ�ϴ���ռ��*/					
/*���С��ͼƬ������                                                    */
/************************************************************************/
void ShowInfo_PicUi(int32 data)
{
	switch(data)
	{
	case INFO_BUY_ORDER:
		if(mrc_checkCharge()!= MR_SUCCESS)
		{
			ShowPicFace(MR_DIALOG_OK_CANCEL, ShowInfo_YES, ShowInfo_NO);
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

/************************************************************************/
/*�����Ի����շѽ���,���ú���CreateDialog   (mrc_drawTextEx)  �ڽ�������*/
/*ʾ��ʾ���շ�������Ϣ���÷������ʹ��ͼƬ�ķ�������������ռ�õ��ڴ�С, */
/*ȱ�����ڽ��治��ͼƬ��ʾ���ۡ�                                        */
/************************************************************************/

void ShowInfo_DialogUi(int32 data)
{
	switch(data)
	{
	case INFO_BUY_ORDER:
		if(mrc_checkCharge()!= MR_SUCCESS)
		{
			CreateDialog( STR_BUY_ORDER, MR_DIALOG_OK_CANCEL, ShowInfo_YES, ShowInfo_NO);
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

/*************************************************************************/
/*����UI����ʾ���档���ñ���UI��ʾ�շѽ���ʱ������Щ�����Ͽ��ܻ�ʹ�ò���,*/
/*������!����ĳ��Զ��崰����շѽ���!                                   */
/*                                                                       */
/*************************************************************************/

void ShowInfo_BaseUi(int32 data)
{
	switch(data)
	{
   	case INFO_BUY_ORDER://����
		if(mrc_checkCharge() != MR_SUCCESS)
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
   		mrc_platTextNew(STR_INFO, STR_BUY_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_CHARGEFAILED);     		
   		break;   			   	
   	case INFO_NO_NETWORK://�����磬�Ʒѳ�ʼ��ʧ�ܡ�
   		mrc_platTextNew(STR_TITLE_HELP, STR_INIT_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_EXIT_APP);     		
   		break;
   	case INFO_HELP:
   	default://����
   		mrc_platTextNew(STR_TITLE_HELP, STR_BUY_HELP,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_NO);  
	}
}
static void GameStartRefresh(int32 data)
{
	int32 width, font_h;
	char *rStr;
	mrc_clearScreen(128, 128, 128);
	mrc_drawText(g_pString, 0, 0, 255, 255, 255, 0, MR_FONT_BIG);

	rStr = "\x8f\xd4\x56\xde\x00\x00";

	//�·�toolbar������
	mrc_drawRect(0, SCREEN_HEIGHT - TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(rStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);

	mrc_drawText(rStr, SCREEN_WIDTH -width, 
		SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//����
		
	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
//��Ϸ�����µ��¼�������
static void Game_KeyHandler(int32 data, int32 type, int32 p1, int32 p2)
{
	if(type == MR_KEY_RELEASE)
	{
		//�����������¼���   
		switch(p1)
		{
		case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			break;
		default:
			break;
		}      
	}
	else if(type == MR_MOUSE_DOWN)
	{
		//������갴���¼���
	}  
	else if(type == MR_MOUSE_UP)
	{
		//������굯���¼���
	}
}

//��Ϸ���洰���¼�����
static void Game_WinHandler(int32 data, int32 eventId)
{
	//DBG_PRINTF(("data=%d, eventId=%d", data, eventId));
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
		GameStartRefresh(data);
		break;
	case WIN_EVENT_EXIT:
		if(g_pString)
			free(g_pString), g_pString = NULL;
		break;
	default:
		break;
	}
}


int32 GameStart(char *info)
{
	int32 len;
	len = mrc_wstrlen((char*)info);
	g_pString = (char*)malloc(len+2);
	if(g_pString == NULL)
	{
		mrc_exit();
		return MR_FAILED;
	}
	memset(g_pString, 0, len);
	memcpy(g_pString, info, len);

	g_gameWinHandle = mrc_platWinNew(0, Game_WinHandler, Game_KeyHandler);  
	if(g_gameWinHandle == MR_FAILED)
		return MR_FAILED;
	else
		return MR_SUCCESS;
}

void main_menuExit(int32 data)
{
	mrc_winClose();
}

int32 main_init(void)
{
	mrc_winInit();

	mrc_clearScreen(0, 0, 0);
	g_pString = NULL;
	//�������˵�
	g_mainMenu = mrc_platMenuNew("\x8b\xa1\x8d\x39\x6a\x21\x62\xdf\x75\x4c\x97\x62\x00\x00", 4); 
	if(g_mainMenu != MR_FAILED)
	{
		mrc_platMenuSetItem(g_mainMenu, "\x67\x2c\x57\x30\x0\x55\x0\x49\x65\x36\x8d\x39\x75\x4c\x97\x62", 0, ShowInfo_BaseUi, INFO_BUY_ORDER);//��һ���˵���:����UI�շѽ���
		mrc_platMenuSetItem(g_mainMenu, "\x81\xea\x5b\x9a\x4e\x49\x65\x36\x8d\x39\x75\x4c\x97\x62\xff\x8\x56\xfe\x72\x47\xff\x9", 1, ShowInfo_PicUi, INFO_BUY_ORDER);//�ڶ����˵���:�Զ����շѽ��棨ͼƬ��
		mrc_platMenuSetItem(g_mainMenu, "\x81\xea\x5b\x9a\x4e\x49\x65\x36\x8d\x39\x75\x4c\x97\x62\xff\x8\x65\x87\x5b\x57\xff\x9", 2, ShowInfo_DialogUi, INFO_BUY_ORDER);//�������˵���:�Զ����շѽ��棨���֣�
		mrc_platMenuSetItem(g_mainMenu,STR_TITLE_HELP, 3, ShowInfo_BaseUi, INFO_HELP);//����
		mrc_platMenuSetItem(g_mainMenu, NULL, 4, main_menuExit, 0);   // �����û�����ѡ�񡢵��"����"�¼���
		mrc_platMenuShow(g_mainMenu);       
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
	md5Init();
	if(mrc_initCharge() == MR_SUCCESS)	
		return main_init();
	else
	{
		mrc_winInit();
		mrc_clearScreen(0, 0, 0);		
		ShowInfo_BaseUi(INFO_NO_NETWORK);
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
��codeΪMR_SMS_INDICATIONʱ��param0Ϊ��Ϣ����ָ�롣
��codeΪMR_LOCALUI_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_LOCALUI_KEY_OK,       //���ؿؼ���"ȷ��"�������(ѡ��)
   MR_LOCALUI_KEY_CANCEL//���ؿؼ���"ȡ��"("����")�������(ѡ��)
};

param1:
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param1Ϊ��Ļ��y���ꣻ
��codeΪMR_SMS_INDICATIONʱ��param1Ϊ����ָ�롣

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
	destroyMd5();
	return 0;
}
