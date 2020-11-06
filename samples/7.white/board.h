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

#define BOARD_WIDTH  8	//ÿ��8������
#define BOARD_HEIGHT  8	//ÿ��8������

#ifdef SCREEN176_220
	#define	SCREEN_WIDTH 176	//��ĻX����
	#define	SCREEN_HEIGHT 220	//��ĻY����
	#define	SCREEN_GAME_TOP_Y 26		//��Ļ����Y���꿪ʼֵ
	#define	SCREEN_GAME_BOTTEM_Y 194	//��Ļ����Y�������ֵ8*21+26��
	
	#define BOARD_OFFSET_X 4
	#define BOARD_OFFSET_Y 26
	#define BOARD_STONE_WIDTH  21
	#define BOARD_STONE_HEIGHT  21	
#endif

#ifdef SCREEN240_320
	#define	SCREEN_WIDTH 240	//��ĻX����
	#define	SCREEN_HEIGHT 320	//��ĻY����
	#define	SCREEN_GAME_TOP_Y 35		//��Ļ����Y���꿪ʼֵ
	#define 	SCREEN_GAME_BOTTEM_Y 275	//��Ļ����Y�������ֵ8*30+35��

	#define BOARD_OFFSET_X 0
	#define BOARD_OFFSET_Y 35
	#define BOARD_STONE_WIDTH  30
	#define BOARD_STONE_HEIGHT  30
#endif

//���嵱ǰ��Ļ״̬���Ƿ�Ϊ���ӵ���Ļ
enum 
{
   SCREEN_STATUS_UNKNOWN=0,
   SCREEN_STATUS_GAME=1
};

//���巵�صĶ������͡�
enum 
{
   SCREEN_ITEM_UNKNOWN=0,
   SCREEN_ITEM_STONE=1,	//���ض�������������
   SCREEN_ITEM_TOP=2,	//���ض��������Ƕ����˵�����
   SCREEN_ITEM_BOTTEM=3	//���ز˵����������ǵײ��˵�����
};

void white_boardInit(void);
void white_boardPaint(int8* board);

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
int32 white_MouseToItem(int32 status,int32 mouse_x,int32 mouse_y,int32 *ItemType,int32 *ItemX,int32 *ItemY);

#endif
