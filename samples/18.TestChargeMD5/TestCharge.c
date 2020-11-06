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


//主界面菜单句柄
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



//用户选择定购，发送计费短信。
//这里是发送3条测试短信，间隔8秒；
//只要第一条测试短信发送成功，
//即认为计费成功、写入签名文件。
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
		//进入游戏状态
		GameStart(STR_PAYSUCCEED);
	}
	else
	{
		mrc_winClose();
		//提示发送失败。
		ShowInfo_BaseUi(INFO_BUY_CHARGEFAILED);
	}
}


void ShowInfo_NO(int32 data)
{
	mrc_winClose();
	//回到主菜单
}

void ShowInfo_CHARGEFAILED(int32 data)
{
	mrc_winClose();
	//提示计费失败
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
		lStr = "\x78\x6e\x5b\x9a";	//确定
		rStr = "\x53\xd6\x6d\x88";	//取消
	}

	//下方toolbar工具栏
	mrc_drawRect(0, SCREEN_HEIGHT -TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(lStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);
	mrc_drawText(lStr, 0, 
			SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
			0, 0, 0, 1,	MR_FONT_MEDIUM);//确定
	mrc_drawText(rStr, SCREEN_WIDTH - width, 
			SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
			0, 0, 0, 1, MR_FONT_MEDIUM);//取消
		
	mrc_bitmapLoad(0, "*", 0, 0, 230, 107, 230);//释放空间。

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
		//处理鼠标按下事件。
	}  
	else if(type==MR_MOUSE_UP)
	{
		//处理鼠标弹起事件.
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
	
	//矩形框中填写收费提示文字信息
	mrc_drawTextEx(STR_BUY_ORDER, rect.x, rect.y, rect, colorst, 
			DRAW_TEXT_EX_IS_UNICODE|DRAW_TEXT_EX_IS_AUTO_NEWLINE, 
			MR_FONT_MEDIUM);

	lStr = rStr = NULL;
	if(g_dialog.type  == MR_DIALOG_OK_CANCEL)
	{
		lStr = "\x78\x6e\x5b\x9a";	//确定
		rStr ="\x53\xd6\x6d\x88";	//取消
	}

	//下方toolbar工具栏
	mrc_drawRect(0, SCREEN_HEIGHT - TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(lStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);
	mrc_drawText(lStr, 0, SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//确定
	mrc_drawText(rStr, SCREEN_WIDTH -width, 
		SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//取消

	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//对话框窗体事件
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

//对话框按键事件
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
		//处理鼠标按下事件。
	}  
	else if(type == MR_MOUSE_UP)
	{
		//处理鼠标弹起事件。
	}
}

/************************************************************************/
/*使用图片的提示收费界面，将含有收费信息的图片显示给用户，此方法较      */
/*mrc_drawTextEx的文字提示界面比较美观，缺点在于所占用的内存较大，所占内*/					
/*存大小视图片而定。                                                    */
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
	case INFO_BUY_CHARGEFAILED://短信发送失败。
   		mrc_platTextNew(STR_INFO,STR_BUY_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_CHARGEFAILED);     		
   		break;   			   	
   	case INFO_NO_NETWORK://无网络，计费初始化失败。
   		mrc_platTextNew(STR_TITLE_HELP,STR_INIT_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_EXIT_APP);     		
   		break;
   	case INFO_HELP:
   	default://帮助
   		mrc_platTextNew(STR_TITLE_HELP,STR_BUY_HELP,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_NO);  
	}
}

/************************************************************************/
/*创建对话框收费界面,利用函数CreateDialog   (mrc_drawTextEx)  在界面上显*/
/*示提示的收费文字信息，该方法相对使用图片的方法优势在于所占用的内存小, */
/*缺点在于界面不如图片显示美观。                                        */
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
	case INFO_BUY_CHARGEFAILED://短信发送失败。
   		mrc_platTextNew(STR_INFO,STR_BUY_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_CHARGEFAILED);     		
   		break;   			   	
   	case INFO_NO_NETWORK://无网络，计费初始化失败。
   		mrc_platTextNew(STR_TITLE_HELP,STR_INIT_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_EXIT_APP);     		
   		break;
   	case INFO_HELP:
   	default://帮助
   		mrc_platTextNew(STR_TITLE_HELP,STR_BUY_HELP,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_NO);  
	}
}

/*************************************************************************/
/*本地UI的提示界面。利用本地UI提示收费界面时，在有些机型上可能会使用不了,*/
/*有问题!建议改成自定义窗体的收费界面!                                   */
/*                                                                       */
/*************************************************************************/

void ShowInfo_BaseUi(int32 data)
{
	switch(data)
	{
   	case INFO_BUY_ORDER://定购
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
   	case INFO_BUY_CHARGEFAILED://短信发送失败。
   		mrc_platTextNew(STR_INFO, STR_BUY_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_CHARGEFAILED);     		
   		break;   			   	
   	case INFO_NO_NETWORK://无网络，计费初始化失败。
   		mrc_platTextNew(STR_TITLE_HELP, STR_INIT_FAILED,
   			MR_DIALOG_CANCEL, 0, NULL, ShowInfo_EXIT_APP);     		
   		break;
   	case INFO_HELP:
   	default://帮助
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

	//下方toolbar工具栏
	mrc_drawRect(0, SCREEN_HEIGHT - TOOLBAR_HEIGHT, SCREEN_WIDTH, TOOLBAR_HEIGHT, 100, 100, 100);

	mrc_textWidthHeight(rStr, DRAW_TEXT_EX_IS_UNICODE, MR_FONT_MEDIUM, &width, &font_h);

	mrc_drawText(rStr, SCREEN_WIDTH -width, 
		SCREEN_HEIGHT - TOOLBAR_HEIGHT + (TOOLBAR_HEIGHT - font_h)/2,
		0, 0, 0, 1, MR_FONT_MEDIUM);//返回
		
	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
//游戏界面下的事件处理函数
static void Game_KeyHandler(int32 data, int32 type, int32 p1, int32 p2)
{
	if(type == MR_KEY_RELEASE)
	{
		//处理按键弹起事件。   
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
		//处理鼠标按下事件。
	}  
	else if(type == MR_MOUSE_UP)
	{
		//处理鼠标弹起事件。
	}
}

//游戏界面窗体事件处理
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
	//创建主菜单
	g_mainMenu = mrc_platMenuNew("\x8b\xa1\x8d\x39\x6a\x21\x62\xdf\x75\x4c\x97\x62\x00\x00", 4); 
	if(g_mainMenu != MR_FAILED)
	{
		mrc_platMenuSetItem(g_mainMenu, "\x67\x2c\x57\x30\x0\x55\x0\x49\x65\x36\x8d\x39\x75\x4c\x97\x62", 0, ShowInfo_BaseUi, INFO_BUY_ORDER);//第一个菜单项:本地UI收费界面
		mrc_platMenuSetItem(g_mainMenu, "\x81\xea\x5b\x9a\x4e\x49\x65\x36\x8d\x39\x75\x4c\x97\x62\xff\x8\x56\xfe\x72\x47\xff\x9", 1, ShowInfo_PicUi, INFO_BUY_ORDER);//第二个菜单项:自定义收费界面（图片）
		mrc_platMenuSetItem(g_mainMenu, "\x81\xea\x5b\x9a\x4e\x49\x65\x36\x8d\x39\x75\x4c\x97\x62\xff\x8\x65\x87\x5b\x57\xff\x9", 2, ShowInfo_DialogUi, INFO_BUY_ORDER);//第三个菜单项:自定义收费界面（文字）
		mrc_platMenuSetItem(g_mainMenu,STR_TITLE_HELP, 3, ShowInfo_BaseUi, INFO_HELP);//帮助
		mrc_platMenuSetItem(g_mainMenu, NULL, 4, main_menuExit, 0);   // 处理用户不做选择、点击"返回"事件。
		mrc_platMenuShow(g_mainMenu);       
	}
	else
	{
		return MR_FAILED;
	}
	return MR_SUCCESS;
}

/*
应用初始化函数(入口点函数)
该函数在应用初始化期间被mythroad平台调用，可以在这个
函数中进行全局变量的初始化等工作。
返回值:
MR_SUCCESS  应用初始化成功
MR_FAILED      应用初始化失败
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
应用事件函数
该函数在应用运行期间，每当mythroad平台收到事件时
被调用
输入:
code:
      code的可能取值如下:
enum {
   MR_KEY_PRESS,           //按键按下事件
   MR_KEY_RELEASE,        //按键释放事件
   MR_MOUSE_DOWN,       //触摸屏（鼠标）按下事件
   MR_MOUSE_UP,            //触摸屏（鼠标）抬起/释放事件
   MR_MENU_SELECT,       //菜单选中事件
   MR_MENU_RETURN,       //菜单返回事件
   MR_DIALOG_EVENT,      // 对话框/编辑框/文本框事件
   MR_EVENT02,             //VM保留，请不要使用
   MR_EXIT_EVENT,           //应用退出事件
   MR_EVENT03,                 //VM保留，请不要使用
   MR_LOCALUI_EVENT         //本地化接口事件
};
param0:
   当code为MR_KEY_PRESS或MR_KEY_RELEASE时，param0的可能取值如下:
enum {
   MR_KEY_0,               //按键 0
   MR_KEY_1,               //按键 1
   MR_KEY_2,               //按键 2
   MR_KEY_3,               //按键 3
   MR_KEY_4,               //按键 4
   MR_KEY_5,               //按键 5
   MR_KEY_6,               //按键 6
   MR_KEY_7,               //按键 7
   MR_KEY_8,               //按键 8
   MR_KEY_9,               //按键 9
   MR_KEY_STAR,            //按键 *
   MR_KEY_POUND,           //按键 #
   MR_KEY_UP,              //按键 上
   MR_KEY_DOWN,            //按键 下
   MR_KEY_LEFT,            //按键 左
   MR_KEY_RIGHT,           //按键 右
   MR_KEY_POWER,           //按键 挂机键
   MR_KEY_SOFTLEFT,        //按键 左软键
   MR_KEY_SOFTRIGHT,       //按键 右软键
   MR_KEY_SEND,            //按键 接听键
   MR_KEY_SELECT,          //按键 确认/选择（若方向键中间有确认键，建议设为该键）
   MR_KEY_VOLUME_UP,          //按键 侧键上
   MR_KEY_VOLUME_DOWN,          //按键 侧键下
   MR_KEY_NONE             //按键 保留
};
当code为MR_MOUSE_DOWN或MR_MOUSE_UP时，param0为屏幕的x坐标；
当code为MR_MENU_SELECT时，param0为菜单index；
当code为MR_DIALOG_EVENT时，param0的可能取值如下:
enum {
   MR_DIALOG_KEY_OK,         //对话框/文本框等的"确定"键被点击(选择)
   MR_DIALOG_KEY_CANCEL  //对话框/文本框等的"取消"("返回")键被点击(选择)
};
当code为MR_SMS_INDICATION时，param0为消息内容指针。
当code为MR_LOCALUI_EVENT时，param0的可能取值如下:
enum {
   MR_LOCALUI_KEY_OK,       //本地控件的"确定"键被点击(选择)
   MR_LOCALUI_KEY_CANCEL//本地控件的"取消"("返回")键被点击(选择)
};

param1:
当code为MR_MOUSE_DOWN或MR_MOUSE_UP时，param1为屏幕的y坐标；
当code为MR_SMS_INDICATION时，param1为号码指针。

返回值:
MR_SUCCESS  操作成功
MR_FAILED      操作失败
*/
int32 mrc_event(int32 code, int32 param0, int32 param1)
{
	mrc_winEvent(code, param0, param1);
	return MR_SUCCESS;
}

/*
应用暂停函数
该函数在应用被暂停时（有电话等事件暂停应用）
被mythroad平台调用。
返回值:
MR_SUCCESS  操作成功
MR_FAILED      操作失败
*/
int32 mrc_pause(void)
{
	return 0;
}

/*
该函数在应用恢复运行时被mythroad平台调用。
返回值:
MR_SUCCESS  操作成功
MR_FAILED      操作失败
*/
int32 mrc_resume(void)
{
	mrc_winResume();
	return 0;
}

/*
该函数在应用退出时被mythroad平台调用。
返回值:
MR_SUCCESS  操作成功
MR_FAILED      操作失败
*/
int32 mrc_exitApp(void)
{
	mrc_releaseCharge();
	destroyMd5();
	return 0;
}
