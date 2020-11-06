#include "gameapp.h"
#include "mrc_win.h"
#include "gameicon.h"
#include "gamesound.h"
#include "gamepayment.h"
#include "gamemainmenu.h"


#define PLANE_SPEED		(6)//飞机移动速度
#define PLANE_WIDTH		(41)//飞机宽度
#define PLANE_HEIGHT	(26)//飞机高度
extern uint8 g_exit_game_status;//退出游戏时候，游戏的状态

static int32 g_game_win_id;//游戏界面窗口ID
static int32 g_update_bk_timer;//更新游戏背景定时器
static int32 g_long_key_timer;//长按键定时器
static uint8 g_is_long_key_timer_running;//长按键定时器是否在运行
static int16 g_plane_x_pos;//飞机x轴位置
static int16 g_plane_y_pos;//飞机y轴位置
static int16 g_bk_y_pos;//背景图片y轴在图片中的相对位置
///////////////////////////////
int32 InitGame(void);
void GameWinHandler(int32 data, int32 eventId);
void GameKeyHanlder(int32 data, int32 type, int32 p1, int32 p2);
void DealGameWinKeyEvent(void);
void PaintGameWinFace(void);
void PaintGameBk(void);
void StartLongKeyTimer(int32 key);
void StartUpdateBkTimer(void);
void LongKeyTimerOutCallBack(int32 key);
void UpdateTimerOutCallBack(int32 data);
void DealGameWinKeyEvent(void);
void StopLongKeyTimer(void);
void StopGameTimer(void);
void DeleletGameTimer(void);
void ExitGameWin(void);
///////////////////////////////
int32 LaunchGame(void)
{
	InitGame();
	g_game_win_id = mrc_winNew(0,GameWinHandler,GameKeyHanlder);
	return MR_SUCCESS;
}

int32 InitGame(void)
{
	g_game_win_id = INVALID_WIN_ID;
	g_update_bk_timer = INVALID_TIMER_ID;
	g_long_key_timer = INVALID_TIMER_ID;
	g_plane_x_pos = (SCREEN_WIDTH -PLANE_WIDTH)/2;
	g_plane_y_pos = SCREEN_HEIGHT - 80;
	g_is_long_key_timer_running = false;
	g_bk_y_pos = 0;
	return MR_SUCCESS;
}

void GameWinHandler(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_PAUSE:
		StopGameTimer();
		StopSound(GAME_SOUND_BK);
		break;
	case WIN_EVENT_SHOW:
		PaintGameWinFace();
		StartUpdateBkTimer();
		PlaySound(GAME_SOUND_BK,1);
		break;
	case WIN_EVENT_REFRESH:
		PaintGameWinFace();
		StartUpdateBkTimer();
		PlaySound(GAME_SOUND_BK,1);
		break;
	case WIN_EVENT_UPDATE:
		PaintGameWinFace();
		break;
	case WIN_EVENT_EXIT:
		ExitGameWin();
		break;
	default:
		break;
	}
}

void GameKeyHanlder(int32 data, int32 type, int32 p1, int32 p2)
{
	if( type == MR_KEY_PRESS)
	{
		switch(p1)
		{
		case MR_KEY_UP:
			if( g_plane_y_pos -PLANE_SPEED > 0 )
			{
				g_plane_y_pos -= PLANE_SPEED;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
				StartLongKeyTimer(p1);
			}
			else
			{
				g_plane_y_pos = 0;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
			}
			break;

		case MR_KEY_DOWN:
			if( g_plane_y_pos+PLANE_SPEED  < SCREEN_HEIGHT -PLANE_HEIGHT)
			{
				g_plane_y_pos += PLANE_SPEED;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
				StartLongKeyTimer(p1);
			}
			else
			{
				g_plane_y_pos = SCREEN_HEIGHT -PLANE_HEIGHT;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
			}
			break;
		case MR_KEY_LEFT:
			if( g_plane_x_pos - PLANE_SPEED  > 0 )
			{
				g_plane_x_pos -= PLANE_SPEED;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
				StartLongKeyTimer(p1);
			}
			else
			{
				g_plane_x_pos = 0;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
			}
			break;
		case MR_KEY_RIGHT:
			if( g_plane_x_pos + PLANE_SPEED< SCREEN_WIDTH - PLANE_WIDTH)
			{
				g_plane_x_pos += PLANE_SPEED;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
				StartLongKeyTimer(p1);
			}
			else
			{
				g_plane_x_pos = SCREEN_WIDTH - PLANE_WIDTH;
				mrc_winWinEvent(WIN_EVENT_UPDATE);
			}
			break;
		default:
			break;
		}
	}
	else if( type == MR_KEY_RELEASE )
	{
		switch(p1)
		{
		case MR_KEY_UP:
		case MR_KEY_DOWN:
		case MR_KEY_LEFT:
		case MR_KEY_RIGHT:
			StopLongKeyTimer();
			break;
		case MR_KEY_SELECT:
		case MR_KEY_SOFTLEFT:
			DealGameWinKeyEvent();
			break;
		case MR_KEY_SOFTRIGHT:
			//CreateExitGameWin(g_exit_game_status);//libo20080731
			CreateExitGameWin(g_exit_game_status);
			break;
		default:
			break;
		}
	}	
	else if ( type == MR_MOUSE_DOWN || type == MR_MOUSE_UP )
	{
		//DealMainMenuTouchEvent(p1,p2);
	}
}

void DealGameWinKeyEvent(void)
{
}


void PaintGameWinFace(void)
{
	const T_ICON_MAP* plane_pic;
	//int16 x,y,w,h;


	mrc_clearScreen(0,0,0);
	PaintGameBk();

	plane_pic = GetIcon(GAME_ICON_PLANE);
	mrc_bitmapShowEx((uint16 *)plane_pic->pdata,g_plane_x_pos,g_plane_y_pos,plane_pic->width,plane_pic->width,plane_pic->height,BM_TRANSPARENT,0,0);
	mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void PaintGameBk(void)
{
	const T_ICON_MAP* game_bk_pic;
	int16 x,y;//,w,h;
	uint8 num = 0,i;
	
	game_bk_pic = GetIcon(GAME_ICON_GAME_BK);

	
	num = (SCREEN_HEIGHT - g_bk_y_pos) /game_bk_pic->height;

	if( (SCREEN_HEIGHT - g_bk_y_pos) % game_bk_pic->height   != 0 )
	{
		num++;
	}

	x = y = 0;
	if( g_bk_y_pos > 0 )
		mrc_bitmapShowEx((uint16 *)game_bk_pic->pdata,x,y,game_bk_pic->width,game_bk_pic->width,g_bk_y_pos,BM_COPY,0,game_bk_pic->height - g_bk_y_pos);

	for( i = 0; i < num; i ++ )
	{
		y = i*game_bk_pic->height + g_bk_y_pos;
		mrc_bitmapShowEx((uint16 *)game_bk_pic->pdata,x,y,game_bk_pic->width,game_bk_pic->width,game_bk_pic->height,BM_COPY,0,0);
	}
}

void StartLongKeyTimer(int32 key)
{
	if( g_is_long_key_timer_running )
	{
		return;
	}
	
	if( INVALID_TIMER_ID == g_long_key_timer  )
	{
		g_long_key_timer = mrc_timerCreate();
	}

	if( INVALID_TIMER_ID == g_long_key_timer  )
	{
		mrc_printf("StartLongKeyTimer,create timer error!");
		mrc_exit();
	}

	mrc_timerStart(g_long_key_timer,LONG_KEY_INTERVAL,key,LongKeyTimerOutCallBack,1);
	g_is_long_key_timer_running = true;
}

void StartUpdateBkTimer(void)
{
	
	if( INVALID_TIMER_ID == g_update_bk_timer )
	{
		g_update_bk_timer = mrc_timerCreate();
	}

	if( INVALID_TIMER_ID == g_update_bk_timer  )
	{
		mrc_printf("StartUpdateBkTimer,create timer error!");
		mrc_exit();
	}

	mrc_timerStart(g_update_bk_timer,200,0,UpdateTimerOutCallBack,1);
}


void LongKeyTimerOutCallBack(int32 key)
{
	switch(key)
	{
		case MR_KEY_UP:
		if( g_plane_y_pos -PLANE_SPEED > 0 )
		{
			g_plane_y_pos -= PLANE_SPEED;
		}
		else
		{
			g_plane_y_pos = 0;
		}
		break;

	case MR_KEY_DOWN:
		if( g_plane_y_pos+PLANE_SPEED  < SCREEN_HEIGHT -PLANE_HEIGHT)
		{
			g_plane_y_pos += PLANE_SPEED;
		}
		else
		{
			g_plane_y_pos = SCREEN_HEIGHT -PLANE_HEIGHT;
		}
		break;
	case MR_KEY_LEFT:
		if( g_plane_x_pos - PLANE_SPEED  > 0 )
		{
			g_plane_x_pos -= PLANE_SPEED;
		}
		else
		{
			g_plane_x_pos = 0;
		}
		break;
	case MR_KEY_RIGHT:
		if( g_plane_x_pos + PLANE_SPEED< SCREEN_WIDTH -PLANE_WIDTH)
		{
			g_plane_x_pos += PLANE_SPEED;
		}
		else
		{
			g_plane_x_pos = SCREEN_WIDTH -PLANE_WIDTH;
		}
		break;
	default:
		return;
	}
	
	mrc_winWinEvent(WIN_EVENT_UPDATE);

}


void UpdateTimerOutCallBack(int32 data)
{
	g_bk_y_pos += 3;
	if( g_bk_y_pos > 44 )
	{
		g_bk_y_pos = 0;
	}
	mrc_winWinEvent(WIN_EVENT_UPDATE);
}


void StopLongKeyTimer(void)
{
	if( g_long_key_timer != INVALID_TIMER_ID )
	{
		mrc_timerStop(g_long_key_timer);
		g_is_long_key_timer_running = false;
	}
}


void StopGameTimer(void)
{
	if( g_update_bk_timer != INVALID_TIMER_ID )
	{
		mrc_timerStop(g_update_bk_timer);
	}
	
	if( g_long_key_timer != INVALID_TIMER_ID )
	{
		mrc_timerStop(g_long_key_timer);
		g_is_long_key_timer_running = false;
	}
	
}

void DeleletGameTimer(void)
{
	if( g_update_bk_timer != INVALID_TIMER_ID )
	{
		mrc_timerDelete(g_update_bk_timer),g_update_bk_timer = INVALID_TIMER_ID;
	}
	
	if( g_long_key_timer != INVALID_TIMER_ID )
	{
		mrc_timerDelete(g_long_key_timer),g_long_key_timer = INVALID_TIMER_ID;
		g_is_long_key_timer_running = false;
	}

}

void ExitGameWin(void)
{
	StopSound(GAME_SOUND_BK);
	DeleletGameTimer();
}
