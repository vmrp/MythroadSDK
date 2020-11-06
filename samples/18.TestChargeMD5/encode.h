#ifndef _ENCODE_H_
#define _ENCODE_H_

typedef struct {
uint8 MD5[16];//MD5У��ֵ��
char Md5IMEI[33];//�û�IMEI��MD5ֵ
uint32 Score;//���֣�
uint32 Payed;//�������ѽ��
mr_datetime PayedDate;//����������ڣ���Payedһ����Ϊ�޶����ݣ�
uint32 Reserved;//��������Ӧ������Լ���Ҫ���̵����ݡ�
}SAVE_RECORD_T;

extern int32 fd;
extern SAVE_RECORD_T *g_record;

void md5Init(void);
void md5ToString(uint8* in, uint8* out);
void md5Make(uint8* in , int32 len, uint8* out);
void destroyMd5(void);
#endif
