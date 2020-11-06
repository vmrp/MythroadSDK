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
// �ƶ���ͨ��2Ԫ���ţ�+��ͨ��ͨ 
#ifdef CHANNEL_ZS22
	#define REG_VALUE 50
	#define ABOUT_STR_SPACE (" ZS22")
#endif

// �ƶ���ͨ��2Ԫ���ţ�+��ͨ���� 
#ifdef CHANNEL_ZS2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" ZS2_CY2")
#endif

//�ƶ�ָ�ƣ�2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_ZY2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" ZY2_CY2")
#endif

// �ƶ����飨2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_XQ2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" XQ2_CY2")
#endif

// �ƶ���ʯ��2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_GS2_CY2
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" GS2_CY2")
#endif

// �ƶ����գ�2Ԫ���ţ�+��ͨ����
#ifdef CHANNEL_CY22
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" CY22")
#endif

#ifdef CHANNEL_TOM22
	#define REG_VALUE 20
	#define ABOUT_STR_SPACE (" TOM22")
#endif

// 3Ԫָ�Ʋ��ţ�ע�ᣩ+2Ԫָ�Ʋ��ţ����ߣ�+������ң���ͨ��
//���ƶ��û�ע��ʹ��3Ԫָ�Ʋ���ͨ�����������ʹ��2Ԫָ�Ʋ���ͨ����
//����ͨ�û�ע��͵��߾�ʹ��2Ԫ���պ���ͨ����
#ifdef CHANNEL_ZY3ZY2_CY2
	#define REG_VALUE 30
	#define ABOUT_STR_SPACE (" ZY3ZY2_CY2")
#endif

#define STRING_ABOUT	VER ## " " ## ABOUT_STR_SPACE

//����ͨ��ID�����û���ҵ�������Ĭ��ͨ�����ء�
int32 SendSms(uint32 Option, uint16 value);

#endif
