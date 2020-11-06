
#ifndef __WHITE_AUX_H__
#define __WHITE_AUX_H__

enum //how's the ai lookin'?
{
   AI_HUMAN,          //doesn't use ai
   AI_BEGINNER,       //uses basic ai
   AI_INTERMEDIATE,   //etc.
   AI_ADVANCED
};

void white_boardHasChanged(void);
void white_new(int32 data);
int32 white_makeMove(int8 x, int8 y, int8* board);
int white_countPieces(int8*board ,int8 * blacks, int8 * whites);

int8 white_IsGameOver(int8* board);
int8* white_cloneBoard(int8* board);

void white_moveCursorToNext(void);
void white_moveCursorToPre(void);
int8 white_getAiLevel(int8 whom);

int white_enumValidMoves(int8 player, int8* board, int8 xs[], int8 ys[], int32 size);
//根据给出的当前棋局，分别列出由白棋、黑棋走子时的可能并保存。
void white_EnumBothValidMoves(int8* Curboard);

#define GET_OTHER_PLAYER(x) (((x)==BOARD_SAVE_WHITE)? BOARD_SAVE_BLACK : BOARD_SAVE_WHITE)

#endif

