#ifndef _FILE_LOG_H_ 
#define _FILE_LOG_H_
/*
向log文件写入TimerLog信息
be as begin & end   
begin = 1
end = 0
*/
void writeTimerLog(void);
void writePaintLog(int32 state);
/*
打开log文件
*/
void openLogFile(void);
/*
关闭log文件
*/
void closeLogFile(void);
#endif


