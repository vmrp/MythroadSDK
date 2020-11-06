
#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"

#include "white.h"
#include "board.h"
#include "white_aux.h"


/*
以下是全局变量定义区
在mythroad平台下，全局变量不能在定义的时候初始化
比如，如下的全局变量定义方式是不支持的:
int32 main_menu = 0;
对全局变量的使用规则同样适用于静态局部变量。
*/

//主界面菜单句柄
int32 main_menu;
//应用使用的定时器句柄
int32 main_timer;

//游戏中点选"功能"后弹出菜单的句柄
int32 main_game_menu;

//用于保存游戏设置以及状态的数组变量
//32字节的状态信息，64字节的当前棋局状态，64字节的当前棋局
//白棋可走子，1字节的白棋可走子总数，64字节的黑棋可走子，
// 1字节的黑棋可走子总数。
int8 white_state[32+64+64+64];

//用于保存悔棋前状态的数组变量
int8 white_back_state[32+64+64+64];

//主棋盘指针
int8* white_board;

//用于保存有效落棋点的数组变量
int8 white_valid_stones[4+64];

//用于保存游戏结果字符串的变量
char white_result_string[1024];

//用于触发游戏定购提示的变量
int8 white_payment;

//保存游戏窗体句柄全局变量
int32 white_GameWinHandle;
//全局变量定义结束

/*
应用的刷新函数
*/
static void white_refresh(int32 data);

char   *myitoa(   int   value,   char   *str,   int   radix   )   
  {   
  	//static   char   szMap[]   =   {   //平台不支持静态局部变量、全局变量在声明时赋值。
  	char   szMap[]   =   {   
  	'0',   '1',   '2',   '3',   '4',   '5',   
  	'6',   '7',   '8',   '9',   'a',   'b',   
  	'c',   'd',   'e',   'f',   'g',   'h',   
  	'i',   'j',   'k',   'l',   'm',   'n',   
  	'o',   'p',   'q',   'r',   's',   't',   
  	'u',   'v',   'w',   'x',   'y',   'z'   
  	}; //   字符映射表   
  	int   nCount   =   -1,   nIndex;   
  	char   *pStr   =   str,   nTemp;   
  	unsigned   int   nValue   =   *(unsigned*)&value;
  	if   (   radix   >=   2   &&   radix   <=   36   )   
  	{   //   限制radix必须在2到36之间   
  		if   (   value   <   0   &&   radix   ==   10   )   
  		{   //   如果是负数就在首位添加负号，并将字符串前移   
  			*pStr++   =   '-';   
  			value   =   -value;   //转为正数，   
  		}   
  		do   { //   循环转换每一个数字，直到结束   
 			 pStr[   ++nCount   ]   =   szMap[   nValue   %   radix   ];   
  			nValue   /=   radix;   
  		}   while(   nValue   >   0   );   //   转换结束后字符串是翻的   
  		nIndex   =   (   nCount   +   1   )   /   2;   //   计算出一半的长度   
  		while(   nIndex--   >   0   )   {   //   将字符串的字符序翻转   
  			nTemp   =   pStr[   nIndex   ];   
  			pStr[   nIndex   ]   =   pStr[   nCount   -   nIndex   ];   
  			pStr[   nCount   -   nIndex   ]   =   nTemp;   
  		}   
  	}   
  	pStr[   nCount   +   1   ]   =   '\0';   //   置结束符   
  	return   str;   
  }   


/*
保存游戏状态
*/
void main_save(void){
   int32 f; 
   f = mrc_open("white.sav", MR_FILE_RDWR+MR_FILE_CREATE);
   if (f){
      mrc_seek(f, 0, MR_SEEK_SET);
      mrc_write(f, white_state, sizeof(white_state));          
      mrc_close(f);
   }
}

/*
读取游戏状态
*/
int32 main_read(void)
{
   int32 ret,f;

   ret = mrc_fileState("white.sav");
   if((ret != MR_IS_FILE))
   {
     return MR_FAILED;
   }

   f = mrc_open("white.sav", MR_FILE_RDONLY );
   if (f == 0)
   {
     return MR_FAILED;
   }    
   mrc_seek(f, 0, MR_SEEK_SET);
   ret=mrc_read(f, white_state, sizeof(white_state));
   if(ret!=sizeof(white_state))
   	{
   		mrc_close(f);
   		return MR_FAILED;
   	}
   mrc_close(f);
   return MR_SUCCESS;

}

/*
游戏结束后，显示的结果窗体的"返回"  键回调函数
*/
void white_gameOverCB(int32 data)
{
   //main_save();//保存决出胜负的局面没有太大意义。
   mrc_timerDelete(main_timer);
   main_timer=0;
   mrc_winCloseNotShow();//关闭结果窗体
   white_GameWinHandle=MR_FAILED;     
   mrc_winCloseNotShow();//关闭棋盘
   mrc_winCloseNotShow();//关闭主菜单。
   mrc_init();
}

/*
游戏结束回调函数
*/
void white_gameOverTimer(int32 data)
{
   int8 blacks,whites;
   int32 str_len=0;
   
   mrc_memset(white_result_string, 0, sizeof(white_result_string));

   white_countPieces(white_board , &blacks, &whites);

   //先在游戏结果字符串前加上两个空格(unicode)
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x20;
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x20;

   //如果白棋和黑棋一样多
   if(blacks == whites){
      mrc_strcpy(&white_result_string[str_len], "\x5e\x73\x5c\x40\x30\x2"); //平局。
      str_len += mrc_strlen(&white_result_string[str_len]);
   }else{
      //如果黑棋多
      if(blacks > whites){
         mrc_strcpy(&white_result_string[str_len], "\x9e\xd1"); //黑
      }else{
         mrc_strcpy(&white_result_string[str_len], "\x76\x7d"); //白
      }
      str_len += mrc_strlen(&white_result_string[str_len]);
      
      mrc_strcat(&white_result_string[str_len],
         "\x68\xcb\x80\xdc\x30\x2\x51\x76\x4e\x2d\xff\xc\x9e\xd1\x68\xcb\xff\x1a");
      str_len += mrc_strlen(&white_result_string[str_len]);
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+blacks/10;
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+blacks%10;
      
      mrc_strcat(&white_result_string[str_len],
         "\xff\x1b\x76\x7d\x68\xcb\xff\x1a");
      str_len += mrc_strlen(&white_result_string[str_len]);
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+whites/10;
      white_result_string[str_len++] = 0x0;
      white_result_string[str_len++] = 0x30+whites%10;
   }
   //加上unicode字符串的结束符
   white_result_string[str_len++] = 0x0;
   white_result_string[str_len++] = 0x0;

   //创建一个用于显示比赛结果的Text窗体
   mrc_platTextNew("\x6b\xd4\x8d\x5b\x7e\xd3\x67\x9c"/*游戏结果*/, 
      white_result_string, 
      MR_DIALOG_CANCEL, 0, NULL, white_gameOverCB);
}

//主菜单中退出应用
void main_exit(int32 data){
	if(main_timer)
	   mrc_timerDelete(main_timer);
   mrc_winClose();
}

//游戏中点选"功能"后弹出菜单的"继续游戏"
void main_back(int32 data){
   mrc_winClose();
}

//游戏中点选"功能"后弹出菜单的"返回键"
void main_game_Esc(int32 data){
   mrc_winClose();
}

//游戏中点选"功能"后弹出菜单的"退出游戏"
void main_game_exit(int32 data){
   main_save();
   mrc_timerDelete(main_timer);
   main_timer=0;   
   mrc_winCloseNotShow();//关闭"继续、退出菜单"
   white_GameWinHandle=MR_FAILED;     
   mrc_winCloseNotShow();//关闭棋盘 
   mrc_winCloseNotShow();//关闭主菜单。
   mrc_init();
}

//游戏中点选"功能"后弹出菜单的"悔棋"
void main_game_roll_bak(int32 data){
   mrc_memcpy(white_state, white_back_state, sizeof(white_state));
   //仅能悔棋一次，将可以悔棋状态设置为否
   white_can_back = FALSE;
   white_boardHasChanged();
   white_moveCursorToNext();
   mrc_winClose();
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

//游戏界面下的事件处理函数
static void white_KeyHandler(int32 data, int32 type,int32 p1,int32 p2)
{
   //用于保存悔棋前状态的临时数组变量
   int8 white_Temp_state[32+64+64+64];
   int32 ItemType=0,ItemX=0,ItemY=0;
   int32 ret ;
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_PRESS)
   {
      switch(p1)
      {
         case MR_KEY_UP:
         case MR_KEY_LEFT:
            white_moveCursorToPre();
            mrc_winWinEvent(WIN_EVENT_REFRESH);
            break;
         case MR_KEY_DOWN:
         case MR_KEY_RIGHT:
            white_moveCursorToNext();
            mrc_winWinEvent(WIN_EVENT_REFRESH);
            break;
         case MR_KEY_SOFTLEFT:
         case MR_KEY_SELECT:
            {               
               //落子
               //为悔棋做准备。只有当前走子的是人时，才需要保存。
			    mrc_memcpy(white_Temp_state ,white_state, sizeof(white_state));      
               //走子。
               ret = white_makeMove(white_cursor_x, white_cursor_y, white_board);
               if(ret != WHITE_FAILED)
               {
                  //走子成功
                  //DBG_PRINTF(("New:用户走子:(%d,%d)",white_cursor_x,white_cursor_y));                  
                  mrc_memcpy(white_back_state ,white_Temp_state, sizeof(white_state));  
                  white_can_back = TRUE;
                  //棋局发生变化，更新当前可走子的位置。
                  white_boardHasChanged();
                  //移动光标到一个可走子的位置。
                  white_moveCursorToNext();
                  mrc_winWinEvent(WIN_EVENT_REFRESH);
               }
                  //游戏已经结束?
				   if (white_IsGameOver(white_board))
				   	{
				      //游戏结束，设置应用的状态为   "不可继续游戏"
				      white_can_continue = FALSE;
				      white_can_back = FALSE;
				      mrc_timerStart(main_timer, 50, 0, white_gameOverTimer, 0);      
				   }               
            }
            break;
         case MR_KEY_SOFTRIGHT:
            //若所处的状态可以悔棋
            if (white_can_back){
                  //游戏中点选"功能"后弹出菜单
                  main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);            
                  if (main_game_menu != MR_FAILED){
                     mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // 继续游戏
                     mrc_platMenuSetItem(main_game_menu, "\x60\x94\x68\xcb", 1, main_game_roll_bak, 0);   //悔棋
                     mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_game_exit, 0);    // 退出游戏
                     mrc_platMenuShow(main_game_menu);
                     
                  }else{
                     return;
                  }
            }else{
               //游戏中点选"功能"后弹出菜单
               main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 2);            
               if (main_game_menu != MR_FAILED){
                  mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // 继续游戏
                  mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 1, main_game_exit, 0);   // 退出游戏
                  mrc_platMenuShow(main_game_menu);
               }else{
                  return;
               }
            }
            break;
         default:
            break;
      }
   }

   //检查是否有触摸屏按下事件并予以处理。
   if(type==MR_MOUSE_DOWN)
   {
	//首先要计算按压的位置。
	if(white_MouseToItem(SCREEN_STATUS_GAME,p1,p2,&ItemType,&ItemX,&ItemY)<0)
		return;
      switch(ItemType)
      {
      	case SCREEN_ITEM_STONE:      		
      		//用户移动光标走子，坐标为转换后的棋盘数组下标。
            {
               int32 ret ;
               //落子
               //为悔棋做准备。只有当前走子的是人时，才需要保存。
	           mrc_memcpy(white_Temp_state ,white_state, sizeof(white_state));      
               ret = white_makeMove((int8)ItemX, (int8)ItemY, white_board);
               if(ret != WHITE_FAILED)
               {
                  //落子成功
                  white_cursor_x=(int8)ItemX;
                  white_cursor_y=(int8)ItemY;
                  //DBG_PRINTF(("New:用户走子:(%d,%d)",white_cursor_x,white_cursor_y));                     
                  mrc_memcpy(white_back_state ,white_Temp_state, sizeof(white_state));  
                  white_can_back = TRUE;
                  //棋局发生变化，更新当前可走子的位置。
                  white_boardHasChanged();
                  //移动光标到一个可走子的位置。
                  white_moveCursorToNext();
                  mrc_winWinEvent(WIN_EVENT_REFRESH);          
               }
                  //游戏已经结束?
				   if (white_IsGameOver(white_board))
				   	{
				      //游戏结束，设置应用的状态为   "不可继续游戏"
				      white_can_continue = FALSE;
				      white_can_back = FALSE;
				      mrc_timerStart(main_timer, 50, 0, white_gameOverTimer, 0);      
				   }                
            }
            break;      		
      	case SCREEN_ITEM_BOTTEM:
      		//用户底部的选择菜单项。
      		if(ItemX==1&&ItemY==0)
      		{
            		//若所处的状态可以悔棋
            		if (white_can_back)
            		{
                  		//游戏中点选"功能"后弹出菜单
                  		main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);            
                  		if (main_game_menu != MR_FAILED)
                  		{
                     		mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // 继续游戏
                     		mrc_platMenuSetItem(main_game_menu, "\x60\x94\x68\xcb", 1, main_game_roll_bak, 0);   //悔棋
                     		mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_game_exit, 0);    // 退出游戏
                     		mrc_platMenuShow(main_game_menu);                     
	                  	}else
	                  	{
                     		return;
                  	    	}
            		}else
            		{
               		//游戏中点选"功能"后弹出菜单
              	 	main_game_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 2);            
               		if (main_game_menu != MR_FAILED)
               		{
                  			mrc_platMenuSetItem(main_game_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 0, main_back, 0);   // 继续游戏
                  			mrc_platMenuSetItem(main_game_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 1, main_game_exit, 0);   // 退出游戏
                  			mrc_platMenuShow(main_game_menu);
               		}else
               		{
                  			return;
               		}
            		}      		
      		}
      		break;
      	default:
      		break;
      	}
   }
}

//绘制落子光标
static void white_drawCursor(void)
{
   if (	(white_cursor_x >= 0)&&
   		(white_cursor_x < BOARD_WIDTH) &&
		(white_cursor_y >= 0)&&
   		(white_cursor_y < BOARD_HEIGHT)   		){
      mrc_spriteDraw(BOARD_BMP_ID, 
                            (uint16)BOARD_SPID_CURSOR, 
                            BOARD_OFFSET_X + white_cursor_x * BOARD_STONE_WIDTH, 
                            BOARD_OFFSET_Y + white_cursor_y * BOARD_STONE_HEIGHT, 
                            BM_TRANSPARENT);
   }
}

//绘制可能的落子点
static void white_drawValid(void)
{
   int8 x,y;
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
         if (white_valid_stones[ BOARD_POS(x, y) ])
         {
            mrc_spriteDraw(BOARD_BMP_ID, 
                                  (uint16)BOARD_SPID_VALID_POINT, 
                                  BOARD_OFFSET_X + x * BOARD_STONE_WIDTH, 
                                  BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT, 
                                  BM_TRANSPARENT);
         }
      }
   }
}


//绘制游戏界面的底部栏
static void white_drawBottom(void)
{
   mrc_drawRect(0, SCREEN_GAME_BOTTEM_Y, SCREEN_WIDTH, 3, white_bottom_line_rgb);
   mrc_drawRect(0, SCREEN_GAME_BOTTEM_Y+3, SCREEN_WIDTH, (SCREEN_HEIGHT-SCREEN_GAME_BOTTEM_Y-3), white_bottom_rgb);
   mrc_drawLine(SCREEN_WIDTH/2, SCREEN_GAME_BOTTEM_Y, SCREEN_WIDTH/2, SCREEN_HEIGHT, white_bottom_line_rgb);   
   mrc_drawText("选项",  SCREEN_WIDTH*5/8, SCREEN_GAME_BOTTEM_Y+4, 0, 0, 0, 0, MR_FONT_BIG);   
}

//绘制游戏界面的顶部栏
static void white_drawTitle(void)
{
   int8 spid;
   mrc_drawRect(0, 0, SCREEN_WIDTH, SCREEN_GAME_TOP_Y-3, white_top_rgb);
   mrc_drawRect(0, SCREEN_GAME_TOP_Y-3, SCREEN_WIDTH, 3, white_bottom_line_rgb);
   mrc_drawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_GAME_TOP_Y-3, white_bottom_line_rgb);      
   if (white_turn(white_board) == BOARD_SAVE_BLACK){
      spid = BOARD_SPID_BLACK_NEXT;
      mrc_drawText("请黑棋走子", 4, 3, 255, 255, 255, 0, MR_FONT_BIG);
   }else{
      spid = BOARD_SPID_WHITE_NEXT;
      mrc_drawText("请白棋走子", 4, 3, 255, 255, 255, 0, MR_FONT_BIG);
   }
   //绘制待下棋子，黑棋或白棋
   mrc_spriteDraw(BOARD_BMP_ID, 
                         (uint16)spid, 
                         SCREEN_WIDTH-BOARD_STONE_WIDTH-1, 
                         1, 
                         BM_COPY);
   if (white_waiting_ai){
      mrc_drawText("请稍候",  SCREEN_WIDTH/2+4, 3, 255, 255, 255, 0, 0);
   }
}

//绘制游戏界面的棋盘两侧边框
static void white_drawSide(void)
{

  if(BOARD_OFFSET_X>0)
  {
	  mrc_drawRect(0, SCREEN_GAME_TOP_Y, BOARD_OFFSET_X, SCREEN_GAME_BOTTEM_Y-SCREEN_GAME_TOP_Y, white_bottom_line_rgb);
      mrc_drawRect(SCREEN_WIDTH-BOARD_OFFSET_X, SCREEN_GAME_TOP_Y, BOARD_OFFSET_X, SCREEN_GAME_BOTTEM_Y-SCREEN_GAME_TOP_Y, white_bottom_line_rgb);
  	}
   
}

//游戏界面刷新
static void white_refresh(int32 data)
{
	white_boardPaint(white_board+4);
	white_drawCursor();
	white_drawValid();
   white_drawTitle();
   white_drawSide();
   white_drawBottom();
   
   mrc_refreshScreen(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//游戏界面窗体事件处理
static void white_WinHandler(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           white_WinHandler(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//开始游戏
void white_start(int32 data)
{
   white_GameWinHandle=-1;
   white_GameWinHandle=mrc_platWinNew(0, white_WinHandler, white_KeyHandler);
   white_can_back = FALSE;
   mrc_winWinEvent(WIN_EVENT_REFRESH);
}

//新游戏
void main_new(int32 data){ 
   white_new(data);
   white_boardHasChanged();
   white_moveCursorToNext();
   white_start(data);
}

//继续游戏
void main_load(int32 data){
   white_boardHasChanged();
   white_moveCursorToNext();
   white_start(data);
}

//帮助
void main_help(int32 data){
   mrc_platTextNew("\x5e\x2e\x52\xa9", "\x4e\xb\x68\xcb\x89\xc4\x52\x19\xff\x1a\x0\xa\x0\x31\x30\x1\x5f\x53\x65\x3e\x4e\xb\x76\x84\x68\xcb\x5b\x50\x57\x28\x6a\x2a\x30\x1\x7a\xd6\x30\x1\x65\x9c\x51\x6b\x4e\x2a\x65\xb9\x54\x11\x51\x67\x67\x9\x4e\x0\x4e\x2a\x67\x2c\x65\xb9\x76\x84\x68\xcb\x5b\x50\xff\xc\x52\x19\x88\xab\x59\x39\x57\x28\x4e\x2d\x95\xf4\x76\x84\x5b\xf9\x62\x4b\x68\xcb\x5b\x50\x51\x68\x90\xe8\x4f\x1a\x88\xab\x54\x3\x63\x89\xff\xc\x63\x62\x62\x10\x67\x2c\x65\xb9\x76\x84\x68\xcb\x5b\x50\x30\x2\x0\xa\x0\x32\x30\x1\x53\xea\x67\x9\x57\x28\x53\xef\x4e\xe5\x54\x3\x5b\xf9\x65\xb9\x68\xcb\x5b\x50\x76\x84\x57\x30\x65\xb9\x62\x4d\x53\xef\x4e\xe5\x4e\xb\x5b\x50\x30\x2\x0\xa\x0\x33\x30\x1\x59\x82\x67\x9c\x68\xcb\x76\xd8\x4e\xa\x6c\xa1\x67\x9\x57\x30\x65\xb9\x53\xef\x4e\xe5\x4e\xb\x5b\x50\xff\xc\x52\x19\x5b\xf9\x62\x4b\x8f\xde\x4e\xb\x30\x2\x0\xa\x0\x34\x30\x1\x53\xcc\x65\xb9\x90\xfd\x6c\xa1\x67\x9\x68\xcb\x5b\x50\x53\xef\x4e\xe5\x4e\xb\x65\xf6\x68\xcb\x5c\x40\x7e\xd3\x67\x5f\xff\xc\x68\xcb\x5b\x50\x59\x1a\x76\x84\x4e\x0\x65\xb9\x83\xb7\x80\xdc\x30\x2", 
   	MR_DIALOG_CANCEL, 0, NULL, NULL);
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
   int32 ret;
   mrc_memset(white_state, 0, sizeof(white_state));
   mrc_memset(white_back_state, 0, sizeof(white_back_state));
   mrc_memset(white_valid_stones, 0, sizeof(white_valid_stones));
   mrc_winInit();
   
   //主棋盘从游戏状态数组的第28个字节开始
   white_board = &white_state[28];
   white_boardInit();
   mrc_clearScreen(0, 0, 0);
   
   //创建定时器
   main_timer=0;
   main_timer = mrc_timerCreate();

	ret=main_read();
   if (ret == MR_SUCCESS){
      
   }
   else
   {
		//第一次启动游戏、没有存盘记录的默认情况下，
		//让用户执黑子，电脑执白子。
	   white_ai=AI_HUMAN;
	   black_ai=AI_HUMAN;	   
	   white_ai_seting=AI_HUMAN;
   		white_stone_seting=BOARD_SAVE_BLACK;
   }

   //若上次退出时状态为可以继续游戏
   if (white_can_continue){
      //创建主菜单
      main_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 4);             // 黑白棋
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x65\xb0\x6e\x38\x62\xf", 0, main_new, 0);   // 新游戏      	
         mrc_platMenuSetItem(main_menu, "\x7e\xe7\x7e\xed\x6e\x38\x62\xf", 1, main_load, 0);   // 继续游戏
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 2, main_help, 0);   // 帮助
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 3, main_exit, 0);   // 退出游戏         
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 4, main_exit, 0);   // 点击返回键，退出游戏
         mrc_platMenuShow(main_menu);
         
      }else{
         return MR_FAILED;
      }
   }else{
      main_menu = mrc_platMenuNew("\x9e\xd1\x76\x7d\x68\xcb", 3);             // 黑白棋
      if (main_menu != MR_FAILED){
         mrc_platMenuSetItem(main_menu, "\x65\xb0\x6e\x38\x62\xf", 0, main_new, 0);   // 新游戏
         mrc_platMenuSetItem(main_menu, "\x5e\x2e\x52\xa9", 1, main_help, 0);   // 帮助
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 2, main_exit, 0);   // 退出游戏         
         mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6e\x38\x62\xf", 3, main_exit, 0);   // 点击返回键，退出游戏
         mrc_platMenuShow(main_menu);
         
      }else{
         return MR_FAILED;
      }
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

