#include "..\..\modules\mrc_base.h"
#include "..\..\modules\mrc_win.h"
#include "..\..\modules\mrc_menu.h"
#include "..\..\modules\mrc_text.h"
#include "..\..\modules\mrc_payment.h"
#include "TestCharge.h"

//菜单项A:Helloworld
void main_menu240(int32 data){
	if(mrc_Charge2()==MR_SUCCESS)
	{//目前一个应用只能够收取一次费用，不能够多次收费。
  		 mrc_platTextNew("\x65\x36\x8d\x39\x7e\xd3\x67\x9c", "\x53\xd1\x90\x1\x77\xed\x4f\xe1\x62\x10\x52\x9f", 
   			MR_DIALOG_CANCEL, 0, NULL, NULL);
  		 DBG_PRINTF(("Charge2() return MR_SUCCESS"));
	}
	else
	{
  		 mrc_platTextNew("\x65\x36\x8d\x39\x7e\xd3\x67\x9c", "\x53\xd1\x90\x1\x77\xed\x4f\xe1\x59\x31\x8d\x25", 
   			MR_DIALOG_CANCEL, 0, NULL, NULL);	
		DBG_PRINTF(("Charge2() failed"));
	}
}
