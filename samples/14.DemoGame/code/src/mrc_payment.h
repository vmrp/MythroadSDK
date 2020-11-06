#ifndef SKY_PAYMENT_H
#define SKY_PAYMENT_H
#include "mrc_base.h"

#define PAYMENT
#define PAYMENT_TOM

#define PAY_MAXRESENDTIMES 3
 //共有几个通道，
 typedef enum{
	ZHANGSHANGLINGTONG_2RMB=0,	// 0表示2元掌上灵通的通道，移动1元，联通2元
	PAYMENT_TEST,									// 1表示测试
	ZHIYUNSHIDAI_2RMB, 						// 2 表示指云时代的通道，移动1元，联通2元
	ZHANGSHANGLINGTONG_2RMB_MMS,		// 3表示掌上灵通的2块钱彩信通道，只有移动。
	ZHIYUNSHIDAI_1RMB,						// 4指云时代1RMB联通通道。
	XINQINGHUDONG_1RMB,					// 5心情互动1RMB联通通道。
	GUNSHIYIDONG_2RMB,						// 6滚石移动2RMB，移动、联通均2元。
	CHUANGYIHEXIAN_2RMB,					// 7创意和弦2RMB，移动、联通均2元。
	TOM_2RMB,											// 8TOM通道，移动、联通均2元。
	TOM_TEST2RMB,									// 9TOM测试通道，移动、联通均2元。
	ZHIYUNSHIDAI_2RMB_JS,					// 10指云时代移动1元联通2元，限江苏省使用。其他省份不可用。
	ZHIYUNSHIDAI_2RMB_MMS,				// 11 指云时代彩信通道，移动联通均2元。
	ZHIYUNSHIDAI_1RMB_MT,				// 12指云时代移动多MO单MT，联通多MO多MT通道，移动联通均1元。	
	ZHANGSHANGLINGTONG_2RMB_318,//13掌上灵通2RMB。
	ZHIYUNSHIDAI_ZMCC10MT_UNICOM20,// 14指云时代移动1元，采用单MT下行屏蔽指令、联通2元
	BEIWEI_CMCC10_UNICOM20,			// 15北纬通道，移动1元，联通2元。	
	ZHANGSHANGLINGTONG_20,			//16 和0号通道完全一致，主要是为了和阅读产品兼容而 增加的通道。表示2元掌上灵通的通道，移动1元，联通2元
	PAY_CHN_ZY31,									//17 指云时代移动3元彩信通道，联通使用1元指令。
	PAY_CHN_XQ21,									//18 心情互动移动2元通道，联通使用1元指令。
	INDONESIA_2000RB,							//19印度尼西亚2000卢比通道。
	MAX_PAY_CHANNEL
}PAY_CHANNEL;




/*
initCharge功能说明:
	初始化计费模块，申请各种资源。必须首先调用。
	
输入:
	无。
	
输出:

注意:
		当处于飞行模式、无网络等情况时，计费模块将初始化失败。
		
返回值:
MR_SUCCESS:初始化成功；
MR_FAILED:初始化失败。
*/
int32 mrc_initCharge(void);

/*
函数名称:	mrc_ChargeEx
功能说明:	提供灵活扩展的收费功能。

输入:
Option:	值为0时，表示不写记录，用于购买道具等多次发送的场合；
				值为1时，表示要写记录，用于产品购买注册等场合。若检查
				到已付费的存盘记录，则本函数立刻返回成功。
				
Channel:	收费渠道，由斯凯定义、分配。
value:		收费金额，单位为人民币0.1元。如15表示1.5元，30表示3元。最大
				取值范围为10条该通道SP短信的对应值，例如，1.5的通道最大值为150。

输出:
MR_SUCCESS:收费成功；
MR_FAILED:收费失败。
*/
int32 mrc_ChargeEx(uint32 Option,uint16 Channel,uint16 value);




/*
checkCharge功能说明:
	检查应用所在目录的appname子目录有无成功发送计费短信的签名文件，
若有，则返回成功，否则返回失败。	

输入:
	无。
	
输出:
MR_SUCCESS:找到成功发送了计费短信的合法签名文件；
MR_FAILED:没有找到指定的签名文件或者签名文件不是本手机的。
*/
int32 mrc_checkCharge(void); 



/*
releaseCharge功能说明:
	释放计费模块相关资源。
	
输入:
	无。

输出:
MR_SUCCESS:成功释放资源。
MR_FAILED:释放失败。
*/
int32 mrc_releaseCharge(void);

//对输入的存盘记录进行编码加密。若加密成功，函数将把加密结果
//返回在一块内存**OutputRec中，这块内存由应用负责释放。
//编码类型ENCODE_TYPE=0表示编解码是手机信息相关的。
int32 mrc_EncodeSave(int32 Type,uint8 *InputRec,int32 InputLen,uint8 **OutputRec,int32 *OutputLen);
//对输入的存盘记录进行解码，解码成功，函数将把解码结果返回在
//一块内存**OutputRec中，这块内存由应用负责释放。
int32 mrc_DecodeSave(int32 Type,uint8 *InputRec,int32 InputLen,uint8 **OutputRec,int32 *OutputLen);

//判断游戏在该厂商上是否免费，若是，则返回MR_SUCCESS，否则返回MR_FAILED
int32 mrc_CheckIsFree(void);


/*
mrc_initChargeAnsy功能说明:
	初始化计费模块，申请各种资源。必须首先调用。
	
输入:
	value:注册文件的收费金额；单位为角。当value=0时，忽略注册文件，直接返回0。
	
输出:

注意:
(1)、当处于飞行模式、无网络等情况时，计费模块将初始化失败。
(2)、异步方式的mrc_initChargeAnsy不能与mrc_initCharge在一个应用中使用；
		
返回值:
(1)、返回值小于0时，表示初始化出错；
(2)、返回值大于等于0时，表示尚需支付费金额；等于0表示已付费完毕。
*/
int32 mrc_initChargeAnsy(int32 value);


/*
mrc_checkChargeAnsy功能说明:
	检查已支付的注册费。
输入:
	value:注册文件的收费金额；单位为角。

输出:
int32 *status:	当前计费模块工作状态，
						0表示空闲、处理完毕；
						1表示忙，正在发送短信或者等待MT回复中；
						2表示超时，
	
返回值:
(1)、返回值小于0时，表示出现错误；其中-1表示未知错误；
				-2表示短信正在发送中，状态未定。
(2)、返回值大于等于0时，表示尚需支付费金额；
注意:
	当短信已MO，但是在超时时间内且尚未收到SP确认时，
	此时查询付费情况将返回-2。
*/
typedef void (*mrc_PayCB)(int32 data);
typedef struct{
		uint16 isReg;//是否已注册
		uint32 Option;//是否生成签名文件，1:生成；0:不生成；
		uint16 Channel;//收费通道
		uint16 value;//收费金额
		int32 timeOut;//超时时间，若为0则不等待，立刻返回
		int32 data;//传给回调函数的参数。
		mrc_PayCB fcb;
}PAY_STATUS_t;
int32 mrc_checkChargeAnsy(PAY_STATUS_t *PayStatus);






typedef struct{
		uint32 Option;//是否生成签名文件，1:生成；0:不生成；
		uint16 Channel;//收费通道
		uint16 value;//收费金额
		int32 timeOut;//超时时间，若为0则不等待，立刻返回
		int32 data;//传给回调函数的参数。
		mrc_PayCB fcb;
}PAY_CALLBACK_t;
/*
函数名称:	mrc_ChargeExAnsy
功能说明:	提供灵活扩展的收费功能。

输入:
PayCtrl.Option:	值为0时，表示不写记录，用于购买道具等多次发送的场合；
				值为1时，表示要写记录，用于产品购买注册等场合。若检查
				到已付费的存盘记录，则本函数立刻返回成功，若是部分付费，
				则扣除已付费金额后收取尚未付费部分；
				
PayCtrl.Channel:	收费渠道，由斯凯定义、分配。
PayCtrl.value:		收费金额，单位为人民币0.1元。如15表示1.5元，30表示3元。最大
				取值范围为10条该通道SP短信的对应值，例如，1.5的通道最大值为150。

PayCtrl.timeOut:		超时时间，若为0自则不等待，此时等同于mrc_ChargeEx函数；
	当超时时间到达后尚未收到SP回复短信，则认为短信发送失败。

PayCtrl.data:	传给回调函数的参数;

PayCtrl.mrc_PayCB fcb:回调函数。
输出:
MR_SUCCESS:函数调用成功；
MR_FAILED:函数调用过程中出错，回调函数将被忽略得不到执行。
*/
int32 mrc_ChargeExAnsy(PAY_CALLBACK_t *PayCtrl);

/*
mrc_releaseChargeAnsy功能说明:
	释放计费模块相关资源。
	
输入:
	无。

输出:
MR_SUCCESS:成功释放资源。
MR_FAILED:释放失败。
*/
int32 mrc_releaseChargeAnsy(void);

/*
checkMonth功能说明:
	检查用户是否为包月用户
若有，则返回成功，否则返回失败。	

输入:
	无。
	
输出:
MR_SUCCESS:用户是包月用户。
MR_FAILED:用户不是包月用户。
*/
int32 mrc_checkMonth(void); 

/*
mrc_RegisterSid功能说明:
给当前游戏、当前用户生成注册文件；
(1)、若用户已注册，则不做任何操作；
(2)、若注册文件不存在，则新生成注册文件；
(3)、若注册文件已存在，则将用户的IMSI添加到注册文件中；

输入:
	无。
	
输出:
MR_SUCCESS:注册成功。
MR_FAILED:注册失败。
*/
int32 mrc_RegisterSid(void); 

 typedef enum{
	CHECK_IS_REGISTER=0x00,
	CHECK_IS_FREE=0x01,
	CHECK_IS_MONTHUSER=0x02
}PAY_CHECK_OPTION;


/*
checkChargeEx功能说明:
	mrc_checkChargeEx(CHECK_IS_REGISTER)==MR_SUCCESS，用户已注册应用；
	mrc_checkChargeEx(CHECK_IS_FREE)==MR_SUCCESS，游戏在该运营商免费；	
	mrc_checkChargeEx(CHECK_IS_MONTHUSER)==MR_SUCCESS，用户是包月用户。	

输入:
	无。
	
输出:
MR_SUCCESS:条件匹配；
MR_FAILED:查找失败。
*/
int32 mrc_checkChargeEx(int32 Option); 

 typedef enum{
	PAY_MSG_MAGIC=0,	//道具短信
	PAY_MSG_REGISTER,	//注册短信
	PAY_MSG_SCORE			//收费积分短信
}PAY_MSG_OPTION;
/*
函数名称:	mrc_UpLoadSms
功能说明:	提供灵活扩展的收费以及上传数据功能。

输入:
Option:	值为0时，表示不写记录，用于购买道具等多次发送的场合；
				值为1时，表示要写记录，用于产品购买注册等场合。若检查
				到已付费的存盘记录，则本函数立刻返回成功。
				值为2时，表示不写记录，上传积分。
				
Channel:	收费渠道，由斯凯定义、分配。
value:		收费金额，单位为人民币0.1元。如15表示1.5元，30表示3元。最大
				取值范围为10条该通道SP短信的对应值，例如，1.5元的通道最大值为150。
data:		需要上传的积分数据；当Option为PAY_MSG_MAGIC、PAY_MSG_REGISTER时无意义，目前只有Option=2时
				有意义。Option=PAY_MSG_SCORE时，score为需要上传的积分数据。
输出:
MR_SUCCESS:收费成功；
MR_FAILED:收费失败。
*/
int32 mrc_UpLoadSms(uint32 Option,uint16 Channel,uint16 value,int32  data);

//获取MPR计费模块版本号、计费控制信息和通道ID
int32 mrc_GetChnInfo(uint8 *Version,uint16 *CtrFlag,uint8 *ChnID);
#endif
