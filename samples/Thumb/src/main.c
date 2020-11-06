#include "..\..\..\modules\mrc_base.h"
#include "..\..\..\modules\mrc_image.h"

#include "fileLog.h"

#ifdef   FONT_SUPPORT
#include "fontread.h"
#endif
	
#define READ_OK			"\x00\x52\x00\x65\x00\x61\x00\x64\x00\x4f\x00\x4b\x00\x00"	
#define READ_FAILED		"\x00\x52\x00\x65\x00\x61\x00\x64\x00\x46\x00\x61\x00\x69\x00\x6c\x00\x65\x00\x64\x00\x00"	
#define DRAW_OK			"\x00\x44\x00\x72\x00\x61\x00\x77\x00\x4f\x00\x4b\x00\x00"
#define DRAW_ERROR    	"\x00\x44\x00\x72\x00\x61\x00\x77\x00\x45\x00\x52\x00\x52\x00\x4f\x00\x52\x00\x00"

int32 mrc_init(void)
{
	int32 test = 0;
	char testStr[100];
	
	T_DRAW_DIRECT_REQ input;
	PT_DSM_COMMON_RSP gp;	
	mr_colourSt clr = {255, 255, 255};

	mrc_clearScreen(0,  0, 0);

	mrc_memset(testStr, 0, 100);
	test = 'abcd';
	mrc_sprintf(testStr, "%d", test);
	mrc_drawText(testStr, 0, 260, 255, 255, 255, FALSE, MR_FONT_MEDIUM);

	#ifndef FONT_SUPPORT
	#else
	FontModuleInit(FALSE, TRUE, FALSE);
	#endif
	
	writeTimerLog();
	openLogFile();//打开文件，准备LOG
	writeTimerLog();
	
	
	
	mrc_memset(&input, 0, sizeof(input));
	if(MR_FAILED == mrc_readFileFromMrpEx(NULL, "test.gif", (uint8 * *)&input.src, &input.src_len, 0))
		{
		#ifndef   FONT_SUPPORT
		mrc_drawText("ReadFailed", 0, 0, 255, 255, 255, FALSE, MR_FONT_MEDIUM);
		#else
		_drawText(READ_FAILED, 0, 0, clr, TRUE, MR_FONT_MEDIUM);
		#endif
		}
	else
		{
		#ifndef   FONT_SUPPORT
		mrc_drawText("ReadOK", 0, 0, 255, 255, 255, FALSE, MR_FONT_MEDIUM);
		#else
		_drawText(READ_OK, 0, 0, clr, TRUE, MR_FONT_MEDIUM);
		#endif
		input.h = 116;
		input.w = 22;
		input.ox = 0;
		input.oy = 100;
		input.src_type = SRC_STREAM;
		
		writePaintLog(1);
		
		#if 1
		if( MR_SUCCESS ==mrc_drawJpegToFrameBuffer(&input))
		#else
		if( MR_SUCCESS == mrc_drawGifToFrameBuffer(&input, (uint8 * *)gp))
		#endif
			{
			#ifndef   FONT_SUPPORT
			mrc_drawText("DrawOK", 0, 300, 255, 255, 255, FALSE, MR_FONT_MEDIUM);
			#else
			_drawText(DRAW_OK, 0, 300, clr, TRUE, MR_FONT_MEDIUM);
			#endif
			}
		else
			{
			#ifndef   FONT_SUPPORT
			mrc_drawText("DrawERROR", 0, 300, 255, 255, 255, FALSE, MR_FONT_MEDIUM);			
			#else
			_drawText(DRAW_ERROR, 0, 300, clr, TRUE, MR_FONT_MEDIUM);
			#endif
			}
		
		writePaintLog(0);
		
		}
	

	mrc_refreshScreen(0, 0, 240, 320);

	writeTimerLog();
	closeLogFile();//关闭LOG文件
	writeTimerLog();
	return MR_SUCCESS;
}


int32 mrc_appEvent(int32 code, int32 param0, int32 param1)
{
	return MR_SUCCESS;
}


int32 mrc_pause(void)
{
	return MR_SUCCESS;
}


int32 mrc_resume(void)
{
	return MR_SUCCESS;
}


int32 mrc_exitApp(void)
{
	#ifndef FONT_SUPPORT
	#else
	FontModuleRelease();
	#endif
	return MR_SUCCESS;
}


#if 0
int32 mrc_extRecvAppEvent(int32 app, int32 code, int32 param0, int32 param1)
{
	return MR_SUCCESS;
}

int32 mrc_extRecvAppEventEx(int32 code, int32 p0, int32 p1, int32 p2, int32 p3, int32 p4, int32 p5)
{
	return MR_SUCCESS;
}
#endif

