#ifndef _MRC_IMAGE_H_
#define _MRC_IMAGE_H_

typedef struct
{
	char *src;
	int32 len;
	int32 src_type;// MRAPP_SRC_TYPE
}MRAPP_IMAGE_ORIGIN_T, *PMRAPP_IMAGE_ORIGIN_T;

typedef struct
{
	int32 width;    //ͼƬ�Ŀ��
	int32 height;   //ͼƬ�ĸ߶�
	int32 type;		//ͼƬ����
}MRAPP_IMAGE_WH, *PMRAPP_IMAGE_WH;

typedef struct
{
	char *src; //�ļ�����������������buf�ĵ�ַ��������ļ�������GB��ʽ
	int32 len; //src��ָ��buf�Ĵ�С
	int32 width;//�û�ͼƬ��ʾ������Ŀ��
	int32 height;//����ͼƬ��ʾ������ĸ߶�
	int32 src_type;// MRAPP_SRC_TYPE
	char *dest;//������ͼƬ���ݴ�ŵ�buf//rgb565 
}MRAPP_IMAGE_DECODE_T, *PMRAPP_IMAGE_DECODE_T;


typedef struct _MRAPP_GIF_FRAME_INFO
{
	int32 fwidth; //��֡�Ŀ��
	int32 fheight; //��֡�ĸ߶�
	int32 ox; //��֡���Ͻǵ�x����(����߼���Ļ)
	int32 oy; //��֡���Ͻǵ�y����(����߼���Ļ)
	int32 transparent_flag; //�Ƿ���Ҫ͸����ʾ
	int32 transparent_color; //͸����ʾ����ɫ
	int32 delay_time; //��֡��ʾ��ʱ��
	char *pdata; //��ѹ�õ�ͼƬ����
	struct _MRAPP_GIF_FRAME_INFO *next; //ָ����һ֡�����ݽṹ
}MRAPP_GIF_FRAME_INFO_T, *PMRAPP_GIF_FRAME_INFO_T;

typedef struct
{
	int32 id;
	int32 width; //gif�Ŀ��
	int32 height; //gif�ĸ߶�
	int bg_color; //gif�ı���ɫ
	int frame_count; //gif�ܵ�֡��
	MRAPP_GIF_FRAME_INFO_T *first; //ָ��gif�ĵ�һ֡�����ݽṹ
}MRAPP_GIF_HEADER, *PMRAPP_GIF_HEADER;

typedef enum
{
	SRC_NAME = 0,    //������ֲ�ӿ����ļ���(���ְ汾��֧��)
	SRC_STREAM   //������ֲ�ӿڵ���ͼƬ������
}MRAPP_SRC_TYPE;

typedef struct 
{
	char *src;//�ļ�����������������buf�ĵ�ַ��������ļ�������GB��ʽ
	int32 src_len; //src��ָ��buf�Ĵ�С
	int32 src_type;//// MRAPP_SRC_TYPE
	int32 ox;//rect
	int32 oy;
	int32 w;
	int32 h;
}T_DRAW_DIRECT_REQ, *PT_DRAW_DIRECT_REQ;

typedef struct 
{
	int32 p1;//gif�������
}T_DSM_COMMON_RSP, *PT_DSM_COMMON_RSP;


/*
��ȡͼƬ���
[in]PMRAPP_IMAGE_ORIGIN_T
[out]PMRAPP_IMAGE_WH ������͵Ľṹ��
code:
PMRAPP_IMAGE_WH p;

mrc_readFileFromMrpEx(NULL, "2.jpg", (uint8**)&input2.src, &input2.len, 0);
input2.src_type = SRC_STREAM;
mrc_getImageInfo(&input2, (uint8**)&p);


*/
int32 mrc_getImageInfo(PMRAPP_IMAGE_ORIGIN_T image, uint8** output);//PMRAPP_IMAGE_WH

/*
ֱ�ӵ���ƽ̨�ӿڽ�jpegͼƬ���Ƶ�ָ���ľ���������
[in] PT_DRAW_DIRECT_REQ
����ֵ��
MR_SUCCESS�� �ɹ�
MR_FAILED ��ʧ��

sample code:

T_DRAW_DIRECT_REQ input;

input.src_type = SRC_STREAM;
input.ox = 80;
input.oy = 80;
input.w = 80;
input.h = 80;
mrc_readFileFromMrpEx(NULL, "1.jpg", (uint8**)&input.src, &input.src_len, 0);
mrc_drawJpegToFrameBuffer(&input);
*/
int32 mrc_drawJpegToFrameBuffer(PT_DRAW_DIRECT_REQ input);


/*
��ʾgif�����Ľӿڣ�ֱ�ӻ��Ƶ�frame buffer�ϣ���ÿһ֡��������ʾҲ����mtk������.
����Ҫ��ʾʱ��Ҫ����mrc_stopGifֹͣ���š�
[in] PT_DRAW_DIRECT_REQ
[out] T_DSM_COMMON_RSP,gif�������
����ֵ��
MR_SUCCESS�� �ɹ�
MR_FAILED ��ʧ��

code:

PT_DSM_COMMON_RSP gp;
T_DRAW_DIRECT_REQ input1;
memset(&input1, 0, sizeof(T_DRAW_DIRECT_REQ));
input1.src_type = SRC_STREAM;

input1.ox = 120;
input1.oy = 60;
input1.w = 60;
input1.h = 60;
mrc_readFileFromMrpEx(NULL, "1.gif", (uint8**)&input1.src, &input1.src_len, 0);
mrc_drawGifToFrameBuffer(&input1, (uint8**)&gp);

*/
int32 mrc_drawGifToFrameBuffer(PT_DRAW_DIRECT_REQ input, uint8** output);

/*
ֹͣ���Ŷ���
[in] T_DSM_COMMON_RSP,gif�������
����ֵ��
MR_SUCCESS�� �ɹ�
MR_FAILED ��ʧ��

code:
PT_DSM_COMMON_RSP input;

mrc_stopGif(input);
*/
int32 mrc_stopGif(PT_DSM_COMMON_RSP input);

/*
����һ��GIFͼƬ��
[in] 
����ֵ��
MR_SUCCESS�� �ɹ�
MR_FAILED ��ʧ��

code:
mrc_readFileFromMrpEx(NULL, "1.gif", (uint8**)&test.src, &test.len, 0);
test.src_type = SRC_STREAM;
input2.src = test.src;
input2.len = test.len;
input2.src_type = SRC_STREAM;
ret = mrc_getImageInfo(&input2, (uint8**)&p);
mrc_printf("output.h is %d----output.w is %d", p->height, p->width);
mrc_printf("output.type is %d", p->type);
//pp = malloc(sizeof(uint16)*p->height*p->width);//����û��BUFFER��ȻҲOK��
//memset(pp, 0, sizeof(pp));
//test.dest = (char*)pp;
test.height = 90;
test.width = 90;
ret = mrc_decodeGifToBuffer(&test, (uint8**)&outl);

mrc_printf("mrc_decodeGifToBuffer ret is %d", ret);
mrc_bitmapShowEx((uint16*)outl->first->pdata, 0, 0, outl->first->fwidth, outl->first->fwidth,
	outl->first->fheight, BM_COPY, 0, 0);//����û��BUFFER��ȻҲOK��
mrc_releaseDecGifRes();
*/
int32 mrc_decodeGifToBuffer(PMRAPP_IMAGE_DECODE_T input, uint8** output);//PMRAPP_GIF_HEADER
/*
Ӧ��֪ͨ��ֲ�ͷ���ǰgif�����õ�����Դ��
[in] 
����ֵ��
MR_SUCCESS�� �ɹ�
MR_FAILED ��ʧ��

code:
	mrc_releaseDecGifRes();
*/
int32 mrc_releaseDecGifRes(void);


#endif