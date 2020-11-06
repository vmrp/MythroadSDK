

//返回通道ID。如果没有找到，则用默认通道返回。
uint16 GetPayChn(uint32 Option,uint16 Value)
{
	uint16 Channel;
	int32 NetId=mrc_getNetworkID();
	
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=CHUANGYIHEXIAN_2RMB;//滚石移动联通通道使用创艺和弦的短信通道代替。
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
	Channel=ZHANGSHANGLINGTONG_2RMB_MMS;//掌上灵通只有2块钱的移动彩信通道，联通号码用短信代替。
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
		Channel=ZHIYUNSHIDAI_2RMB;//滚石移动联通通道使用指云时代的短信通道代替。
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
		Channel=ZHANGSHANGLINGTONG_2RMB;//滚石移动联通通道使用掌上灵通的短信通道代替。
	else
		Channel=GUNSHIYIDONG_2RMB;
#endif

// 3元指云彩信（注册）+2元指云彩信（道具）+指云（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元彩信通道；
//而联通用户注册和道具均使用2元指云彩信通道。
#ifdef CHANNEL_ZY3ZY2_ZY2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 3元指云彩信（注册）+2元指云彩信（道具）+灵通（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元指云彩信通道；
//而联通用户注册和道具均使用2元掌上灵通通道。
#ifdef CHANNEL_ZY3ZY2_ZS2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
		else
			Channel=ZHANGSHANGLINGTONG_2RMB;
#endif


// 3元指云彩信（注册）+2元滚石（道具）+指云（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元滚石通道；
//而联通用户注册和道具均使用2元指云时代通道。
#ifdef CHANNEL_ZY3GS2_ZY2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 3元指云彩信（注册）+2元滚石（道具）+指云（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元滚石通道；
//而联通用户注册和道具均使用2元掌上灵通通道。
#ifdef CHANNEL_ZY3GS2_ZS2
		if(1==Option && NetId==MR_NET_ID_MOBILE)
			Channel=PAY_CHN_ZY31;
		else if(0==Option && NetId==MR_NET_ID_MOBILE)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=ZHANGSHANGLINGTONG_2RMB;
#endif

// 2元心情彩信（移动）+指云（联通）
#ifdef CHANNEL_XQ2_ZY2
	if(NetId==MR_NET_ID_MOBILE)
		Channel=PAY_CHN_XQ21;
	else
		Channel=ZHIYUNSHIDAI_2RMB_MMS;
#endif

// 2元心情彩信（移动）+灵通（联通）
#ifdef CHANNEL_XQ2_ZS2
	if(NetId==MR_NET_ID_MOBILE)
		Channel=PAY_CHN_XQ21;
	else
		Channel=ZHANGSHANGLINGTONG_2RMB;
#endif





// 移动灵通（2元短信）+联通创艺
#ifdef CHANNEL_ZS2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=ZHANGSHANGLINGTONG_2RMB_318;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// 移动灵通（2元短信）+联通创艺
#ifdef CHANNEL_ZS22
		Channel=ZHANGSHANGLINGTONG_2RMB_318;
#endif

//移动指云（2元彩信）+联通创艺
#ifdef CHANNEL_ZY2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=ZHIYUNSHIDAI_2RMB_MMS;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// 移动心情（2元彩信）+联通创艺
#ifdef CHANNEL_XQ2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=PAY_CHN_XQ21;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// 移动滚石（2元短信）+联通创艺
#ifdef CHANNEL_GS2_CY2
		if(MR_NET_ID_MOBILE==NetId)
			Channel=GUNSHIYIDONG_2RMB;
		else
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

// 移动创艺（2元彩信）+联通创艺
#ifdef CHANNEL_CY22
			Channel=CHUANGYIHEXIAN_2RMB;
#endif

#ifdef CHANNEL_TOM22
	Channel=TOM_2RMB;
#endif

// 3元指云彩信（注册）+2元指云彩信（道具）+创意和弦（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元指云彩信通道；
//而联通用户注册和道具均使用2元创艺和弦通道。
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
		DBG_PRINTF(("不是同一天则没有必要检查限额，直接发送。"));
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
	{//是同一天，检查限额情况。
		if((PayedValue+value)>400)
		{
			DBG_PRINTF(("每天最高限额40RMB。超过限额直接返回计费成功。"));
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