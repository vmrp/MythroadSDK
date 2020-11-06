#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_payment.h"

#include "sendsms.h"
#include "encode.h"

static uint16 GetPayChn(uint32 Option,uint16 Value);
int32 ReadPay(char* recordName);
int32 WritePay(char* recordName);
int32 SendSms(uint32 Option, uint16 value);

//����ͨ��ID�����û���ҵ�������Ĭ��ͨ�����ء�
static uint16 GetPayChn(uint32 Option,uint16 Value)
{
	uint16 Channel;
	int32 NetId=mrc_getNetworkID();
	
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=CHUANGYIHEXIAN_2RMB;//��ʯ�ƶ���ͨͨ��ʹ�ô��պ��ҵĶ���ͨ�����档
	else
		Channel=GUNSHIYIDONG_2RMB;	
	
#ifdef CHANNEL_ZHANGSHANGLINGTONG_2RMB	
	Channel=ZHANGSHANGLINGTONG_2RMB;
#endif

#ifdef CHANNEL_PAYMENT_TEST
	Channel = PAYMENT_TEST;
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_2RMB
	Channel=ZHIYUNSHIDAI_2RMB;
#endif

#ifdef CHANNEL_ZHANGSHANGLINGTONG_2RMB_MMS
	Channel=ZHANGSHANGLINGTONG_2RMB_MMS;//������ֻͨ��2��Ǯ���ƶ�����ͨ������ͨ�����ö��Ŵ��档
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_1RMB
	Channel=ZHIYUNSHIDAI_1RMB;
#endif

#ifdef CHANNEL_XINQINGHUDONG_1RMB
		Channel=XINQINGHUDONG_1RMB;
#endif

#ifdef CHANNEL_GUNSHIYIDONG_2RMB
	Channel=GUNSHIYIDONG_2RMB;
#endif

#ifdef CHANNEL_GUNSHIZHIYUN_2RMB
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=ZHIYUNSHIDAI_2RMB;//��ʯ�ƶ���ͨͨ��ʹ��ָ��ʱ���Ķ���ͨ�����档
	else
		Channel=GUNSHIYIDONG_2RMB;
#endif

#ifdef CHANNEL_CHUANGYIHEXIAN_2RMB
	Channel=CHUANGYIHEXIAN_2RMB;
#endif

#ifdef CHANNEL_TOM_2RMB
	Channel=TOM_2RMB;
#endif

#ifdef CHANNEL_TOM_TEST2RMB
	Channel=TOM_TEST2RMB;
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_2RMB_JS
	Channel=ZHIYUNSHIDAI_2RMB_JS;
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_2RMB_MMS
	Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_1RMB_MT
	Channel=ZHIYUNSHIDAI_1RMB_MT;
#endif

#ifdef CHANNEL_ZHANGSHANGLINGTONG_2RMB_318
	Channel=ZHANGSHANGLINGTONG_2RMB_318;
#endif

#ifdef CHANNEL_ZHIYUNSHIDAI_CMCC10MT_UNICOM20
	Channel=ZHIYUNSHIDAI_ZMCC10MT_UNICOM20;
#endif

#ifdef CHANNEL_BEIWEI_CMCC10_UNICOM20
	Channel=BEIWEI_CMCC10_UNICOM20;
#endif

#ifdef CHANNEL_GUNSHIZHANGSHANG_2RMB
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=ZHANGSHANGLINGTONG_2RMB;//��ʯ�ƶ���ͨͨ��ʹ��������ͨ�Ķ���ͨ�����档
	else
		Channel=GUNSHIYIDONG_2RMB;
#endif

// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫָ�Ʋ��ţ����ߣ�+ָ�ƣ���ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫ����ͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫָ�Ʋ���ͨ����
#ifdef CHANNEL_ZY3ZY2_ZY2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫָ�Ʋ��ţ����ߣ�+��ͨ����ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫָ�Ʋ���ͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫ������ͨͨ����
#ifdef CHANNEL_ZY3ZY2_ZS2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
		else
			Channel=ZHANGSHANGLINGTONG_2RMB;
#endif


// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫ��ʯ�����ߣ�+ָ�ƣ���ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫ��ʯͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫָ��ʱ��ͨ����
#ifdef CHANNEL_ZY3GS2_ZY2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫ��ʯ�����ߣ�+ָ�ƣ���ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫ��ʯͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫ������ͨͨ����
#ifdef CHANNEL_ZY3GS2_ZS2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=ZHANGSHANGLINGTONG_2RMB;
#endif

// 2Ԫ������ţ��ƶ���+ָ�ƣ���ͨ��
#ifdef CHANNEL_XQ2_ZY2
	if(NetId==MR_NET_ID_MOBILE)
		Channel=PAY_CHN_XQ21;
	else
		Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 2Ԫ������ţ��ƶ���+��ͨ����ͨ��
#ifdef CHANNEL_XQ2_ZS2
	if(NetId==MR_NET_ID_MOBILE)
		Channel=PAY_CHN_XQ21;
	else
		Channel=ZHANGSHANGLINGTONG_2RMB;
#endif

// �ƶ���ͨ��2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_ZS2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=ZHANGSHANGLINGTONG_2RMB_318;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// �ƶ���ͨ��2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_ZS22
		Channel=ZHANGSHANGLINGTONG_2RMB_318;
#endif

//�ƶ�ָ�ƣ�2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_ZY2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// �ƶ����飨2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_XQ2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=PAY_CHN_XQ21;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// �ƶ���ʯ��2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_GS2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// �ƶ����գ�2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_CY22
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

#ifdef CHANNEL_TOM22
	Channel=TOM_2RMB;
#endif

// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫָ�Ʋ��ţ����ߣ�+������ң���ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫָ�Ʋ���ͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫ���պ���ͨ����
#ifdef CHANNEL_ZY3ZY2_CY2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

	return Channel;
}

 //����MD5ʱ�ڴ�������ַ����������˽��priKey,���ⶨ��.������Ϣʱ,�ö����ݲ�����.
int32 ReadPay(char* recordName)
{
	uint8* buf = NULL;
	uint8 md5[16] = {0};
	char priKey[33];
	uint8* bufIn;
// 	uint8 oldMd5[16] = {0};
	int32 len=0;
	int32 fileLen = 0;
	uint8* tmp = NULL;
	#ifdef DEBUG_ON
	uint8 str1[33] = {0};
	uint8 str2[33] = {0};
	#endif

	if(mrc_UserInfoMD5(0,priKey)!=MR_SUCCESS)
		return MR_FAILED;
	len=strlen(priKey);
	 bufIn= mrc_malloc(sizeof(SAVE_RECORD_T)+1+len);	
	if(NULL == bufIn)
		return MR_FAILED;
	memset(bufIn, 0, sizeof(SAVE_RECORD_T)+1+len);



	if (0 == fd && (MR_IS_FILE == mrc_fileState(recordName)))
	{
		fileLen = mrc_getLen(recordName);
		
//  	if(fileLen > 16)			//�ļ�������16���ֽڵ�����
		if(fileLen > 0)
		{
			fd = mrc_open(recordName, MR_FILE_RDONLY);

			if(fd)
			{
				len = 0;
				tmp = mrc_malloc(fileLen);

// 				tmp = mrc_malloc(fileLen - sizeof(g_record->MD5));
				if(NULL== tmp)
					return MR_FAILED;
				
				memset(tmp, 0, fileLen);
// 				memset(tmp, 0, fileLen - sizeof(g_record->MD5));				
				mrc_read(fd, tmp, fileLen);
// 				mrc_read(fd, tmp, fileLen - sizeof(g_record->MD5));
				
// 				mrc_read(fd, oldMd5, sizeof(oldMd5));
				
// 				md5Make(tmp, fileLen - sizeof(g_record->MD5), md5);
				
// 		#ifdef DEBUG_ON		//��ӡ��MDֵ
// 				md5ToString(oldMd5, str1);
// 				md5ToString(md5, str2);
// 				mrc_printf("---File---OldMd5-[%s]---CurMd5-[%s]---", str1, str2);
// 		#endif
// 				//���ڵ���ƽ̨mrc_EncodeSave����,�����ļ��޸ĺ�ʵ�ʼ��ܵ��ǲ���δ���޸�,�����Ƚϼ�������
// 				if(0 == memcmp(md5, oldMd5, sizeof(md5)))
// 					mrc_printf("-----File is the same -----");
// 				else
// 					mrc_printf("----Someone changed the file------");
				
				mrc_DecodeSave(0, tmp, fileLen, &buf, &len);
				
// 				mrc_free(tmp), tmp = NULL;

				if (1 == buf[0]) 
				{
					//��ȡ�ļ��б������Ϣ
					len = 0;
					len++;
					memcpy(&g_record->MD5, buf+len, sizeof(g_record->MD5));
					len += sizeof(g_record->MD5);
					memcpy(&g_record->Score, buf+len, sizeof(uint32));
					len +=  sizeof(uint32);
					memcpy(&g_record->Payed, buf+len, sizeof(uint32));
					len += sizeof(uint32);
					memcpy(&g_record->PayedDate, buf+len, sizeof(mr_datetime));
					len += sizeof(mr_datetime);
					memcpy(&g_record->Reserved, buf+len, sizeof(uint32));

					//�����ļ��б�����Ϣ��MD5,����ļ��Ƿ��޸�
					len = 0;
					bufIn[0] = 1;	//У��encodesave
					len ++;
				 	len += sizeof(g_record->MD5);
					memcpy(bufIn+len, &g_record->Score, sizeof(uint32));
					len +=  sizeof(uint32);
					memcpy(bufIn+len, &g_record->Payed, sizeof(uint32));
					len += sizeof(uint32);
					memcpy(bufIn+len, &g_record->PayedDate, sizeof(mr_datetime));
					len += sizeof(mr_datetime);
					memcpy(bufIn+len, &g_record->Reserved, sizeof(uint32));
					len += sizeof(uint32);
					memcpy(bufIn+len, priKey, strlen(priKey));
					len += strlen(priKey);
					
					memset(md5, 0, sizeof(md5));
					md5Make(bufIn, len, md5);

		#ifdef DEBUG_ON		//��ӡ��MDֵ
					memset(str1, 0, sizeof(str1));
					memset(str2, 0, sizeof(str2));
					md5ToString(g_record->MD5, str1);
					md5ToString(md5, str2);
					mrc_printf("---Content---OldMd5-[%s]---CurMd5-[%s]---", str1, str2);
		#endif
		
					mrc_close(fd), fd = 0;
			
					mrc_free(bufIn), bufIn = NULL;
					
					if (0 == memcmp(g_record->MD5, md5, sizeof(md5)))
					{
						mrc_printf("-----Content is the same -----");
						return MR_SUCCESS;
					}
					else
					{
 						mrc_printf("-----Content is changed-----");
						return MR_FAILED;
					}
				}
				else
				{
// 					mrc_free(tmp), tmp = NULL;
					mrc_free(bufIn), bufIn = NULL;
					return MR_FAILED;
				}
			}
			else
			{
				mrc_free(bufIn), bufIn = NULL;
				return MR_FAILED;
			}
		}
		else
		{
			mrc_free(bufIn), bufIn = NULL;
			return MR_FAILED;
		}
	}
	else
	{
		mrc_free(bufIn), bufIn = NULL;
		return MR_IGNORE;
	}
}

 //����MD5ʱ�ڴ�������ַ����������˽�е���ԿpriKey
 //priKey�ɿ����߷��䣬ע�����ֵ�ڸ���Ϸ�����а汾�б�����ͬ��
 //һ��ȷ�����Ͳ������޸ģ�������Ϣʱ,priKey���ݲ�������.
//char* priKey = "TestCharge";

int32 WritePay(char* recordName)
{
	uint8* buf = NULL;
	int32 bufLen = 0;
	char priKey[33];

	uint8 md5[16] = {0};
	int32 len = 0;
	uint8* tmp = NULL;
	uint8* bufIn = NULL;
#ifdef DEBUG_ON
	uint8 str1[33] = {0};
#endif

	if(mrc_UserInfoMD5(0,priKey)!=MR_SUCCESS)
		return MR_FAILED;
	len=strlen(priKey);
	tmp = mrc_malloc(sizeof(SAVE_RECORD_T) + 1 + len);
	if(NULL == tmp)
		return MR_FAILED;
	
	bufIn = mrc_malloc(sizeof(SAVE_RECORD_T)+1);
	if(NULL == bufIn)
		return MR_FAILED;
	
	memset(tmp, 0, sizeof(SAVE_RECORD_T) + 1 + len );
	memset(bufIn, 0, sizeof(SAVE_RECORD_T)+1);
	
	len = 0;
	tmp[0] = 1;						//У��encodesave
	len ++;	
 	//��鱣��ṹ��Ϣʱ,g_record->MD5ֵΪ0,������MD5���ٽ��������MD5���浽�ṹ��
	len += sizeof(g_record->MD5);

	memcpy(tmp+len, &g_record->Score, sizeof(uint32));
	len +=  sizeof(uint32);
	memcpy(tmp+len, &g_record->Payed, sizeof(uint32));
	len += sizeof(uint32);
	memcpy(tmp+len, &g_record->PayedDate, sizeof(mr_datetime));
	len += sizeof(mr_datetime);
	memcpy(tmp+len, &g_record->Reserved, sizeof(uint32));
	len += sizeof(uint32);
	memcpy(tmp+len, priKey, strlen(priKey));
	len += strlen(priKey);

	md5Make(tmp, len, md5);

#ifdef DEBUG_ON		//��ӡ��MDֵ
	md5ToString(md5, str1);
	mrc_printf("-----CurMd5-[%s]---", str1);
#endif

	len -= strlen(priKey); 

	//����������MD5ֵ
	memcpy(tmp+1, md5, sizeof(g_record->MD5));

	//priKey������
	memcpy(bufIn, tmp, len);

	if(MR_SUCCESS == mrc_EncodeSave(0, bufIn, sizeof(SAVE_RECORD_T)+1, &buf, &bufLen))
	{
// 		memset(md5, 0, sizeof(md5));
// 		md5Make(buf, bufLen, md5);
// 		
// #ifdef DEBUG_ON		//��ӡ��MDֵ
// 		memset(str1, 0, sizeof(str1));
// 		md5ToString(md5, str1);
// 		mrc_printf("--file--[%s]---", str1);
// #endif
		
		if(0 == fd)
		{
			mrc_remove(recordName);
			fd = mrc_open(recordName, MR_FILE_CREATE|MR_FILE_RDWR);
		}

		if(fd)
		{
			mrc_write(fd, buf, bufLen);			//�����ṹ���ܺ������
// 			mrc_write(fd, md5, sizeof(md5));	//�����ṹ���ܺ�����ݵ�MD5ֵ
			mrc_close(fd), fd = 0;
			mrc_free(tmp), tmp = NULL;
			mrc_free(bufIn), bufIn = NULL;
			return MR_SUCCESS;
		}
		else
		{
			mrc_free(tmp), tmp = NULL;
			mrc_free(bufIn), bufIn = NULL;
			return MR_FAILED;
		}
	}
	else
	{
		mrc_free(tmp), tmp = NULL;
		mrc_free(bufIn), bufIn = NULL;
		return MR_FAILED;
	}
}


int32 SendSms(uint32 Option, uint16 value)
{
	int32 ret;
	mr_datetime CurDate;
	mrc_getDatetime(&CurDate);

	ret = ReadPay(RECORD_FILE_NAME);
		
	if (MR_FAILED == ret)			//���ļ����޸Ļ򲻴���ֱ��д�ļ�,������ȡ����Ϣɾ��
	{
		memset(g_record, 0, sizeof(SAVE_RECORD_T));

		memcpy(&g_record->PayedDate, &CurDate, sizeof(mr_datetime));

		g_record->Payed = value;

		ret = mrc_ChargeEx(Option, GetPayChn(Option, value), value);
		if(MR_SUCCESS == ret)
		{
			WritePay(RECORD_FILE_NAME);			
		}
		return ret;
	}
// 
// 	DEBUG("\nPayDateTime(%2d-%2d-%2d:Payed%3d),CurDate(%2d-%2d-%2d:Value%3d);",
// 		PayDateTime.year,
// 		PayDateTime.month,
// 		PayDateTime.year,
// 		PayedValue,
// 		CurDate.year,
// 		CurDate.month,
// 		CurDate.day,
// 		value
// 	);
	if(g_record->PayedDate.year!=CurDate.year
		||g_record->PayedDate.month!=CurDate.month
		||g_record->PayedDate.day!=CurDate.day)
	{
// 		DEBUG("����ͬһ����û�б�Ҫ����޶ֱ�ӷ��͡�");
		memcpy(&g_record->PayedDate, &CurDate, sizeof(mr_datetime));

		g_record->Payed = value;

		ret = mrc_ChargeEx(Option, GetPayChn(Option, value), value);
		if(MR_SUCCESS == ret)
		{
			WritePay(RECORD_FILE_NAME);			
		}
		return ret;
	}
	else 
	{//��ͬһ�죬����޶������
		if((g_record->Payed + value)>400)
		{
			DEBUG("ÿ������޶�40RMB�������޶�ֱ�ӷ��ؼƷѳɹ���");
			return MR_SUCCESS;
		}
		g_record->Payed += value;
		ret = mrc_ChargeEx(Option, GetPayChn(Option,value), value);		
		if(MR_SUCCESS == ret)
		{
			WritePay(RECORD_FILE_NAME);			
		}
		return ret;	
	}
}
