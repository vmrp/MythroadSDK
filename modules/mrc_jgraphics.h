#ifndef _MRC_JGRAPHICS_H
#define _MRC_JGRAPHICS_H

#include "mrc_base.h"
#include "mrc_bmp.h"
extern int __SJC_SCREEN_WIDTH__;
extern int __SJC_SCREEN_HEIGHT__;
extern uint16 * __SJC_SCREEN_BUFFER__;


#define TOP_Graphics            16
#define BASELINE_Graphics       64
#define BOTTOM_Graphics         32
#define VCENTER_Graphics        0x2
#define AP_V_MASK_Graphics      (TOP_Graphics|BASELINE_Graphics|BOTTOM_Graphics|VCENTER_Graphics)

#define LEFT_Graphics           0x4
#define HCENTER_Graphics        0x1
#define RIGHT_Graphics          0x8
#define AP_H_MASK_Graphics      (LEFT_Graphics|HCENTER_Graphics|RIGHT_Graphics)



typedef struct {
	uint8*  data;
	uint16  width;
	uint16	height;
	uint8   trans;//1:ʹ��͸��ɫ;0:��ʹ��
	uint16  transcolor;
} mrc_jImageSt;


enum
{
	TRANS_NONE_Sprite,
	TRANS_MIRROR_Sprite	,
	TRANS_ROT180_Sprite,
	TRANS_MIRROR_ROT180_Sprite,
	TRANS_ROT90_Sprite,
	TRANS_MIRROR_ROT90_Sprite,
	TRANS_ROT270_Sprite,
	TRANS_MIRROR_ROT270_Sprite,		
};






/*-----------------------------------------------------------------------------------------
��������mrc_jgraphics_init
����  ����ʼ��sjc_Graphics����ȡ��Ļ�ĸߺͿ�
��ʼ���ü����򣬳�ʼ��ƽ�Ʋ�������ȡ��Ļ����
�ڻ��ƿ�ʼǰ���ȵ��ã���ʼ����ͼ��
*/
extern void mrc_jgraphics_init(void);

/*��������mrc_jgraphics_reinit
����  �����³�ʼ���ü�����ȫ��Ļ����
		���³�ʼ��ƽ�Ʋ�����0��0��
		������Ⱦ����ѭ����ʼʱ����*/
extern void mrc_jgraphics_reinit(void);


/*------------------------------------------------------------------------------------------
������	��mrc_jgraphics_translate
����	��ƽ�Ƶ�ǰ����ϵ*/
extern void mrc_jgraphics_translate(int x, int y);


/*������	��mrc_jgraphics_setClip
����	�����赱ǰ�ü����ο�,��translateӰ��*/
extern void mrc_jgraphics_setClip(int x, int y, int width, int height);

/*
������	��mrc_jgraphics_clipRect
����	�����òü����Ρ�
���������	x		--��ǰ����ϵ����Ҫ���òü��������ϵ��x����
			y		--��ǰ����ϵ����Ҫ���òü��������ϵ��y����
			width	--��Ҫ���òü����εĿ�
			height	--��Ҫ���òü����εĸ�
!!��Ҫ���õĲü����γ�����ǰ�ü����εĲ��ֽ�����ǰ�ü����βü�*/
extern void mrc_jgraphics_clipRect(int x, int y, int width, int height);

/*
������	��mrc_jgraphics_getClipHeight
����	����ȡ��ǰ�ü����εĸ�*/
extern int 	mrc_jgraphics_getClipHeight(void);

/*
������	��mrc_jgraphics_getClipWidth
����	����ȡ��ǰ�ü����εĿ�*/
extern int 	mrc_jgraphics_getClipWidth(void);

/*
������	��mrc_jgraphics_getClipX
����	����ȡ��ǰ�ü����ε����ϵ�����Ļ����ϵ�µ�x����*/
extern int 	mrc_jgraphics_getClipX(void);

/*
������	��mrc_jgraphics_getClipY
����	����ȡ��ǰ�ü����ε����ϵ�����Ļ����ϵ�µ�y����*/
extern int 	mrc_jgraphics_getClipY(void); 





/*-----------------------------------------------------------------------------------------------
������	��mrc_jgraphics_setFont
����	�����õ�ǰ����
		MR_FONT_SMALL,
		MR_FONT_MEDIUM,
		MR_FONT_BIG
*/
extern void mrc_jgraphics_setFont(uint16 font);

/*
������	��mrc_jgraphics_getFont
����	����ȡ��ǰ����*/
extern uint16 mrc_jgraphics_getFont(void);

/*
������	��mrc_jgraphics_setColor
����	�����õ�ǰ��ɫ
����    ��int RGB*/
extern void mrc_jgraphics_setColor(int RGB);

/*
������	��mrc_jgraphics_setColor_Ex
����	�����õ�ǰ��ɫ
����    ��int red, int green, int blue*/
extern void mrc_jgraphics_setColor_Ex(int red, int green, int blue);

/*
������	��mrc_jgraphics_getColor
����	����ȡ��ǰ��ɫ
����    ��8/8/8 format pixel (0x00RRGGBB)*/
extern int  getColor_Graphics(void);






/*-----------------------------------------------------------------------------------------
������	��mrc_jgraphics_drawString
����	�������ַ���,������Unicode�ַ�������
*/
extern void mrc_jgraphics_drawString(char* str, int x, int y, int anchor);


//extern void drawChar_Graphics_unichar_int_int_int(uint8* c, int x, int y, int anchor);




/*-------------------------------------------------------------------------------------------
������	��mrc_jgraphics_drawImage
����	������ͼ��
		typedef struct {
		uint8*  data; //ԴͼƬָ��
		uint16  width;
		uint16	height;
		uint8   trans;//1:ʹ��͸��ɫ;0:��ʹ��
		} Image_s;*/
extern void mrc_jgraphics_drawImage(mrc_jImageSt * img, int x, int y, int anchor);

/*
������	��mrc_jgraphics_drawRegion
����	������ͼ��
����	��	src,					--ͼ��	Image_s�ṹָ��
			x_src, y_src,			--Դͼ��
			width,height,			--Դͼ���͸�
			transform,				--��ת������
									TRANS_NONE_Sprite			�����任
									TRANS_MIRROR_Sprite			����
									TRANS_ROT180_Sprite			��ת180
									TRANS_MIRROR_ROT180_Sprite	������ת180
									TRANS_ROT90_Sprite 			��ת90
									TRANS_MIRROR_ROT90_Sprite 	������ת90
									TRANS_ROT270_Sprite 		��ת270
									TRANS_MIRROR_ROT270_Sprite 	������ת270
			x_dest,y_dest,			--��Ļ�ϵ�λ��
            anchor					--ê����������ǰֻ֧��Ϊ0�����ϵ㣩��*/
extern void mrc_jgraphics_drawRegion(mrc_jImageSt * src, int x_src, int y_src, int width, int height, int transform, int x_dest, int y_dest, int anchor);




/*-----------------------------------------------------------------------------------------------
������	��mrc_jgraphics_drawLine
����	������ֱ��
����    ��	x1:��ǰ����ϵ����Ҫ����ֱ��һ�˵�x����
			y1:��ǰ����ϵ����Ҫ����ֱ��һ�˵�y����
			x2:��ǰ����ϵ����Ҫ����ֱ����һ�˵�x����
			y2:��ǰ����ϵ����Ҫ����ֱ����һ�˵�y����
*/
extern void mrc_jgraphics_drawLine(int x1, int y1, int x2, int y2);
/*
������	��mrc_jgraphics_fillRect
����	������������
*/
extern void mrc_jgraphics_fillRect(int x, int y, int width, int height);

/*
������	��mrc_jgraphics_drawRect
����	�����ƾ��ο�
*/
extern void mrc_jgraphics_drawRect(int x, int y, int width, int height);

/*
������	��mrc_jgraphics_fillRoundRect
����	������Բ�������Σ�Ŀǰ��ͬ��fillRect_Graphics��
*/
extern void mrc_jgraphics_fillRoundRect(int x, int y, int width, int height, int arcWidth, int arcHeight);
/*
������	��mrc_jgraphics_drawRoundRect
����	������Բ�Ǿ��ο�Ŀǰ��ͬ��drawRect_Graphics��
*/
extern void mrc_jgraphics_drawRoundRect(int x, int y, int width, int height, int arcWidth,int arcHeight);

/*
������	��mrc_jgraphics_drawArc
����	������Բ
����	��	x,y				��Ӿ������ϵ�����
			width��height	��Ӿ��ο���
			startAngle      ��ʼ�Ƕ�		����ǰû���ã�
			arcAngle		�ܹ���Խ�ĽǶȣ���ǰû���ã�*/
extern void mrc_jgraphics_drawArc(int x, int y, int width, int height, int startAngle, int arcAngle);

/*
������	��mrc_jgraphics_drawRoundRect
����	�������������
����	��	x,y				��Ӿ������ϵ�����
			width��height	��Ӿ��ο���
			startAngle      ��ʼ�Ƕȣ�0��90��270��360��
			arcAngle		�ܹ���Խ�ĽǶȣ�180��*/				
extern void mrc_jgraphics_fillArc(int x, int y, int width, int height, int startAngle, int arcAngle);

/*
������	��mrc_jgraphics_drawRoundRect
����	���������������
*/
extern void mrc_jgraphics_fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3);



#endif