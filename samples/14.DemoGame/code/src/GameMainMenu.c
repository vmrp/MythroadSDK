#include "gamemainmenu.h"
#include "mrc_win.h"
#include "mrc_text.h"
#include "gameicon.h"
#include "gamecommon.h"
#include "gamepayment.h"
#include "gameapp.h"

#define MENU_ITEM_COUNT	4
#define GAME_VERSION		"V0.100"
/////////////////////////////////////////////////////
static uint8 g_main_menu_focus;
static int32 g_main_menu_win_id;
static const T_BMP_ICON_MAP* g_bk_pic;
/////////////////////////////////////////////////////
void InitMainMenu(void);
void GameMainMenuWinHandler(int32 data, int32 eventId);
void GameMainMenuKeyHanlder(int32 data, int32 type, int32 p1, int32 p2);
void PaintMainMenuFace(void);
void DealMainMenuKeyEvent(void);
//void MainMenuStartGame(void);
void MainMenuShowHelp(void);
void MainMenuShowAbout(void);
void MainMenuExitGame(void);
void DealMainMenuTouchEvent(int32 p1,int32 p2);
int8 GetMainMenuTouchEventFocus(int32 p1,int32 p2);
char *Asc2Unicode(char *os,char *is);
/////////////////////////////////////////////////////
void CreateGameMainMenuWin(void)
{
	InitMainMenu();
	g_main_menu_win_id = mrc_winNew(0,GameMainMenuWinHandler,GameMainMenuKeyHanlder);
}


void InitMainMenu(void)
{
	g_main_menu_focus = 0;
	g_bk_pic = NULL;
	g_main_menu_win_id = -1;
}


void GameMainMenuWinHandler(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_PAUSE:
		break;
	case WIN_EVENT_SHOW:
	case WIN_EVENT_REFRESH:
		PaintMainMenuFace();
		break;
	case WIN_EVENT_EXIT:
		break;
	default:
		break;
	}
}

void GameMainMenuKeyHanlder(int32 data, int32 type, int32 p1, int32 p2)
{
	if( type == MR_KEY_RELEASE )
	{
		switch(p1)
		{
		case MR_KEY_UP:
			g_main_menu_focus = (g_main_menu_focus -1 + MENU_ITEM_COUNT)%MENU_ITEM_COUNT;
			mrc_winWinEvent(WIN_EVENT_REFRESH);
			break;

		case MR_KEY_DOWN:
			g_main_menu_focus = (g_main_menu_focus +1 + MENU_ITEM_COUNT)%MENU_ITEM_COUNT;
			mrc_winWinEvent(WIN_EVENT_REFRESH);
			break;

		case MR_KEY_SELECT:
		case MR_KEY_SOFTLEFT:
			DealMainMenuKeyEvent();
			break;
		case MR_KEY_SOFTRIGHT:
			break;
		default:
			break;
		}
	}	
	else if ( type == MR_MOUSE_DOWN || type == MR_MOUSE_UP )
	{
		DealMainMenuTouchEvent(p1,p2);
	}
}

void PaintMainMenuFace(void)
{
	const T_ICON_MAP* main_menu_pic,*focus_pic;
	//int16 x,y,w,h;
	if( NULL == g_bk_pic )
	{
		g_bk_pic = GetBackroundPic();
	}

	if( NULL == g_bk_pic  ||  NULL ==  g_bk_pic->pdata)
	{
		mrc_printf("PaintMainMenuFace,load bk pic fail!!!");
		mrc_exit();
		return;
	}

	mrc_clearScreen(0,0,0);
	mrc_bmpShow(g_bk_pic->pdata,0,0,g_bk_pic->width, g_bk_pic->height,BM_COPY,0,0);
	

	main_menu_pic = GetIcon(GAME_ICON_MAIN_MENU);
	focus_pic = GetIcon(GAME_ICON_MENU_FOCUS);
	mrc_bitmapShowEx((uint16 *)focus_pic->pdata,62,127 + 24*g_main_menu_focus,focus_pic->width,focus_pic->width,focus_pic->height,BM_TRANSPARENT,0,0);
	mrc_bitmapShowEx((uint16 *)main_menu_pic->pdata,87,130,main_menu_pic->width,main_menu_pic->width,main_menu_pic->height,BM_TRANSPARENT,0,0);
	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
}

void DealMainMenuKeyEvent(void)
{
	switch( g_main_menu_focus )
	{
	case 0:
		MainMenuStartGame();
		return;
	case 1:
		MainMenuShowHelp();
		return;
	case 2:
		MainMenuShowAbout();
		return;
	case 3:
		MainMenuExitGame();
		return;
	default:
		return;
	}
}

void MainMenuStartGame(void)
{
	if( mrc_checkCharge()  != MR_SUCCESS )
	{
		StartPay();
	}
	else
	{
		LaunchGame();
	}
}


void MainMenuShowHelp(void)
{
	char* title = "\x5e\x2e\x52\xa9\x00\x00";//帮助
	//确认键/5键:开始游戏
	//左软键:暂停/恢复游戏
	//左右方向键/4、6键:移动控制台
	//右软键:退出游戏
	char* conten = "\x78\x6e\x8b\xa4\x95\x2e\x00\x2f\x00\x35\x95\x2e\x00\x3a\x5f\x00\x59\xcb\x6e\x38\x62\x0f\x00\x0d\x00\x0a\x5d\xe6\x8f\x6f\x95\x2e\x00\x3a\x66\x82\x50\x5c\x00\x2f\x60\x62\x59\x0d\x6e\x38\x62\x0f\x00\x0d\x00\x0a\x5d\xe6\x53\xf3\x65\xb9\x54\x11\x95\x2e\x00\x2f\x00\x34\x30\x01\x00\x36\x95\x2e\x00\x3a\x79\xfb\x52\xa8\x63\xa7\x52\x36\x53\xf0\x00\x0d\x00\x0a\x53\xf3\x8f\x6f\x95\x2e\x00\x3a\x90\x00\x51\xfa\x6e\x38\x62\x0f\x00\x0d\x00\x0a\x00\x00";

	mrc_platTextNew(title, conten, MR_DIALOG_CANCEL, 0, NULL, NULL);
}


void MainMenuShowAbout(void)
{
	char* title = "\x51\x73\x4e\x8e\x00\x00";//关于
	//char* conten = NULL;
	//DEMOGAME
	//版本号：
	char* txt = "\x00\x44\x00\x45\x00\x4d\x00\x4f\x00\x47\x00\x41\x00\x4d\x00\x45\x00\x0d\x00\x0a\x72\x48\x67\x2c\x53\xf7\xff\x1a\x00\x00";
	char buf[128] = {0};
	char tmp[128] = {0};
	int16 len = 0,tmp_len = 0;
	char* pay_channel_name = NULL;

	//加入版本号信息
	len = mrc_wstrlen(txt);
	memcpy(buf,txt,len);
	Asc2Unicode(tmp, GAME_VERSION);
	tmp_len = mrc_wstrlen(tmp);
	memcpy(buf+len,tmp,tmp_len);
	len += tmp_len;

	//加入一个空格
	memcpy(buf+len,"\x00\x20",2);
	len += 2;


	//加入收费通道缩写名词
	memset(tmp,0,sizeof(tmp));
	pay_channel_name = GetChannelShortName();
	Asc2Unicode(tmp, pay_channel_name);
	tmp_len = mrc_wstrlen(tmp);
	memcpy(buf+len,tmp,tmp_len);
	
	
	mrc_platTextNew(title,buf, MR_DIALOG_CANCEL, 0, NULL, NULL);
}


void MainMenuExitGame(void)
{
	mrc_winClose();
	mrc_exit();
}

void DealMainMenuTouchEvent(int32 p1,int32 p2)
{
	int8 focus = GetMainMenuTouchEventFocus(p1,p2);
	
	if( focus < 0 )
	{
		return;
	}
	
	if( g_main_menu_focus  != focus )
	{
		g_main_menu_focus = focus;
		mrc_winWinEvent(WIN_EVENT_REFRESH);
	}
	else
	{
		DealMainMenuKeyEvent();
	}
}

int8 GetMainMenuTouchEventFocus(int32 p1,int32 p2)
{
	int16 item_w,item_h;
	int8 focus = -1;
	
	item_w = 66;//一个菜单项的宽度
	item_h = 14;//一个菜单项的高度
	
	if( ( p1  >=87 ) &&  (p1 <  87 + item_w )  &&  (p2  >= 130 ) &&   (p2 < 130 + item_h ) )
	{
		focus = 0; 
	}
	else 	if(  ( p1  >=87 ) &&  (p1 <  87 + item_w )  && ( p2  >= 154 ) &&   (p2 < 154 + item_h ) )
	{
		focus = 1; 
	}
	else 	if( ( p1  >=87 ) &&  (p1 <  87 + item_w )  && ( p2  >= 178 )  &&   (p2 < 178 + item_h ) )
	{
		focus = 2; 
	}
	else 	if( ( p1  >=87 ) &&  (p1 <  87 + item_w )  && ( p2  >= 202 ) &&   (p2 < 202 + item_h ) )
	{
		focus = 3; 
	}
	return focus;
	
}


char *Asc2Unicode(char *os,char *is)
{
	char *p = os;

	if( NULL == os || NULL == is )
	{
		return NULL;
	}
	
	*p = '\0'; 
	p++;

	while(*is != '\0')
	{
		*(p++) = *(is++);
		*(p++) ='\0';
	}

	*p = '\0';
	return os;
}

