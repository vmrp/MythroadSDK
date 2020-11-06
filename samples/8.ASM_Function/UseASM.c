#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"

#ifdef DEMO_DEBUG
#define DBG_PRINTF(a) mrc_printf a
#else
#define DBG_PRINTF(a) 
#endif

//主界面菜单句柄
int32 main_menu;
extern long FixedByFrac(long a, long b);


//菜单项A:嵌入汇编
void main_menuA(int32 data){
	long a=65539,b=65539,c=0;
	c=FixedByFrac(a,b);
	DBG_PRINTF(("嵌入汇编结果%d",c));
   mrc_platTextNew("\x5d\x4c\x51\x65\x6c\x47\x7f\x16", "\x7f\x16\x8b\xd1\x90\x9\x98\x79\x4e\x3a\x4f\x7f\x75\x28\x6c\x47\x7f\x16\x5b\x9e\x73\xb0\x30\x2", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
}

//菜单项B:帮助
void main_menuB(int32 data){
   mrc_platTextNew("\x5e\x2e\x52\xa9", "\x8f\xd9\x66\x2f\x0\x43\x4e\x2d\x5d\x4c\x51\x65\x6c\x47\x7f\x16\x5b\x9e\x73\xb0\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x5b\x9a\x70\xb9\x5c\xf\x65\x70\x4e\x58\x6c\xd5\x76\x84\x0\x44\x0\x45\x0\x4d\x0\x4f\xff\x1", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
}

void main_menuExit(int32 data){
	mrc_winClose();
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
      main_menu = mrc_platMenuNew("\x5d\x4c\x51\x65\x6c\x47\x7f\x16", 2); //嵌入汇编
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x5b\x9a\x70\xb9\x5c\xf\x65\x70\x4e\x58\x6c\xd5", 0, main_menuA, 0);//16bit定点小数乘法
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 1, main_menuB, 0);   // 帮助
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
   return 0;
}