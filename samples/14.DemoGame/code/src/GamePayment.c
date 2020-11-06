#include "gamepayment.h"
#include "gamemainmenu.h"
#include "gamecommon.h"
#include "mrc_win.h"



#define 	TOOLBAR_H             26
#define 	BUTTON_COLOR		100,200,100
typedef enum
{
	REG_STATUS_WAIT,//µÈµ½ÓÃ»§Ñ¡ÔñÊÇ·ñÒª×¢²á
	REG_STATUS_SUC,//×¢²á³É¹¦£¬µÈµ½ÓÃ»§·µ»Ø¼ÌÐøÓÎÏ·
	REG_STATUS_FAILED//×¢²áÊ§°Ü£¬µÈµ½ÓÃ»§·µ»Ø
}REG_STATU_T;


uint8 g_is_have_reg;//ÊÇ·ñÒÑ¾­×¢²á³É¹¦
uint8 g_reg_status;//×¢²á´°¿Ú×´Ì¬
int32 g_exit_game_win_id;//ÍË³öÓÎÏ·Ñ¯ÎÊ¶Ô»°¿ò
uint8 g_exit_game_status;//ÍË³öÓÎÏ·Ê±ºò£¬ÓÎÏ·µÄ×´Ì¬
int32 g_game_reg_win_id;// ÓÎÏ·×¢²á´°¿Úid
int32 g_init_win_id;//ÊÕ·ÑÄ£¿é³õÊ¼»¯Ê§°ÜÌáÊ¾´°¿Ú
/////////////////////////////////////
void InitPayErrorWinHandle(int32 data, int32 eventId);
void InitPayErrorKeyHandle(int32 data, int32 type, int32 p1, int32 p2);
void PaintInitPayErrorWinFace(void);
////////////////////////////////////
int32 InitGamePayment(void)
{
	g_is_have_reg = 0;
	g_reg_status = REG_STATUS_WAIT;	
	g_game_reg_win_id = -1;
	return mrc_initCharge();
}


void StartPay()
{
	g_game_reg_win_id = mrc_winNew(0,PayWinHandle,PayKeyHandle);
}


void PayWinHandle(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_PAUSE:
		break;

	case WIN_EVENT_SHOW:
	case WIN_EVENT_REFRESH:
		RegisterGame();
		break;
	case WIN_EVENT_EXIT:
		g_game_reg_win_id = -1;
		break;
	default:
		break;
	}
}


void PayKeyHandle(int32 data, int32 type, int32 p1, int32 p2)
{
	switch(type)
	{
	case MR_KEY_PRESS:
		break;
	case MR_KEY_RELEASE:
		if( p1 ==  MR_KEY_SOFTLEFT)
		{
			//×¢²áµÄÊ±ºòÐèÒªÐ´SIDÇ©ÃûÎÄ¼þ

			//ÓÉÓÚ°´¼üÊÂ¼þÊÇÍ¨¹ý¶¨Ê±Æ÷À´´¦Àí
			//·ÀÖ¹ÖØ¸´×¢²á
			if( g_is_have_reg  || mrc_checkCharge() == MR_SUCCESS )
			{
				g_reg_status = REG_STATUS_SUC;
				g_is_have_reg = 1;
				mrc_winResume();
				return;
			}

			
			if(SendSms(1,GAME_REGISTER_MONEY) == MR_SUCCESS)
			{
				g_is_have_reg = 1;
				g_reg_status = REG_STATUS_SUC;
			}
			else
			{
				g_reg_status = REG_STATUS_FAILED;
			}
			mrc_winResume();
		}
		else if ( p1 ==  MR_KEY_SOFTRIGHT )
		{
			if( g_is_have_reg )
			{
				//ÓÎÏ·ÒÑ¾­×¢²á³É¹¦£¬µã»÷·µ»Ø¿ÉÒÔ¼ÌÐøÓÎÏ·
				//¸¶·Ñ³É¹¦ÒÔºó£¬½øÈëÕý³£ÓÎÏ·×´Ì¬

				//fix bug here,ÕâÐ©ÐèÒªÏÈ¹Ø±Õ×¢²áÐÅÏ¢´°¿Ú£¬ÔÙÆô¶¯ÓÎÏ·½çÃæ
				mrc_winCloseNotShow();
				MainMenuStartGame();
			}
			else
			{
				//ÓÃ»§¾ö¾ø×¢²á»òÕß×¢²áÊ§°Ü,·µ»Øµ½Ö÷²Ëµ¥½çÃæ
				//Marbles_SetStatus(STATUS_MENU);
				g_reg_status = REG_STATUS_WAIT;
				mrc_winClose();
			}
			
		}
		break;

	case MR_MOUSE_DOWN:
		break;

	case MR_MOUSE_UP:
		break;
	}
}

void RegisterGame(void)
{
	if( g_reg_status == REG_STATUS_WAIT )
	{
		char* left = "\x6c\xe8\x51\x8c\x00\x00";//×¢²á
		char* right = "\x53\xd6\x6d\x88\x00\x00";//È¡Ïû
		//ÓÎÏ·ÐèÒªÏÈ×¢²á²ÅÄÜÊ¹ÓÃ£¬×¢²á·Ñ2Ôª£¬ÊÇ·ñ×¢²á?
		char* content  = "\x6e\x38\x62\x0f\x97\x00\x89\x81\x51\x48\x6c\xe8\x51\x8c\x62\x4d\x80\xfd\x4f\x7f\x75\x28\xff\x0c\x6c\xe8\x51\x8c\x8d\x39\x00\x32\x51\x43\xff\x0c\x66\x2f\x54\x26\x6c\xe8\x51\x8c\x00\x3f\x00\x00";
		DrawTextFace(left,right,content);
	}
	else if( g_reg_status == REG_STATUS_SUC )
	{
		 char* right = "\x8f\xd4\x56\xde\x00\x00";//·µ»Ø
		//ÓÎÏ·×¢²á³É¹¦£¬°´·µ»Ø¼ÌÐøÓÎÏ·¡£
		char* content = "\x6e\x38\x62\x0f\x6c\xe8\x51\x8c\x62\x10\x52\x9f\xff\x0c\x63\x09\x8f\xd4\x56\xde\x7e\xe7\x7e\xed\x6e\x38\x62\x0f\x30\x02\x00\x00";
		DrawTextFace(NULL,right,content);
	}
	else if( g_reg_status == REG_STATUS_FAILED)
	{
		//¸¶·ÑÊ§°Ü£¬·µ»ØÖ÷²Ëµ¥
		char* right = "\x8f\xd4\x56\xde\x00\x00";//·µ»Ø
		//×¢²áÊ§°Ü£¬ÇëÉÔºòÔÙÊÔ...
		char* content = "\x6c\xe8\x51\x8c\x59\x31\x8d\x25\xff\x0c\x8b\xf7\x7a\x0d\x50\x19\x51\x8d\x8b\xd5\x00\x2e\x00\x2e\x00\x2e\x00\x00";
		DrawTextFace(NULL,right,content);
	}

}

int32 SendSms(int Option,int value)
{
	uint16 Channel = ZHIYUNSHIDAI_2RMB;
	int32 NetId=mrc_getNetworkID();
	

	if( NetId == MR_NET_ID_NONE )
		return MR_FAILED;

	Channel = GetPayChannel();
	return mrc_ChargeEx(Option,Channel,value);		
	
}


//»ñÈ¡ÊÕ·ÑÍ¨µÀ,±ØÐëÔÚmprÎÄ¼þÀïÃæ¶¨ÒåÊÕ·ÑÍ¨µÀµÄºê
int32 GetPayChannel(void)
{
	int32 Channel = ZHIYUNSHIDAI_ZMCC10MT_UNICOM20;
	int32 NetId = mrc_getNetworkID();
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=ZHIYUNSHIDAI_ZMCC10MT_UNICOM20;//¹öÊ¯ÒÆ¶¯ÁªÍ¨Í¨µÀÊ¹ÓÃÖ¸ÔÆÊ±´úµÄ¶ÌÐÅÍ¨µÀ´úÌæ¡£
	else
		Channel=GUNSHIYIDONG_2RMB;	
	
#ifdef CHANNEL_ZHANGSHANGLINGTONG_2RMB	
	Channel=ZHANGSHANGLINGTONG_2RMB;
#endif

#ifdef CHANNEL_PAYMENT_TEST
	Channel=PAYMENT_TEST;
#endif

#ifdef CHANNEL_ZHANGSHANGLINGTONG_2RMB_MMS
	Channel=ZHANGSHANGLINGTONG_2RMB_MMS;//ÕÆÉÏÁéÍ¨Ö»ÓÐ2¿éÇ®µÄÒÆ¶¯²ÊÐÅÍ¨µÀ£¬ÁªÍ¨ºÅÂëÓÃ¶ÌÐÅ´úÌæ¡£
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
		Channel=ZHIYUNSHIDAI_ZMCC10MT_UNICOM20;//¹öÊ¯ÒÆ¶¯ÁªÍ¨Í¨µÀÊ¹ÓÃÖ¸ÔÆÊ±´úµÄ¶ÌÐÅÍ¨µÀ´úÌæ¡£
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

	//Ìí¼Ó±±Î³Í¨µÀ
#ifdef CHANNEL_BEIWEI_CMCC10_UNICOM20
	Channel=BEIWEI_CMCC10_UNICOM20;
#endif

#ifdef CHANNEL_GUNSHIZHANGSHANG_2RMB
	if(NetId!=MR_NET_ID_MOBILE)
		Channel=ZHANGSHANGLINGTONG_2RMB;//¹öÊ¯ÒÆ¶¯ÁªÍ¨Í¨µÀÊ¹ÓÃÕÆÉÏÁéÍ¨µÄ¶ÌÐÅÍ¨µÀ´úÌæ¡£
	else
		Channel=GUNSHIYIDONG_2RMB;
#endif

	return Channel;
}

#define CHANNEL_GUNSHIZHANGSHANG_2RMB
//»ñÈ¡ÊÕ·ÑÍ¨µÀËõÐ´Ãû³Æ,Ö»ÄÜ¸ù¾ÝmprÎÄ¼þÖÐ¶¨ÒåµÄºêÀ´»ñÈ¡¶ÌÃû´Ê
char* GetChannelShortName(void)
{
	char* Channel = "ErrChannel";

	#if  defined(CHANNEL_ZHANGSHANGLINGTONG_2RMB)	
		Channel = "ZS12";
	
	#elif  defined(CHANNEL_PAYMENT_TEST)
		Channel = "TEST";

	#elif defined(CHANNEL_ZHANGSHANGLINGTONG_2RMB_MMS)
		Channel="ZSCX22";

	#elif defined(CHANNEL_XINQINGHUDONG_1RMB)
		Channel = "CQ11";

	#elif defined(CHANNEL_GUNSHIYIDONG_2RMB)
		Channel = "GS22";

	#elif defined(CHANNEL_GUNSHIZHIYUN_2RMB)
		Channel = "GSZY22";

	#elif defined(CHANNEL_CHUANGYIHEXIAN_2RMB)
		Channel = "CY22";

	#elif defined(CHANNEL_TOM_2RMB)
		Channel = "TOM22";

	#elif defined(CHANNEL_ZHIYUNSHIDAI_2RMB_MMS)
		Channel = "ZYCX22";

	#elif defined(CHANNEL_ZHIYUNSHIDAI_1RMB_MT)
		Channel = "ZYMT11";

	#elif defined(CHANNEL_ZHANGSHANGLINGTONG_2RMB_318)
		Channel = "ZS22";

	#elif defined(CHANNEL_ZHIYUNSHIDAI_CMCC10MT_UNICOM20)
		Channel = "ZYMT12";
		
	#elif defined(CHANNEL_BEIWEI_CMCC10_UNICOM20)
		Channel = "BW12";
		
	#elif defined(CHANNEL_GUNSHIZHANGSHANG_2RMB)
		Channel = "GSZS22";
	#endif
	
	return Channel;
	
}


void DrawTextFace( char* left, char* right,char* content)
{
	//int16 x,y,w,h,l,tmp;
	int32 font_w,font_h;
	mr_screenRectSt rect;
	mr_colourSt colorst;


	if( NULL == content )
	{
		return;
	}

	colorst.r = 100;
	colorst.g = 200;
	colorst.b = 100;
	
	mrc_textWidthHeight(content,1,MR_FONT_MEDIUM,&font_w,&font_h);
	rect.w = font_h*9+2;//Ã¿ÐÐ9¸ö×Ö
	rect.h = 4*font_h + 4;

	//Èç¹ûÖ»ÓÐÒ»ÐÐÎÄ×ÖµÄ»°£¬¾ÍÐèÒªµ÷Õûrect.xµÄÎ»ÖÃ
	if( font_w > font_h*9 )
	{
		rect.x =  (SCREEN_WIDTH - rect.w )/2;
	}
	else
	{
		rect.x =  (SCREEN_WIDTH - font_w )/2;
	}
		
	rect.y =  (SCREEN_HEIGHT- rect.h )/2;

	mrc_drawRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,10,10,10);
	mrc_drawTextEx(content,  rect.x,  rect.y+2,  rect,  colorst,  3,  MR_FONT_MEDIUM);


	if( right )
	{
		mrc_textWidthHeight(right, 1, MR_FONT_MEDIUM,&font_w, &font_h);
		mrc_drawText(right,SCREEN_WIDTH-font_w-1,SCREEN_HEIGHT-TOOLBAR_H +1 + (TOOLBAR_H -font_h)/2,BUTTON_COLOR,1,MR_FONT_MEDIUM);
	}

	if( left )
	{
		mrc_textWidthHeight(left, 1, MR_FONT_MEDIUM,&font_w, &font_h);
		mrc_drawText(left,1,SCREEN_HEIGHT-TOOLBAR_H +1 + (TOOLBAR_H -font_h)/2,BUTTON_COLOR,1,MR_FONT_MEDIUM);
	}

	mrc_refreshScreen(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
}


//ÓÎÏ·ÖÐÍË³öÓÎÏ·´°¿Ú
void CreateExitGameWin(uint8 game_status)
{
	g_exit_game_status = game_status;
	g_exit_game_win_id = mrc_winNew( 0, ExitGameWinHandle,ExitGameKeyHandle);
}

void ExitGameWinHandle(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_PAUSE:
		break;
	case WIN_EVENT_SHOW:
	case WIN_EVENT_REFRESH:
		PaintExitGameWin(0);
		break;
	case WIN_EVENT_EXIT:
		g_exit_game_win_id = -1;
		break;
	default:
		break;
	}
}


void ExitGameKeyHandle(int32 data, int32 type, int32 p1, int32 p2)
{
	switch(type)
	{
	case MR_KEY_RELEASE:
		if( p1 ==  MR_KEY_SOFTLEFT)
		{
			mrc_winCloseNotShow();//¹Ø±Õµ±Ç°´°¿Ú
			mrc_winClose();//¹Ø±ÕÓÎÏ·½çÃæ£¬·µ»ØÖ÷²Ëµ¥
		}
		else if( p1 ==  MR_KEY_SOFTRIGHT)
		{
			mrc_winClose();//¹Ø±Õµ±Ç°´°¿Ú£¬¼ÌÐøÓÎÏ·
		}
		break;

	case MR_MOUSE_DOWN:
		break;

	case MR_MOUSE_UP:
		break;
	}
}

void PaintExitGameWin(int32 data)
{
	char* left = "\x90\x00\x51\xfa\x00\x00";//ÍË³ö
	char* right = "\x53\xd6\x6d\x88\x00\x00";//È¡Ïû
	//ÊÇ·ñÍË³öÓÎÏ·å
	char* content  = "\x66\x2f\x54\x26\x90\x00\x51\xfa\x6e\x38\x62\x0f\xff\x1f\x00\x00";
	DrawTextFace(left,right,content);
}

void CreateInitPaymentErrorWin(void)
{
	mrc_winNew( 0, InitPayErrorWinHandle,InitPayErrorKeyHandle);
}

void InitPayErrorWinHandle(int32 data, int32 eventId)
{
	switch(eventId)
	{
	case WIN_EVENT_PAUSE:
		break;
	case WIN_EVENT_SHOW:
	case WIN_EVENT_REFRESH:
		PaintInitPayErrorWinFace();
		break;
	case WIN_EVENT_EXIT:
		break;
	default:
		break;
	}
}


void InitPayErrorKeyHandle(int32 data, int32 type, int32 p1, int32 p2)
{
	switch(type)
	{
		case MR_KEY_RELEASE:
			if( p1 ==  MR_KEY_SOFTRIGHT)
			{
				mrc_winClose();
				mrc_exit();
			}
			break;
	}
}


void PaintInitPayErrorWinFace(void)
{
	char* right = "\x90\x00\x51\xfa\x00\x00";//ÍË³ö
	//ÍøÂç³ö´í£¬ÇëÉÔºòÔÙÊÔ£¡
	char* content = "\x7f\x51\x7e\xdc\x51\xfa\x95\x19\xff\x0c\x8b\xf7\x7a\x0d\x50\x19\x51\x8d\x8b\xd5\xff\x01\x00\x00";
	DrawTextFace(NULL,right,content);
}
