#ifndef _DRAWTEXT_H
#define _DRAWTEXT_H
#ifndef BOOL
typedef unsigned char BOOL;
#endif
typedef enum charset_e
{
	MR_SET_GB,				//BG�ַ���
	MR_SET_UNICODE		//UNICODE�ַ���
}E_CHR_SET;
/*
��	  �ܣ����Ƶ����ı�����Ӧ��SKY SDK mrc_drawText�ӿ�
����˵����
	      	  char*chr					��IN �ݶ����������ı�����
		  int16 x					��IN �ݶ����������ı�����ʼx���꣨�������Ļ����ԭ��(0,0)��
		  int16 y					��IN �ݶ����������ı�����ʼy���꣨�������Ļ����ԭ��(0,0)��
		  mr_colourSt  colorst      		��IN �ݶ����������ı����ɫֵ�����mr_colourSt����
		  E_CHRSET flag			��IN �ݶ�Ӧ��E_CHRSETö���壬ȡֵΪSET_GB,MR_SET_UNICODE�������������ı����ַ�������
		  uint16 font				��IN �ݶ�Ӧ�� SKY SDK MR_FONT_TYPEö���壬ȡֵΪMR_FONT_BIG, MR_FONT_MEDIUM, MR_FONT_SMALL
����ֵ:
		MR_SUCCESS  ���Ƴɹ�
		MR_FAILED   ����ʧ��
*/
int32 _drawText(char* chr, int16 x, int16 y,  mr_colourSt colorst,E_CHR_SET flag,  uint16 font);
/*
��	  �ܣ����Ƶ����ַ�
����˵����
	      	  char*chr					��IN �ݶ����������ı�����
		  int16 x					��IN �ݶ����������ı�����ʼx���꣨�������Ļ����ԭ��(0,0)��
		  int16 y					��IN �ݶ����������ı�����ʼy���꣨�������Ļ����ԭ��(0,0)��
		  mr_colourSt  colorst      		��IN �ݶ����������ı����ɫֵ�����mr_colourSt����
		  E_CHRSET flag			��IN �ݶ�Ӧ��E_CHRSETö���壬ȡֵΪSET_GB,MR_SET_UNICODE�������������ı����ַ�������
		  uint16 font				��IN �ݶ�Ӧ�� SKY SDK MR_FONT_TYPEö���壬ȡֵΪMR_FONT_BIG, MR_FONT_MEDIUM, MR_FONT_SMALL
����ֵ:
		MR_SUCCESS  ���Ƴɹ�
		MR_FAILED   ����ʧ��
*/
int32 _drawChar(char* chr, int16 x, int16 y, mr_colourSt colorst,E_CHR_SET flag,  uint16 font);
/*
��	  �ܣ�����ָ�����ı�����������ʾ������ָ���ľ����������Զ�����
����˵����
	      	  char*chr					��IN �ݶ����������ı�����
		  int16 x					��IN �ݶ����������ı�����ʼx���꣨�������Ļ����ԭ��(0,0)��
		  int16 y					��IN �ݶ����������ı�����ʼy���꣨�������Ļ����ԭ��(0,0)��
		  mr_screenRectSt  rect              ��IN �ݶ����������ı�����ʾ�������mr_screenRectSt����
		  mr_colourSt  colorst      		��IN �ݶ����������ı����ɫֵ�����mr_colourSt����
		  E_CHRSET flag			��IN �ݶ�Ӧ��E_CHRSETö���壬ȡֵΪSET_GB,MR_SET_UNICODE�������������ı����ַ�������
		  uint16 font				��IN �ݶ�Ӧ�� SKY SDK MR_FONT_TYPEö���壬ȡֵΪMR_FONT_BIG, MR_FONT_MEDIUM, MR_FONT_SMALL
����ֵ:
		MR_SUCCESS  ���Ƴɹ�
		MR_FAILED   ����ʧ��
*/
int32 _drawTextLeft(char* pcText, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, E_CHR_SET flag, uint16 font);
int32 _drawTextLeftByLineN(char* pcText, int16 x, int16 y, mr_screenRectSt rect, mr_colourSt colorst, E_CHR_SET flag, uint16 font, int32 lineStart);
/*
��	  �ܣ���ȡ�ַ�����ָ�������еĿ���ֵ
����˵����
	      	  char*pcText				��IN �ݶ����ı�����
		  int32 width				��OUT���ַ����Ŀ�ȣ����м�
		  int32 height				��OUT ���ַ����ĸ߶�
		  mr_screenRectSt  rect              ��IN �� �����������ı�����ʾ�������mr_screenRectSt����
		  mr_colourSt  colorst      		��IN �ݶ����������ı����ɫֵ�����mr_colourSt����
		  E_CHRSET flag			��IN �ݶ�Ӧ��E_CHRSETö���壬ȡֵΪSET_GB,MR_SET_UNICODE�������������ı����ַ�������
		  uint16 font				��IN �ݶ�Ӧ�� SKY SDK MR_FONT_TYPEö���壬ȡֵΪMR_FONT_BIG, MR_FONT_MEDIUM, MR_FONT_SMALL
����ֵ:
		MR_SUCCESS  ���Ƴɹ�
		MR_FAILED   ����ʧ��
*/
int32 _textWidthHeight(char *pcText,int32 *width,int32 *height,E_CHR_SET flag, uint16 font);
int32 _textWidthHeightLine(char *pcText,int32 *width,int32 *height,int32 *lines,E_CHR_SET flag, uint16 font, int32 linewidth);
/*
��	  �ܣ���Ϸ�Դ�����ģ���ʼ��������mrc_init�е��á�
����˵����
	      	  BOOL isBigFontSupport					��IN ���Դ��ֿ��Ƿ����BIG�ֿ� ����Ӧ��PC����MR_FONT_BIGѡ ��
		  BOOL isMediumFontSupport				��IN�� �Դ��ֿ��Ƿ����MEDIUM�ֿ�  ����Ӧ��PC����MR_FONT_MEDIUMѡ ��
		  BOOL isSmallFontSupport				��IN ���Դ��ֿ��Ƿ����SMALL�ֿ�  ����Ӧ��PC����MR_FONT_SMALLѡ ��
����ֵ:
		MR_SUCCESS  ��ʼ���ɹ�
		MR_FAILED   ��ʼ��ʧ��
*/
int32 FontModuleInit(BOOL isBigFontSupport, BOOL isMediumFontSupport, BOOL isSmallFontSupport);
/*
��	  �ܣ���Ϸ�Դ�����ģ����Դ�ͷţ��������mrc_exitApp�е��á�
����˵����
	         ��
����ֵ:
		��
*/
void FontModuleRelease(void);
#endif
