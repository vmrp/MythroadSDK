#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_exb.h"
#include "fileLog.h"
#define LOG_FILE_NAME  "FPS.txt"         //log文件名称

char buf[40];
int32  h_file;
int32
	b_begin,b_paintBegin;

void writePaintLog(int32 state)
{
	int32 timeValue= 0;	
	//mrc_getDatetime(&dt);
	timeValue = mrc_getUptime();
	mrc_memset(buf,0,40);
	if(b_paintBegin)
		sprintf(buf,"Paint at %d in state as %d\n",timeValue,state);
	else
		sprintf(buf,"Paint at %d out state as %d\n",timeValue,state);
	mrc_write(h_file,buf,strlen(buf));
	b_paintBegin = !b_paintBegin;
}
/*
向log文件写入TimerLog信息
*/
void writeTimerLog(void)
{
	int32 timeValue= 0;
	//mr_datetime dt;
	if(0 == h_file)
		return;
	//mrc_getDatetime(&dt);
	timeValue = mrc_getUptime();
	mrc_memset(buf,0,40);
	if(b_begin)
		sprintf(buf,"Timer at %d in\n",timeValue);
	else
		sprintf(buf,"Timer at %d out\n",timeValue);
	mrc_write(h_file,buf,strlen(buf));
	b_begin = !b_begin;
}

/*
打开log文件
*/
void openLogFile(void)
{
	h_file = mrc_open(LOG_FILE_NAME,MR_FILE_WRONLY|MR_FILE_CREATE);
	if(0 == h_file )
		return;
	mrc_memset(buf,0,40);
	sprintf(buf,"openLogFile\n");
	mrc_write(h_file,buf,strlen(buf));
	b_begin = TRUE;
	b_paintBegin = TRUE;
}


/*
关闭log文件
*/
void closeLogFile(void)
{
	if(0 != h_file)
		{
		mrc_memset(buf,0,40);
		sprintf(buf,"closeLogFile\n");
		mrc_write(h_file,buf,strlen(buf));
		mrc_close(h_file);
		}
}