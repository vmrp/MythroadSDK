#include "mrc_base.h"
#include "mrc_payment.h"
#include "gamemainmenu.h"
#include "mrc_win.h"
#include "gamepayment.h"
#include "gameicon.h"
#include "gamesound.h"

/////////////////////////////////////////////
int32 InitSdk(void);
void PaintGameExitFace(void);
///////////////////////////////////////////
int32 mrc_init(void)
{
	if( InitSdk() == MR_SUCCESS )
	{
		CreateGameMainMenuWin();
	}
	else
	{
		CreateInitPaymentErrorWin();
	}
	return MR_SUCCESS;
}


int32 mrc_event(int32 code, int32 param0, int32 param1)
{
	return mrc_winEvent(code, param0, param1);
}


int32 mrc_pause(void)
{
	int32 win_id;
	win_id = mrc_getActiveWinId();
	if( win_id != MR_FAILED )
	{
		return mrc_sendEventTo(win_id, WIN_EVENT_PAUSE);
	}
	else
	{
		mrc_printf("mrc_pause,mrc_getActiveWinId failed.");
		return MR_FAILED;
	}
}

int32 mrc_resume(void)
{
	mrc_winResume();
	return MR_SUCCESS;
}

int32 mrc_exitApp(void)
{
	PaintGameExitFace();
	mrc_releaseCharge();
	return MR_SUCCESS;
}


int32 InitSdk(void)
{
	mrc_winInit();
	InitIcon();
	InitSound();
	return InitGamePayment();
}

void PaintGameExitFace(void)
{
	//ÓÎÏ·ÍË³öÖÐ...
	char* content = "\x6e\x38\x62\x0f\x90\x00\x51\xfa\x4e\x2d\x00\x2e\x00\x2e\x00\x2e\x00\x00";
	DrawTextFace(NULL,NULL,content);
}

