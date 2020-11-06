

#include "..\..\modules\mrc_base.h"

#include "white.h"
#include "board.h"
#include "white_aux.h"

int white_countPieces(int8*board ,int8 * blacks, int8 * whites)
{
   int i, j;
   int bl = 0, wh = 0;
   
   for(i = 0; i < BOARD_HEIGHT; i++)
   {
      for(j = 0; j < BOARD_WIDTH; j++)
      {
         if(board[ BOARD_POS(j, i) ] == BOARD_SAVE_BLACK)
            bl++;
         else if(board[ BOARD_POS(j, i) ] == BOARD_SAVE_WHITE)
            wh++;
      }
   }

   if(blacks)
      *blacks = bl;
   if(whites)
      *whites = wh;

   return (BOARD_HEIGHT * BOARD_WIDTH) - bl - wh;
}

//在当前棋局下，对于player方，在x,y这个落子点的(x_iter,y_iter)偏移射线方向
//有无可走的棋子。若无，则返回0，若有，则返回可以翻转的对方棋子个数。
static int white_numOutflankedPieces(int8 x_iter, int8 y_iter, int8 x, int8 y, 
   int8 player, int8* board)
{
   int checked = 0; //counts how many spaces we've traveled in the direction row_iter,col_iter
   int x_check = x + x_iter; //row,col to check at each iteration
   int y_check = y + y_iter;

   //while the check row and column are in bounds
   while(x_check >= 0 && y_check >= 0 && x_check < BOARD_WIDTH && y_check < BOARD_HEIGHT)
   {
   	//待检查点是没有棋子的没有空位置，则没有符合条件的对方棋子
      if(board[ BOARD_POS(x_check, y_check) ] == BOARD_SAVE_EMPTY) //if the space is blank, it's not a valid move
         return 0;
      //找到一个本方的棋子，则 终止搜索，返回搜索到的对方棋子个数。
      if(board[ BOARD_POS(x_check, y_check) ]  == player) //if we encounter the same color as our player
         return checked; //return how many pieces we've looked at thus far
      //记录找到了一个对方的棋子。	
      checked++; //we've examined one more piece
      //向更靠边缘的方向进行搜索。
      x_check += x_iter; //move one piece farther
      y_check += y_iter;
   }

   return 0; //it got to the edge of the board without finding any pieces to outflank
}

//根据现有棋盘的情况，判断在x,y这个位置上，player是否可以落子。
int8 white_OldIsStoneValid(int8 x, int8 y, int8 player, int8* board)
{
   int i;

   if(board && player && x >= 0 && y >= 0 && y < BOARD_HEIGHT
            && x < BOARD_WIDTH && board[ BOARD_POS(x, y) ] == BOARD_SAVE_EMPTY) //check for validity
   {
      for(i = 0; i < 9; i++) //for each space surrounding the row,col in question
      {
         if(i == 4) //skip row,col
            continue;

         //i/3 - 1 and i%3 - 1 are the row and col iterators for the each surrounding space
         if(white_numOutflankedPieces(i/3 - 1, i%3 - 1, x, y, player, board)) //if we would outflank nonzero pieces this direction
            return 1; //it's valid
      }
   }

   return 0; //nothing found
}

int8 white_isStoneValid(int8 x, int8 y, int8 player, int8* board)
{
   if(player==BOARD_SAVE_WHITE)
   {
   	if( *(board+4+64+y*8+x)==BOARD_SAVE_WHITE)
   		return 1;
   }
   else if(player==BOARD_SAVE_BLACK)
   {
   	if( *(board+4+64+64+y*8+x)==BOARD_SAVE_BLACK)
		return 1;
   }
   return 0; //nothing found
}

//寻找是否有可以走的棋子
int8 white_OldhasValidMoves(int8 player, int8* board)
{

   int8 x,y;
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
         if(white_OldIsStoneValid(x, y, player, board))
            return 1;
      }
   }

   return 0;
}

int8 white_hasValidMoves(int8 player, int8* board)
{
   if( (player==BOARD_SAVE_WHITE) && board[2]>0)
            return 1;
   if( (player==BOARD_SAVE_BLACK) && board[1]>0)
            return 1;
   return 0;
}


int8 white_getAiLevel(int8 whom)
{
   return ((whom == BOARD_SAVE_BLACK) ? black_ai : white_ai);
}

//棋盘发生了变化，重新扫描整个棋盘，
//计算当前方有哪些落子位置可用。
void white_boardHasChanged(void)
{
   int8 x,y;
   //white_countPieces(white_board, &white_blacks, &white_whites);
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
         white_valid_stones[ BOARD_POS(x, y) ] = white_isStoneValid(x, y, white_turn(white_board), white_board);
      }
   }
}

void white_moveCursorToNext(void)
{
   int8 x,y;
   int8 ori_x = white_cursor_x+1;
   for (y=white_cursor_y;y<BOARD_HEIGHT;y++)
   {
      for(x=ori_x;x<BOARD_WIDTH;x++)
      {
         if(white_valid_stones[ BOARD_POS(x, y) ])
         {
            white_cursor_x = x;
            white_cursor_y = y;
            return;
         }
      }
      ori_x = 0;
   }
   //if(white_cursor_x||white_cursor_y)
   if(white_cursor_x!=-1||white_cursor_y!=0)
   {
      //libo20070831 white_cursor_x = 0;
      white_cursor_x = -1;
      white_cursor_y = 0;
      white_moveCursorToNext();
   }else{
      if(!white_valid_stones[ BOARD_POS(white_cursor_x, white_cursor_y) ]){
         white_cursor_x = -1;
         white_cursor_y = -1;
      }
   }
}

void white_moveCursorToPre(void)
{
   int8 x,y;
   int8 ori_x = white_cursor_x-1;
   for (y=white_cursor_y;y>=0;y--)
   {
      for(x=ori_x;x>=0;x--)
      {
         if(white_valid_stones[ BOARD_POS(x, y) ])
         {
            white_cursor_x = x;
            white_cursor_y = y;
            return;
         }
      }
      ori_x = BOARD_WIDTH-1;
   }
   //如果搜索失败，则从棋盘的右下角往左上角重新搜索。
   //这里修改了全局变量white_cursor_x和white_cursor_y，预防了死循环的可能。
   if((white_cursor_x!=BOARD_WIDTH)&&(white_cursor_y!=BOARD_HEIGHT-1))
   {
      white_cursor_x = BOARD_WIDTH;
      white_cursor_y = BOARD_HEIGHT-1;
      white_moveCursorToPre();
   }else{
      if(!white_valid_stones[ BOARD_POS(white_cursor_x, white_cursor_y) ]){
      		//无子可走。
         white_cursor_x = -1;
         white_cursor_y = -1;
      }
   }
}

void white_new(int32 data)
{
   MR_MEMSET(white_state+28, 0, sizeof(white_state)-28);
   
   white_board[ BOARD_POS(BOARD_WIDTH/2, BOARD_HEIGHT /2 - 1) ] = 
   white_board[ BOARD_POS(BOARD_WIDTH/2 -1, BOARD_HEIGHT /2) ] = BOARD_SAVE_BLACK;

   white_board[ BOARD_POS(BOARD_WIDTH/2-1, BOARD_HEIGHT /2 - 1) ] = 
   white_board[ BOARD_POS(BOARD_WIDTH/2, BOARD_HEIGHT /2) ] = BOARD_SAVE_WHITE;
   
   white_turn(white_board) = BOARD_SAVE_BLACK;

   //玩家对战
   white_ai = AI_HUMAN;
   black_ai = AI_HUMAN;
   white_can_back = FALSE;
   white_can_continue = TRUE;
   white_cursor_x=0;
   white_cursor_y=0;
   white_EnumBothValidMoves(white_state+28);
}

//翻转对方的棋子。函数返回翻转对方棋子的总数量。
static int white_outflank(int8 x, int8 y, int8 player, int8* board)
{
   int i, j;
   int outflanks, total = 0;
   int x_iter, y_iter;
   int x_cur, y_cur;
    //for each space surrounding the row,col in question
    //搜索上下左右以及四个对角线，共8个方向。
   for(i = 0; i < 9; i++)
   {
	//skip row,col   
      if(i == 4) 
         continue;
      //set row and col iterators for each surrounding space
      //X轴方向修正值-1,0,1
      x_iter = i/3 - 1;
      //Y轴方向修正值-1,0,1
      y_iter = i%3 - 1;
	//根据偏移修正值搜索在这个射线方向有多少个对方的棋子被夹住而将被翻转。
      outflanks = white_numOutflankedPieces(x_iter, y_iter, x, y, player, board); //get num outflanks
      total += outflanks;                                                           //add to total

      x_cur = x; //start at row,col
      y_cur = y;
      //对前面检测到的outflanks个对方棋子进行翻转操作。
      for(j = 0; j < outflanks; j++) //for each one that direction
      {
         x_cur += x_iter; //first, move one space
         y_cur += y_iter;
         board[ BOARD_POS(x_cur,y_cur) ] = GET_OTHER_PLAYER(board[ BOARD_POS(x_cur,y_cur) ]); //reverse that piece
      }
   }

   return total;
}


int32 white_makeMove(int8 x, int8 y, int8* board)
{

   if(!board || x < 0 || y < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT
         || board[ BOARD_POS(x,y) ] != BOARD_SAVE_EMPTY)
      return WHITE_FAILED; //deny outright if invalid  
   //翻转对方的棋子。函数返回翻转对方棋子的总数量。
   if(!white_outflank(x, y, white_turn(board), board)) //if we didn't outflank anything, invalid move
      return WHITE_FAILED;
   //记录走子。
   board[ BOARD_POS(x,y) ] = white_turn(board); //add the piece where they moved
   white_EnumBothValidMoves(board);
   //控制权转移，交由对方走子。
   white_turn(board) = GET_OTHER_PLAYER(white_turn(board));//other player's turn   
   if(!white_hasValidMoves(white_turn(board), board))     //if the new player has no valid moves
   {
      //对方无子可走，则控制权转回到本方
      white_turn(board) = GET_OTHER_PLAYER(white_turn(board));                             //switch back
      //本方可以走子，则返回(等待用户走子操作)
      if(white_hasValidMoves(white_turn(board), board))   //if there ARE valid moves now
         return WHITE_NOOPPONENTMOVES;          //tell them so
      //本方也无可走子，则返回游戏结束的提示。         
      white_turn(board) = GET_OTHER_PLAYER(white_turn(board));                             //stay as original
      return WHITE_GAMEOVER;                    //if neither player has moves, game's over
   }

   return WHITE_OK; //otherwise, everything went normally
}


int8 white_IsGameOver(int8* board)
{
   return !(white_OldhasValidMoves(BOARD_SAVE_BLACK, board) 
      || white_OldhasValidMoves(BOARD_SAVE_WHITE, board));
}

//计算当前走子方在当前棋局有多少个落子点。
//如果size>0，则记录、保存搜索得到的前size个落子点。
int white_OldenumValidMoves(int8 player, int8* board, int8 xs[], int8 ys[], int32 size)
{
   int moves = 0;
   int8 x,y;
   
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
               if(white_OldIsStoneValid(x,y,player,board))
               {
                  if(moves < size)
                  {
                     xs[moves] = x;
                     ys[moves] = y;
                  }
                  moves++;
               }
      }
   }
   return moves;
}

//根据给出的当前棋局，分别列出由白棋、黑棋走子时的可能并保存。
void white_EnumBothValidMoves(int8* Curboard)
{
   int8 x,y,*White,*Black;
   Curboard[1]=0;
   Curboard[2]=0;
   White=Curboard+4+64;
   Black=Curboard+4+64+64;
   mrc_memset(White,0,64);
   mrc_memset(Black,0,64);
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
               if(white_OldIsStoneValid(x,y,BOARD_SAVE_BLACK,Curboard))
               {
		    Black[y*BOARD_WIDTH+x]=BOARD_SAVE_BLACK;
                  Curboard[1]++;
               }
               if(white_OldIsStoneValid(x,y,BOARD_SAVE_WHITE,Curboard))
               {
                  White[y*BOARD_WIDTH+x]=BOARD_SAVE_WHITE;
                  Curboard[2]++;
               }               
      }
   }
   return ;
}

//计算当前走子方在当前棋局有多少个落子点。
//如果size>0，则记录、保存搜索得到的前size个落子点。
//注意，这依赖于white_EnumBothValidMoves的计算结果。
int white_enumValidMoves(int8 player, int8* board, int8 xs[], int8 ys[], int32 size)
{
   int moves = 0;
   int8 x,y;

   if(board==NULL)
   	return 0;
   if(size==0 && player==BOARD_SAVE_WHITE)
   	return board[2];
   else if(size==0 && player==BOARD_SAVE_BLACK)
   	return board[1];
   
   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
      		if(player==BOARD_SAVE_WHITE)
      		{
	               if(board[4+64+y*BOARD_WIDTH+x]==player)
       	        {
              		if(moves < size)
                  		{
                     		xs[moves] = x;
                     		ys[moves] = y;
                  		}
                  		moves++;
              	  }
      		}
      		else if(player==BOARD_SAVE_BLACK)
      		{//BOARD_SAVE_BLACK
	               if(board[4+64+64+y*BOARD_WIDTH+x]==player)
       	        {
              		if(moves < size)
                  		{
                     		xs[moves] = x;
                     		ys[moves] = y;
                  		}
                  		moves++;
              	  }
      		}
	               
      }
   }
   return moves;
}



//复制一个棋盘
int8* white_cloneBoard(int8* board)
{
   int8 *n = NULL;
   unsigned int count=0;
   //当前棋盘、白棋可走子棋盘、黑棋可走子棋盘。
   count=(4+3*BOARD_HEIGHT * BOARD_WIDTH)*sizeof(int8);
  if(board && (n = mrc_malloc(count) )!= NULL)
   {
	  mrc_memcpy(n,board,count);
   }

   return n;
}
