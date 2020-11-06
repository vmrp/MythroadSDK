#ifndef _SENDSMS_H_
#define _SENDSMS_H_

#define RECORD_FILE_NAME "TestCharge\\pay.dat"
#define VER "V110"
#define DEBUG mrc_printf
// #define CHANNEL_PAYMENT_TEST
// #define DEBUG_ON

#ifdef CHANNEL_PAYMENT_TEST
	#define REG_VALUE 50
	#define ABOUT_STR_SPACE ("PAY_TEST")
#endif
// 移动灵通（2元短信）+联通灵通 
#ifdef CHANNEL_ZS22
	#define REG_VALUE 50
	#define ABOUT_STR_SPACE (" ZS22")
#endif

// 移动灵通（2元短信）+联通创艺 
#ifdef CHANNEL_ZS2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" ZS2_CY2")
#endif

//移动指云（2元彩信）+联通创艺
#ifdef CHANNEL_ZY2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" ZY2_CY2")
#endif

// 移动心情（2元彩信）+联通创艺
#ifdef CHANNEL_XQ2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" XQ2_CY2")
#endif

// 移动滚石（2元短信）+联通创艺
#ifdef CHANNEL_GS2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" GS2_CY2")
#endif

// 移动创艺（2元彩信）+联通创艺
#ifdef CHANNEL_CY22
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" CY22")
#endif

#ifdef CHANNEL_TOM22
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" TOM22")
#endif

// 3元指云彩信（注册）+2元指云彩信（道具）+创意和弦（联通）
//即移动用户注册使用3元指云彩信通道、购买道具使用2元指云彩信通道；
//而联通用户注册和道具均使用2元创艺和弦通道。
#ifdef CHANNEL_ZY3ZY2_CY2
	#define REG_VALUE 30
	#define ABOUT_STR_SPACE (" ZY3ZY2_CY2")
#endif

#define STRING_ABOUT	VER ## " " ## ABOUT_STR_SPACE

//返回通道ID。如果没有找到，则用默认通道返回。
int32 SendSms(uint32 Option, uint16 value);

#endif
