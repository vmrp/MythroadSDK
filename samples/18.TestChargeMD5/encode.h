#ifndef _ENCODE_H_
#define _ENCODE_H_

typedef struct {
uint8 MD5[16];//MD5校验值；
char Md5IMEI[33];//用户IMEI的MD5值
uint32 Score;//积分；
uint32 Payed;//当天消费金额
mr_datetime PayedDate;//最后消费日期，和Payed一起作为限额依据；
uint32 Reserved;//后续各个应用添加自己需要存盘的数据。
}SAVE_RECORD_T;

extern int32 fd;
extern SAVE_RECORD_T *g_record;

void md5Init(void);
void md5ToString(uint8* in, uint8* out);
void md5Make(uint8* in , int32 len, uint8* out);
void destroyMd5(void);
#endif
