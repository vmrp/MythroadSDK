#ifndef _FILE_LOG_H_ 
#define _FILE_LOG_H_
/*
��log�ļ�д��TimerLog��Ϣ
be as begin & end   
begin = 1
end = 0
*/
void writeTimerLog(void);
void writePaintLog(int32 state);
/*
��log�ļ�
*/
void openLogFile(void);
/*
�ر�log�ļ�
*/
void closeLogFile(void);
#endif


