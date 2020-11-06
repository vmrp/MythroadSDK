
#include "..\..\modules\mrc_base.h"
#include "board.h"

void white_boardInit(void)
{
#ifdef	SCREEN176_220
   mrc_bitmapLoad(BOARD_BMP_ID, "board.bmp", 0, 0, 
             BOARD_STONE_WIDTH, BOARD_STONE_HEIGHT*16, BOARD_STONE_WIDTH);
#endif

#ifdef SCREEN240_320
   mrc_bitmapLoad(BOARD_BMP_ID, "board.bmp", 0, 0, 
             BOARD_STONE_WIDTH, BOARD_STONE_HEIGHT*16, BOARD_STONE_WIDTH);
#endif
   mrc_spriteSet(BOARD_BMP_ID, BOARD_STONE_HEIGHT);
}

static int32 white_boardGetSPID(int8* board, int32 x, int32 y, int32* draw_line)
{
   int32 x1= x-1;
   int32 y1 = y-1;
   int32 spid = 0;
   *draw_line = FALSE;
   if(x==0){  
   	// ����һ��
      if(y==0){
         if (board[0] == BOARD_SAVE_BLACK){
            spid = BOARD_SPID_BLACK_NONE;
         }else   if (board[0] == BOARD_SAVE_WHITE){
            spid = BOARD_SPID_WHITE_NONE;
         }else {
            spid = BOARD_SPID_EMPTY_NONE;
            *draw_line = TRUE;
         } 
         //���Ͻ�
      }else {  
      // ����һ��
         if (board[y*BOARD_WIDTH] == BOARD_SAVE_BLACK){
            if((board[y1*BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
               spid = BOARD_SPID_BLACK_NONE;
            }else{
               spid = BOARD_SPID_BLACK_TOP;
            }
         }else   if (board[y*BOARD_WIDTH] == BOARD_SAVE_WHITE){
            if((board[y1*BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
               spid = BOARD_SPID_WHITE_NONE;
            }else{
               spid = BOARD_SPID_WHITE_TOP;
            }
         }else {
         
            if((board[y1*BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
               spid = BOARD_SPID_EMPTY_NONE;
            }else{
               spid = BOARD_SPID_EMPTY_TOP;
            }
            *draw_line = TRUE;
            
         }  
      }
   }else if (y==0){// ����һ��   
      if (board[x] == BOARD_SAVE_BLACK){
         if((board[x1] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_BLACK_NONE;
         }else{
            spid = BOARD_SPID_BLACK_LEFT;
         }
      }else   if (board[x] == BOARD_SAVE_WHITE){
         if((board[x1] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_WHITE_NONE;
         }else{
            spid = BOARD_SPID_WHITE_LEFT;
         }
      }else {
      
         if((board[x1] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_EMPTY_NONE;
         }else{
            spid = BOARD_SPID_EMPTY_LEFT;
         }
         *draw_line = TRUE;
         
      }  
   }else{
   
      if (board[x+y*BOARD_WIDTH] == BOARD_SAVE_BLACK){
         
         if((board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY) 
            && (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_BLACK_NONE;
         }else if (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_BLACK_LEFT;
         }else if (board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_BLACK_TOP;
         }else{
            spid = BOARD_SPID_BLACK_BOTH;
         }
         
      }else   if (board[x+y*BOARD_WIDTH] == BOARD_SAVE_WHITE){
         
         if((board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY) 
            && (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_WHITE_NONE;
         }else if (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_WHITE_LEFT;
         }else if (board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_WHITE_TOP;
         }else{
            spid = BOARD_SPID_WHITE_BOTH;
         }
         
      }else {
         
         if((board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY) 
            && (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY)){
            spid = BOARD_SPID_EMPTY_NONE;
         }else if (board[x + y1 * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_EMPTY_LEFT;
         }else if (board[x1 + y * BOARD_WIDTH] == BOARD_SAVE_EMPTY){
            spid = BOARD_SPID_EMPTY_TOP;
         }else{
            spid = BOARD_SPID_EMPTY_BOTH;
         }
         
         *draw_line = TRUE;
      }
      
   }
   return spid;
}

static void white_boardDrawLine(int32 x, int32 y)
{
   int16 xh1, yh1, xh2, yh2;
   int16 xv1, yv1, xv2, yv2;
   if (x==0){
      xh1 = BOARD_OFFSET_X + BOARD_STONE_WIDTH/2;
   }else{
      xh1 = BOARD_OFFSET_X + x * BOARD_STONE_WIDTH;
   }
   if (x==BOARD_WIDTH-1){
      xh2 = BOARD_OFFSET_X + x * BOARD_STONE_WIDTH + BOARD_STONE_WIDTH/2;
   }else{
      xh2 = BOARD_OFFSET_X + (x+1) * BOARD_STONE_WIDTH;
   }
   yh1 = yh2 = BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT + BOARD_STONE_HEIGHT/2;

   if (y==0){
      yv1 = BOARD_OFFSET_Y+ BOARD_STONE_HEIGHT/2;
   }else{
      yv1 = BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT;
   }
   if (y==BOARD_HEIGHT-1){
      yv2 = BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT+ BOARD_STONE_HEIGHT/2;
   }else{
      yv2 = BOARD_OFFSET_Y + (y+1) * BOARD_STONE_HEIGHT;
   }
   xv1 = xv2 = BOARD_OFFSET_X + x * BOARD_STONE_WIDTH+ BOARD_STONE_WIDTH/2;

   mrc_drawLine(xh1, yh1, xh2, yh2,
                           BOARD_LINE_RGB);
   mrc_drawLine(xv1, yv1, xv2, yv2,
                           BOARD_LINE_RGB);
}

void white_boardPaint(int8* board)
{
   int x,y;
   int32 draw_line;

   for (y=0;y<BOARD_HEIGHT;y++)
   {
      for(x=0;x<BOARD_WIDTH;x++)
      {
         mrc_spriteDraw(BOARD_BMP_ID, 
                               (uint16)white_boardGetSPID(board, x, y, &draw_line), 
                               BOARD_OFFSET_X + x * BOARD_STONE_WIDTH, 
                               BOARD_OFFSET_Y + y * BOARD_STONE_HEIGHT, 
                               BM_COPY);
         if (draw_line){
            white_boardDrawLine(x, y);
         }
      }
   }
}

//���ݴ����������λ�÷��ع�굱ǰλ�õĶ���
//status:
//	0	�Ƿ�����Ļ״̬��
//	1	��ǰ��Ļ״̬Ϊ��Ϸ���̽��档
//mouse_x	��ĻX	������
//mouse_y	��ĻY	������
//ItemType		���ض�������
//	0	δ֪�Ĵ������͡�
//	1	����
//	2	������
//	3	�ײ��˵���
//ItemX��ItemY�Ƿ��ض����ڶ���������±�λ�á�
//��ItemType=1ʱ�������������������±�λ�ã�
//��ItemType=2��3ʱ���ǲ˵�����±�λ�á�
int32 white_MouseToItem(int32 status,int32 mouse_x,int32 mouse_y,int32 *ItemType,int32 *ItemX,int32 *ItemY)
{
	int8 i=0,j=0;
	if(!status||mouse_x<0||mouse_y<0||mouse_x>=SCREEN_WIDTH||mouse_y>=SCREEN_HEIGHT)
	{
		*ItemType=0;
		*ItemX=-1;
		*ItemY=-1;
		return -1;
	}
	if(status!=SCREEN_STATUS_GAME)
		return -1;
	if(mouse_y<SCREEN_GAME_TOP_Y)
	{
		//�û���������Ǳ���������������
	}
	else if(mouse_y<SCREEN_GAME_BOTTEM_Y)
	{
		*ItemType=SCREEN_ITEM_STONE;
		//�û�����������������ݣ���Ҫ����ǵ�����ĸ����Ӳ�����
		//������Ҫ��������X��Y������������Ӧ�±�λ�á�
		for(i=0;i<8;i++)
		{
			if( (BOARD_OFFSET_Y +i * BOARD_STONE_HEIGHT)<mouse_y
				&&(BOARD_OFFSET_Y +(i+1) * BOARD_STONE_HEIGHT)>mouse_y )
			{
				*ItemY=i;
				break;
			}

		};
		for(j=0;j<8;j++)
		{
			if( (BOARD_OFFSET_X +j * BOARD_STONE_WIDTH)<mouse_x
				&&(BOARD_OFFSET_X +(j+1) * BOARD_STONE_WIDTH)>mouse_x )
			{
				*ItemX=j;
				break;
			}

		};
	}
	else
	{
		//�û���������ǵײ��˵�ѡ�����Ҫ����
		*ItemType=SCREEN_ITEM_BOTTEM;
		*ItemX=mouse_x/(SCREEN_WIDTH/2);
		*ItemY=0;
	}
	return 0;
}
