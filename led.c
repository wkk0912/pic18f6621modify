#include<pic18.h>
#include"led.h"
#include"menu.h"
#include"eeprom.h"
extern SYS_T sys;

void led_pin_init(void)
{
    TRISF5 = 0;//
    TRISF6 = 0;
    TRISF7 = 0;
	TRISB2 = 0;
	
	TRISA3 = 0;
	TRISA4 = 0;
	TRISA5 = 0;
	
    RF5 = 1;
    RF6 = 1;
    RF7 = 1;
	RB2 = 1;
	
	RA3 = 1;//D1
	RA4 = 1;//D2
	RA5 = 1;//D3
}




extern unsigned char ua_err;
extern unsigned char ub_err;
extern unsigned char uc_err;
extern unsigned char ia_err;
extern unsigned char ib_err;
extern unsigned char ic_err;

void syswaring(void)
{
	static unsigned char last_err_code;

	
	if(sys.err_judge_flag == 1)
	{
	
	sys.err_judge_flag = 0;
	if((ua_err==0)&&(ub_err == 0)&&(uc_err==0)&&(ia_err==0)&&(ib_err==0)&&(ic_err==0)){sys.err_code = 0;}
	else if((ua_err==3)||(ub_err == 3)||(uc_err==3)||(ia_err==3)||(ib_err==3)||(ic_err==3)){sys.err_code = 3;}
	else if((ua_err==2)||(ub_err == 2)||(uc_err==2)||(ia_err==2)||(ib_err==2)||(ic_err==2)){sys.err_code = 2;}
	else if((ua_err==1)||(ub_err == 1)||(uc_err==1)||(ia_err==1)||(ib_err==1)||(ic_err==1)){sys.err_code = 1;}
	//else if(((ua_err==4)&&(ub_err == 4)&&(uc_err==4))||(ia_err==4)||(ib_err==4)||(ic_err==4)){sys.err_code = 4;}
	}
	if((sys.err_code !=0 && sys.err_code !=4))
	{
		if(last_err_code != sys.err_code)
		{
			last_err_code = sys.err_code;
			record_a_err(last_err_code);
		}
	}
	if(sys.err_code == 3)
	{
		LED_RUN_ON;
		LED_WARNING_ON;
		RB2 = 0;
		DLY1_ON;
	}
	else if(sys.err_code == 2)
	{
		LED_RUN_ON;
		LED_WARNING_ON;
		RB2 = 0;
		DLY1_OFF;
	}
	else if(sys.err_code==1)
	{
		LED_RUN_ON;
		LED_WARNING_ON;
		RB2 = 1;
		DLY1_OFF;
	}
	else if(sys.err_code==0)
	{
		LED_RUN_ON;
		LED_WARNING_OFF;
		RB2 = 1;
		DLY1_OFF;
	}
	else if(sys.err_code==4)
		{
		LED_RUN_OFF;
		LED_WARNING_OFF;
		RB2 = 1;
		DLY1_OFF;
		}
}


