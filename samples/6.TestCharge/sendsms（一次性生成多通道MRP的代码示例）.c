

//����ͨ��ID�����û���ҵ�������Ĭ��ͨ�����ء�
uint16 GetPayChn(uint32 Option,uint16 Value)
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
	Channel=PAYMENT_TEST;
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

int32 SendSms(uint32 Option,uint16 value)
{
	int32 ret;
	mr_datetime CurDate;
	mrc_getDatetime(&CurDate);

	af_ReadPay();
	DBG_PRINTF(("\nPayDateTime(%2d-%2d-%2d:Payed%3d),CurDate(%2d-%2d-%2d:Value%3d);",
		PayDateTime.year,
		PayDateTime.month,
		PayDateTime.year,
		PayedValue,
		CurDate.year,
		CurDate.month,
		CurDate.day,
		value
	));
	if(PayDateTime.year!=CurDate.year
		||PayDateTime.month!=CurDate.month
		||PayDateTime.day!=CurDate.day)
	{
		DBG_PRINTF(("����ͬһ����û�б�Ҫ����޶ֱ�ӷ��͡�"));
		PayDateTime.year=CurDate.year;
		PayDateTime.month=CurDate.month;
		PayDateTime.day=CurDate.day;
		PayedValue=value;

		ret=mrc_ChargeEx(Option,GetPayChn(Option,value),value);
		if(MR_SUCCESS == ret)
		{
			af_WritePay();			
		}
		return ret;
	}
	else 
	{//��ͬһ�죬����޶������
		if((PayedValue+value)>400)
		{
			DBG_PRINTF(("ÿ������޶�40RMB�������޶�ֱ�ӷ��ؼƷѳɹ���"));
			return MR_SUCCESS;
		}
		PayedValue+=value;
		ret=mrc_ChargeEx(Option,GetPayChn(Option,value),value);		
		if(MR_SUCCESS == ret)
		{
			af_WritePay();			
		}
		return ret;	
	}
}