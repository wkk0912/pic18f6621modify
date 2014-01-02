
#include<pic18.h>
#include"ziku.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "lcd.h"


extern const unsigned char ascii_8_16[];
extern const unsigned char ziku[50][34];
extern const unsigned char fxdz[];

unsigned char bufb[100];


void lcd_pin_init(void)
{
    TRISE = 0x00;
    TRISD1 = 0;
    TRISD2 = 0;
    TRISD3 = 0;
    TRISD4 = 0;
    TRISD5 = 0;
    TRISD6 = 0;//BL
}



static void dly(void)
{
    unsigned int i = 3;
    while(i--);
}


void lcd_col_config(unsigned char col)
{
	unsigned char d;
	
	d = col | lcd_col;
	
	rs = 0;
	rw = 0;	
	PORTE = d;

	e  = 1;
	dly();	
	e  = 0;
	 
	
	
}

void lcd_row_config(unsigned char row)
{
	unsigned char d;
	
	d = row | lcd_row;

	rs = 0;
	rw = 0;
    PORTE = d;
     
	e  = 1;    
	dly();	
	e  = 0;
 	
}


void lcd_page_config(unsigned char page)
{
	unsigned char d;
	
	d = page | lcd_page;
	
	rs = 0;
	rw = 0;	
	PORTE = d;

	e  = 1;	
	dly();	
	e  = 0;
 	
}


void write_data_to_lcd(unsigned char data)
{
	
	rs = 1;
	rw = 0;
	
	PORTE = data;
	
	e  = 1;	
	dly();	
	e  = 0;
 
}

void write_cmd_to_lcd(unsigned char cmd)
{

	rs = 0;
	rw = 0;		
	PORTE = cmd;

	e  = 1;
	dly();	
	e  = 0;
	 
}


void fill_bit_picture(void)
{
	unsigned i,j;
	const unsigned char *p = fxdz;

	static unsigned char k=0;
	k++;
	
	for(i=0;i<128;i++)
	{
		for(j=0;j<8;j++)
		{
			lcd_col_config(i);
			lcd_page_config(j);
			if(i>63){cs1=1;cs2=0;}
			else{cs1=0;cs2=1;}
			
			if(k&1)write_data_to_lcd(*p);
			else write_data_to_lcd(0xff-*p);
			p++;
		}
	}

	for(i=0;i<1000;i++)for(j=0;j<1000;j++);
	
}
void lcd_clear(void)
{
	unsigned char i,j;

	cs1 = 0;cs2=0;

	for(i=0;i<8;i++)
	{
		lcd_page_config(i);
		lcd_col_config(0);
		for(j=0;j<64;j++)
		{
			write_data_to_lcd(0);
		}
	}
}






void init_lcd(void)
{

	cs1 = 0;
	cs2 = 0;
	dly();	
	dly();	
 	write_cmd_to_lcd(0x3e);
	write_cmd_to_lcd(0x3f);
	lcd_row_config(0);
	lcd_clear();	
}











void dis_double_word(int x,int y,unsigned char code1,unsigned char code2,unsigned char flag)
{
    unsigned char i,pos,temp;
    const  unsigned char *d;

    for(i = 0; i<60;i++)
    {
        if((code1 == ziku[i][0])&&(code2== ziku[i][1]))
        {
            d = i;
            break;
        }
    }
    if(i == 60)return;
    
    for(pos = 0;pos<32;pos++)
    {
        temp = ziku[i][2+pos];         
        if((y+(pos>>1))>=64)
        {
             cs1 = 1;
             cs2 = 0;
              
			 lcd_col_config(y-64+(pos>>1));
        }
        else
        {
             cs1 = 0;
             cs2 = 1;
             lcd_col_config(y+(pos>>1));
        }
        lcd_page_config(x+(pos&0x01));
        if(flag == 0)
        {
            write_data_to_lcd(temp);
        }
        else
        {
            write_data_to_lcd(0xff - temp);
            
        }
        
        
    }
    
    
}




void dis_signle_char(int x, int y, unsigned char acsii,unsigned char flag) 
{       

    unsigned char  temp,pos;    
    for (pos=0;pos<16;pos++)
    {
        temp=ascii_8_16[((acsii-0x20)*16)+pos];

        if((y+(pos>>1))>=64)
        {
            cs1 = 1;
            cs2 = 0;
            lcd_col_config(y-64+(pos>>1));
        }
        else
        {
            cs1 = 0;
            cs2 = 1;
            lcd_col_config(y+(pos>>1));
        }
        lcd_page_config(x+(pos&0x01));
        
        if(flag == 0)
        {
            write_data_to_lcd(temp);
        }
        else
        {
            write_data_to_lcd(0xff - temp);
            
        } 
    
    }
}




int
xprint(int x,int y,unsigned char flag, const char *buf)
{	 
	int len;
    int t_x=x;
    int t_y=y;
	int i;	

	

	unsigned char code1;
	unsigned char code2;

	len = strlen(buf);

	for (i = 0; i < len; )
    {
		if (buf[i] >= ' ' && buf[i] < 0x7f) 
        { //ascii
            dis_signle_char(t_x, t_y, buf[i],flag);
            i++;
            t_y=t_y+8;
			
		}
        else if (buf[i] >= 0x7f)
        { //oo×?
			code1 = buf[i++];
			code2 = buf[i++];
            dis_double_word(t_x,t_y,code1,code2,flag);
            t_y=t_y+16;
			
		}
        else 
        {
			i++;
			continue;
		}
    }


	
	 
	return 0;
}



int xprintf(int x, int y,unsigned char flag,const char *fmt, ...)
{
	va_list arg_ptr;

	memset(bufb, '\0', sizeof(bufb));

	va_start(arg_ptr, fmt);
	
	sprintf(bufb, fmt, arg_ptr);
	
	va_end(arg_ptr);

	
    xprint(x,y,bufb,flag);
	return 0;
}


//由于picc不支持vsprintf,所以使用sprintf
//在刷lcd时，采用下面格式

//memset(bufb,'\0',sizeof(bufb));
//int sprintf( char *buffer, const char *format, [ argument] … );
//xprint(int x,int y, const char *buf)











