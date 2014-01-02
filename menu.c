
#include<pic18.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include"led.h"
#include"key.h"
#include"menu.h"
#include"ds1302.h"
#include"lcd.h"
#include"eeprom.h"
#include"uart.h"
#include"adc.h"
extern AD_T adm;


SYS_T sys;
extern unsigned char bufb[100];
extern RTC_T rtc;
extern KEY_T key;


FUN_T fun_i[90]={

  fun0,
  fun1,
  fun2,
  fun3,
  fun4,
  fun5,
  fun6,
  fun7,
  fun8,
  fun9,
  fun10,
  fun11,
  fun12,
  fun13,
  fun14,
  fun15,
  fun16,
  fun17,
  fun18,
  fun19,
  fun20,
  fun21,
  fun22,
  fun23,
  fun24,
  fun25,
  fun26,
  fun27,
  fun28,
  fun29,
  fun30,
  fun31,
  fun32,
  fun33,
  fun34,
  fun35,
  fun36,
  fun37,
  fun38,
  fun39,
  fun40,
  fun41,
  fun42,
  fun43,
  fun44,
  fun45,
  fun46,
  fun47,
  fun48,
  fun49,
  fun50,
  fun51,
  fun52,
  fun53,
  fun54,
  fun55,
  fun56,
  fun57,
  fun58,
  fun59,
  fun60,
  fun61,
  fun62,
  fun63,
  fun64,
  fun65,
  fun66,
  fun67,
  fun68,
  fun69,
  fun70,
	
};

const unsigned char menu_map[90][5]=
{
/*----------|----------|-----------|----------|----------|----------*/
/*index     k1         k2          k3         k4         k5         */
/*          >>         <<          ent        esc                   */
  0,        1,         3,          4,         0,//          
  1,        2,         0,          4,         0,//uav ubv ucv          
  2,        3,         1,          4,         0,//iav ibv icv          
  3,        0,         2,          4,         0,//btg addr         
  
  4,        5,         6,          7,         8,//main_menu          
  5,        5,         5,          5,         5,//>>          
  6,        6,         6,          6,         6,//<<          
  7,        7,         7,          7,         7,//ent          
  8,        8,         8,          8,         8,//esc
  
  9,        10,        11,         12,        13,//time set          
  10,       10,        10,         10,        10,//>>          
  11,       11,        11,         11,        11,//<<          
  12,       12,        12,         12,        12,//ent          
  13,       13,        13,         13,        13,//esc
  
  14,       15,        16,         17,        18,//get password          
  15,       15,        15,         15,        15,//+          
  16,       16,        16,         16,        16,//-          
  17,       17,        17,         17,        17,//ent          
  18,       18,        18,         18,        18,//esc  
        
  19,       20,        21,         22,        23,//change password          
  20,       20,        20,         20,        20,//+          
  21,       21,        21,         21,        21,//-          
  22,       22,        22,         22,        22,//ent          
  23,       23,        23,         23,        23,//esc          

  24,       25,        26,         27,        28,//query err          
  25,       25,        25,         25,        25,//+          
  26,       26,        26,         26,        26,//-          
  27,       27,        27,         27,        27,//ent          
  28,       28,        28,         28,        28,//esc 
         
  29,       30,        31,         32,        33,//get passwore          
  30,       30,        30,         30,        30,//+          
  31,       31,        31,         31,        31,//-          
  32,       32,        32,         32,        32,//ent          
  33,       33,        33,         33,        33,//esc
          
  34,       35,        36,         37,        38,//change password          
  35,       35,        35,         35,        35,//+          
  36,       36,        36,         36,        36,//-          
  37,       37,        37,         37,        37,//ent          
  38,       38,        38,         38,        38,//esc 
         
  39,       39,        39,         39,        39,          
  40,       40,        40,         40,        40,   

       
  41,       42,        43,         44,        45,          
  42,       42,        42,         42,        42,          
  43,       43,        43,         43,        43,          
  44,       44,        44,         44,        44,          
  45,       45,        45,         45,        45,

  
  46,       47,        48,         49,        50,          
  47,       47,        47,         47,        47,          
  48,       48,        48,         48,        48,          
  49,       49,        49,         49,        49,
  50,       50,        50,         50,        50,
  
  51,       52,        53,         54,        55,
  52,       52,        52,         52,        52,
  53,       53,        53,         53,        53,
  54,       54,        54,         54,        54,
  55,       55,        55,         55,        55,

  
  56,       57,        58,         59,        60,
  57,       57,        57,         57,        57,
  58,       58,        58,         58,        58,
  59,       59,        59,         59,        59,
  60,       60,        60,         60,        60,

  
  61,       62,        63,         64,        65,
  62,       62,        62,         62,        62,  
  63,       63,        63,         63,        63,
  64,       64,        64,         64,        64,
  65,       65,        65,         65,        65,

  
  66,       67,        68,         69,        70,
  67,       67,        67,         67,        67,
  68,       68,        68,         68,        68,
  69,       69,        69,         69,        69,
  70,       70,        70,         70,        70,

   };




void display_menu(void)
{
    sys.menu_index= menu_map[sys.menu_index][key.num];
    fun_i[sys.menu_index].fun();    
}

void fun0(void)
{
	lcd_clear();
    if(sys.flag.bits.run== 1)
	{
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"当前状态:运行");
	    xprint(1,12,0,bufb);	    
	}
	else
	{
	    memset(bufb,'\0',sizeof(bufb));		
	    sprintf( bufb,"当前状态:停运");
	    xprint(1,12,0,bufb);		    
	}

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"20%02d-%02d-%02d",rtc.year,rtc.month,rtc.date);
	xprint(3,24,0,bufb);	

	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%02d:%02d:%02d",rtc.hour,rtc.minute,rtc.second);
	xprint(5,32,0,bufb);	    
}
void fun1(void)
{
	lcd_clear();
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电压参数");
	xprint(0,32,0,bufb);	
	
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"A相电压:%4dV",sys.uav);
	xprint(2,12,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"B相电压:%4dV",sys.ubv);
	xprint(4,12,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"C相电压:%4dV",sys.ucv);
	xprint(6,12,0,bufb);	
}


void fun2(void)
{
    lcd_clear();
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"漏泄电流");
	xprint(0,32,0,bufb);	

	if(adm.ch_num==6)
	{

    
	
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"A相电流:%4duA",sys.iav);
	xprint(2,8,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"B相电流:%4duA",sys.ibv);
	xprint(4,8,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"C相电流:%4duA",sys.icv);
	xprint(6,8,0,bufb);
		}
	else
		{
			memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"泄漏电流:%4duA",sys.iav);
		    xprint(3,8,0,bufb);
			
		}
}
void fun3(void)
{    
	lcd_clear();
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"通讯参数");
	xprint(0,32,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	if(sys.brg==0){     sprintf( bufb,"波特率:  4800");}
	else if(sys.brg==1){sprintf( bufb,"波特率:  9600");}
	else if(sys.brg==2){sprintf( bufb,"波特率:115200");}	
	xprint(2,12,0,bufb);

	
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"地  址:   %03d",sys.addr);
	xprint(4,12,0,bufb);

}


//主菜单选择页面
void fun4(void)//
{
	
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"   时间设置    ");
	xprint(0,8,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"   参数设置    ");
	xprint(2,8,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"   故障报告    ");
	xprint(4,8,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"   密码修改    ");
	xprint(6,8,0,bufb);
	switch(sys.main_menu_phase)
	{
	case 0:
    	memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"√");
		xprint(0,16,0,bufb);
		break;
	case 1:
		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"√");
		xprint(2,16,0,bufb);
	    break;
	case 2:
		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"√");
		xprint(4,16,0,bufb);
		break;
	case 3:
		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"√");
		xprint(6,16,0,bufb);
		break;
	default:break;
	}
}
//>>
void fun5(void)
{
    sys.main_menu_phase++;
    if(sys.main_menu_phase>3)sys.main_menu_phase = 0;
    sys.menu_index = 4;  
    fun4();
}




void fun6(void)
{
    sys.main_menu_phase--;
    if(sys.main_menu_phase<0)sys.main_menu_phase=3;
    sys.menu_index = 4; 
    fun4();
     
}
//ent
void fun7(void)
{
    switch(sys.main_menu_phase)
    {
    case 0://time_set		
        sys.menu_index = 9;	
		lcd_clear();	
        fun9();
        break;
	case 1://参数设置
		sys.menu_index = 14;
		lcd_clear();
		fun14();
		break;
	case 2:
		sys.menu_index = 24;
		lcd_clear();
		fun24();
		break;
	case 3:
		sys.menu_index = 29;
		lcd_clear();
		fun29();
		break;

    default:break;
    }
}
void fun8(void)
{
    sys.main_menu_phase = 0;
    sys.menu_index = 0;
    fun0();
}


RTC_T rtc_buf;

void fun9(void)
{
    if(sys.time_set_phase == 0)
    {
	    rtc_buf.second = rtc.second;
        rtc_buf.minute = rtc.minute;
        rtc_buf.hour = rtc.hour;
        rtc_buf.date = rtc.date;
        rtc_buf.month = rtc.month;
        rtc_buf.year = rtc.year;
    }
        
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"时间设置");
	xprint(0,32,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"20%02d-%02d-%02d",rtc_buf.year,rtc_buf.month,rtc_buf.date);
	xprint(3,24,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%02d:%02d:%02d",rtc_buf.hour,rtc_buf.minute,rtc_buf.second);
	xprint(5,40,0,bufb);	  		
	
    switch(sys.time_set_phase)
    {    

	case 1://year
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.year);
	    xprint(3,40,1,bufb);	    
	    break;
	case 2://month
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.month);
	    xprint(3,64,1,bufb);	    
	    break;
	case 3://date
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.date);
	    xprint(3,88,1,bufb);	    
	    break;

	case 4://hour
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.hour);
	    xprint(5,40,1,bufb);	    
	    break;
	case 5://minute
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.minute);
	    xprint(5,64,1,bufb);	    
	    break;
	case 6://date
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%02d",rtc_buf.second);
	    xprint(5,88,1,bufb);	    
	    break;
	default:break;
	}
	
    
}
void fun10(void)
{
    switch(sys.time_set_phase)
    {
    case 1:
        rtc_buf.year++;
        if(rtc_buf.year >=100)rtc_buf.year=0;
        break;
    case 2:
        rtc_buf.month++;
        if(rtc_buf.month>=13)rtc_buf.month = 0;
        break;

    case 3:
        rtc_buf.date++;
        if(rtc_buf.date>=31)rtc_buf.date = 0;
        break;

    case 4:
        rtc_buf.hour++;
        if(rtc_buf.hour>=24)rtc_buf.hour = 0;
        break;
    case 5:
        rtc_buf.minute++;
        if(rtc_buf.minute>=60)rtc_buf.minute= 0;
        break;
    case 6:
        rtc_buf.second++;
        if(rtc_buf.second>=60)rtc_buf.second= 0;
        break; 
    default:break;
    }
    sys.menu_index = 9;
    fun9();
}
void fun11(void)
{
    switch(sys.time_set_phase)
    {
    case 1:
        rtc_buf.year--;
        if(rtc_buf.year < 0)rtc_buf.year=99;
        break;
    case 2:
        rtc_buf.month--;
        if(rtc_buf.month< 0)rtc_buf.month = 12;
        break;

    case 3:
        rtc_buf.date--;
        if(rtc_buf.date< 0)rtc_buf.date = 30;
        break;

    case 4:
        rtc_buf.hour--;
        if(rtc_buf.hour< 0)rtc_buf.hour = 23;
        break;
    case 5:
        rtc_buf.minute--;
        if(rtc_buf.minute< 0)rtc_buf.minute= 59;
        break;
    case 6:
        rtc_buf.second--;
        if(rtc_buf.second< 0)rtc_buf.second= 59;
        break; 
    default:break;
    }
    sys.menu_index = 9;
    fun9();
    
}
void fun12(void)
{
    char temp;
    
    switch(sys.time_set_phase)
    {
    case 1:		
        temp = rtc_buf.year/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.year%10);        
        set_rtc_time(temp,0x8c);
        rtc.year = rtc_buf.year;	
        break;
        
    case 2:		
        temp = rtc_buf.month/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.month%10);
        set_rtc_time(temp,0x88);
        rtc.month= rtc_buf.month;        
        break;
    case 3:
        temp = rtc_buf.date/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.date%10);
        set_rtc_time(temp,0x86);
        rtc.date= rtc_buf.date;
        break;
    case 4:
        temp = rtc_buf.hour/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.hour%10);
        set_rtc_time(temp,0x84);
        rtc.hour= rtc_buf.hour;        
        break;
    case 5:
        temp = rtc_buf.minute/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.minute%10);
        set_rtc_time(temp,0x82);
        rtc.minute= rtc_buf.minute;
        break;
    case 6:
        temp = rtc_buf.second/10;
        temp = temp << 4;
        temp = temp +(rtc_buf.second%10);
        set_rtc_time(temp,0x80);
        rtc.second= rtc_buf.second;
       
        break;
    default:break;
	}
	sys.time_set_phase++;
    if(sys.time_set_phase >= 7)
    {
        sys.time_set_phase = 0;
        sys.menu_index = 4;
        lcd_clear();
        fun4();
    }
    else
    {

        sys.menu_index = 9;
        fun9();
    }
    
}
void fun13(void)
{
    sys.time_set_phase = 0;
    sys.menu_index = 4;
    fun4();
}


//请输入密码

void fun14(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"输入密码");
	xprint(1,32,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d%d%d%d%d%d",sys.psw_buf[0],sys.psw_buf[1],sys.psw_buf[2],sys.psw_buf[3],sys.psw_buf[4],sys.psw_buf[5]);
	xprint(4,40,0,bufb);

	
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d",sys.psw_buf[sys.pswin]);
	xprint(4,40+sys.pswin*8,1,bufb);    
}
//<<
void fun15(void)
{
    sys.psw_buf[sys.pswin]++;
    if(sys.psw_buf[sys.pswin] ==10)sys.psw_buf[sys.pswin]=0;
    sys.menu_index = 14;
    fun14();
}
void fun16(void)
{
    sys.psw_buf[sys.pswin]--;
    if(sys.psw_buf[sys.pswin]<0)sys.psw_buf[sys.pswin]=9;
    sys.menu_index = 14;
    fun14();    
}
void fun17(void)
{
    sys.pswin++;
    if(sys.pswin == 6)
    {
        if((sys.password[0]==sys.psw_buf[0])&&
        (sys.password[1]==sys.psw_buf[1])&&
        (sys.password[2]==sys.psw_buf[2])&&
        (sys.password[3]==sys.psw_buf[3])&&
        (sys.password[4]==sys.psw_buf[4]))
        {
            sys.psw_buf[0]=0;
            sys.psw_buf[1]=0;
            sys.psw_buf[2]=0;
            sys.psw_buf[3]=0;
            sys.psw_buf[4]=0;
            sys.psw_buf[5]=0;
            sys.pswin = 0;
            sys.menu_index = 19;
			lcd_clear();
            fun19();
            
        }
        else
        {
            sys.psw_buf[0]=0;
            sys.psw_buf[1]=0;
            sys.psw_buf[2]=0;
            sys.psw_buf[3]=0;
            sys.psw_buf[4]=0;
            sys.psw_buf[5]=0;
            sys.pswin = 0;
            sys.menu_index = 14;
            fun14();
            
        }
    }
	else
	{
		sys.menu_index = 14;
        fun14();
		
	}
}
void fun18(void)
{
    sys.psw_buf[0]=0;
    sys.psw_buf[1]=0;
    sys.psw_buf[2]=0;
    sys.psw_buf[3]=0;
    sys.psw_buf[4]=0;
    sys.psw_buf[5]=0;
    sys.pswin = 0;
    sys.menu_index = 4;
    fun4();    
}
/*
    波特率设置
    地址设置  
    电压阈值
    电流阈值
*/
void fun19(void)
{
    
    memset(bufb,'\0',sizeof(bufb));
	sprintf(bufb,"  波特率设置");
	xprint(0,16,0,bufb);
	
	memset(bufb,'\0',sizeof(bufb));
    sprintf( bufb,"  地址设置");    
	xprint(2,16,0,bufb);
	
	memset(bufb,'\0',sizeof(bufb));
    sprintf( bufb,"  电压阈值");
	xprint(4,16,0,bufb);

    
	memset(bufb,'\0',sizeof(bufb));
    sprintf( bufb,"  电流阈值");
    xprint(6,16,0,bufb);

    
    switch(sys.pare_set_phase)
    {
    case 0:
        memset(bufb,'\0',sizeof(bufb));
        sprintf( bufb,"√");
        xprint(0,16,0,bufb);        
        break;
    case 1:
        memset(bufb,'\0',sizeof(bufb));
        sprintf( bufb,"√");
        xprint(2,16,0,bufb);        
        break;
    case 2:
        memset(bufb,'\0',sizeof(bufb));
        sprintf( bufb,"√");
        xprint(4,16,0,bufb);        
        break;    
    case 3:
		memset(bufb,'\0',sizeof(bufb));
        sprintf( bufb,"√");
        xprint(6,16,0,bufb);  
		break;
	default:break;	
	}
	
}
//+
void fun20(void)
{
	sys.pare_set_phase++;
	if(sys.pare_set_phase == 4)
	{
		sys.menu_index = 41;
		lcd_clear();
		fun41();
	}
	else
	{
		sys.menu_index = 19;
		fun19();
	}
	
}
//-
void fun21(void)
{
    sys.pare_set_phase--;
    if(sys.pare_set_phase<0)
    {
        sys.pare_set_phase = 4;
        sys.menu_index = 41;
        lcd_clear();
        fun41();
    }
    else
    {
        sys.menu_index = 19;
        fun19();
    }
}
//ent
void fun22(void)
{
    switch(sys.pare_set_phase)
    {
    case 0: 
        sys.menu_index=46;
        lcd_clear();
        fun46();
        break;
    case 1:
        sys.menu_index=51;
        lcd_clear();
        fun51();
        break;
    case 2:
        sys.menu_index=56;
        lcd_clear();
        fun56();
        break;    
    case 3:
        sys.menu_index=61;
        lcd_clear();
        fun61();
        break;		
    default:break;
	 
        
    }
    
}
//esc
void fun23(void)
{
    sys.pare_set_phase = 0;
    sys.menu_index = 4;
    lcd_clear();
    fun4();    
}

//故障查询
//序号 01 总计 00
//类型 高度故障
//时间 2012-12-26
//       10:28:56
void fun24(void)
{
	if(sys.err_total_number != 0)
	{

    	sys.err_buf[0] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+0);
    	sys.err_buf[1] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+1);
    	sys.err_buf[2] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+2);
    	sys.err_buf[3] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+3);
    	sys.err_buf[4] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+4);
    	sys.err_buf[5] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+5);
    	sys.err_buf[6] = read_data_from_eeprom(ERR_ADDR_BASE+7*sys.err_read_index+6);
	
	
    
    	memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"序号:%02d 总计:%02d",sys.err_read_index,sys.err_total_number);
		xprint(0,0,0,bufb);

		memset(bufb,'\0',sizeof(bufb));
		if(sys.err_buf[0]==0)
		{
	    	sprintf( bufb,"类型:高度故障");
		}
		else if(sys.err_buf[0]==1)
		{
	    	sprintf( bufb,"类型:中度故障");
		}
		else if(sys.err_buf[0]==2)
		{
	    	sprintf( bufb,"类型:低度故障");
		}
		xprint(2,0,0,bufb);

		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"时间:20%02d-%02d-%02d",sys.err_buf[1],sys.err_buf[2],sys.err_buf[3]);
		xprint(4,0,0,bufb);

		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"       %02d:%02d:%02d",sys.err_buf[4],sys.err_buf[5],sys.err_buf[6]);
		xprint(6,0,0,bufb);
	}
	else
	{
		sys.menu_index = 40;
		lcd_clear();
		fun40();
		
	}
    
}
//<<
void fun25(void)
{
    sys.err_read_index++;
    if(sys.err_read_index==sys.err_total_number)sys.err_read_index=0;
    sys.menu_index = 24;
    fun24();
}
//>>
void fun26(void)
{
    sys.err_read_index--;
    if(sys.err_read_index < 0)sys.err_read_index=sys.err_total_number - 1;
    sys.menu_index = 24;
    fun24();
}
//ent
void fun27(void)
{
    sys.menu_index = 24;
}
//esc
void fun28(void)
{
    sys.menu_index = 4;
    fun4();
}

//输入密码
void fun29(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"输入密码");
	xprint(1,32,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d%d%d%d%d%d",sys.psw_buf[0],sys.psw_buf[1],sys.psw_buf[2],sys.psw_buf[3],sys.psw_buf[4],sys.psw_buf[5]);
	xprint(4,40,0,bufb);

	
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d",sys.psw_buf[sys.pswin]);
	xprint(4,40+sys.pswin*8,1,bufb);  
    
}
//<<
void fun30(void)
{
    sys.psw_buf[sys.pswin]++;
    if(sys.psw_buf[sys.pswin] ==10)sys.psw_buf[sys.pswin]=0;
    sys.menu_index = 29;
    fun29();
}
//>>
void fun31(void)
{
    sys.psw_buf[sys.pswin]--;
    if(sys.psw_buf[sys.pswin]== -1)sys.psw_buf[sys.pswin]=9;
    sys.menu_index = 29;
    fun29();    
}
//ent
void fun32(void)
{
    sys.pswin++;
    if(sys.pswin == 6)
    {
        if((sys.password[0]==sys.psw_buf[0])&&
        (sys.password[1]==sys.psw_buf[1])&&
        (sys.password[2]==sys.psw_buf[2])&&
        (sys.password[3]==sys.psw_buf[3])&&
        (sys.password[4]==sys.psw_buf[4]))
        {
            sys.psw_buf[0]=0;
            sys.psw_buf[1]=0;
            sys.psw_buf[2]=0;
            sys.psw_buf[3]=0;
            sys.psw_buf[4]=0;
            sys.psw_buf[5]=0;
            sys.pswin = 0;
            sys.menu_index = 34;
            fun34();
            
        }
        else
        {
            sys.psw_buf[0]=0;
            sys.psw_buf[1]=0;
            sys.psw_buf[2]=0;
            sys.psw_buf[3]=0;
            sys.psw_buf[4]=0;
            sys.psw_buf[5]=0;
            sys.pswin = 0;
            sys.menu_index = 29;
            fun29();
            
        }
    }
    else
    {
        sys.menu_index = 29;
        fun29();        
    }
}
//esc
void fun33(void)
{
    sys.psw_buf[0]=0;
    sys.psw_buf[1]=0;
    sys.psw_buf[2]=0;
    sys.psw_buf[3]=0;
    sys.psw_buf[4]=0;
    sys.psw_buf[5]=0;
    sys.pswin = 0;
    sys.menu_index = 4;
    fun4();    
    
}

//密码修改

void fun34(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"修改密码");
	xprint(1,32,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d%d%d%d%d%d",sys.psw_buf[0],sys.psw_buf[1],sys.psw_buf[2],sys.psw_buf[3],sys.psw_buf[4],sys.psw_buf[5]);
	xprint(4,40,0,bufb);

	
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%d",sys.psw_buf[sys.pswin]);
	xprint(4,40+sys.pswin*8,1,bufb);  
    
}

//<<
void fun35(void)
{
    sys.psw_buf[sys.pswin]++;
    if(sys.psw_buf[sys.pswin] ==10)sys.psw_buf[sys.pswin]=0;
    sys.menu_index = 34;
    fun34();
}
//>>
void fun36(void)
{
    sys.psw_buf[sys.pswin]--;
    if(sys.psw_buf[sys.pswin]< 0)sys.psw_buf[sys.pswin]=9;
    sys.menu_index = 34;
    fun34();    
}
//ent
void fun37(void)
{
    sys.pswin++;
    if(sys.pswin == 6)
    {
        sys.password[0]=sys.psw_buf[0];
        sys.password[1]=sys.psw_buf[1];
        sys.password[2]=sys.psw_buf[2];
        sys.password[3]=sys.psw_buf[3];
        sys.password[4]=sys.psw_buf[4];
        sys.password[5]=sys.psw_buf[5];
        write_data_to_eeprom(H_PSW0,sys.password[0]);
        write_data_to_eeprom(H_PSW1,sys.password[1]);
        write_data_to_eeprom(H_PSW2,sys.password[2]);
        write_data_to_eeprom(H_PSW3,sys.password[3]);
        write_data_to_eeprom(H_PSW4,sys.password[4]);
        write_data_to_eeprom(H_PSW5,sys.password[5]);

        sys.pswin = 0;
        sys.psw_buf[0] = 0;
        sys.psw_buf[1] = 0;
        sys.psw_buf[2] = 0;
        sys.psw_buf[3] = 0;
        sys.psw_buf[4] = 0;
        sys.psw_buf[5] = 0;

        sys.menu_index=4;
        fun4();
         
    }
    else
    {
        sys.menu_index = 34;
        fun34();
        
    }
}
//esc
void fun38(void)
{
    sys.psw_buf[0]=0;
    sys.psw_buf[1]=0;
    sys.psw_buf[2]=0;
    sys.psw_buf[3]=0;
    sys.psw_buf[4]=0;
    sys.psw_buf[5]=0;
    sys.pswin = 0;
    sys.menu_index = 4;
    fun4();    
    
}

void fun39(void)
{
	
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb," 故障记录清除!!");
	xprint(3,0,0,bufb);	
}

void fun40(void)
{
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb," 无故障记录!!");
	xprint(3,0,0,bufb);
}

//清除故障选择项
void fun41(void)
{
    memset(bufb,"\0",sizeof(bufb));
    sprintf(bufb,"√清除故障记录");
    xprint(0,16,0,bufb);
}

//++
void fun42(void)
{
    sys.pare_set_phase = 0;
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}
//--
void fun43(void)
{
    sys.pare_set_phase= 3;
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}
//ent
void fun44(void)
{
    sys.menu_index = 66;
    lcd_clear();
    fun66();
    
}
//esc
void fun45(void)
{
    sys.menu_index = 4; 
	sys.main_menu_phase = 0;
    lcd_clear();
    fun4();
}



//波特率设置                
void fun46(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"波特率设置");
	xprint(2,24,0,bufb);

	

	memset(bufb,'\0',sizeof(bufb));
    switch(sys.brg_buf)
    {
    case 0:
        sprintf( bufb,"  4800");
        break;
    case 1:
        sprintf( bufb,"  9600");
        break;
    case 2:
        sprintf( bufb,"115200");
        break;        
    }
	
	xprint(4,40,1,bufb);	
    
}
//++
void fun47(void)
{
    sys.brg_buf++;
    if(sys.brg_buf == 3)sys.brg_buf = 0;
    sys.menu_index = 46;
    fun46();
}
//--
void fun48(void)
{
    sys.brg_buf--;
    if(sys.brg_buf<0)sys.brg_buf = 2;
    sys.menu_index = 46;
    fun46();
}
//ent
void fun49(void)
{
    sys.brg = sys.brg_buf;
    write_data_to_eeprom(HOST_BRG,sys.brg);
    set_uart_brg();
    sys.menu_index = 19;
    lcd_clear();
    fun19();
    
}
void fun50(void)
{
    sys.brg_buf = sys.brg;
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}
//地址设置
void fun51(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"地址设置");
	xprint(2,32,0,bufb);
	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"%03d",sys.addr_buf);
	xprint(44,32,1,bufb);
	
}
//++
void fun52(void)
{
    sys.addr_buf++;
    sys.menu_index = 51;
    fun51();
}
//--
void fun53(void)
{
    sys.addr_buf--;
    sys.menu_index = 51;
    fun51();
}
//ent
void fun54(void)
{
    sys.addr= sys.addr_buf;
    write_data_to_eeprom(HOST_ADDR,sys.addr);
    sys.menu_index = 19;
    lcd_clear();
    fun19();

}
//esc
void fun55(void)
{
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}

//电压参数设置
void fun56(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电压参数设置");
	xprint(0,16,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电压参数H %04dV",sys.v1);
	xprint(2,4,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电压参数M %04dV",sys.v2);
	xprint(4,4,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电压参数L %04dV",sys.v3);
	xprint(6,4,0,bufb);

	switch(sys.v_step)
	{
	case 0:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(2,84,1,bufb);
	    break;
	case 1:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(2,92,1,bufb);
	    break;
	case 2:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(2,100,1,bufb);
	    break;
	case 3:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(2,108,1,bufb);
	    break;

	case 4:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(4,84,1,bufb);
	    break;
	case 5:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(4,92,1,bufb);
	    break;
	case 6:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(4,100,1,bufb);
	    break;
	case 7:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(4,108,1,bufb);
	    break;
	case 8:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(6,84,1,bufb);
	    break;
	case 9:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(6,92,1,bufb);
	    break;
	case 10:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(6,100,1,bufb);
	    break;
	case 11:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.vbf);
	    xprint(6,108,1,bufb);
	    break;    
	}
    
}
//++
void fun57(void)
{
    sys.vbf++;
    if(sys.vbf > 9)sys.vbf=0;
    sys.menu_index = 56;
    fun56();
}
void fun58(void)
{
    sys.vbf--;
    if(sys.vbf < 0)sys.vbf=9;
    sys.menu_index = 56;
    fun56();
    
}

//计算中间变量
int vvv;
void fun59(void)
{
    switch(sys.v_step)
    {
    case 0:
        sys.v1 = sys.v1%1000;
        sys.v1 = sys.v1+sys.vbf*1000; 
        write_data_to_eeprom(PARA_V1H,sys.v1>>8);
        write_data_to_eeprom(PARA_V1L,sys.v1&0xff);
        sys.vbf = (sys.v1/100)%10;
        vvv = sys.vbf;
        sys.v_step = 1;
        break;

     case 1:
        sys.v1 = sys.v1 - vvv*100;
        sys.v1 = sys.v1 + sys.vbf*100;
        write_data_to_eeprom(PARA_V1H,sys.v1>>8);
        write_data_to_eeprom(PARA_V1L,sys.v1&0xff);
        sys.vbf = (sys.v1/10)%10;
        vvv = sys.vbf;
        sys.v_step = 2;
        break;

     case 2:
        sys.v1 = sys.v1 - vvv*10;
        sys.v1 = sys.v1 + sys.vbf*10;
        write_data_to_eeprom(PARA_V1H,sys.v1>>8);
        write_data_to_eeprom(PARA_V1L,sys.v1&0xff);
        
        sys.vbf = sys.v1%10;
        vvv = sys.vbf;
        sys.v_step = 3;
        break;
    case 3:
        sys.v1 = sys.v1 - vvv;
        sys.v1 = sys.v1 + sys.vbf;
        write_data_to_eeprom(PARA_V1H,sys.v1>>8);
        write_data_to_eeprom(PARA_V1L,sys.v1&0xff);
        
        sys.vbf = (sys.v2/1000)%10;
        vvv = sys.vbf;
        sys.v_step = 4;
        break;


    case 4:
        sys.v2 = sys.v2 - vvv*1000;
        sys.v2 = sys.v2 + sys.vbf*1000;
        write_data_to_eeprom(PARA_V2H,sys.v2>>8);
        write_data_to_eeprom(PARA_V2L,sys.v2&0xff);        
        sys.vbf = (sys.v2/100)%10;
        vvv = sys.vbf;
        sys.v_step = 5;
        break;

     case 5:
        sys.v2 = sys.v2 - vvv*100;
        sys.v2 = sys.v2 + sys.vbf*100;
        write_data_to_eeprom(PARA_V2H,sys.v2>>8);
        write_data_to_eeprom(PARA_V2L,sys.v2&0xff);
        sys.vbf = (sys.v2/10)%10;
        vvv = sys.vbf;
        sys.v_step = 6;
        break;

     case 6:
        sys.v2 = sys.v2 - vvv*10;
        sys.v2 = sys.v2 + sys.vbf*10;
        write_data_to_eeprom(PARA_V2H,sys.v2>>8);
        write_data_to_eeprom(PARA_V2L,sys.v2&0xff);
        sys.vbf = sys.v2%10;
        vvv = sys.vbf;
        sys.v_step = 7;
        break;
    case 7:
        sys.v2 = sys.v2 - vvv;
        sys.v2 = sys.v2 + sys.vbf;
        write_data_to_eeprom(PARA_V2H,sys.v2>>8);
        write_data_to_eeprom(PARA_V2L,sys.v2&0xff);
        sys.vbf = (sys.v3/1000)%10;
        vvv = sys.vbf;
        sys.v_step = 8;
        break;


    case 8:
        sys.v3 = sys.v3 - vvv*1000;
        sys.v3 = sys.v3 + sys.vbf*1000;
        write_data_to_eeprom(PARA_V3H,sys.v3>>8);
        write_data_to_eeprom(PARA_V3L,sys.v3&0xff);
        sys.vbf = (sys.v3/100)%10;
        vvv = sys.vbf;
        sys.v_step = 9;
        break;

     case 9:
        sys.v3 = sys.v3 - vvv*100;
        sys.v3 = sys.v3 + sys.vbf*100;
         write_data_to_eeprom(PARA_V3H,sys.v3>>8);
        write_data_to_eeprom(PARA_V3L,sys.v3&0xff);
        sys.vbf = (sys.v3/10)%10;
        vvv = sys.vbf;
        sys.v_step = 10;
        break;

     case 10:
        sys.v3 = sys.v3 - vvv*10;
        sys.v3 = sys.v3 + sys.vbf*10;
         write_data_to_eeprom(PARA_V3H,sys.v3>>8);
        write_data_to_eeprom(PARA_V3L,sys.v3&0xff);
        sys.vbf = sys.v3%10;
        vvv = sys.vbf;
        sys.v_step = 11;
        break;
    case 11:
        sys.v3 = sys.v3 - vvv;
        sys.v3 = sys.v3 + sys.vbf;
         write_data_to_eeprom(PARA_V3H,sys.v3>>8);
        write_data_to_eeprom(PARA_V3L,sys.v3&0xff);
        sys.v_step = 0;
        sys.vbf = sys.v1/1000;
        vvv = sys.vbf;
        sys.menu_index = 19;
        lcd_clear();
        fun19();
        return;
        break;
        
    }
    sys.menu_index = 56;
    fun56();
 
}


void fun60(void)
{
    sys.v_step = 0;
    sys.vbf = sys.v1/1000;
    vvv = sys.vbf;
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}


//电流参数设置
void fun61(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电流参数设置");
	xprint(0,16,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电流参数H %04duA",sys.c1);
	xprint(2,0,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电流参数M %04duA",sys.c2);
	xprint(4,0,0,bufb);

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"电流参数L %04duA",sys.c3);
	xprint(6,0,0,bufb);

	switch(sys.c_step)
	{
	case 0:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(2,80,1,bufb);
	    break;
	case 1:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(2,88,1,bufb);
	    break;
	case 2:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(2,96,1,bufb);
	    break;
	case 3:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(2,104,1,bufb);
	    break;

	case 4:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(4,80,1,bufb);
	    break;
	case 5:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(4,88,1,bufb);
	    break;
	case 6:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(4,96,1,bufb);
	    break;
	case 7:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(4,104,1,bufb);
	    break;
	case 8:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(6,80,1,bufb);
	    break;
	case 9:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(6,88,1,bufb);
	    break;
	case 10:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(6,96,1,bufb);
	    break;
	case 11:
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"%01d",sys.cbf);
	    xprint(6,104,1,bufb);
	    break;    
	}
    
}
//++
void fun62(void)
{
    sys.cbf++;
    if(sys.cbf > 9)sys.cbf=0;
    sys.menu_index = 61;
    fun61();
}
void fun63(void)
{
    sys.cbf--;
    if(sys.cbf < 0)sys.cbf=9;
    sys.menu_index = 61;
    fun61();
    
}

//计算中间变量
int ccc;
void fun64(void)
{
    switch(sys.c_step)
    {
    case 0:
        sys.c1 = sys.c1%1000;
        sys.c1 = sys.c1+sys.cbf*1000; 
        write_data_to_eeprom(PARA_C1H,sys.c1>>8);
        write_data_to_eeprom(PARA_C1L,sys.c1&0xff);
        sys.cbf = (sys.c1/100)%10;
        ccc = sys.cbf;
        sys.c_step = 1;
        break;

     case 1:
        sys.c1 = sys.c1 - ccc*100;
        sys.c1 = sys.c1 + sys.cbf*100;
        write_data_to_eeprom(PARA_C1H,sys.c1>>8);
        write_data_to_eeprom(PARA_C1L,sys.c1&0xff);
        sys.cbf = (sys.c1/10)%10;
        ccc = sys.cbf;
        sys.c_step = 2;
        break;

     case 2:
        sys.c1 = sys.c1 - ccc*10;
        sys.c1 = sys.c1 + sys.cbf*10;
        write_data_to_eeprom(PARA_C1H,sys.c1>>8);
        write_data_to_eeprom(PARA_C1L,sys.c1&0xff);

        sys.cbf = sys.c1%10;
        ccc = sys.cbf;
        sys.c_step = 3;
        break;
    case 3:
        sys.c1 = sys.c1 - ccc;
        sys.c1 = sys.c1 + sys.cbf;
        write_data_to_eeprom(PARA_C1H,sys.c1>>8);
        write_data_to_eeprom(PARA_C1L,sys.c1&0xff);
        sys.cbf = (sys.c2/1000)%10;
        ccc = sys.cbf;
        sys.c_step = 4;
        break;


    case 4:
        sys.c2 = sys.c2 - ccc*1000;
        sys.c2 = sys.c2 + sys.cbf*1000;
        write_data_to_eeprom(PARA_C2H,sys.c2>>8);
        write_data_to_eeprom(PARA_C2L,sys.c2&0xff);        
        sys.cbf = (sys.c2/100)%10;
        ccc = sys.cbf;
        sys.c_step = 5;
        break;

     case 5:
        sys.c2 = sys.c2 - ccc*100;
        sys.c2 = sys.c2 + sys.cbf*100;
        write_data_to_eeprom(PARA_C2H,sys.c2>>8);
        write_data_to_eeprom(PARA_C2L,sys.c2&0xff);
        sys.cbf = (sys.c2/10)%10;
        ccc = sys.cbf;
        sys.c_step = 6;
        break;

     case 6:
        sys.c2 = sys.c2 - ccc*10;
        sys.c2 = sys.c2 + sys.cbf*10;
        write_data_to_eeprom(PARA_C2H,sys.c2>>8);
        write_data_to_eeprom(PARA_C2L,sys.c2&0xff);
        sys.cbf = sys.c2%10;
        ccc = sys.cbf;
        sys.c_step = 7;
        break;
    case 7:
        sys.c2 = sys.c2 - ccc;
        sys.c2 = sys.c2 + sys.cbf;
        write_data_to_eeprom(PARA_C2H,sys.c2>>8);
        write_data_to_eeprom(PARA_C2L,sys.c2&0xff);
        sys.cbf = (sys.c3/1000)%10;
        ccc = sys.cbf;
        sys.c_step = 8;
        break;


    case 8:
        sys.c3 = sys.c3 - ccc*1000;
        sys.c3 = sys.c3 + sys.cbf*1000;
        write_data_to_eeprom(PARA_C3H,sys.c3>>8);
        write_data_to_eeprom(PARA_C3L,sys.c3&0xff);
        sys.cbf = (sys.c3/100)%10;
        ccc = sys.cbf;
        sys.c_step = 9;
        break;

     case 9:
        sys.c3 = sys.c3 - ccc*100;
        sys.c3 = sys.c3 + sys.cbf*100;
        write_data_to_eeprom(PARA_C3H,sys.c3>>8);
        write_data_to_eeprom(PARA_C3L,sys.c3&0xff);
        sys.cbf = (sys.c3/10)%10;
        ccc = sys.cbf;
        sys.c_step = 10;
        break;

     case 10:
        sys.c3 = sys.c3 - ccc*10;
        sys.c3 = sys.c3 + sys.cbf*10;
         write_data_to_eeprom(PARA_C3H,sys.c3>>8);
        write_data_to_eeprom(PARA_C3L,sys.c3&0xff);
        sys.cbf = sys.c3%10;
        ccc = sys.cbf;
        sys.c_step = 11;
        break;
    case 11:
        sys.c3 = sys.c3 - ccc;
        sys.c3 = sys.c3 + sys.cbf;
        write_data_to_eeprom(PARA_C3H,sys.c3>>8);
        write_data_to_eeprom(PARA_C3L,sys.c3&0xff);
        sys.c_step = 0;
        sys.cbf = sys.c1/1000;
        ccc = sys.cbf;
        sys.menu_index = 19;
        lcd_clear();
        fun19();
        return;
        break;
        
    }
    sys.menu_index = 61;
    fun61();
}


void fun65(void)
{
    sys.c_step = 0;
    sys.cbf = sys.c1/1000;
    ccc = sys.cbf;
    sys.menu_index = 19;
    lcd_clear();
    fun19();
}
//清除故障记录

unsigned char xz = 0;
void fun66(void)
{
    memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"清除故障报告");
   	xprint(1,16,0,bufb);

    if(xz == 0)
    {
   	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"是");
   	    xprint(4,32,1,bufb);

   	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"否");
   	    xprint(4,80,0,bufb);
   	}
   	else 
   	{
   	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"是");
   	    xprint(4,32,0,bufb);

   	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"否");
   	    xprint(4,80,1,bufb);   	    
   	}
	
}
//+
void fun67(void)
{
    if(xz == 0)xz = 1;
    else xz = 0;
    sys.menu_index = 66;
    fun66();
    
}
//-
void fun68(void)
{
    if(xz == 0)xz = 1;
    else xz = 0;
    sys.menu_index = 66;
    fun66();
}

//ent
void fun69(void)
{
    unsigned i;
    if(xz == 0)
    {
		
        for(i=ERR_TOTAL;i<702;i++)
        {
            write_data_to_eeprom(i,0);
			if(i&2)RG2 ^= 1;
			
        }  
        sys.menu_index = 39;
        lcd_clear();
        fun39();
		
    }
    else
    {
        sys.menu_index = 41;
        lcd_clear();
        fun41();
        xz = 0;
    }
}
void fun70(void)
{
    sys.menu_index = 41;
    lcd_clear();
    fun41();
    xz = 0;
    
}
void fun71(void){}














extern unsigned char uc_err;

void lcd_fresh(void)
{
	static unsigned count = 0;
	
    	
	if(sys.menu_index == 0)
	{
/*

		if(sys.err_code == 4)
		{
			memset(bufb,'\0',sizeof(bufb));
	    	sprintf( bufb,"当前状态:停运");
	    	xprint(1,12,0,bufb);	    	   
		}
		else
		{
			memset(bufb,'\0',sizeof(bufb));
	    	sprintf( bufb,"当前状态:运行");
	    	xprint(1,12,0,bufb);	 
	    	   
		}
		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"20%02d-%02d-%02d",rtc.year,rtc.month,rtc.date);
		xprint(3,24,0,bufb);

		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"%02d:%02d:%02d",rtc.hour,rtc.minute,rtc.second);
		xprint(5,32,0,bufb);
	*/  

	    	memset(bufb,'\0',sizeof(bufb));
	    	    	sprintf( bufb,"%4d",uc_err);
	    	
	    	xprint(0,0,0,bufb);

			memset(bufb,'\0',sizeof(bufb));
	    	    	sprintf( bufb,"%4d",sys.err_code);
	    	
	    	xprint(0,64,0,bufb);

			memset(bufb,'\0',sizeof(bufb));
			sprintf( bufb,"Au:%4dV",sys.uav);
			xprint(2,0,0,bufb);	

			memset(bufb,'\0',sizeof(bufb));
			sprintf( bufb,"Bu:%4dV",sys.ubv);
			xprint(4,0,0,bufb);	

			memset(bufb,'\0',sizeof(bufb));
			sprintf( bufb,"Cu:%4dV",sys.ucv);
			xprint(6,0,0,bufb);

			memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"Ai:%4d ",sys.iav);
		    xprint(2,64,0,bufb);	

		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"Bi:%4d ",sys.ibv);
		    xprint(4,64,0,bufb);	

		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"Ci:%4d ",sys.icv);
		    xprint(6,64,0,bufb);
		    
		    
	}
	else if(sys.menu_index ==1)
	{
		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"A相电压:%4dV",sys.uav);
		xprint(2,12,0,bufb);	

		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"B相电压:%4dV",sys.ubv);
		xprint(4,12,0,bufb);	

		memset(bufb,'\0',sizeof(bufb));
		sprintf( bufb,"C相电压:%4dV",sys.ucv);
		xprint(6,12,0,bufb);
	}
	else if(sys.menu_index == 2)
	{

	    if((RD0==0)&&(RF0==0)&&(RC1==0))	    
	    {
    	    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"A相电流:%4duA ",sys.iav);
		    xprint(2,8,0,bufb);	

		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"B相电流:%4duA ",sys.ibv);
		    xprint(4,8,0,bufb);	

		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"C相电流:%4duA ",sys.icv);
		    xprint(6,8,0,bufb);	
	    }
	    else
	    {
	        memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"                ");
		    xprint(2,8,0,bufb);	
	        memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"泄漏电流:%4duA",sys.iav);
		    xprint(3,8,0,bufb);
		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"                ");
		    xprint(5,8,0,bufb);	
		    memset(bufb,'\0',sizeof(bufb));
		    sprintf( bufb,"                ");
		    xprint(6,8,0,bufb);	
		    
	    }
	 }
	
	
	else if(sys.menu_index == 39)
	{
		count++;
		if(count == 4)
		{
			count =0;
			sys.menu_index = 41;
            lcd_clear();
            fun41();            
		}
	}

	else if(sys.menu_index == 40)
	{
		count++;
		if(count == 4)
		{
			count =0;
			sys.menu_index =4;
			lcd_clear();
			fun4();
		}
	}
}







