#ifndef __WHITE_H__
#define __WHITE_H__


#define white_cursor_x white_state[0]
#define white_cursor_y white_state[1]
#define white_waiting white_state[2]		//AI搜索已启动，在等待AI搜索的结果。
#define white_can_continue white_state[3]	//是否可以继续
#define white_blacks  white_state[4]	//实际无用
#define white_whites  white_state[5]	//实际无用
#define white_waiting_ai  white_state[6]//是否在等待电脑
#define black_ai  white_state[7]//黑棋的AI水平
#define white_ai  white_state[8]//白棋的AI水平

#define white_stone_seting  white_state[9]//用户选择的棋子
#define white_ai_seting  white_state[10]//电脑的棋力是初级(1)、中级(2)还是高级(3)
#define white_can_back  white_state[11]//是否可以悔棋。

#define BOARD_POS(x,y)  (4+(x) + (y) * BOARD_WIDTH)
#define white_turn(board)  board[0]

#define white_cursor_rgb 0,180,90

//#define white_top_rgb 40,150,220
#define white_top_rgb 19,194,244
#define white_bottom_rgb 140,210,250
#define white_bottom_line_rgb 70,70,70

#define white_SoftTouch_
#define white_GameCtrlPauseAIShow 0x01


extern int8 white_back_state[32+64+64+64];

extern int8 white_state[32+64+64+64];
extern int8* white_board;
extern int8 white_valid_stones[4+64];

#define WHITE_FAILED          1    //失败
#define WHITE_GAMEOVER   2    
#define WHITE_NOOPPONENTMOVES   3    
#define WHITE_OK   4    

//#define WHITE_DEBUG

#ifdef WHITE_DEBUG
#define DBG_PRINTF(a) mrc_printf a
#else
#define DBG_PRINTF(a) 
#endif

//#define	DBG_LoadTest

#endif
