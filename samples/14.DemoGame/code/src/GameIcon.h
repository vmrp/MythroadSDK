#ifndef	INCLUDE_GAME_ICON_H
#define	INCLUDE_GAME_ICON_H

#include "mrc_base.h"
#include "mrc_bmp.h"

typedef enum
{
	GAME_ICON_MIN_ID = 0,
	GAME_ICON_MAIN_MENU,
	GAME_ICON_MENU_FOCUS,
	GAME_ICON_GAME_BK,
	GAME_ICON_PLANE,
	GAME_ICON_MAX_ID
}T_ICON_ID;


typedef struct
{	
	int32 len;
	void* pdata;
	uint16 width;
	uint16 height;
}T_ICON_MAP;


typedef struct
{	
	int32 len;
	BMP* pdata;
	uint16 width;
	uint16 height;
}T_BMP_ICON_MAP;

///////////////////////////////////
void InitIcon(void);
const T_ICON_MAP *GetIcon(int32 index);
const T_BMP_ICON_MAP * GetBackroundPic(void);

#endif
