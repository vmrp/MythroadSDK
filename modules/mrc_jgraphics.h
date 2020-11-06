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
	uint8   trans;//1:使用透明色;0:不使用
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
函数名：mrc_jgraphics_init
功能  ：初始化sjc_Graphics，获取屏幕的高和宽
初始化裁剪区域，初始化平移参数，获取屏幕缓存
在绘制开始前最先调用，初始化绘图。
*/
extern void mrc_jgraphics_init(void);

/*函数名：mrc_jgraphics_reinit
功能  ：重新初始化裁剪区域（全屏幕），
		重新初始化平移参数（0，0）
		可在渲染绘制循环开始时调用*/
extern void mrc_jgraphics_reinit(void);


/*------------------------------------------------------------------------------------------
函数名	：mrc_jgraphics_translate
功能	：平移当前坐标系*/
extern void mrc_jgraphics_translate(int x, int y);


/*函数名	：mrc_jgraphics_setClip
功能	：重设当前裁剪矩形框,受translate影响*/
extern void mrc_jgraphics_setClip(int x, int y, int width, int height);

/*
函数名	：mrc_jgraphics_clipRect
功能	：设置裁剪矩形。
输入参数：	x		--当前坐标系下所要设置裁剪矩形左上点的x坐标
			y		--当前坐标系下所要设置裁剪矩形左上点的y坐标
			width	--所要设置裁剪矩形的宽
			height	--所要设置裁剪矩形的高
!!所要设置的裁剪矩形超出当前裁剪矩形的部分将被当前裁剪矩形裁剪*/
extern void mrc_jgraphics_clipRect(int x, int y, int width, int height);

/*
函数名	：mrc_jgraphics_getClipHeight
功能	：获取当前裁剪矩形的高*/
extern int 	mrc_jgraphics_getClipHeight(void);

/*
函数名	：mrc_jgraphics_getClipWidth
功能	：获取当前裁剪矩形的宽*/
extern int 	mrc_jgraphics_getClipWidth(void);

/*
函数名	：mrc_jgraphics_getClipX
功能	：获取当前裁剪矩形的左上点在屏幕坐标系下的x坐标*/
extern int 	mrc_jgraphics_getClipX(void);

/*
函数名	：mrc_jgraphics_getClipY
功能	：获取当前裁剪矩形的左上点在屏幕坐标系下的y坐标*/
extern int 	mrc_jgraphics_getClipY(void); 





/*-----------------------------------------------------------------------------------------------
函数名	：mrc_jgraphics_setFont
功能	：设置当前字体
		MR_FONT_SMALL,
		MR_FONT_MEDIUM,
		MR_FONT_BIG
*/
extern void mrc_jgraphics_setFont(uint16 font);

/*
函数名	：mrc_jgraphics_getFont
功能	：获取当前字体*/
extern uint16 mrc_jgraphics_getFont(void);

/*
函数名	：mrc_jgraphics_setColor
功能	：设置当前颜色
参数    ：int RGB*/
extern void mrc_jgraphics_setColor(int RGB);

/*
函数名	：mrc_jgraphics_setColor_Ex
功能	：设置当前颜色
参数    ：int red, int green, int blue*/
extern void mrc_jgraphics_setColor_Ex(int red, int green, int blue);

/*
函数名	：mrc_jgraphics_getColor
功能	：获取当前颜色
返回    ：8/8/8 format pixel (0x00RRGGBB)*/
extern int  getColor_Graphics(void);






/*-----------------------------------------------------------------------------------------
函数名	：mrc_jgraphics_drawString
功能	：绘制字符串,仅处理Unicode字符串输入
*/
extern void mrc_jgraphics_drawString(char* str, int x, int y, int anchor);


//extern void drawChar_Graphics_unichar_int_int_int(uint8* c, int x, int y, int anchor);




/*-------------------------------------------------------------------------------------------
函数名	：mrc_jgraphics_drawImage
功能	：绘制图像
		typedef struct {
		uint8*  data; //源图片指针
		uint16  width;
		uint16	height;
		uint8   trans;//1:使用透明色;0:不使用
		} Image_s;*/
extern void mrc_jgraphics_drawImage(mrc_jImageSt * img, int x, int y, int anchor);

/*
函数名	：mrc_jgraphics_drawRegion
功能	：绘制图像
参数	：	src,					--图像	Image_s结构指针
			x_src, y_src,			--源图像
			width,height,			--源图像宽和高
			transform,				--翻转参数：
									TRANS_NONE_Sprite			不做变换
									TRANS_MIRROR_Sprite			镜像
									TRANS_ROT180_Sprite			旋转180
									TRANS_MIRROR_ROT180_Sprite	镜像旋转180
									TRANS_ROT90_Sprite 			旋转90
									TRANS_MIRROR_ROT90_Sprite 	镜像旋转90
									TRANS_ROT270_Sprite 		旋转270
									TRANS_MIRROR_ROT270_Sprite 	镜像旋转270
			x_dest,y_dest,			--屏幕上的位置
            anchor					--锚定参数（当前只支持为0（左上点））*/
extern void mrc_jgraphics_drawRegion(mrc_jImageSt * src, int x_src, int y_src, int width, int height, int transform, int x_dest, int y_dest, int anchor);




/*-----------------------------------------------------------------------------------------------
函数名	：mrc_jgraphics_drawLine
功能	：绘制直线
参数    ：	x1:当前坐标系下所要绘制直线一端的x坐标
			y1:当前坐标系下所要绘制直线一端的y坐标
			x2:当前坐标系下所要绘制直线另一端的x坐标
			y2:当前坐标系下所要绘制直线另一端的y坐标
*/
extern void mrc_jgraphics_drawLine(int x1, int y1, int x2, int y2);
/*
函数名	：mrc_jgraphics_fillRect
功能	：绘制填充矩形
*/
extern void mrc_jgraphics_fillRect(int x, int y, int width, int height);

/*
函数名	：mrc_jgraphics_drawRect
功能	：绘制矩形框
*/
extern void mrc_jgraphics_drawRect(int x, int y, int width, int height);

/*
函数名	：mrc_jgraphics_fillRoundRect
功能	：绘制圆角填充矩形（目前等同于fillRect_Graphics）
*/
extern void mrc_jgraphics_fillRoundRect(int x, int y, int width, int height, int arcWidth, int arcHeight);
/*
函数名	：mrc_jgraphics_drawRoundRect
功能	：绘制圆角矩形框（目前等同于drawRect_Graphics）
*/
extern void mrc_jgraphics_drawRoundRect(int x, int y, int width, int height, int arcWidth,int arcHeight);

/*
函数名	：mrc_jgraphics_drawArc
功能	：绘制圆
参数	：	x,y				外接矩形左上点坐标
			width，height	外接矩形宽，高
			startAngle      起始角度		（当前没有用）
			arcAngle		总共跨越的角度（当前没有用）*/
extern void mrc_jgraphics_drawArc(int x, int y, int width, int height, int startAngle, int arcAngle);

/*
函数名	：mrc_jgraphics_drawRoundRect
功能	：绘制填充扇形
参数	：	x,y				外接矩形左上点坐标
			width，height	外接矩形宽，高
			startAngle      起始角度（0，90，270，360）
			arcAngle		总共跨越的角度（180）*/				
extern void mrc_jgraphics_fillArc(int x, int y, int width, int height, int startAngle, int arcAngle);

/*
函数名	：mrc_jgraphics_drawRoundRect
功能	：绘制填充三角形
*/
extern void mrc_jgraphics_fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3);



#endif