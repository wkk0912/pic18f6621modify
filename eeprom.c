
#include<pic18.h>
#include"lcd.h"
#include"menu.h"
#include"ds1302.h"
#include"uart.h"


extern unsigned char bufb[100];
extern SYS_T sys;
extern RTC_T rtc;



void write_data_to_eeprom(unsigned int addr,unsigned char data)
{
    EEADRH = 0X03&(addr>>8);
    EEADR  = 0x00ff&addr;
    EEDATA = data;
    EEPGD  = 0;
    CFGS   = 0;
    WREN   = 1;
    GIE    = 0;
    EECON2 = 0X55;
    EECON2 = 0XAA;
    WR     = 1;
	while(!EEIF);
	EEIF = 0;
    GIE    = 1;
    WREN   = 0;
	
}


unsigned char read_data_from_eeprom(unsigned int addr)
{
    EEADRH = 0X03&(addr>>8);
    EEADR  = 0x00ff&addr;
    EEPGD  = 0;
    CFGS   = 0;
    RD     = 1;
    return EEDATA;    
}

void record_a_err(unsigned char err_style)
{
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+0,err_style);
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+1,rtc.year);   
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+2,rtc.month);
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+3,rtc.date);
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+4,rtc.hour);
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+5,rtc.minute);
    write_data_to_eeprom(ERR_ADDR_BASE+sys.err_record_index*7+6,rtc.second);

    sys.err_total_number++;
    if(sys.err_total_number>MAX_RECORD_NUMBER)sys.err_total_number=MAX_RECORD_NUMBER;
    write_data_to_eeprom(ERR_TOTAL,sys.err_total_number);

    sys.err_record_index++;
    if(sys.err_record_index>MAX_RECORD_NUMBER)sys.err_record_index=0;
    write_data_to_eeprom(ERR_INDEX,sys.err_record_index);    
}

void read_a_err(void)
{
    int map_index;
    
    if(sys.err_total_number==MAX_RECORD_NUMBER)
    {
        map_index = sys.err_record_index-1-sys.err_read_index;
        if(map_index < 0)
        {
            map_index = MAX_RECORD_NUMBER+ map_index;            
        }        
    }
    else if(sys.err_total_number<MAX_RECORD_NUMBER)
    {
        map_index = sys.err_record_index-1-sys.err_record_index;
    }

    sys.err_buf[0]=read_data_from_eeprom(map_index+0);
    sys.err_buf[1]=read_data_from_eeprom(map_index+1);
    sys.err_buf[2]=read_data_from_eeprom(map_index+2);
    sys.err_buf[3]=read_data_from_eeprom(map_index+3);
    sys.err_buf[4]=read_data_from_eeprom(map_index+4);
    sys.err_buf[5]=read_data_from_eeprom(map_index+5);
    sys.err_buf[6]=read_data_from_eeprom(map_index+6);
}





unsigned int eaddr=0;
unsigned char edata=0;
unsigned int eread;
unsigned int coo;
unsigned char testf = 1;
void testeeprom(void)
{
	if(testf == 2)
	{
		eread = read_data_from_eeprom(2);
		if(eread == 0xff)testf=0;
		else testf=1;
	}

	if(testf == 0)
	{
		
	    eaddr++;
	    if(eaddr>500)
	    {
	        testf = 1;
	        eaddr = 0;
	        return;
	    }
	    edata++;
	    write_data_to_eeprom(eaddr,edata);
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"e_addr:%4d  ",eaddr);
	    xprint(0,0,0,bufb);
	}

	if(testf ==1)
	{
	    edata = read_data_from_eeprom(eaddr);
	    eaddr++;
	    if(eaddr >500)
	    {
	         testf =2;
			eaddr = 0;
	    }
	    
	    memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"e_data:%4d  ",edata);
	    xprint(2,0,0,bufb);
		memset(bufb,'\0',sizeof(bufb));
	    sprintf( bufb,"e_addr:%4d  ",eaddr);
	    xprint(4,0,0,bufb);
	    	
	}
	
	
		
	
}
