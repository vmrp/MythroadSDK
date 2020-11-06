#ifndef __HELLOWORLD_H__
#define __HELLOWORLD_H__

#ifdef DEMO_DEBUG
#define DBG_PRINTF(a) mrc_printf a
#else
#define DBG_PRINTF(a) 
#endif

#ifdef	CONFIG_176
	void main_menu176(int32 data);
#else
	void main_menu240(int32 data);
#endif

#endif
