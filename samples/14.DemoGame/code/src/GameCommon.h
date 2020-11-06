#ifndef INCLUDE_GAME_COMMON_H
#define INCLUDE_GAME_COMMON_H

enum
{
	false = 0,
	true
};

#define SCREEN_WIDTH			(240)
#define SCREEN_HEIGHT		(320)

#define INVALID_TIMER_ID		(0)
#define INVALID_WIN_ID		(-1)

#define LONG_KEY_INTERVAL	(100)//³¤°´¼ü100ms



#define DEBUG_ON

#ifdef DEBUG_ON 
#define DEBUG  mrc_printf     
#else
#define DEBUG
#endif


#endif

