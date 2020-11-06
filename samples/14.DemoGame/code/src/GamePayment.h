#ifndef INCLUDE_GAME_PAYMENT_H
#define INCLUDE_GAME_PAYMENT_H

/////////////////////////////////////
#include "mrc_base.h"
#include "mrc_payment.h"
#define GAME_REGISTER_MONEY	20//×¢²á·ÑÓÃ2Ôª

/////////////////////////////////////////
int32 InitGamePayment(void);
void StartPay(void);
void PayWinHandle(int32 data, int32 eventId);
void PayKeyHandle(int32 data, int32 type, int32 p1, int32 p2);
void RegisterGame(void);
int32 SendSms(int Option,int value);
int32 GetPayChannel(void);
char* GetChannelShortName(void);
void DrawTextFace( char* left, char* right, char* content);
void CreateExitGameWin(uint8 game_status);
void ExitGameWinHandle(int32 data, int32 eventId);
void ExitGameKeyHandle(int32 data, int32 type, int32 p1, int32 p2);
void PaintExitGameWin(int32 data);
void CreateInitPaymentErrorWin(void);
#endif

