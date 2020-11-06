#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_aux.h"
#include "..\..\modules\mrc_bmp.h"
#include "Simpledemo.h"

/*
以下是全局变量定义区
在mythroad平台下，全局变量不能在定义的时候初始化
比如，如下的全局变量定义方式是不支持的:
int32 main_menu = 0;
对全局变量的使用规则同样适用于静态局部变量。
*/

//主界面菜单句柄
int32 main_menu;
int32 draw_WinHandle;
uint8 MusicSetting;
uint8 MusicStatus;




//游戏界面窗体事件处理
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
		//刷新屏幕。
		mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		break;
   	case WIN_EVENT_EXIT:
		break;
   	default:
		break;
	}
}

//游戏界面下的事件处理函数
static void KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
	BMP *Himage;
	//用于保存悔棋前状态的临时数组变量
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
		case MR_KEY_1:			//按键 1
			mrc_clearScreen(128,128,128);
			mrc_drawText("Hello", 0, 0, 255, 158, 80, 0, MR_FONT_BIG);
			mrc_winWinEvent(WIN_EVENT_REFRESH);			
			break;
		case MR_KEY_2:          //按键2
			mrc_clearScreen(128,128,128);
			mrc_bitmapLoad(0, "man.bmp", 0, 0, 63, 173, 63);
			mrc_bitmapShow(0, 20, 80, BM_COPY, 0, 0, 63, 173);
			mrc_bitmapLoad(0, "*", 0, 0, 63, 173, 63);
			mrc_winWinEvent(WIN_EVENT_REFRESH);			
			break;
		case MR_KEY_3:          //按键3			
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
		case MR_KEY_4:			//按键4	
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
应用初始化函数
该函数在应用初始化期间被mythroad平台调用，可以在这个
函数中进行全局变量的初始化等工作。
返回值:
MR_SUCCESS  应用初始化成功
MR_FAILED      应用初始化失败
*/

int32 mrc_init(void)
{
   mrc_winInit();
   mrc_clearScreen(0, 0, 0);
	//创建主菜单
	main_menu=0;
	MusicSetting=0;
	draw_WinHandle=0;
	draw_WinHandle=mrc_platWinNew(0, WinHandler, KeyHandler);
   mrc_clearScreen(128, 128, 128);

   return MR_SUCCESS;
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
	if(MusicSetting &&MusicStatus)
	{
		mrc_soundStop(0);
		MusicStatus=0;
	}
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
	mrc_clearScreen(0, 0, 0);
	mrc_drawText("请稍候", SCREEN_WIDTH/3,SCREEN_HEIGHT/3, 255, 255, 255, 0,MR_FONT_BIG);	
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
该函数在应用退出时被mythroad平台调用。
返回值:
MR_SUCCESS  操作成功
MR_FAILED      操作失败
*/
int32 mrc_exitApp(void)
{
   return 0;
}


