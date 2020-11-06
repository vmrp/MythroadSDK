#ifndef _mrc_bmpH_
#define _mrc_bmpH_

//�����þɵ�MyThroad��ʽʱ����Ҫ���������еı��뿪�ء�
//#define MR_OLD

#ifdef MR_OLD
#include "cfunction.h"
#endif

/* Bitmap header */
typedef struct _mrc_bmpHeader
{
	uint16		Magic;				/* Magic identifier: "BM" */
	uint32		FileSize;			/* Size of the BMP file in bytes */
	uint16		Reserved1;			/* Reserved */
	uint16		Reserved2;			/* Reserved */
	uint32		DataOffset;			/* Offset of image data relative to the file's start */
	uint32		HeaderSize;			/* Size of the header in bytes */
	uint32		Width;				/* Bitmap's width */
	uint32		Height;				/* Bitmap's height */
	uint16		Planes;				/* Number of color planes in the bitmap */
	uint16		BitsPerPixel;		/* Number of bits per pixel */
	uint32		CompressionType;	/* Compression type */
	uint32		ImageDataSize;		/* Size of uncompressed image's data */
	uint32		HPixelsPerMeter;	/* Horizontal resolution (pixels per meter) */
	uint32		VPixelsPerMeter;	/* Vertical resolution (pixels per meter) */
	uint32		ColorsUsed;			/* Number of color indexes in the color table that are actually used by the bitmap */
	uint32		ColorsRequired;		/* Number of color indexes that are required for displaying the bitmap */
} mrc_bmpHeader;//����ԱӦ��ͨ����װ�ĺ�������BMP���ݡ�


/* Private data structure */
struct _BMP
{
	mrc_bmpHeader	Header;
	uint8*		Palette;
	uint8*		Data;
	uint32		      PaletteType;    // 0:no need free;1:need free;
	uint32		      DataType;    // 0:no need free;1:need free;
	uint8*	MrpBuffer;//20071126�Ϊ��ʵ��mrc_bmpLoadFromMrp�����ӵ�
	//�ֶΣ�ʹ�ñ�������BMPλͼ��ʽ�淶��_BMPͷ���ٷ��Ϲ淶����ˣ�
	//���������BMPͷ�����ĵط�������ʹ��sizeof(_BMP)��memcpy֮�࣬��Ҫ
	//��Ҫ�ر�ע�⡣
};



/* Bitmap image */
typedef  struct _BMP BMP;

/* Error codes */
typedef enum
{
	mrc_bmpOK = 0,				/* No error */
	mrc_bmpERROR,				/* General error */
	mrc_bmpOUT_OF_MEMORY,		/* Could not allocate enough memory to complete the operation */
	mrc_bmpIO_ERROR,			/* General input/output error */
	mrc_bmpFILE_NOT_FOUND,		/* File not found */
	mrc_bmpFILE_NOT_SUPPORTED,	/* File is not a supported BMP variant */
	mrc_bmpFILE_INVALID,		/* File is not a BMP image or is an invalid BMP */
	mrc_bmpINVALID_ARGUMENT,	/* An argument is invalid or out of range */
	mrc_bmpTYPE_MISMATCH,		/* The requested action is not compatible with the BMP's type */
	mrc_bmpERROR_NUM
} mrc_bmpSTATUS;


/*********************************** Public methods **********************************/


/* Construction/destruction */
BMP*		mrc_bmpCreate( uint32 width, uint32 height, uint16 depth );
void			mrc_bmpFree( BMP* bmp );


/* I/O */
//�Ӵ����ж�ȡ256ɫbmp�ļ�������256ɫλͼ�����
//���������ʹ��ʱ����Ҫ����mrc_bmpFree�ͷ��ڴ档
BMP*			mrc_bmpLoadFromFile				( char* filename );
//�ӻ������ж�ȡ256ɫbmp�ļ�������256ɫλͼ�����
//���������ʹ��ʱ����Ҫ�ȵ���mrc_bmpFree�ͷ��ڴ档
//Buffer���ڴ�ռ��Ƿ���Ҫ�ͷţ��ɳ���Ա����Buffer����Դȷ����
BMP* 			mrc_bmpLoadFromBuffer( uint8* buf, int32 len );
//��mrp�ļ�����ȡ256ɫbmp�ļ�������256ɫλͼ�����
//���������ʹ��ʱ����Ҫ�ȵ���mrc_bmpFree�ͷ��ڴ档
BMP*			mrc_bmpLoadFromMrp				( char* filename );
void				mrc_bmpWriteFile				( BMP* bmp, char* filename );


/* Meta info */
uint32			mrc_bmpGetWidth				( BMP* bmp );
uint32			mrc_bmpGetHeight				( BMP* bmp );
uint16			mrc_bmpGetDepth				( BMP* bmp );


/* Pixel access */
void			mrc_bmpGetPixelRGB				( BMP* bmp, uint32 x, uint32 y, uint8* r, uint8* g, uint8* b );
void			mrc_bmpSetPixelRGB				( BMP* bmp, uint32 x, uint32 y, uint8 r, uint8 g, uint8 b );//��������16ɫ��256ɫ����������λͼ��ʽ�С�
void			mrc_bmpGetPixelIndex			( BMP* bmp, uint32 x, uint32 y, uint8* val );
void			mrc_bmpSetPixelIndex			( BMP* bmp, uint32 x, uint32 y, uint8 val );


/* Palette handling */
/*
��ȡ��ɫ����ɫ����
����:ͼƬ�����
���:ͼƬ��ɫ��ɫ������������16ɫ��256ɫλͼ���򷵻�0��
��16ɫ��256ɫλͼ��ɫ��������16��256���򷵻ؾ��ͷ��ColorUsed��ֵ��
*/
uint32 mrc_bmpGetColorUsed( BMP* bmp);
void			mrc_bmpGetPaletteColor			( BMP* bmp, uint8 index, uint8* r, uint8* g, uint8* b );
void			mrc_bmpSetPaletteColor			( BMP* bmp, uint8 index, uint8 r, uint8 g, uint8 b );

/*
��ȡָ����Ļ����������Ϣ��
����
di:Ŀ����Ļ��������ţ�
���:
bitmapInfoĿ����Ļ��������Ϣ��
����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��

*/
int32 mrc_bitmapGetInfo(uint32 di,mr_bitmapSt *bitmapInfo);


/*
����ָ����Ļ����������Ϣ��
����
di:Ŀ����Ļ��������ţ�
bitmapInfo:�����õ���Ļ������������
����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
      
����:
1������mrc_bitmapSetInfoǰ���������mrc_bitmapGetInfo�����ֵ��
2����ʹ����Ϻ󣬱���ָ���ֵ��
3������Ļ�����в������������á�

*/
int32 mrc_bitmapSetInfo(uint32 di,mr_bitmapSt *bitmapInfo);


//ȡ��Ļ���������ڴ��ַ
uint16 * w_getScreenBuffer(void);
//������Ļ���������ڴ��ַ
void w_setScreenBuffer(uint16 *ptr);
//��ȡ��Ļ���������
void mrc_getScreenSize(int32 *w,int32 *h);
//������Ļ���������
void mrc_setScreenSize(int32 w, int32 h);

//��λͼ��y��sx�п�ʼ��w�����ظ��Ƶ�Ŀ��row��
//��ʹ��256ɫλͼʱ����Palette!=NULL�����Palette�л��16bit����ɫ���Ӷ��������ܡ�
//���������Palette��������ΪNULL��
void mrc_bmpGet16BitLineFrom8BitData( BMP* bmp, int32 y, int32 sx, int32 w, uint16* row,uint16 * Palette);

/*
��hBMPָ���windows bmp 256ɫ��16ɫ��ʽ��ͼƬ����(sx, sy)��ʼ��
���Ϊw, h�����򣬻��Ƶ�ͼƬ����di��(x, y)��ʼ�ĵط���

����:
di               Ŀ��ͼƬ�������
hBMP        ָ�򱣴�windows bmp 256ɫ��ʽ��ͼƬ���ڴ�
x,y           windows bmp 256ɫ��16ɫBMPͼƬ�����
w,h             ����������Ŀ��

sx,sy          ������������ԴͼƬ����ʼλ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bmpBufferDraw(uint16 di, BMP*hBMP, int32 x, int32 y, int32 w, int32 h, uint16 rop,int32 sx, int32 sy);

//mrc_bmpBufferDrawEX����mrc_bmpLoadFromBuffer���ٵ���mrc_bmpBufferDraw��mrc_bmpFree()������ʵ���������ޡ�
int32 mrc_bmpBufferDrawEX(uint16 di,uint8* buf,  int32 len, int32 x, int32 y,int32 w, int32 h,uint16 rop, int32 sx, int32 sy);

/*
	�����ΪhBMP��256ɫ��16ɫbmp�����е�ͼƬ���ӻ�����ͼƬ��(sx, sy)
	��ʼ�Ŀ��Ϊw, h�����򣬻��Ƶ�(x, y)��ʼ����Ļ�����С�

����:
p        ԴͼƬָ��
x,y              ��Ļλ��
rop              ѡ�����£�
   BM_OR,         			//SRC .OR. DST*   ��͸��Ч��
   BM_XOR,        			//SRC .XOR. DST*
   BM_COPY,       		//DST = SRC*      ����
   BM_NOT,        			//DST = (!SRC)*
   BM_MERGENOT,   	//DST .OR. (!SRC)
   BM_ANDNOT,     		//DST .AND. (!SRC)
   BM_TRANSPARENT,//͸��ɫ����ʾ��ͼƬ�ĵ�һ�����أ����Ͻ�����Ϊ(0,0)�����أ���͸��ɫ
   BM_AND,        			//DST AND SRC
   BM_GRAY,        		//�ҶȻ�ͼ�� �൱��BM_TRANSPARENT���ҶȻ�ͼ��
                              DST�Ҷ� �� 30%R + 59%G + 11%BͼƬ���
   BM_REVERSE     		//�����ͼ���൱��BM_TRANSPARENT�������ͼ��V1939��

sx,sy              ԴͼƬ����ʼλ��
w,h             ������ͼƬ�Ŀ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bmpShow(BMP* hBMP,
   int16 x,
   int16 y,
   int16 w,
   int16 h,
   uint16 rop,
   int16 sx,
   int16 sy
);

//mrc_bmpShowExʵ�������ȵ���mrc_bmpLoadFromBuffer���BMP�����
//Ȼ�����mrc_bmpShow��������mrc_bmpFree�ͷž����
int32 mrc_bmpShowEx(uint8 *buffer,
   int16 x,
   int16 y,
   int16 w,
   int16 h,
   uint16 rop,
   int16 sx,
   int16 sy
);



mrc_bmpSTATUS mrc_bmpGetError(void);
/* Useful macro that may be used after each BMP operation to check for an error */
#define mrc_bmpCHECK_ERROR( output_file, return_value ) \
	if ( mrc_bmpGetError() != mrc_bmpOK )													\
	{																				\
		fprintf( ( output_file ), "BMP error: %s\n", mrc_bmpGetErrorDescription() );	\
		return( return_value );														\
	}																				\

   /*�����MAKERGB��MRƽ̨�ڲ���*/
#ifdef MR_ANYKA_MOD
#define MAKERGB(r, g, b)     (uint32) ( ((uint32)r<<16) | ((uint32)g << 8) | ((uint32)b) )
#else
#define MAKERGB(r, g, b)     (uint16) ( ((uint32)(r>>3) << 11) + ((uint32)(g>>2) << 5) + ((uint32)(b>>3)) )
#endif

/*************************will be delete************************************/


/*
��buf��len�е�windows bmp 256ɫ��ʽ��ͼƬ����(sx, sy)��ʼ��
���Ϊw, h�����򣬻��Ƶ�ͼƬ����di��(x, y)��ʼ�ĵط���

����:
di               Ŀ��ͼƬ�������
buf,len        ָ�򱣴�windows bmp 256ɫ��ʽ��ͼƬ���ڴ�
w,h             ����������Ŀ��
x,y             ��������������Ļ�ϵ���ʼλ��
sx,sy          ������������ԴͼƬ����ʼλ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bmpBufferDrawOld(uint16 di, uint8* buf,  int32 len, int32 x, int32 y, int32 w, int32 h, int32 sx, int32 sy);

/*
��mrp����Ϊfilename��windows bmp 256ɫ��ʽ��ͼƬ����(sx, sy)��
ʼ�Ŀ��Ϊw, h�����򣬻��Ƶ���Ļ��(x, y)��ʼ�ĵط���

��mythroad�����У���Ϊ"*.bmp"���ļ�������Ϊ16Bit��24Bitɫ��
windows bmp��ʽ�����Ըýӿ�ʹ�õ�ͼƬ�ļ�������Ҫ��
��׺�޸�Ϊ��"*.bmp"����������޸�Ϊ"*.bm"��


����:
filename     �ļ���
w,h             ����������Ŀ��
x,y             ��������������Ļ�ϵ���ʼλ��
sx,sy          ������������ԴͼƬ����ʼλ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bmpShowOld(char* filename, int32 x, int32 y, int32 w, int32 h, int32 sx, int32 sy);


/*************************above will be delete************************************/



/* ͼƬ��ʽ*/
typedef enum
{
	MRC_IMG_GIF = 0,
	MRC_IMG_JPG
} MRC_IMG_TYPE;


/*
��������:
	��������ʽ��ͼƬתΪ16bitBMP��

����:
*pImg    	 ͼƬ��ԭʼ���ݣ�
ImgSize   ͼƬ���ֽ�����
ImgType	ͼƬ��ʽ:

**bmp	���ڴ�Ž���õ���ͼƬ�Ļ�����ָ�롣��������SDK���䣬
	���û������ͷš�
*w 	����õ���ͼƬ�����������
*h 	����õ���ͼƬ�ߵ���������

GIFͼƬתBMPʱ����GIFͼƬ�ĵ�һ֡ת��Ϊ16bitBMP��
����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
      
 ��ע:
 	�ú���Ŀǰģ�������в�֧�֡�      
*/
int32 mrc_Img2bmp(uint8 *pImg,int32 ImgSize,MRC_IMG_TYPE ImgType,uint16 **bmp,int32 *w,int32 *h);

int32 mrc_PrintScreen(char *filename);

#define FLIP_NONE	0x0000
#define	FLIP_HORI	0x0100
#define FLIP_VERT	0x0200


int32 bitmapShowFlip(uint16* p, int16 x, int16 y, uint16 mw, uint16 w, uint16 h, uint16 rop, 
		int16 sx, int16 sy, uint16 transcolor);


#define TRANS_NONE					0x0000
#define TRANS_ROT90					0x0100
#define TRANS_ROT180				0x0200
#define TRANS_ROT270				0x0300
#define TRANS_MIRROR				0x0400
#define TRANS_MIRROR_ROT90		0x0500
#define TRANS_MIRROR_ROT180		0x0600
#define TRANS_MIRROR_ROT270		0x0700

/*
ropȡֵ:
1��TRANS_NONE�� û�н���ת���ͷ�ת�� 
2��TRANS_ROT90�� 90��ת���� 
3��TRANS_ROT180�� 180��ת���� 
4��TRANS_ROT270�� 270��ת���� 
5��TRANS_MIRROR�� ���ҷ�ת�� 
6��TRANS_MIRROR_ROT90�� ���ҷ�ת��90��ת���� 
7��TRANS_MIRROR_ROT180�� ���ҷ�ת��180��ת���� 
8��TRANS_MIRROR_ROT270�� ���ҷ�ת��270��ת���� 
����:
p        ԴͼƬָ��
x,y     ��Ļ	��ʾλ��
mw		ͼƬ��ԭʼ��ȣ���������ȡ�
rop : (BM_TRANSPARENT ��BM_COPY�������������ģʽĬ��BM_COPY����) | (TRANS_NONE��TRANS_MIRROR_ROT270,����
		������mrc_bitmapshowEx��ͬ)
sx,sy           ԴͼƬ����ʼλ��
w,h             ������ͼƬ�Ŀ��
transcolor : ͸��ɫ (16bit),������MAKERGB�꽫(r,g,b)ת��Ϊ16bit�ĸ�ʽ��

����:
      MR_SUCCESS     �ɹ�
      MR_FAILED         ʧ��
*/
int32 mrc_bitmapShowFlip(uint16* p, int16 x, int16 y, uint16 mw, uint16 w, uint16 h, uint16 rop, 
		int16 sx, int16 sy, uint16 transcolor);
#endif
