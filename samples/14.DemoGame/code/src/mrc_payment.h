#ifndef SKY_PAYMENT_H
#define SKY_PAYMENT_H
#include "mrc_base.h"

#define PAYMENT
#define PAYMENT_TOM

#define PAY_MAXRESENDTIMES 3
 //���м���ͨ����
 typedef enum{
	ZHANGSHANGLINGTONG_2RMB=0,	// 0��ʾ2Ԫ������ͨ��ͨ�����ƶ�1Ԫ����ͨ2Ԫ
	PAYMENT_TEST,									// 1��ʾ����
	ZHIYUNSHIDAI_2RMB, 						// 2 ��ʾָ��ʱ����ͨ�����ƶ�1Ԫ����ͨ2Ԫ
	ZHANGSHANGLINGTONG_2RMB_MMS,		// 3��ʾ������ͨ��2��Ǯ����ͨ����ֻ���ƶ���
	ZHIYUNSHIDAI_1RMB,						// 4ָ��ʱ��1RMB��ͨͨ����
	XINQINGHUDONG_1RMB,					// 5���黥��1RMB��ͨͨ����
	GUNSHIYIDONG_2RMB,						// 6��ʯ�ƶ�2RMB���ƶ�����ͨ��2Ԫ��
	CHUANGYIHEXIAN_2RMB,					// 7�������2RMB���ƶ�����ͨ��2Ԫ��
	TOM_2RMB,											// 8TOMͨ�����ƶ�����ͨ��2Ԫ��
	TOM_TEST2RMB,									// 9TOM����ͨ�����ƶ�����ͨ��2Ԫ��
	ZHIYUNSHIDAI_2RMB_JS,					// 10ָ��ʱ���ƶ�1Ԫ��ͨ2Ԫ���޽���ʡʹ�á�����ʡ�ݲ����á�
	ZHIYUNSHIDAI_2RMB_MMS,				// 11 ָ��ʱ������ͨ�����ƶ���ͨ��2Ԫ��
	ZHIYUNSHIDAI_1RMB_MT,				// 12ָ��ʱ���ƶ���MO��MT����ͨ��MO��MTͨ�����ƶ���ͨ��1Ԫ��	
	ZHANGSHANGLINGTONG_2RMB_318,//13������ͨ2RMB��
	ZHIYUNSHIDAI_ZMCC10MT_UNICOM20,// 14ָ��ʱ���ƶ�1Ԫ�����õ�MT��������ָ���ͨ2Ԫ
	BEIWEI_CMCC10_UNICOM20,			// 15��γͨ�����ƶ�1Ԫ����ͨ2Ԫ��	
	ZHANGSHANGLINGTONG_20,			//16 ��0��ͨ����ȫһ�£���Ҫ��Ϊ�˺��Ķ���Ʒ���ݶ� ���ӵ�ͨ������ʾ2Ԫ������ͨ��ͨ�����ƶ�1Ԫ����ͨ2Ԫ
	PAY_CHN_ZY31,									//17 ָ��ʱ���ƶ�3Ԫ����ͨ������ͨʹ��1Ԫָ�
	PAY_CHN_XQ21,									//18 ���黥���ƶ�2Ԫͨ������ͨʹ��1Ԫָ�
	INDONESIA_2000RB,							//19ӡ��������2000¬��ͨ����
	MAX_PAY_CHANNEL
}PAY_CHANNEL;




/*
initCharge����˵��:
	��ʼ���Ʒ�ģ�飬���������Դ���������ȵ��á�
	
����:
	�ޡ�
	
���:

ע��:
		�����ڷ���ģʽ������������ʱ���Ʒ�ģ�齫��ʼ��ʧ�ܡ�
		
����ֵ:
MR_SUCCESS:��ʼ���ɹ���
MR_FAILED:��ʼ��ʧ�ܡ�
*/
int32 mrc_initCharge(void);

/*
��������:	mrc_ChargeEx
����˵��:	�ṩ�����չ���շѹ��ܡ�

����:
Option:	ֵΪ0ʱ����ʾ��д��¼�����ڹ�����ߵȶ�η��͵ĳ��ϣ�
				ֵΪ1ʱ����ʾҪд��¼�����ڲ�Ʒ����ע��ȳ��ϡ������
				���Ѹ��ѵĴ��̼�¼���򱾺������̷��سɹ���
				
Channel:	�շ���������˹�����塢���䡣
value:		�շѽ���λΪ�����0.1Ԫ����15��ʾ1.5Ԫ��30��ʾ3Ԫ�����
				ȡֵ��ΧΪ10����ͨ��SP���ŵĶ�Ӧֵ�����磬1.5��ͨ�����ֵΪ150��

���:
MR_SUCCESS:�շѳɹ���
MR_FAILED:�շ�ʧ�ܡ�
*/
int32 mrc_ChargeEx(uint32 Option,uint16 Channel,uint16 value);




/*
checkCharge����˵��:
	���Ӧ������Ŀ¼��appname��Ŀ¼���޳ɹ����ͼƷѶ��ŵ�ǩ���ļ���
���У��򷵻سɹ������򷵻�ʧ�ܡ�	

����:
	�ޡ�
	
���:
MR_SUCCESS:�ҵ��ɹ������˼ƷѶ��ŵĺϷ�ǩ���ļ���
MR_FAILED:û���ҵ�ָ����ǩ���ļ�����ǩ���ļ����Ǳ��ֻ��ġ�
*/
int32 mrc_checkCharge(void); 



/*
releaseCharge����˵��:
	�ͷżƷ�ģ�������Դ��
	
����:
	�ޡ�

���:
MR_SUCCESS:�ɹ��ͷ���Դ��
MR_FAILED:�ͷ�ʧ�ܡ�
*/
int32 mrc_releaseCharge(void);

//������Ĵ��̼�¼���б�����ܡ������ܳɹ����������Ѽ��ܽ��
//������һ���ڴ�**OutputRec�У�����ڴ���Ӧ�ø����ͷš�
//��������ENCODE_TYPE=0��ʾ��������ֻ���Ϣ��صġ�
int32 mrc_EncodeSave(int32 Type,uint8 *InputRec,int32 InputLen,uint8 **OutputRec,int32 *OutputLen);
//������Ĵ��̼�¼���н��룬����ɹ����������ѽ�����������
//һ���ڴ�**OutputRec�У�����ڴ���Ӧ�ø����ͷš�
int32 mrc_DecodeSave(int32 Type,uint8 *InputRec,int32 InputLen,uint8 **OutputRec,int32 *OutputLen);

//�ж���Ϸ�ڸó������Ƿ���ѣ����ǣ��򷵻�MR_SUCCESS�����򷵻�MR_FAILED
int32 mrc_CheckIsFree(void);


/*
mrc_initChargeAnsy����˵��:
	��ʼ���Ʒ�ģ�飬���������Դ���������ȵ��á�
	
����:
	value:ע���ļ����շѽ���λΪ�ǡ���value=0ʱ������ע���ļ���ֱ�ӷ���0��
	
���:

ע��:
(1)�������ڷ���ģʽ������������ʱ���Ʒ�ģ�齫��ʼ��ʧ�ܡ�
(2)���첽��ʽ��mrc_initChargeAnsy������mrc_initCharge��һ��Ӧ����ʹ�ã�
		
����ֵ:
(1)������ֵС��0ʱ����ʾ��ʼ������
(2)������ֵ���ڵ���0ʱ����ʾ����֧���ѽ�����0��ʾ�Ѹ�����ϡ�
*/
int32 mrc_initChargeAnsy(int32 value);


/*
mrc_checkChargeAnsy����˵��:
	�����֧����ע��ѡ�
����:
	value:ע���ļ����շѽ���λΪ�ǡ�

���:
int32 *status:	��ǰ�Ʒ�ģ�鹤��״̬��
						0��ʾ���С�������ϣ�
						1��ʾæ�����ڷ��Ͷ��Ż��ߵȴ�MT�ظ��У�
						2��ʾ��ʱ��
	
����ֵ:
(1)������ֵС��0ʱ����ʾ���ִ�������-1��ʾδ֪����
				-2��ʾ�������ڷ����У�״̬δ����
(2)������ֵ���ڵ���0ʱ����ʾ����֧���ѽ�
ע��:
	��������MO�������ڳ�ʱʱ��������δ�յ�SPȷ��ʱ��
	��ʱ��ѯ�������������-2��
*/
typedef void (*mrc_PayCB)(int32 data);
typedef struct{
		uint16 isReg;//�Ƿ���ע��
		uint32 Option;//�Ƿ�����ǩ���ļ���1:���ɣ�0:�����ɣ�
		uint16 Channel;//�շ�ͨ��
		uint16 value;//�շѽ��
		int32 timeOut;//��ʱʱ�䣬��Ϊ0�򲻵ȴ������̷���
		int32 data;//�����ص������Ĳ�����
		mrc_PayCB fcb;
}PAY_STATUS_t;
int32 mrc_checkChargeAnsy(PAY_STATUS_t *PayStatus);






typedef struct{
		uint32 Option;//�Ƿ�����ǩ���ļ���1:���ɣ�0:�����ɣ�
		uint16 Channel;//�շ�ͨ��
		uint16 value;//�շѽ��
		int32 timeOut;//��ʱʱ�䣬��Ϊ0�򲻵ȴ������̷���
		int32 data;//�����ص������Ĳ�����
		mrc_PayCB fcb;
}PAY_CALLBACK_t;
/*
��������:	mrc_ChargeExAnsy
����˵��:	�ṩ�����չ���շѹ��ܡ�

����:
PayCtrl.Option:	ֵΪ0ʱ����ʾ��д��¼�����ڹ�����ߵȶ�η��͵ĳ��ϣ�
				ֵΪ1ʱ����ʾҪд��¼�����ڲ�Ʒ����ע��ȳ��ϡ������
				���Ѹ��ѵĴ��̼�¼���򱾺������̷��سɹ������ǲ��ָ��ѣ�
				��۳��Ѹ��ѽ�����ȡ��δ���Ѳ��֣�
				
PayCtrl.Channel:	�շ���������˹�����塢���䡣
PayCtrl.value:		�շѽ���λΪ�����0.1Ԫ����15��ʾ1.5Ԫ��30��ʾ3Ԫ�����
				ȡֵ��ΧΪ10����ͨ��SP���ŵĶ�Ӧֵ�����磬1.5��ͨ�����ֵΪ150��

PayCtrl.timeOut:		��ʱʱ�䣬��Ϊ0���򲻵ȴ�����ʱ��ͬ��mrc_ChargeEx������
	����ʱʱ�䵽�����δ�յ�SP�ظ����ţ�����Ϊ���ŷ���ʧ�ܡ�

PayCtrl.data:	�����ص������Ĳ���;

PayCtrl.mrc_PayCB fcb:�ص�������
���:
MR_SUCCESS:�������óɹ���
MR_FAILED:�������ù����г����ص������������Եò���ִ�С�
*/
int32 mrc_ChargeExAnsy(PAY_CALLBACK_t *PayCtrl);

/*
mrc_releaseChargeAnsy����˵��:
	�ͷżƷ�ģ�������Դ��
	
����:
	�ޡ�

���:
MR_SUCCESS:�ɹ��ͷ���Դ��
MR_FAILED:�ͷ�ʧ�ܡ�
*/
int32 mrc_releaseChargeAnsy(void);

/*
checkMonth����˵��:
	����û��Ƿ�Ϊ�����û�
���У��򷵻سɹ������򷵻�ʧ�ܡ�	

����:
	�ޡ�
	
���:
MR_SUCCESS:�û��ǰ����û���
MR_FAILED:�û����ǰ����û���
*/
int32 mrc_checkMonth(void); 

/*
mrc_RegisterSid����˵��:
����ǰ��Ϸ����ǰ�û�����ע���ļ���
(1)�����û���ע�ᣬ�����κβ�����
(2)����ע���ļ������ڣ���������ע���ļ���
(3)����ע���ļ��Ѵ��ڣ����û���IMSI��ӵ�ע���ļ��У�

����:
	�ޡ�
	
���:
MR_SUCCESS:ע��ɹ���
MR_FAILED:ע��ʧ�ܡ�
*/
int32 mrc_RegisterSid(void); 

 typedef enum{
	CHECK_IS_REGISTER=0x00,
	CHECK_IS_FREE=0x01,
	CHECK_IS_MONTHUSER=0x02
}PAY_CHECK_OPTION;


/*
checkChargeEx����˵��:
	mrc_checkChargeEx(CHECK_IS_REGISTER)==MR_SUCCESS���û���ע��Ӧ�ã�
	mrc_checkChargeEx(CHECK_IS_FREE)==MR_SUCCESS����Ϸ�ڸ���Ӫ����ѣ�	
	mrc_checkChargeEx(CHECK_IS_MONTHUSER)==MR_SUCCESS���û��ǰ����û���	

����:
	�ޡ�
	
���:
MR_SUCCESS:����ƥ�䣻
MR_FAILED:����ʧ�ܡ�
*/
int32 mrc_checkChargeEx(int32 Option); 

 typedef enum{
	PAY_MSG_MAGIC=0,	//���߶���
	PAY_MSG_REGISTER,	//ע�����
	PAY_MSG_SCORE			//�շѻ��ֶ���
}PAY_MSG_OPTION;
/*
��������:	mrc_UpLoadSms
����˵��:	�ṩ�����չ���շ��Լ��ϴ����ݹ��ܡ�

����:
Option:	ֵΪ0ʱ����ʾ��д��¼�����ڹ�����ߵȶ�η��͵ĳ��ϣ�
				ֵΪ1ʱ����ʾҪд��¼�����ڲ�Ʒ����ע��ȳ��ϡ������
				���Ѹ��ѵĴ��̼�¼���򱾺������̷��سɹ���
				ֵΪ2ʱ����ʾ��д��¼���ϴ����֡�
				
Channel:	�շ���������˹�����塢���䡣
value:		�շѽ���λΪ�����0.1Ԫ����15��ʾ1.5Ԫ��30��ʾ3Ԫ�����
				ȡֵ��ΧΪ10����ͨ��SP���ŵĶ�Ӧֵ�����磬1.5Ԫ��ͨ�����ֵΪ150��
data:		��Ҫ�ϴ��Ļ������ݣ���OptionΪPAY_MSG_MAGIC��PAY_MSG_REGISTERʱ�����壬Ŀǰֻ��Option=2ʱ
				�����塣Option=PAY_MSG_SCOREʱ��scoreΪ��Ҫ�ϴ��Ļ������ݡ�
���:
MR_SUCCESS:�շѳɹ���
MR_FAILED:�շ�ʧ�ܡ�
*/
int32 mrc_UpLoadSms(uint32 Option,uint16 Channel,uint16 value,int32  data);

//��ȡMPR�Ʒ�ģ��汾�š��Ʒѿ�����Ϣ��ͨ��ID
int32 mrc_GetChnInfo(uint8 *Version,uint16 *CtrFlag,uint8 *ChnID);
#endif
