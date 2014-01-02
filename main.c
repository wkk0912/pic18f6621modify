#include<pic18.h>
#include"adc.h"
#include"time.h"
#include"uart.h"
#include"ds1302.h"
#include"menu.h"
#include"key.h"
#include"lcd.h"
#include"ziku.h"
#include"led.h"
#include"eeprom.h"

__CONFIG(1,HSPLL);//HSPLL
__CONFIG(2,BOREN&PWRTEN&WDTDIS&WDTPS32K);
__CONFIG(3,MCLREN);
__CONFIG(4, XINSTDIS & STVREN  & DEBUGDIS&LVPDIS);
__CONFIG(5,0xFFFF);
__CONFIG(6,WRTEN);
__CONFIG(7,TREN);


unsigned char judge_flag    = 0;
unsigned char key_scan_flag = 0;
unsigned char lcd_refresh_flag = 0;
UART_T uart;

extern KEY_T key;
extern unsigned char bufb[100];
extern SYS_T sys;
extern AD_T adm;



unsigned int elcr;


void parament_init(void)
{

	unsigned char c;
    //串口
    uart.count = 0;
    uart.flag  = 0;
    uart.time  = 0;
    
    sys.menu_index =0;
    sys.main_menu_phase = 0;
    sys.time_set_phase  = 0;
    sys.pare_set_phase  = 0;
    sys.time_set_phase  = 0;
    sys.flag.byte = 0;

    sys.lcd_fresh_time = 0;
	sys.lcd_fresh_flag = 0;

	sys.key_scand_time = 0;
	sys.key_scand_flag = 0;

    c = read_data_from_eeprom(HOST_INIT);

    if(c == 0xbb)
    {   	    
        sys.addr = read_data_from_eeprom(HOST_ADDR);
        sys.addr_buf = sys.addr;

        sys.brg  = read_data_from_eeprom(HOST_BRG);
        sys.brg_buf = sys.brg;
        
        sys.password[0]=read_data_from_eeprom(H_PSW0);
        sys.password[1]=read_data_from_eeprom(H_PSW1);
        sys.password[2]=read_data_from_eeprom(H_PSW2);
        sys.password[3]=read_data_from_eeprom(H_PSW3);
        sys.password[4]=read_data_from_eeprom(H_PSW4);
        sys.password[5]=read_data_from_eeprom(H_PSW5);

        sys.v1 = read_data_from_eeprom(PARA_V1H);
        sys.v1 = sys.v1<<8;
        sys.v1 = sys.v1 + read_data_from_eeprom(PARA_V1L);
        sys.v2 = read_data_from_eeprom(PARA_V2H);
        sys.v2 = sys.v2<<8;
        sys.v2 = sys.v2 + read_data_from_eeprom(PARA_V2L);
        sys.v3 = read_data_from_eeprom(PARA_V3H);
        sys.v3 = sys.v3<<8;
        sys.v3 = sys.v3 + read_data_from_eeprom(PARA_V3L);
        sys.vbf = (sys.v1/1000)%10;
       
        sys.c1 = read_data_from_eeprom(PARA_C1H);
        sys.c1 = sys.c1<<8;
        sys.c1 = sys.c1 + read_data_from_eeprom(PARA_C1L);
        sys.c2 = read_data_from_eeprom(PARA_C2H);
        sys.c2 = sys.c2<<8;
        sys.c2 = sys.c2 + read_data_from_eeprom(PARA_C2L);
        sys.c3 = read_data_from_eeprom(PARA_C3H);
        sys.c3 = sys.c3<<8;
        sys.c3 = sys.c3 + read_data_from_eeprom(PARA_C3L);
        sys.cbf = (sys.c1/1000)%10;
        

        sys.err_record_index = read_data_from_eeprom(ERR_INDEX);
        sys.err_total_number = read_data_from_eeprom(ERR_TOTAL);
        sys.err_read_index = 0;    
        
        
    }
    else//第一次上电初始化默认参数和eeprom
    
    {
        sys.addr = 0x01;
        sys.brg  = 0x01;
        
		sys.password[0]=0;
        sys.password[1]=0;
        sys.password[2]=0;
        sys.password[3]=0;
        sys.password[4]=0;
        sys.password[5]=0;	
        
        sys.err_record_index = 0;
        sys.err_read_index   = 0;
        sys.err_total_number = 0;

        sys.v1 = 10;       
        sys.v2 = 20;
        sys.v3 = 30;
        sys.vbf = 0;
         
        sys.c1 = 10;
        sys.c2 = 20;
        sys.c3 = 30;
        sys.cbf = 0;
        
        write_data_to_eeprom(PARA_V1H,sys.v1>>8);
        write_data_to_eeprom(PARA_V1L,sys.v1&0xff);
        write_data_to_eeprom(PARA_V2H,sys.v2>>8);
        write_data_to_eeprom(PARA_V2L,sys.v2&0xff);
        write_data_to_eeprom(PARA_V3H,sys.v3>>8);
        write_data_to_eeprom(PARA_V3L,sys.v3&0xff);

        write_data_to_eeprom(PARA_C1H,sys.c1>>8);
        write_data_to_eeprom(PARA_C1L,sys.c1&0xff);
        write_data_to_eeprom(PARA_C2H,sys.c2>>8);
        write_data_to_eeprom(PARA_C2L,sys.c2&0xff);
        write_data_to_eeprom(PARA_C3H,sys.c3>>8);
        write_data_to_eeprom(PARA_C3L,sys.c3&0xff);
        
      
		write_data_to_eeprom(HOST_ADDR,sys.addr);
        write_data_to_eeprom(HOST_BRG,sys.brg);  
        
        write_data_to_eeprom(H_PSW0,sys.password[0]);
		write_data_to_eeprom(H_PSW1,sys.password[1]);
		write_data_to_eeprom(H_PSW2,sys.password[2]);
		write_data_to_eeprom(H_PSW3,sys.password[3]);
        write_data_to_eeprom(H_PSW4,sys.password[4]);
        write_data_to_eeprom(H_PSW5,sys.password[5]);
        
        write_data_to_eeprom(ERR_INDEX,sys.err_record_index);
        write_data_to_eeprom(ERR_TOTAL,sys.err_read_index);
        write_data_to_eeprom(HOST_INIT,0xbb);		     
    }
    

   
}


unsigned char ii,jj;

void main(void)
{
	adc_init();
	capture_init();
	timer1_init();
	timer2_init();
	ds1302_pin_init();
	ds1302_init();
	key_pin_init();
	
	lcd_pin_init();
	led_pin_init();
	set_mode_pin_init();	
	lcd_clear();	
	init_lcd();
	TRISG2 = 0;
	parament_init();
	if((RD0==0)&&(RF0==0)&&(RC1==0))adm.ch_num=6;
	else adm.ch_num = 4;
	PEIE = 1;
	GIE  = 1;
	START_AD;

    sys.v1 = 30;       
    sys.v2 = 20;
    sys.v3 = 10;

	
	
	while(1)
	{
	    if(adm.time_flag == 1)
	    {
	        adm.time_flag = 0; 
	        ad_sequence_sample();			    	        
	    }
	
		if(sys.lcd_fresh_flag == 1)
		{
		    sys.lcd_fresh_flag = 0;
		    ds1302_get_time();

			 if((RD0==0)&&(RF0==0)&&(RC1==0))adm.ch_num=6;
			 else adm.ch_num = 4;
					
			lcd_fresh();
			syswaring();
			FEED_DOG;	
			
		}
			
		if(sys.key_scand_flag== 1)
		{		 
			sys.key_scand_flag = 0;	
			FEED_DOG;	
			
			key_scan();
			if(key.flag == 1)
			{
				key.flag = 0;	
				
				display_menu();				 			
			}			
		}

		if(uart.flag == R_ED)
		{
		    uart.flag = R_IDEL;
		    uart_receive_deal();
		    
		}
		
		
	}
}




void interrupt isr(void)
{
    if(CCP5IF == 1)
	{
	    CCP5IF = 0;
	    if(adm.status == 1)
	    {        
	        if((adm.channle==3)||(adm.channle==4)||(adm.channle==5))
			{
				ADCON0&=0xc3;
				ADCON0|=0X02;
				adm.idle_time = 0;
    			while(ADIF == 0);ADIF = 0;
        		adm.ad1 = ADRESH&0X03;
        		adm.ad1 = adm.ad1<<8;
        		adm.ad1 = adm.ad1+ADRESL;
    			START_5MS
    			adm.status = 2;	
    		}	
	    }

	}
    /*捕捉触发ad*/
    if(CCP4IF == 1)
	{
	    CCP4IF = 0;
	    if(adm.status == 1)
	    {
			if((adm.channle==0)||(adm.channle==1)||(adm.channle==2))
			{
				ADCON0&=0xc3;
				ADCON0|=0X06;	
				adm.idle_time = 0;
				while(ADIF == 0);ADIF = 0;
        	    adm.ad1 = ADRESH&0X03;
        	    adm.ad1 = adm.ad1<<8;
        	    adm.ad1 = adm.ad1+ADRESL;
    		    START_5MS
    		    adm.status = 2;
			}
	    }
	}
	/*定时中断触发ad*/
	if(TMR1IF == 1)
	{
	    TMR1IF = 0;
	    TMR1ON = 0;//停止timer1
	    if(adm.status == 2)
	    {
	        if((adm.channle==0)||(adm.channle==1)||(adm.channle==2))
			{
				ADCON0&=0xc3;
				ADCON0|=0X06;	
				adm.idle_time = 0;
				while(ADIF == 0);ADIF = 0;
        	    adm.ad2 = ADRESH&0X03;
        	    adm.ad2 = adm.ad1<<8;
        	    adm.ad2 = adm.ad1+ADRESL;    		    
			}
	        else if((adm.channle==3)||(adm.channle==4)||(adm.channle==5))
			{
				ADCON0&=0xc3;
				ADCON0|=0X02;
				adm.idle_time = 0;
    			while(ADIF == 0);ADIF = 0;
        		adm.ad2 = ADRESH&0X03;
        		adm.ad2 = adm.ad1<<8;
        		adm.ad2 = adm.ad1+ADRESL;    			
    		}		        
	        adm.status = 3;
	    }
	}	

	
    /*串口接收*/
	if(RC1IF == 1)
	{
	    uart.r_buf[uart.count] = RCREG1;
	    uart.flag = R_ING;
	    uart.time = 0;
	    uart.count++;
	    uart.count=uart.count%20;    
	}

	
	/*系统时钟 */
	if(TMR2IF == 1)
	{	
		
		TMR2IF = 0; 

		/*系统时钟ad采样间隔控制*/
		adm.time_count++;
		if(adm.time_count >= 10)
		{
		    adm.time_count = 0;
		    adm.time_flag = 1;
		}

        /*系统时钟lcd刷屏控制 16ms*30 = 480ms*/
	    sys.lcd_fresh_time++;
	    if(sys.lcd_fresh_time == 30)
	    {		
	    	sys.lcd_fresh_time = 0;
	        sys.lcd_fresh_flag = 1;
	    }	    

        /*键盘扫描时间控制 16ms*/
	    sys.key_scand_flag = 1;

        /*串口接收 16*6 = 96*/
	    if(uart.flag==R_ING)
	    { 
	        uart.time++;
	        if(uart.time == 6)
	        {
	            uart.flag = R_ED;
	            uart.count = 0;
	            uart.time = 0;
	        }
	    }
	}
}


