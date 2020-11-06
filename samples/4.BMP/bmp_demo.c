#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_aux.h"
#include "..\..\modules\mrc_bmp.h"


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

/*
应用的刷新函数
*/
static void white_refresh(int32 data);
void main_ShowMenu(void);

//刷新屏幕
static void white_refresh(int32 data)
{
	mrc_refreshScreen(0, 0, 240, 320);
	return;
}

void Test_BMP16bit_back(int32 data)
{
	mrc_winClose();
	return;
}

void Test_BMP256_back(int32 data)
{
	mrc_winClose();
	return;
}

void Test_BMP16_back(int32 data)
{
	mrc_winClose();
	return;
}


//游戏界面下的事件处理函数
static void KeyHandler_BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
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
         default:
            break;
      }       
   	}

}

//游戏界面下的事件处理函数
static void KeyHandler_BMP256(int32 data, int32 type,int32 p1,int32 p2)
{
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
         default:
            break;
      }       
   	}

}

//游戏界面下的事件处理函数
static void KeyHandler_BMP16(int32 data, int32 type,int32 p1,int32 p2)
{
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
         default:
            break;
      }       
   	}
}

//游戏界面下的事件处理函数
static void KeyHandler_gif2BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
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
         default:
            break;
      }       
   	}

}

//游戏界面下的事件处理函数
static void KeyHandler_Img2BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
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
         default:
            break;
      }       
   	}

}


//游戏界面窗体事件处理
static void WinHandler_BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //刷新屏幕。
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//游戏界面窗体事件处理
static void WinHandler_BMP256(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP256(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //刷新屏幕。
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}


//游戏界面窗体事件处理
static void WinHandler_BMP16(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP16(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //刷新屏幕。
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//游戏界面窗体事件处理
static void WinHandler_gif2BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_gif2BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //刷新屏幕。
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//游戏界面窗体事件处理
static void WinHandler_Img2BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_Img2BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //刷新屏幕。
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

void Test_BMP16bit(int32 data)
{
	int32 ret;
	char retbuf[64];		
	int32 fontWidth,fontHeight;	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP16bit, KeyHandler_BMP16bit);
   mrc_clearScreen(128, 128, 128);
   
   //从MRP中读取并显示。
   ret=mrc_bitmapLoad(0,"fullscreen24bit.bmp", 0, 0, 240, 320,240);
   if(ret==MR_FAILED)
   		return;
   ret=mrc_getUptime();
	mrc_bitmapShow(0, 0, 0,BM_COPY,0,0,240,320);   
	ret=mrc_getUptime()-ret;
	mrc_printf("mrc_bitmapShow used %d ms",ret);
	
	ret=mrc_textWidthHeight("个",0,MR_FONT_SMALL,&fontWidth,&fontHeight);   
	mrc_sprintf(retbuf,"字体高度%d，宽度%d",fontHeight,fontWidth);
	mrc_drawText(retbuf,0,210,200,100,100,0,MR_FONT_BIG);		  
	
	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
    ret=mrc_bitmapLoad(0,"*", 0, 0, 240, 320,240);//释放空间。
	return;
}




void Test_BMP256(int32 data)
{
	BMP *hBMP256;
	int32 ret;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP256, KeyHandler_BMP256);
   mrc_clearScreen(128, 128, 128);


   //从MRP中读取并显示。
   hBMP256=mrc_bmpLoadFromFile("fullscreen256.bmp256");
   if(hBMP256==NULL)
   		return;
   mrc_printf("mrc_bmpLoadFromMrp  Success!");
   ret=mrc_getUptime();
	mrc_bmpShow(hBMP256,0,0,240,320,BM_COPY,0,0);
	ret=mrc_getUptime()-ret;
	mrc_printf("mrc_bmpShow used %d ms",ret);
   mrc_winWinEvent(WIN_EVENT_REFRESH);
   return;
   
   //直接从磁盘文件中读取并显示。
   hBMP256=mrc_bmpLoadFromFile("test.bmp256");
	mrc_bmpShow(hBMP256,0,0,64,64,BM_OR,0,0);
	//white_refresh(data);
	//return;
	mrc_bmpShow(hBMP256,64,0,64,64,BM_XOR,0,0);
	mrc_bmpShow(hBMP256,128,0,64,64,BM_COPY,0,0);

	mrc_bmpShow(hBMP256,0,64,64,64,BM_NOT,0,0);
	mrc_bmpShow(hBMP256,64,64,64,64,BM_MERGENOT,0,0);
	mrc_bmpShow(hBMP256,128,64,64,64,BM_ANDNOT,0,0);

	mrc_bmpShow(hBMP256,0,128,64,64,BM_TRANSPARENT,0,0);
	mrc_bmpShow(hBMP256,64,128,64,64,BM_AND,0,0);
	mrc_bmpShow(hBMP256,128,128,64,64,BM_GRAY,0,0);

	mrc_bmpShow(hBMP256,0,192,64,64,BM_REVERSE,0,0);
   
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}


void Test_BMP16(int32 data)
{
	uint8 index,r,g,b,index2,r2,g2,b2;
	uint32 row,col;
	BMP *hBMP,*hBMP2;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP16, KeyHandler_BMP16);
   mrc_clearScreen(128, 128, 128);

   //从磁盘文件中读取
	hBMP=mrc_bmpLoadFromFile("test.bmp16");

	//各种显示功能
	mrc_bmpShow(hBMP,0,0,64,64,BM_OR,0,0);
	mrc_bmpShow(hBMP,64,0,64,64,BM_XOR,0,0);
	mrc_bmpShow(hBMP,128,0,64,64,BM_COPY,0,0);

	mrc_bmpShow(hBMP,0,64,64,64,BM_NOT,0,0);
	mrc_bmpShow(hBMP,64,64,64,64,BM_MERGENOT,0,0);
	mrc_bmpShow(hBMP,128,64,64,64,BM_ANDNOT,0,0);

	mrc_bmpShow(hBMP,0,128,64,64,BM_TRANSPARENT,0,0);
	mrc_bmpShow(hBMP,64,128,64,64,BM_AND,0,0);
	mrc_bmpShow(hBMP,128,128,64,64,BM_GRAY,0,0);

	mrc_bmpShow(hBMP,0,192,64,64,BM_REVERSE,0,0);
	mrc_bmpFree(hBMP);
	hBMP=NULL;
	

	//下面测试BMP创建以及写文件功能。
   //从MRP中读取
	hBMP=mrc_bmpLoadFromFile("test.bmp16");	
	hBMP2=mrc_bmpCreate(mrc_bmpGetWidth(hBMP),mrc_bmpGetHeight(hBMP),mrc_bmpGetDepth(hBMP));
	for(index=0;index<mrc_bmpGetColorUsed(hBMP);index++)
	{
		mrc_bmpGetPaletteColor(hBMP, index, &r,&g,&b);
		mrc_bmpSetPaletteColor(hBMP2, index,r,g,b);
		mrc_bmpGetPaletteColor(hBMP2, index, &r2,&g2,&b2);
		if(r2!=r ||g2!=g||b2!=b)
		{
			return;//something wrong
		}
	}	


	for(row=0;row<mrc_bmpGetHeight(hBMP2);row++)
	{
		for(col=0;col<mrc_bmpGetWidth(hBMP2);col++)
			{
				mrc_bmpGetPixelIndex(hBMP, col,row, &index);
				mrc_bmpSetPixelIndex(hBMP2, col,row, index);				
				mrc_bmpGetPixelIndex(hBMP2, col,row, &index2);
				if(index2!=index)
				{
				
					return;//something wrong
				}				
			}
	}
	mrc_bmpWriteFile(hBMP2,"testcopy.bmp16");
	mrc_bmpShow(hBMP2,0,256,64,64,256,0,0);
	mrc_bmpFree(hBMP);
	mrc_bmpFree(hBMP2);
	hBMP=NULL;
	hBMP2=NULL;
	hBMP2=mrc_bmpLoadFromFile("testcopy.bmp16");	
	mrc_bmpShow(hBMP2,64,256,64,64,255,0,0);
	mrc_bmpFree(hBMP2);
	hBMP2=NULL;
	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

void Test_gif2BMP16bit(int32 data)
{
	int32 ret,gifsize,gif_width,gif_height;
	uint8 *gif=NULL;
	uint16 *bmp=NULL;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_gif2BMP16bit, KeyHandler_gif2BMP16bit);
   mrc_clearScreen(128, 128, 128);

	ret=mrc_readFileFromMrpEx(NULL,"gx_af_enemi_5.gif",&gif,&gifsize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx 返回成功");
	if(gif)
	{
		//mrc_gif2bmp(gif,gifsize,&bmp,&gif_width,&gif_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx 返回NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,0,gif_width,gif_width,gif_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");
	mrc_printf("now mrc_free(gif)");
   mrc_free(gif);
   	mrc_printf("now mrc_free(bmp)");
	mrc_free(bmp);
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

void Test_Img2BMP16bit(int32 data)
{
	int32 ret,ImgSize,Img_width,Img_height;
	uint8 *Img=NULL;//由mrc_readFileFromMrpEx申请分配空间
	uint16 *bmp=NULL;//由mrc_Img2bmp申请、分配空间。
	mr_screenRectSt TextRect;
	mr_colourSt TextColor;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_Img2BMP16bit, KeyHandler_Img2BMP16bit);
   mrc_clearScreen(128, 128, 128);

	ret=mrc_readFileFromMrpEx(NULL,"gx_af_enemi_5.gif",&Img,&ImgSize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx 返回成功");
	if(Img)
	{
	//	mrc_Img2bmp(Img,ImgSize,MRC_IMG_GIF,&bmp,&Img_width,&Img_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx 返回NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,0,Img_width,Img_width,Img_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");	
	if(Img)
	{
		mrc_printf("now mrc_free(Img)");
   		mrc_free(Img);
   		Img=NULL;
	}
	if(bmp)
	{
		mrc_printf("now mrc_free(bmp)");
		mrc_free(bmp);
		bmp=NULL;
	}



	ret=mrc_readFileFromMrpEx(NULL,"tree.jpg",&Img,&ImgSize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx 返回成功");
	if(Img)
	{
	//	mrc_Img2bmp(Img,ImgSize,MRC_IMG_JPG,&bmp,&Img_width,&Img_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx 返回NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,100,Img_width,Img_width,Img_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");
	TextColor.r=3;
	TextColor.g=3;
	TextColor.b=253;
	TextRect.x=20;
	TextRect.y=120;
	TextRect.w=60;
	TextRect.h=60;
	mrc_drawTextEx("tree.jpg",20,120,TextRect,TextColor,2,MR_FONT_BIG);
	if(Img)
	{
		mrc_printf("now mrc_free(Img)");
   		mrc_free(Img);
   		Img=NULL;
	}
	if(bmp)
	{
		mrc_printf("now mrc_free(bmp)");
		mrc_free(bmp);
		bmp=NULL;
	}	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

//主菜单中退出应用
void main_exit(int32 data){
   mrc_winClose();
}

void main_ShowMenu(void)
{
	mrc_printf("Hello! It's Graphy Demo!");
	main_menu = mrc_platMenuNew("\x0\x32\x0\x35\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6",6);             // 256色位图演示
	if (main_menu != MR_FAILED)
	{
	   mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x4f\x4d\x56\xfe\x59\x4\x74\x6", 0, Test_BMP16bit, 0);   // 256色位图演示 	
	   mrc_platMenuSetItem(main_menu, "\x0\x32\x0\x35\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6", 1, Test_BMP256, 0);   // 256色位图演示 
	   mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6", 2, Test_BMP16, 0);   // 16色位图演示 	   
	   mrc_platMenuSetItem(main_menu, "\x0\x47\x0\x49\x0\x46\x8f\x6c\x4f\x4d\x56\xfe\x59\x4\x74\x6", 3, Test_gif2BMP16bit, 0);   // gif转16bitBMP位图演示 	   	   
	   mrc_platMenuSetItem(main_menu, "\x0\x4a\x0\x50\x0\x47\x8f\x6c\x4f\x4d\x56\xfe\x59\x4\x74\x6", 4, Test_Img2BMP16bit, 0);   // JPG转16bitBMP位图演示 	   	   	   
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 5, main_exit, 0);   // 点击返回键，退出演示         	   
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 6, main_exit, 0);   // 点击返回键，退出演示         	   
	   mrc_platMenuShow(main_menu);	   
	}
	else
	{
	   return;
	}
	return;
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
	draw_WinHandle=0;
	main_ShowMenu();

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
