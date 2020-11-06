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


//主界面菜单句柄
int32 main_menu;
int32 GameWinHandle;

void ShowInfo(int32 data);
int32 GameStart(char *info);


	//用户选择定购，发送计费短信。
	//这里是发送3条测试短信，间隔8秒；
	//只要第一条测试短信发送成功，
	//即认为计费成功、写入签名文件。
void ShowInfo_YES(int32 data)
{
	if(mrc_ChargeEx(1,PAYMENT_TEST,30)==MR_SUCCESS)
	{
		mrc_winClose();
		//进入游戏状态
		GameStart(STR_PAYSUCCEED);
	}
	else
	{
		mrc_winClose();
		//提示发送失败。
		ShowInfo(INFO_BUY_CHARGEFAILED);
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


void ShowInfo(int32 data)
{
	switch(data)
	{
   	case INFO_BUY_ORDER://定购
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



//游戏界面下的事件处理函数
static void Game_KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
   if(type == MR_KEY_PRESS)
   {
		//处理按键按下事件。   
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
			//处理按键弹起事件。
   	}
	else   if(type==MR_MOUSE_DOWN)
   {
			//处理鼠标按下事件。
   }  
	else if(type==MR_MOUSE_UP)
	{
			//处理鼠标弹起事件。
	}
}


//游戏界面窗体事件处理
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
           //刷新屏幕。
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
    //创建主菜单
    main_menu = mrc_platMenuNew("\x8b\xa1\x8d\x39\x6d\x4b\x8b\xd5", 2); 
    if (main_menu != MR_FAILED){
       mrc_platMenuSetItem(main_menu, "\x65\x36\x53\xd6\x8d\x39\x75\x28", 0, ShowInfo, INFO_BUY_ORDER);//第一个菜单项:开始游戏
       mrc_platMenuSetItem(main_menu,STR_TITLE_HELP, 1, ShowInfo, INFO_HELP);//帮助
       mrc_platMenuSetItem(main_menu, NULL, 2, main_menuExit, 0);   // 处理用户不做选择、点击"返回"事件。
       mrc_platMenuShow(main_menu);       
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

当code为MR_LOCALUI_EVENT时，param0的可能取值如下:
enum {
   MR_LOCALUI_KEY_OK,       //本地控件的"确定"键被点击(选择)
   MR_LOCALUI_KEY_CANCEL//本地控件的"取消"("返回")键被点击(选择)
};

param1:
当code为MR_MOUSE_DOWN或MR_MOUSE_UP时，param1为屏幕的y坐标；

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
  return 0;
}
