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
					Ŀǰ���Ʊ���Ϊ"C"�����ֻ��ϵ�T����
�����
					TotalKB	�ô����ܵ���������λΪKB��
					FreeKB	�ô��̿�����������λΪKB��
����ֵ:	
					���̷������ֽ�������ʧ�ܻ�����ֽ���Ϊ0ʱ������0��
*/
uint32 mrc_GetDiskFreeSpace32(
  uint8 *lpDirectoryName,                 // pointer to the directory name
  uint32 *TotalKB, // receives the number of bytes on disk
  uint32 *FreeKB // receives the free bytes on disk
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
   MRP_CTRCHN,
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

/*
��������:mrc_BCDDecode:
	���ܼ��:��ѹ��BCD��������ִ����������
����:
	char *bcd:	ѹ��BCD��������ִ���
	int32 len:	ѹ��BCD��������ִ����ȣ�

���:	
	char *output:	����ַ������ÿռ��ɵ����߸���������ͷţ������������������ͷ��ڴ档	
����ֵ:
	�ɹ�:����ָ��output��
	ʧ��:����NULL
*/
char *mrc_BCDDecode(char *bcd,int32 len,char *output);

//����ͬmrc_getPackName(void);
char* mrc_getPackNameMr(void);

//����ͬ int32 mrc_setPackName(char * name);
int32 mrc_setPackNameMr(char * name);

/*
��������:GetCurLanguageID:
���ܼ��:��ȡ�ֻ��ĵ�ǰ��������
����:
		�ޣ�
		
���:

���أ�
MR_PLAT_VALUE_BASEֵ��1000
MR_PLAT_VALUE_BASE + 0 �����ļ�1000
MR_PLAT_VALUE_BASE + 1 ��Ӣ�ļ�1001
MR_FAILED              ����ȡʧ��
MR_IGNORE              ����֧�ָù���

*/
int32 GetCurLanguageID(void);


/*
��������:md5MakeFromMem
���ܼ��:���ڴ��е����ݼ�����Կ�����MD5��
����:
char *key:	��Կ������������Կ����ΪNULL���ɡ���������Կ��
					����Կ������һ�����MD5
uint8* in:		������ָ�롣
int32 offset:	��in+offset�ĵ�ַƫ�ƿ�ʼ��len���ֽڵ����ݼ���MD5��
					���offset<0������ʧ�ܡ�
int32 len:		��Ҫ��������������ֽ���������ֵС��0������ʧ�ܡ�
					���len=0����key!=NULL���򽫷���key��MD5��
					����len==0 && key==NULL�����ص�MD5ֵ������MD5�����ľ���ʵ�֡�

���:
uint8* out:	����������MR_SUCCESS����ͨ��out����16���ֽڵ�MD5У��ֵ��
					��16���ֽڵ��ڴ��ɵ��������롢�ͷš�

���أ�
MR_SUCCESS:MD5��ȡ�ɹ���
MR_FAILED    :��ȡʧ�ܣ���ʱout�е�ֵ�ǲ�ȷ���ģ�������ΪMD5ֵʹ�á�
*/
int32 md5MakeFromMem(char *key,uint8* in,int32 offset , int32 len, uint8* out);


/*
��������:md5MakeFromFileHandle
���ܼ��:���ļ��е����ݼ�����Կ����MD5��
����:
char *key:	��Կ������������Կ����ΪNULL���ɡ���������Կ��
					����Կ������һ�����MD5��
int32 fhandle:	��Ҫ����MD5���ļ������
int32 offset:	���ļ�ͷ��offset�ֽڵĵ�ַƫ�ƿ�ʼ��len���ֽڵ����ݼ���MD5��
					���offset<0������ʧ�ܡ�
int32 len:		��Ҫ��������������ֽ�����
				(1)������ֵС��0������ʧ�ܡ�
				(2)�����len=0����key!=NULL���򽫷���key��MD5������
							��len==0 && key==NULL�����ص�MD5ֵ������MD5�����ľ���ʵ�֡�
				(3)��������ʱ����ͨ���ļ������ȡ�ļ����ȣ����Խ���
							����9�ζ�ȡʧ�ܻ�������9�ζ���0���ֽ�ʱ����ʧ�ܣ�
							��(len+offset)>filelenʱͨ��������ʧ�ܡ�
���:
uint8* out:	����������MR_SUCCESS����ͨ��out����16���ֽڵ�MD5У��ֵ��
					��16���ֽڵ��ڴ��ɵ��������롢�ͷš�

���أ�
MR_SUCCESS:MD5��ȡ�ɹ���
MR_FAILED    :��ȡʧ�ܣ���ʱout�е�ֵ�ǲ�ȷ���ģ�������ΪMD5ֵʹ�á�
*/
int32 md5MakeFromFileHandle(char *key,int32 fhandle,int32 offset , int32 len, uint8* out);
/*
��������:md5MakeFromFile
���ܼ��:���ļ��е����ݼ�����Կ����MD5��
����:
char *key:	��Կ������������Կ����ΪNULL���ɡ���������Կ��
					����Կ������һ�����MD5
char *filename:	��Ҫ����MD5���ļ�����
int32 offset:	���ļ�ͷ��offset�ֽڵĵ�ַƫ�ƿ�ʼ��len���ֽڵ����ݼ���MD5��
					���offset<0������ʧ�ܡ�
int32 len:		��Ҫ��������������ֽ�����
				(1)������ֵС��0������ʧ�ܡ�
				(2)�����len=0����key!=NULL���򽫷���key��MD5������
							��len==0 && key==NULL�����ص�MD5ֵ������MD5�����ľ���ʵ�֡�
				(3)�����(offset+len)>�ļ����ȣ���ȡ���ļ�ĩβΪֹ������������
					
���:
uint8* out:	����������MR_SUCCESS����ͨ��out����16���ֽڵ�MD5У��ֵ��
					��16���ֽڵ��ڴ��ɵ��������롢�ͷš�

���أ�
MR_SUCCESS:MD5��ȡ�ɹ���
MR_FAILED    :��ȡʧ�ܣ���ʱout�е�ֵ�ǲ�ȷ���ģ�������ΪMD5ֵʹ�á�
*/
int32 md5MakeFromFile(char *key,char *filename,int32 offset , int32 len, uint8* out);


/*
��������:md5ToString
���ܼ��:��16�ֽڵ�MD5У��ֵת��Ϊ32�ֽڵ�ASCII�ɼ��ַ�����
����:
uint8 *in:	MD5У��ֵ��
���:
uint8* out:	����������MR_SUCCESS����ͨ��out����32���ֽڵ�MD5У��ֵ��
					��32���ֽڵ��ڴ��ɵ��������롢�ͷš�

���أ�
MR_SUCCESS:MD5��ȡ�ɹ���
MR_FAILED    :��ȡʧ��
*/
int32 md5ToString(uint8* in, uint8* out);



/*
���ٴ�����ʹ��˵��
ʹ�ò��衣
1��	���ü��ٴ������������������ MR_IGNORE ��ô�Ͳ�֧�֡�
2��	���óɹ��Ժ��������ٴ������������ɹ��Ժ󣬾Ϳ�����mr_event()
�н��������ˡ�
3��	mr_event()��
param1  MR_MOTION_TITLE�¼��Ժ��ʾ�н��յ����ٴ��������¼��ˡ�
Param2  ��ʾx��y�����ƫ�ƣ�xռ�õ�λ16bit��yռ�ø�λ��16bit��
Param3  ��ʾz����ƫ��
Ӧ�ó���ֻ��Ҫ����Щ���ݽ��д���Ϳ��ԡ�
4��	ֹͣ���ٴ�������Ӧ��ʹ�ý����Ժ�ֹͣ��������

�ر�ע����
��������Ҫ����direct�����򣩡�shark���𶯣���ת���Ƕȷ������󣬿���ͨ�����Ӷ�x
��y��z��Щԭʼ���ݴ����Ժ�õ���
*/



typedef enum
{
    MR_MOTION_SENSITIVE_LOW,
    MR_MOTION_SENSITIVE_NORMAL,
    MR_MOTION_SENSITIVE_HIGH,

    NUM_OF_MDI_MOTION_SENSITIVE
} MR_MOTION_SENSITIVE_ENUM;//�����������жȡ�ö�����͡�

typedef struct 
{
	uint8 isStart;
	int32 key;//0:IDLE,2:up,4:left;6:right;8:down
	int16 x;
	int16 y;
	int32 maxRange;
}CTRL_MOTION2KEY_T;
int32 mrc_motion2KeyStart(int32 sensitive);
int32 mrc_motion2Key(CTRL_MOTION2KEY_T *ctrlMotion2key,int32 *code,int32 *param0,int32 *param1);
int32 mrc_motion2KeyStop(void);

typedef enum
{
    MOTION_SENSITIVE_LOW,
    MOTION_SENSITIVE_NORMAL,
    MOTION_SENSITIVE_HIGH
}MOTION_SENSITIVE_T;

typedef enum
{
	MOTION_SHAKE_NO_DIRECT,
	MOTION_SHAKE_LEFT,
	MOTION_SHAKE_RIGHT,
	MOTION_SHAKE_FORWARD,
	MOTION_SHAKE_BACKWARD
}MOTION_SHAKE_T;

typedef enum
{
	MOTION_EVENT_SHAKE,
	MOTION_EVENT_TILT
}MOTION_EVENT_T;

typedef struct
{
	int32 x;
	int32 y;
	int32 z;
}T_MOTION_TILT;

#define MR_MOTION_STOP_LISTEN               4001
#define MR_MOTION_SENOR_PWRON 		4002
#define MR_MOTION_SENOR_PWROFF 		4003
#define MR_MOTION_LISTEN_SHAKE             4004
#define MR_MOTION_LISTEN_TILT                4005
#define MR_MOTION_SENSOR_MAXRANGE	4006

//�򿪴�����
int32 mrc_motionSensorPowerOn(void);

//�رմ�����
int32 mrc_motionSensorPowerOff(void);

//��ͣ���մ������¼�
int32 mrc_motionSensorStopListen(void);

//�����ζ��¼�
int32 mrc_motionSensorStartShakeListen(int32 sensitive);

//��������¼�
int32 mrc_motionSensorStartTiltListen(int32 sensitive);

/*��ȡ���ز�����ȡֵ��Χ�����ֵMAXRANGE��
�ɹ�:
	����MR_PLAT_VALUE_BASE+MAXRANGE�������Ҫ�����ս����ȥ1000(MR_PLAT_VALUE_BASE��ֵ)
ʧ��:
	����MR_FAILED;
��֧��:
	����MR_INGORE;
*/
int32 mrc_motionSensorGetRange(void);


/*
������:mrc_unicodeToGb2312
���룺
��unicode������ַ���ת��gb2312����
input����Ҫת����unicode�ַ���
input_len:��Ҫת����unicode�ַ������ȣ���λ�ֽ���
output��ת���ɹ��Ժ��bg2312�����ַ�����Ż�������
���������ڴ���Ӧ�õ������ṩ�������ͷš�
ע�⣺���������������ʹ��malloc���䴦��Ŀռ䣬�����ֻ����ܻ����������
output_len��output�������ĳ��ȣ���λ�ֽ���

���أ�
    MR_SUCCESS	ת���ɹ�
    MR_FAILED   ת��ʧ��

*/
int32 mrc_unicodeToGb2312(uint8* input, int32 input_len, uint8** output, int32* output_len);


/*
������:mrc_getRegAppAddr
	��ȡ�̻�Ӧ�á��ڴ澵��Ӧ�õ�����ʱ���ص�ַ��
	Ӧ�����ƿ���ͨ��mrc_getPackName()��ȡ��
���룺
char *MrpName:	Ӧ�����ƣ��̻�Ӧ�ö���"*"��ͷ	�ģ�RAMӦ�ö���"$"��ͷ�ģ�

���أ�
NULL:��ȡʧ�ܣ�
����ֵΪӦ���ڴ��ַ��
*/
int32 mrc_getRegAppAddr(char *MrpName);



//-----------------------¼������-------------------------------------
enum
{
	DSM_ERROR_NO_ERROR =0,
	DSM_ERROR_UNKNOW,
	DSM_ERROR_NO_SPACE,
	DSM_ERROR_TERMINATED
};

typedef enum
{
   SRC_NAME = 0,    //������ֲ�ӿ����ļ���
   SRC_STREAM   //������ֲ�ӿڵ���ͼƬ������
}VOICE_REC_TYPE;

typedef struct{
    char *src;       		//¼���ļ�������ļ�����������streamģʽ�¿�ΪNULL
    int32 src_len;		//������streamģʽʱ���Ըò�����
    int32 src_type;	//�μ�VOICE_REC_TYPE����Ϊ SRC_STREAM ��ʾʵʱ��ȡ������ģʽ��
    int32 format;		//MR_SOUND_WAV , MR_SOUND_PCM , MR_SOUND_AMR , MR_SOUND_AMR_WB 
}VOICE_REC_REQ_T;

typedef void (*VOICE_REC_CB)(uint8* output, int32 output_len);

/*
������:mrc_voiceRecStart



���룺
VOICE_REC_REQ_T *voiceCtl

���أ�
MR_SUCCESS	: 	����ɹ�
MR_FAILED  		:	����ʧ��
MR_IGNORE  	:	��֧�ָù���

ע��
¼�����쳣���ͨ��mr_event֪ͨ��mr_event�Ĳ������£�
��һ����MR_ERROR_EVENT
�ڶ�����DSM_ERROR_NO_SPACE	���ռ���
        				DSM_ERROR_TERMINATED�����ж�
        				DSM_ERROR_UNKNOW		��δ֪����
��������0
*/
int32 mrc_voiceRecStart(VOICE_REC_REQ_T *voiceCtl);

/*
������:mrc_voiceRecStreamProc
	stream¼��ģʽ�»�ȡ��ǰ��¼���ݣ�����ʹ���߿��Կ�������ʮ����Ķ�ʱ����ʱ��ѯ����ȡ���������ݡ�
���룺
	�ޣ� 
���:
	*output  ����ǰ¼�����ݶ�ȡ��ַ��
    *output_len  ��¼�����ݳ��ȣ�
	MR_PLAT_EX_CB *cb �� ��output_len>0 ���� Ӧ�ô�����������ַ�е�����ʱ��������ô˻ص����ƶ��豸����Ķ�ָ�롣

���أ�
MR_SUCCESS	: 	����ɹ�
MR_FAILED  		:	����ʧ��
MR_IGNORE  	:	��֧�ָù���

ע��:
	��ʹ������ʽ¼����ʹ��WAV��ʽ����Ҫ��¼����������Ӧ�����wavͷ��Ϣ�������޷�������
*/
int32 mrc_voiceRecStreamProc(uint8 **output,int32 *output_len,VOICE_REC_CB *cb);

/*
������:mrc_voiceRecPause
	��ͣ¼��
���룺
	�ޡ� 
���:
	�ޡ�
���أ�
MR_SUCCESS	: 	����ɹ�
MR_FAILED  		:	����ʧ��
MR_IGNORE  	:	��֧�ָù���
*/
int32 mrc_voiceRecPause(void);

/*
������:mrc_voiceRecResume
	�ָ�¼��
���룺
	�ޡ� 
���:
	�ޡ�
���أ�
MR_SUCCESS	: 	����ɹ�
MR_FAILED  		:	����ʧ��
MR_IGNORE  	:	��֧�ָù���
*/
int32 mrc_voiceRecResume(void);

/*
������:mrc_voiceRecStop
	ֹͣ¼��
���룺
	�ޡ� 
���:
	�ޡ�
���أ�
MR_SUCCESS	: 	����ɹ�
MR_FAILED  		:	����ʧ��
MR_IGNORE  	:	��֧�ָù���
*/
int32 mrc_voiceRecStop(void);


#define MRC_PLAT_VALUE_BASE 1000

/*
������:mrc_isTouchSupport
	���ܣ���ȡ�ֻ��Ƿ��Ǵ�������Ϣ��
	���룺
		  ��
	���أ�
	MRC_PLAT_VALUE_BASE	���Ǵ�����
	MRC_PLAT_VALUE_BASE+1	��������
	MR_FAILED	����ȡʧ�ܡ�
	MR_IGNORE	����֧�ֻ�ȡ��������Ϣ��

*/
int32 mrc_isTouchSupport(void);



int32 mrc_writeBigEndianU32(uint32 data,uint8 *p);

int32 mrc_writeBigEndianU16(uint16 data,uint8 *p);

uint32 readBigEndianUint32(uint8 *p);

uint16 readBigEndianUint16(uint8 *p);

uint32 readLittleEndianUint32(uint8 *p);

uint16 readLittleEndianUint16(uint8 *p);

typedef struct
{
	uint8       IMEI[16];	     //IMEI ����Ϊ15�ֽ�
	uint8       IMSI[16];	     //IMSI ����Ϊ15�ֽ�
	char        manufactory[8];  //�ֻ���ƹ�˾�������7���ַ������ֽ���\0
	char        type[8];         //�ֻ��з���Ŀ����mobile type�����7���ַ������ֽ���\0
	uint32      ver;             //��ֲ����汾
	uint8       spare[12];       //����
}MRC_PHONEINFO_T;
/*
������:mrc_getphoneInfo
	���ܣ���ȡ�ֻ��ĳ��̻�����Ϣ��
	���룺
		  ��
	���:
			MRC_PHONEINFO_T* phoneInfo;���е�IMSI������α�룬ֻ����ʵ��IMSI��ӳ�䡣
	���أ�
	MR_SUCCESS :	��ȡ�˹�����
	MR_FAILED	����ȡʧ�ܡ�
	MR_IGNORE	����֧�ֻ�ȡ��������Ϣ��

*/

int32 mrc_getphoneInfo(MRC_PHONEINFO_T* phoneInfo);



/*
������:mrc_getSdkVer
	���ܣ���ȡSDK�Ʒ�ģ��汾�š�
	���룺
		  ��
	���أ�
		SDK�İ汾�š��汾��ΪAABBCCCDDD��ʽ��int32���������У�
		AAΪ���λ�汾�ţ�
		BBΪ�θ�λ�汾�ţ�
		CCC���ӹ��ܰ汾�ţ�ÿ���д�Ĺ��ܱ仯�����޸��ӹ��ܰ汾�š�
		DDD��Build�汾�ţ�ÿ�θĶ�����֮�󣬶����޸�Build�汾�š�

*/

int32 mrc_getSdkVer(void);

typedef struct
{
	char       IMEI[16];	     //IMEI ����Ϊ15�ֽڣ����һ���ֽ���'\0'���
	char       IMSI[16];	     //IMSI ����Ϊ15�ֽڣ����һ���ֽ���'\0'���
	char       manufactory[8];  //�ֻ���ƹ�˾�������7���ַ������ֽ���\0
	char       type[8];         //�ֻ��з���Ŀ����mobile type�����7���ַ������ֽ���\0
	unsigned int     ver;             //��ֲ����汾
	unsigned char    spare[12];       //����
}MR_PHONEINFO_T;

/*
������:mrc_editNetworkAccount
	���ܣ��û�������������ʺš�ֻ�к��������Ӧ����Ҫʹ������ӿڡ�
	
	��Ϊ�������Ӫ�̺ܶ࣬������Ӫ��ʹ�õ��ʺ�����Ҳ������ͬ���������ص�ַҲ���ܲ�һ��������Ϊ�˴����������ӵ�����������������¼ٶ���
	A�� ����汾ֻ֧��ֱ�����ӻ�������ģʽ���������ص�ַ��ͬ�������
	B�� ���Žӿڣ�����������ʧ�ܵ�����£����û���������ȷ���ʺ�����

	1.	�ں���İ汾����Ҫ����һ���˵�������˵��Ĺ��ܾ������û���������ȷ���ʺ����ϡ����õĽӿ��ǣ�mrc_editNetworkAccount();��������ӿ�֮��Ӧ�û��յ�PAUSE�¼���
	���û�������ȷ����Ϣ��Ӧ�û��յ�RESUME�¼���ͬʱ��ҪӦ�ñ���һ����־λ�������û��Ƿ��Ѿ����ù��µ��ʺ����ϣ��Ժ�ÿ�����и�Ӧ���ڵ���mr_initNetWork��ǰ����Ҫ�ж������־λ�������ýӿ������������־λ��
	���ñ�־λ�Ľӿ��ǣ�mrc_selectNetworkAccount(option) ��ֵ�ĺ������£�
	option��
		0��ʹ���û����õ��ʺ�����
	   	1��ʹ�ó���Ԥ����ʺ�����

	
	���룺
		  ��
	���أ�
	MR_SUCCESS :	���óɹ���
	MR_FAILED	:	����ʧ�ܡ�
	MR_IGNORE	:	��֧�֡�

*/
int32 mrc_editNetworkAccount(void);

/*
������:mrc_editNetworkAccount
	���ܣ��û�������������ʺš�ֻ�к��������Ӧ����Ҫʹ������ӿڡ�
	
	��Ϊ�������Ӫ�̺ܶ࣬������Ӫ��ʹ�õ��ʺ�����Ҳ������ͬ���������ص�ַҲ���ܲ�һ��������Ϊ�˴����������ӵ�����������������¼ٶ���
	A�� ����汾ֻ֧��ֱ�����ӻ�������ģʽ���������ص�ַ��ͬ�������
	B�� ���Žӿڣ�����������ʧ�ܵ�����£����û���������ȷ���ʺ�����

	1.	�ں���İ汾����Ҫ����һ���˵�������˵��Ĺ��ܾ������û���������ȷ���ʺ����ϡ����õĽӿ��ǣ�mrc_editNetworkAccount();��������ӿ�֮��Ӧ�û��յ�PAUSE�¼���
	���û�������ȷ����Ϣ��Ӧ�û��յ�RESUME�¼���ͬʱ��ҪӦ�ñ���һ����־λ�������û��Ƿ��Ѿ����ù��µ��ʺ����ϣ��Ժ�ÿ�����и�Ӧ���ڵ���mr_initNetWork��ǰ����Ҫ�ж������־λ�������ýӿ������������־λ��
	���ñ�־λ�Ľӿ��ǣ�mrc_selectNetworkAccount(option) ��ֵ�ĺ������£�
	option��
		0��ʹ���û����õ��ʺ�����
	   	1��ʹ�ó���Ԥ����ʺ�����

	
	���룺
		  ��
	���أ�
	MR_SUCCESS :	���óɹ���
	MR_FAILED	:	����ʧ�ܡ�
	MR_IGNORE	:	��֧�֡�

*/
int32 mrc_selectNetworkAccount(int32 option);

#endif
