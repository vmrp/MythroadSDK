#include "gameicon.h"
#include "gamecommon.h"



static T_ICON_MAP g_icon_map[GAME_ICON_MAX_ID];

void AddIcon(int16 id,const char* name,int16 w,int16 h);
////////////////////////////////////////////////////
void AddIcon(int16 id,const char* name,int16 w,int16 h)
{
	int32 ret;
	g_icon_map[id].width =w;
	g_icon_map[id].height =h;
	g_icon_map[id].pdata = NULL;
	ret = mrc_readFileFromMrpEx(NULL,name,(uint8**)&(g_icon_map[id].pdata),(int32 *)&(g_icon_map[id].len),0);
	if( ret == MR_FAILED)
	{
		int32 ret =mrc_ferrno();
		DEBUG("AddIcon,read pic[%s] error,errno[%d].",name,ret);
		mrc_exit();
	}
}

void InitIcon(void)
{
	AddIcon(GAME_ICON_MAIN_MENU, "main_menu.bmp", 66, 87);
	AddIcon(GAME_ICON_MENU_FOCUS, "menu_focus.bmp", 114, 21);
	AddIcon(GAME_ICON_GAME_BK, "game_bk.bmp", 240, 44);
	AddIcon(GAME_ICON_PLANE, "plane.bmp", 41, 26);
}

const T_ICON_MAP *GetIcon(int32 index)
{
	if( index > GAME_ICON_MIN_ID && index < GAME_ICON_MAX_ID )
	{
		return &g_icon_map[index];	
	}
	else
	{
		DEBUG("GetIcon,index[%d] error!!!!!!!",index);
		return NULL;
	}
}

const T_BMP_ICON_MAP * GetBackroundPic(void)
{
	T_BMP_ICON_MAP* bk_pic = malloc(sizeof(T_BMP_ICON_MAP));

	if( NULL == bk_pic )
	{
		DEBUG("GetBackroundPic, malloc failed!");
		mrc_exit();
		return NULL;
	}
	
	memset(bk_pic,0,sizeof(T_BMP_ICON_MAP));
	bk_pic->pdata = mrc_bmpLoadFromMrp("bk.bmp256");
	
	if( bk_pic->pdata == NULL )
	{
		int32 ret = mrc_bmpGetError();
		DEBUG("GetLoginPic,read bk.bmp256 error,errno[%d].",ret);
		free(bk_pic);
		return NULL;
	}
	
	bk_pic->width = 240;
	bk_pic->height = 320;
	
	return bk_pic;
}

