#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_aux.h"
#include "..\..\modules\mrc_bmp.h"


/*
������ȫ�ֱ���������
��mythroadƽ̨�£�ȫ�ֱ��������ڶ����ʱ���ʼ��
���磬���µ�ȫ�ֱ������巽ʽ�ǲ�֧�ֵ�:
int32 main_menu = 0;
��ȫ�ֱ�����ʹ�ù���ͬ�������ھ�̬�ֲ�������
*/

//������˵����
int32 main_menu;
int32 draw_WinHandle;

/*
Ӧ�õ�ˢ�º���
*/
static void white_refresh(int32 data);
void main_ShowMenu(void);

//ˢ����Ļ
static void white_refresh(int32 data)
{
	mrc_refreshScreen(0, 0, 240, 320);
	return;
}

void Test_BMP16bit_back(int32 data)
{
	mrc_winClose();
	return;
}

void Test_BMP256_back(int32 data)
{
	mrc_winClose();
	return;
}

void Test_BMP16_back(int32 data)
{
	mrc_winClose();
	return;
}


//��Ϸ�����µ��¼�������
static void KeyHandler_BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }       
   	}

}

//��Ϸ�����µ��¼�������
static void KeyHandler_BMP256(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }       
   	}

}

//��Ϸ�����µ��¼�������
static void KeyHandler_BMP16(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }       
   	}
}

//��Ϸ�����µ��¼�������
static void KeyHandler_gif2BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }       
   	}

}

//��Ϸ�����µ��¼�������
static void KeyHandler_Img2BMP16bit(int32 data, int32 type,int32 p1,int32 p2)
{
   //���ڱ������ǰ״̬����ʱ�������
   //DBG_PRINTF(("(type,p1,p2)=(%d,%d,%d)", type, p1, p2));
   //DBG_PRINTF(("type=%d, p1=%d, p2=%d", type, p1, p2));
   if(type == MR_KEY_RELEASE)
   	{
      switch(p1)
      {
         case MR_KEY_SOFTRIGHT:
			mrc_winClose();
			mrc_winWinEvent(WIN_EVENT_REFRESH);
         	break;
         default:
            break;
      }       
   	}

}


//��Ϸ���洰���¼�����
static void WinHandler_BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//��Ϸ���洰���¼�����
static void WinHandler_BMP256(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP256(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}


//��Ϸ���洰���¼�����
static void WinHandler_BMP16(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_BMP16(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//��Ϸ���洰���¼�����
static void WinHandler_gif2BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_gif2BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

//��Ϸ���洰���¼�����
static void WinHandler_Img2BMP16bit(int32 data,int32 eventId)
{
   mrc_printf("data=%d, eventId=%d", data, eventId);
   switch(eventId)
   {
   	case WIN_EVENT_SHOW:
   	{
           WinHandler_Img2BMP16bit(data, WIN_EVENT_REFRESH);
   		break;
   	}
   	case WIN_EVENT_PAUSE:
   		break;
   	case WIN_EVENT_REFRESH:
           //ˢ����Ļ��
           white_refresh(data);
   		break;
   	case WIN_EVENT_EXIT:
   		break;
   	default:
   		break;
   }
}

void Test_BMP16bit(int32 data)
{
	int32 ret;
	char retbuf[64];		
	int32 fontWidth,fontHeight;	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP16bit, KeyHandler_BMP16bit);
   mrc_clearScreen(128, 128, 128);
   
   //��MRP�ж�ȡ����ʾ��
   ret=mrc_bitmapLoad(0,"fullscreen24bit.bmp", 0, 0, 240, 320,240);
   if(ret==MR_FAILED)
   		return;
   ret=mrc_getUptime();
	mrc_bitmapShow(0, 0, 0,BM_COPY,0,0,240,320);   
	ret=mrc_getUptime()-ret;
	mrc_printf("mrc_bitmapShow used %d ms",ret);
	
	ret=mrc_textWidthHeight("��",0,MR_FONT_SMALL,&fontWidth,&fontHeight);   
	mrc_sprintf(retbuf,"����߶�%d�����%d",fontHeight,fontWidth);
	mrc_drawText(retbuf,0,210,200,100,100,0,MR_FONT_BIG);		  
	
	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
    ret=mrc_bitmapLoad(0,"*", 0, 0, 240, 320,240);//�ͷſռ䡣
	return;
}




void Test_BMP256(int32 data)
{
	BMP *hBMP256;
	int32 ret;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP256, KeyHandler_BMP256);
   mrc_clearScreen(128, 128, 128);


   //��MRP�ж�ȡ����ʾ��
   hBMP256=mrc_bmpLoadFromFile("fullscreen256.bmp256");
   if(hBMP256==NULL)
   		return;
   mrc_printf("mrc_bmpLoadFromMrp  Success!");
   ret=mrc_getUptime();
	mrc_bmpShow(hBMP256,0,0,240,320,BM_COPY,0,0);
	ret=mrc_getUptime()-ret;
	mrc_printf("mrc_bmpShow used %d ms",ret);
   mrc_winWinEvent(WIN_EVENT_REFRESH);
   return;
   
   //ֱ�ӴӴ����ļ��ж�ȡ����ʾ��
   hBMP256=mrc_bmpLoadFromFile("test.bmp256");
	mrc_bmpShow(hBMP256,0,0,64,64,BM_OR,0,0);
	//white_refresh(data);
	//return;
	mrc_bmpShow(hBMP256,64,0,64,64,BM_XOR,0,0);
	mrc_bmpShow(hBMP256,128,0,64,64,BM_COPY,0,0);

	mrc_bmpShow(hBMP256,0,64,64,64,BM_NOT,0,0);
	mrc_bmpShow(hBMP256,64,64,64,64,BM_MERGENOT,0,0);
	mrc_bmpShow(hBMP256,128,64,64,64,BM_ANDNOT,0,0);

	mrc_bmpShow(hBMP256,0,128,64,64,BM_TRANSPARENT,0,0);
	mrc_bmpShow(hBMP256,64,128,64,64,BM_AND,0,0);
	mrc_bmpShow(hBMP256,128,128,64,64,BM_GRAY,0,0);

	mrc_bmpShow(hBMP256,0,192,64,64,BM_REVERSE,0,0);
   
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}


void Test_BMP16(int32 data)
{
	uint8 index,r,g,b,index2,r2,g2,b2;
	uint32 row,col;
	BMP *hBMP,*hBMP2;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_BMP16, KeyHandler_BMP16);
   mrc_clearScreen(128, 128, 128);

   //�Ӵ����ļ��ж�ȡ
	hBMP=mrc_bmpLoadFromFile("test.bmp16");

	//������ʾ����
	mrc_bmpShow(hBMP,0,0,64,64,BM_OR,0,0);
	mrc_bmpShow(hBMP,64,0,64,64,BM_XOR,0,0);
	mrc_bmpShow(hBMP,128,0,64,64,BM_COPY,0,0);

	mrc_bmpShow(hBMP,0,64,64,64,BM_NOT,0,0);
	mrc_bmpShow(hBMP,64,64,64,64,BM_MERGENOT,0,0);
	mrc_bmpShow(hBMP,128,64,64,64,BM_ANDNOT,0,0);

	mrc_bmpShow(hBMP,0,128,64,64,BM_TRANSPARENT,0,0);
	mrc_bmpShow(hBMP,64,128,64,64,BM_AND,0,0);
	mrc_bmpShow(hBMP,128,128,64,64,BM_GRAY,0,0);

	mrc_bmpShow(hBMP,0,192,64,64,BM_REVERSE,0,0);
	mrc_bmpFree(hBMP);
	hBMP=NULL;
	

	//�������BMP�����Լ�д�ļ����ܡ�
   //��MRP�ж�ȡ
	hBMP=mrc_bmpLoadFromFile("test.bmp16");	
	hBMP2=mrc_bmpCreate(mrc_bmpGetWidth(hBMP),mrc_bmpGetHeight(hBMP),mrc_bmpGetDepth(hBMP));
	for(index=0;index<mrc_bmpGetColorUsed(hBMP);index++)
	{
		mrc_bmpGetPaletteColor(hBMP, index, &r,&g,&b);
		mrc_bmpSetPaletteColor(hBMP2, index,r,g,b);
		mrc_bmpGetPaletteColor(hBMP2, index, &r2,&g2,&b2);
		if(r2!=r ||g2!=g||b2!=b)
		{
			return;//something wrong
		}
	}	


	for(row=0;row<mrc_bmpGetHeight(hBMP2);row++)
	{
		for(col=0;col<mrc_bmpGetWidth(hBMP2);col++)
			{
				mrc_bmpGetPixelIndex(hBMP, col,row, &index);
				mrc_bmpSetPixelIndex(hBMP2, col,row, index);				
				mrc_bmpGetPixelIndex(hBMP2, col,row, &index2);
				if(index2!=index)
				{
				
					return;//something wrong
				}				
			}
	}
	mrc_bmpWriteFile(hBMP2,"testcopy.bmp16");
	mrc_bmpShow(hBMP2,0,256,64,64,256,0,0);
	mrc_bmpFree(hBMP);
	mrc_bmpFree(hBMP2);
	hBMP=NULL;
	hBMP2=NULL;
	hBMP2=mrc_bmpLoadFromFile("testcopy.bmp16");	
	mrc_bmpShow(hBMP2,64,256,64,64,255,0,0);
	mrc_bmpFree(hBMP2);
	hBMP2=NULL;
	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

void Test_gif2BMP16bit(int32 data)
{
	int32 ret,gifsize,gif_width,gif_height;
	uint8 *gif=NULL;
	uint16 *bmp=NULL;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_gif2BMP16bit, KeyHandler_gif2BMP16bit);
   mrc_clearScreen(128, 128, 128);

	ret=mrc_readFileFromMrpEx(NULL,"gx_af_enemi_5.gif",&gif,&gifsize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx ���سɹ�");
	if(gif)
	{
		//mrc_gif2bmp(gif,gifsize,&bmp,&gif_width,&gif_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx ����NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,0,gif_width,gif_width,gif_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");
	mrc_printf("now mrc_free(gif)");
   mrc_free(gif);
   	mrc_printf("now mrc_free(bmp)");
	mrc_free(bmp);
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

void Test_Img2BMP16bit(int32 data)
{
	int32 ret,ImgSize,Img_width,Img_height;
	uint8 *Img=NULL;//��mrc_readFileFromMrpEx�������ռ�
	uint16 *bmp=NULL;//��mrc_Img2bmp���롢����ռ䡣
	mr_screenRectSt TextRect;
	mr_colourSt TextColor;
	
   draw_WinHandle=mrc_platWinNew(0, WinHandler_Img2BMP16bit, KeyHandler_Img2BMP16bit);
   mrc_clearScreen(128, 128, 128);

	ret=mrc_readFileFromMrpEx(NULL,"gx_af_enemi_5.gif",&Img,&ImgSize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx ���سɹ�");
	if(Img)
	{
	//	mrc_Img2bmp(Img,ImgSize,MRC_IMG_GIF,&bmp,&Img_width,&Img_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx ����NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,0,Img_width,Img_width,Img_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");	
	if(Img)
	{
		mrc_printf("now mrc_free(Img)");
   		mrc_free(Img);
   		Img=NULL;
	}
	if(bmp)
	{
		mrc_printf("now mrc_free(bmp)");
		mrc_free(bmp);
		bmp=NULL;
	}



	ret=mrc_readFileFromMrpEx(NULL,"tree.jpg",&Img,&ImgSize, 0);
	if(ret==MR_FAILED)
		return;
	else
		mrc_printf("mrc_readFileFromMrpEx ���سɹ�");
	if(Img)
	{
	//	mrc_Img2bmp(Img,ImgSize,MRC_IMG_JPG,&bmp,&Img_width,&Img_height);
	}
	else
		mrc_printf("mrc_readFileFromMrpEx ����NULL");
	if(bmp)
		mrc_bitmapShowEx(bmp,0,100,Img_width,Img_width,Img_height,BM_COPY,0,0);
	else
		mrc_printf("bmp==NULL");
	TextColor.r=3;
	TextColor.g=3;
	TextColor.b=253;
	TextRect.x=20;
	TextRect.y=120;
	TextRect.w=60;
	TextRect.h=60;
	mrc_drawTextEx("tree.jpg",20,120,TextRect,TextColor,2,MR_FONT_BIG);
	if(Img)
	{
		mrc_printf("now mrc_free(Img)");
   		mrc_free(Img);
   		Img=NULL;
	}
	if(bmp)
	{
		mrc_printf("now mrc_free(bmp)");
		mrc_free(bmp);
		bmp=NULL;
	}	
   mrc_winWinEvent(WIN_EVENT_REFRESH);
	return;
}

//���˵����˳�Ӧ��
void main_exit(int32 data){
   mrc_winClose();
}

void main_ShowMenu(void)
{
	mrc_printf("Hello! It's Graphy Demo!");
	main_menu = mrc_platMenuNew("\x0\x32\x0\x35\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6",6);             // 256ɫλͼ��ʾ
	if (main_menu != MR_FAILED)
	{
	   mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x0\x62\x0\x69\x0\x74\x4f\x4d\x56\xfe\x59\x4\x74\x6", 0, Test_BMP16bit, 0);   // 256ɫλͼ��ʾ 	
	   mrc_platMenuSetItem(main_menu, "\x0\x32\x0\x35\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6", 1, Test_BMP256, 0);   // 256ɫλͼ��ʾ 
	   mrc_platMenuSetItem(main_menu, "\x0\x31\x0\x36\x82\x72\x4f\x4d\x56\xfe\x59\x4\x74\x6", 2, Test_BMP16, 0);   // 16ɫλͼ��ʾ 	   
	   mrc_platMenuSetItem(main_menu, "\x0\x47\x0\x49\x0\x46\x8f\x6c\x4f\x4d\x56\xfe\x59\x4\x74\x6", 3, Test_gif2BMP16bit, 0);   // gifת16bitBMPλͼ��ʾ 	   	   
	   mrc_platMenuSetItem(main_menu, "\x0\x4a\x0\x50\x0\x47\x8f\x6c\x4f\x4d\x56\xfe\x59\x4\x74\x6", 4, Test_Img2BMP16bit, 0);   // JPGת16bitBMPλͼ��ʾ 	   	   	   
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 5, main_exit, 0);   // ������ؼ����˳���ʾ         	   
	   mrc_platMenuSetItem(main_menu, "\x90\x0\x51\xfa\x6f\x14\x79\x3a", 6, main_exit, 0);   // ������ؼ����˳���ʾ         	   
	   mrc_platMenuShow(main_menu);	   
	}
	else
	{
	   return;
	}
	return;
}





/*
Ӧ�ó�ʼ������
�ú�����Ӧ�ó�ʼ���ڼ䱻mythroadƽ̨���ã����������
�����н���ȫ�ֱ����ĳ�ʼ���ȹ�����
����ֵ:
MR_SUCCESS  Ӧ�ó�ʼ���ɹ�
MR_FAILED      Ӧ�ó�ʼ��ʧ��
*/
int32 mrc_init(void)
{
   mrc_winInit();
   mrc_clearScreen(0, 0, 0);
	//�������˵�
	main_menu=0;
	draw_WinHandle=0;
	main_ShowMenu();

   return MR_SUCCESS;
}

/*
Ӧ���¼�����
�ú�����Ӧ�������ڼ䣬ÿ��mythroadƽ̨�յ��¼�ʱ
������
����:
code:
      code�Ŀ���ȡֵ����:
enum {
   MR_KEY_PRESS,           //���������¼�
   MR_KEY_RELEASE,        //�����ͷ��¼�
   MR_MOUSE_DOWN,       //����������꣩�����¼�
   MR_MOUSE_UP,            //����������̧꣩��/�ͷ��¼�
   MR_MENU_SELECT,       //�˵�ѡ���¼�
   MR_MENU_RETURN,       //�˵������¼�
   MR_DIALOG_EVENT,      // �Ի���/�༭��/�ı����¼�
   MR_EVENT02,             //VM�������벻Ҫʹ��
   MR_EXIT_EVENT,           //Ӧ���˳��¼�
   MR_EVENT03,                 //VM�������벻Ҫʹ��
   MR_LOCALUI_EVENT         //���ػ��ӿ��¼�
};

param0:
   ��codeΪMR_KEY_PRESS��MR_KEY_RELEASEʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_KEY_0,               //���� 0
   MR_KEY_1,               //���� 1
   MR_KEY_2,               //���� 2
   MR_KEY_3,               //���� 3
   MR_KEY_4,               //���� 4
   MR_KEY_5,               //���� 5
   MR_KEY_6,               //���� 6
   MR_KEY_7,               //���� 7
   MR_KEY_8,               //���� 8
   MR_KEY_9,               //���� 9
   MR_KEY_STAR,            //���� *
   MR_KEY_POUND,           //���� #
   MR_KEY_UP,              //���� ��
   MR_KEY_DOWN,            //���� ��
   MR_KEY_LEFT,            //���� ��
   MR_KEY_RIGHT,           //���� ��
   MR_KEY_POWER,           //���� �һ���
   MR_KEY_SOFTLEFT,        //���� �����
   MR_KEY_SOFTRIGHT,       //���� �����
   MR_KEY_SEND,            //���� ������
   MR_KEY_SELECT,          //���� ȷ��/ѡ����������м���ȷ�ϼ���������Ϊ�ü���
   MR_KEY_VOLUME_UP,          //���� �����
   MR_KEY_VOLUME_DOWN,          //���� �����
   MR_KEY_NONE             //���� ����
};
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param0Ϊ��Ļ��x���ꣻ
��codeΪMR_MENU_SELECTʱ��param0Ϊ�˵�index��
��codeΪMR_DIALOG_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_DIALOG_KEY_OK,         //�Ի���/�ı���ȵ�"ȷ��"�������(ѡ��)
   MR_DIALOG_KEY_CANCEL  //�Ի���/�ı���ȵ�"ȡ��"("����")�������(ѡ��)
};
��codeΪMR_LOCALUI_EVENTʱ��param0�Ŀ���ȡֵ����:
enum {
   MR_LOCALUI_KEY_OK,       //���ؿؼ���"ȷ��"�������(ѡ��)
   MR_LOCALUI_KEY_CANCEL//���ؿؼ���"ȡ��"("����")�������(ѡ��)
};

param1:
��codeΪMR_MOUSE_DOWN��MR_MOUSE_UPʱ��param1Ϊ��Ļ��y���ꣻ

����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_event(int32 code, int32 param0, int32 param1)
{
   mrc_winEvent(code, param0, param1);
   return MR_SUCCESS;
}

/*
Ӧ����ͣ����
�ú�����Ӧ�ñ���ͣʱ���е绰���¼���ͣӦ�ã�
��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_pause(void)
{
   return 0;
}

/*
�ú�����Ӧ�ûָ�����ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_resume(void)
{
   mrc_winResume();
   return 0;
}

/*
�ú�����Ӧ���˳�ʱ��mythroadƽ̨���á�
����ֵ:
MR_SUCCESS  �����ɹ�
MR_FAILED      ����ʧ��
*/
int32 mrc_exitApp(void)
{
   return 0;
}
