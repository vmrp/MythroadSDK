

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

//�ڵ�ǰ����£�����player������x,y������ӵ��(x_iter,y_iter)ƫ�����߷���
//���޿��ߵ����ӡ����ޣ��򷵻�0�����У��򷵻ؿ��Է�ת�ĶԷ����Ӹ�����
static int white_numOutflankedPieces(int8 x_iter, int8 y_iter, int8 x, int8 y, 
   int8 player, int8* board)
{
   int checked = 0; //counts how many spaces we've traveled in the direction row_iter,col_iter
   int x_check = x + x_iter; //row,col to check at each iteration
   int y_check = y + y_iter;

   //while the check row and column are in bounds
   while(x_check >= 0 && y_check >= 0 && x_check < BOARD_WIDTH && y_check < BOARD_HEIGHT)
   {
   	//��������û�����ӵ�û�п�λ�ã���û�з��������ĶԷ�����
      if(board[ BOARD_POS(x_check, y_check) ] == BOARD_SAVE_EMPTY) //if the space is blank, it's not a valid move
         return 0;
      //�ҵ�һ�����������ӣ��� ��ֹ�����������������ĶԷ����Ӹ�����
      if(board[ BOARD_POS(x_check, y_check) ]  == player) //if we encounter the same color as our player
         return checked; //return how many pieces we've looked at thus far
      //��¼�ҵ���һ���Է������ӡ�	
      checked++; //we've examined one more piece
      //�������Ե�ķ������������
      x_check += x_iter; //move one piece farther
      y_check += y_iter;
   }

   return 0; //it got to the edge of the board without finding any pieces to outflank
}

//�����������̵�������ж���x,y���λ���ϣ�player�Ƿ�������ӡ�
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

//Ѱ���Ƿ��п����ߵ�����
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

//���̷����˱仯������ɨ���������̣�
//���㵱ǰ������Щ����λ�ÿ��á�
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
   //�������ʧ�ܣ�������̵����½������Ͻ�����������
   //�����޸���ȫ�ֱ���white_cursor_x��white_cursor_y��Ԥ������ѭ���Ŀ��ܡ�
   if((white_cursor_x!=BOARD_WIDTH)&&(white_cursor_y!=BOARD_HEIGHT-1))
   {
      white_cursor_x = BOARD_WIDTH;
      white_cursor_y = BOARD_HEIGHT-1;
      white_moveCursorToPre();
   }else{
      if(!white_valid_stones[ BOARD_POS(white_cursor_x, white_cursor_y) ]){
      		//���ӿ��ߡ�
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

   //��Ҷ�ս
   white_ai = AI_HUMAN;
   black_ai = AI_HUMAN;
   white_can_back = FALSE;
   white_can_continue = TRUE;
   white_cursor_x=0;
   white_cursor_y=0;
   white_EnumBothValidMoves(white_state+28);
}

//��ת�Է������ӡ��������ط�ת�Է����ӵ���������
static int white_outflank(int8 x, int8 y, int8 player, int8* board)
{
   int i, j;
   int outflanks, total = 0;
   int x_iter, y_iter;
   int x_cur, y_cur;
    //for each space surrounding the row,col in question
    //�������������Լ��ĸ��Խ��ߣ���8������
   for(i = 0; i < 9; i++)
   {
	//skip row,col   
      if(i == 4) 
         continue;
      //set row and col iterators for each surrounding space
      //X�᷽������ֵ-1,0,1
      x_iter = i/3 - 1;
      //Y�᷽������ֵ-1,0,1
      y_iter = i%3 - 1;
	//����ƫ������ֵ������������߷����ж��ٸ��Է������ӱ���ס��������ת��
      outflanks = white_numOutflankedPieces(x_iter, y_iter, x, y, player, board); //get num outflanks
      total += outflanks;                                                           //add to total

      x_cur = x; //start at row,col
      y_cur = y;
      //��ǰ���⵽��outflanks���Է����ӽ��з�ת������
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
   //��ת�Է������ӡ��������ط�ת�Է����ӵ���������
   if(!white_outflank(x, y, white_turn(board), board)) //if we didn't outflank anything, invalid move
      return WHITE_FAILED;
   //��¼���ӡ�
   board[ BOARD_POS(x,y) ] = white_turn(board); //add the piece where they moved
   white_EnumBothValidMoves(board);
   //����Ȩת�ƣ����ɶԷ����ӡ�
   white_turn(board) = GET_OTHER_PLAYER(white_turn(board));//other player's turn   
   if(!white_hasValidMoves(white_turn(board), board))     //if the new player has no valid moves
   {
      //�Է����ӿ��ߣ������Ȩת�ص�����
      white_turn(board) = GET_OTHER_PLAYER(white_turn(board));                             //switch back
      //�����������ӣ��򷵻�(�ȴ��û����Ӳ���)
      if(white_hasValidMoves(white_turn(board), board))   //if there ARE valid moves now
         return WHITE_NOOPPONENTMOVES;          //tell them so
      //����Ҳ�޿����ӣ��򷵻���Ϸ��������ʾ��         
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

//���㵱ǰ���ӷ��ڵ�ǰ����ж��ٸ����ӵ㡣
//���size>0�����¼�����������õ���ǰsize�����ӵ㡣
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

//���ݸ����ĵ�ǰ��֣��ֱ��г��ɰ��塢��������ʱ�Ŀ��ܲ����档
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

//���㵱ǰ���ӷ��ڵ�ǰ����ж��ٸ����ӵ㡣
//���size>0�����¼�����������õ���ǰsize�����ӵ㡣
//ע�⣬��������white_EnumBothValidMoves�ļ�������
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



//����һ������
int8* white_cloneBoard(int8* board)
{
   int8 *n = NULL;
   unsigned int count=0;
   //��ǰ���̡�������������̡�������������̡�
   count=(4+3*BOARD_HEIGHT * BOARD_WIDTH)*sizeof(int8);
  if(board && (n = mrc_malloc(count) )!= NULL)
   {
	  mrc_memcpy(n,board,count);
   }

   return n;
}
