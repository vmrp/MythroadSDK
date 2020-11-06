#ifndef SKY_SDK_EXB_H
#define SKY_SDK_EXB_H

void   mrc_sand(uint32   seed);
uint32   mrc_rand(void);


  #define abs(VAL) (((VAL)>0)?(VAL):(-(VAL)))

/*
����:
	�򿪡��ر�LCD��ʱ���߹��ܡ�
	
����:
	char CanSleep=1 ʱ������LCD��ʱ���ߣ�
	char CanSleep=0ʱ��������LCD��ʱ���ߡ�

�����
MR_SUCCESS ���ɹ�
MR_FAILED  ��ʧ��
MR_IGNORE  : ��֧�ָù���
*/
int32 mrc_LCDCanSleep(char CanSleep);


/*
������:
					mrc_GetCurrentDirectory:
���ܣ�
					��õ�ǰĿ¼·����ע�⣬���ص�Ŀ¼·����GB����ġ�

���룺
					nBufferLength����Ŀ¼��Ϣ�Ļ������ֽ�����
					lpBuffer ����Ŀ¼��Ϣ�Ļ�����ָ�롣
�����
					��ǰĿ¼��
����ֵ:	
					Ŀ¼��Ϣ���ֽ������������ַ�����������
					����ȡʧ�ܣ��򷵻�ֵΪ0��
*/
int32 mrc_GetCurrentDirectory(
  int32 nBufferLength,  // size, in characters, of directory buffer
  char *lpBuffer       // pointer to buffer for current directory
);

/*
������:
					mrc_GetDiskFreeSpaceEx:
���ܣ�
					���ָ���̷��Ŀռ���Ϣ��

���룺
					lpDirectoryName��Ŀ������ϵ�һ��Ŀ¼����ΪNULL��ʾ��ǰĿ¼��
					Ŀǰ���Ƶ�ǰĿ¼����ΪNULL���ұ������ֻ��ϵ�T����
�����
					TotalBytes	�ô����ܵ��ֽ�����
					FreeBytes	�ô��̿����ֽ�����
����ֵ:	
					���̷������ֽ�������ʧ�ܻ�����ֽ���Ϊ0ʱ������0��
*/
uint64 mrc_GetDiskFreeSpaceEx(
  uint8 *lpDirectoryName,                 // pointer to the directory name
  uint64 *TotalBytes, // receives the number of bytes on disk
  uint64 *FreeBytes // receives the free bytes on disk
  );


/*
��������:		mrc_strrchr

��������:		��һ���ַ���������һ���ַ������ֵ�λ�á�

�������:		string����NULL��β���ַ�����
								c����Ҫ���ҵ��ַ���

����ֵ:			���������ַ��ڴ��������ֵ�λ��ָ�룬��û���ҵ���
								����NULL��
*/
char * mrc_strrchr (
        const char * string,
        int32 ch
        );




typedef enum {
   MRP_ORICODING,//ֱ�Ӷ�ȡ���롣ֻ��˹������Ȩ�û�����ִ�и����Ͳ�����
   MRP_FILENAME,//MRP�ļ����ƣ����11����Ч�ַ���������'\0'
   MRP_APPNAME,//MRPӦ�����ƣ��û��ɼ���Ӧ���������23����Ч�ַ���������'\0'������"�׵�1944"��
   MRP_APPID,//ÿ��Ӧ�ö�Ӧһ��Ψһ��ID��uint32���͡�
   MRP_APPVER,//uint32����   
   MRP_VENDER,//��������Ϣ�����39����Ч�ַ���������'\0'��
   MRP_DESCRIPTION,   //Ӧ��������Ϣ �����63����Ч�ַ�
   MRP_VERSION,//�Ʒ�ͨ���汾���,uint16���ͣ������ֽڡ�
   MRP_CHANNEL,//�Ʒ�ͨ�����,�����ֽڣ��͵�ַ��RecBuf[0]���ƶ����ߵ�ַ��RecBuf[1]����ͨ��
   MRP_NONE
}E_MRP_INFOID;

/*
��������:		mrc_GetMrpInfo

��������:		�ӵ�ǰMRP�ļ��ж�ȡͷ��Ϣ��

�������:		CMD�����������롣
								RecBuf�����շ������ݵĻ�����ָ�룻
								BufLen�����շ������ݵĻ������ֽ�����

����ֵ:			��������֧�֡�����ʧ�ܵ����ʱ����������ֵС�ڵ���0��
								�������ɹ�����������ֵΪRecBuf��ʵ����д���ֽ�����
��ע:
	�ú�����δʵ�֡�
*/
int32 mrc_GetMrpInfo(char *MrpName,E_MRP_INFOID CMD,uint8 *RecBuf,int32 BufLen);

/*************************************************************************
  Function:       mrc_tell
  Description:    �õ���ǰ�ļ���дָ���λ�á��ο�MSDN��_tellʵ�֡�
  Input:          aFileHandle:�ļ����
  Output:         
  Return:         �����������ǰ�ļ���дָ�롣����ֵС��0,��ʾ��������
  Others:         None
��ע:
  1���˺���Ŀǰֻ����ģ������ʹ�ã����ֻ���ʹ�ý�����MR_FAILED(-1)��
  2��Ŀǰ���ṩ32bit�汾������ȡ�ļ����ȳ���2GB�����������
  
**************************************************************************/
int32 mrc_tell(int32 aFileHandle);

//��һ���޷���32bit�����������ֽ���(little-endian)ת��Ϊ�����ֽ���(big-endian)��
uint32 mrc_htonl(uint32 hostlong);
//��һ���޷���32bit�����������ֽ���(big-endian)ת��Ϊ�����ֽ���(little-endian)��
uint32 mrc_ntohl(uint32 netlong);

/*************************************************************************
  Function:       mrc_BCDEncode
  Description:    �������ASCII���ִ�����BCDѹ�����롣
  Input:          char *in	:ASCII���ִ�;
  						char *out :����ַ��������������������߸��𴴽��û�����������
  						���벻����mrc_strlen(in)/2+mrc_strlen(in)%2�����⣬������޴�������־��
  Output:        char *out	:BCD�����ַ�����
  Return:         ���������*in��*out������NULL���򷵻�out��ָ�룬���򷵻�NULL��
  Others:         None
**************************************************************************/
char* mrc_BCDEncode(char *in,char *out);

//����ͬmrc_getPackName(void);
char* mrc_getPackNameMr(void);

//����ͬ int32 mrc_setPackName(char * name);
int32 mrc_setPackNameMr(char * name);
#endif
