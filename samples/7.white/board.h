#ifndef __BOARD_H__
#define __BOARD_H__

#define BOARD_BMP_ID 1

#define BOARD_SPID_EMPTY_NONE 0
#define BOARD_SPID_EMPTY_BOTH 1
#define BOARD_SPID_EMPTY_LEFT 2
#define BOARD_SPID_EMPTY_TOP 3
#define BOARD_SPID_BLACK_NONE 4
#define BOARD_SPID_BLACK_BOTH 5
#define BOARD_SPID_BLACK_LEFT 6
#define BOARD_SPID_BLACK_TOP 7
#define BOARD_SPID_WHITE_NONE 8
#define BOARD_SPID_WHITE_BOTH 9
#define BOARD_SPID_WHITE_LEFT 10
#define BOARD_SPID_WHITE_TOP 11
#define BOARD_SPID_VALID_POINT 12
#define BOARD_SPID_CURSOR 13

#define BOARD_SPID_BLACK_NEXT 14
#define BOARD_SPID_WHITE_NEXT 15



#define BOARD_SAVE_EMPTY  0
#define BOARD_SAVE_BLACK   1
#define BOARD_SAVE_WHITE  2

#define BOARD_LINE_RGB  90,70,0


#define	COLOUR_THINKING 253, 166, 0	
#define	COLOUR_THINKING_BG 214, 105, 73

#define BOARD_WIDTH  8	//每行8个棋子
#define BOARD_HEIGHT  8	//每列8个棋子

#ifdef SCREEN176_220
	#define	SCREEN_WIDTH 176	//屏幕X轴宽度
	#define	SCREEN_HEIGHT 220	//屏幕Y轴宽度
	#define	SCREEN_GAME_TOP_Y 26		//屏幕棋盘Y坐标开始值
	#define	SCREEN_GAME_BOTTEM_Y 194	//屏幕棋盘Y坐标结束值8*21+26。
	
	#define BOARD_OFFSET_X 4
	#define BOARD_OFFSET_Y 26
	#define BOARD_STONE_WIDTH  21
	#define BOARD_STONE_HEIGHT  21	
#endif

#ifdef SCREEN240_320
	#define	SCREEN_WIDTH 240	//屏幕X轴宽度
	#define	SCREEN_HEIGHT 320	//屏幕Y轴宽度
	#define	SCREEN_GAME_TOP_Y 35		//屏幕棋盘Y坐标开始值
	#define 	SCREEN_GAME_BOTTEM_Y 275	//屏幕棋盘Y坐标结束值8*30+35。

	#define BOARD_OFFSET_X 0
	#define BOARD_OFFSET_Y 35
	#define BOARD_STONE_WIDTH  30
	#define BOARD_STONE_HEIGHT  30
#endif

//定义当前屏幕状态，是否为走子的屏幕
enum 
{
   SCREEN_STATUS_UNKNOWN=0,
   SCREEN_STATUS_GAME=1
};

//定义返回的对象类型。
enum 
{
   SCREEN_ITEM_UNKNOWN=0,
   SCREEN_ITEM_STONE=1,	//返回对象类型是棋子
   SCREEN_ITEM_TOP=2,	//返回对象类型是顶部菜单对象
   SCREEN_ITEM_BOTTEM=3	//返回菜单对象类型是底部菜单对象。
};

void white_boardInit(void);
void white_boardPaint(int8* board);

//根据触摸屏的鼠标位置返回光标当前位置的对象。
//status:
//	0	非法的屏幕状态；
//	1	当前屏幕状态为游戏棋盘界面。
//mouse_x	屏幕X	轴坐标
//mouse_y	屏幕Y	轴坐标
//ItemType		返回对象类型
//	0	未知的错误类型。
//	1	棋子
//	2	标题行
//	3	底部菜单项
//ItemX、ItemY是返回对象在对象数组的下标位置。
//当ItemType=1时，是棋子在棋局数组的下标位置，
//当ItemType=2、3时，是菜单项的下标位置。
int32 white_MouseToItem(int32 status,int32 mouse_x,int32 mouse_y,int32 *ItemType,int32 *ItemX,int32 *ItemY);

#endif
