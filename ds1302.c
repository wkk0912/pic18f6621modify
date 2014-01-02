#include<pic18.h>
#include"ds1302.h"
#include"lcd.h"

RTC_T rtc;
unsigned char time[8];
extern unsigned char bufb[100];



void delay_us(unsigned int us)		  
{
	while(us--);
}




void delay_ms(unsigned int MS)		  
{
	unsigned int i,j;
	for( i=0;i<MS;i++)
		for(j=0;j<1180;j++);	 
}
 



void ds1302_pin_init(void)		  
{ 
	TRISC3=0;
	TRISC4=0;
	TRISC5=0;
  
}





void ds1302_write_byte(unsigned char byte)
{
    unsigned char i;
 
    for(i=0;i<8;i++)        //8位数据计数
    {
	    RTC_CLK = 0;        //拉低时钟端
        if(byte&0x01)       //当前位是否是1
        {
            RTC_DATA = 1;   //当前位是1，拉高数据端
        }
        else						  
        {
            RTC_DATA = 0;   //当前位是0，拉低数据端
        }  
        delay_us(10);       //调整时钟和脉冲宽度
        RTC_CLK = 1;        //时钟上升沿（DS1302采样数据）
        byte>>=1;           //数据右移1位，为送出新数据位做准备
    }
}



unsigned char ds1302_read_byte(void)
{
    unsigned char i,byte=0;
    TRISC4 = 1;		     //将数据端口设置为输入		  
    RTC_DATA = 0;		 //无上拉电阻
    for(i=0;i<8;i++)	 //8位数据计数
    {
        byte>>=1;  		 //保存读入的数据位
        RTC_CLK = 1;	 //时钟上升沿
        delay_us(10);	 //延时，调整时钟脉冲宽度
        RTC_CLK = 0;	 //时钟下降沿，DS1302输出数据位
        delay_us(10);	 //等待数据变化（MEGA16太快，必须等待DS1302的数据位输出，否则不能正确读出）
        if(RTC_DATA)	 //当前位是否是高电平
        {
            byte |= 0x80;//是高电平就将返回数据的当前位置1
        }         
    }
    TRISC4 = 0;		    //最后将数据端口设置为输出
    return byte;		//返回读出的数据
}



void ds1302_write_data(unsigned char addr,unsigned char data)
{
    RTC_CS = 0;	 		//拉低片选端
    RTC_CLK = 0;	 	//拉低时钟端
    delay_us(10);
    RTC_CS = 1;	 		//拉高片选端
    delay_us(10); 		//调整片选脉冲
    ds1302_write_byte(addr);	 //写入操作命令（地址）
    delay_us(10);
    RTC_CLK = 0;	 	//拉低时钟端
    delay_us(10);
    ds1302_write_byte(data);//写入数据
    RTC_CLK = 0;	 		//拉低时钟端
    delay_us(10);			//调整片选脉冲
    RTC_CS = 0;	 			//拉低片选端
}



unsigned char ds1302_read_data(unsigned char addr)
{
    unsigned char data;

    RTC_CS = 0;	 		//拉低片选端
    RTC_CLK = 0;	 	//拉低时钟端
    delay_us(10);
    RTC_CS = 1;	 		//拉高片选端
    delay_us(10); 		//调整片选脉冲
    ds1302_write_byte(addr);	 //写入操作命令（地址）
    delay_us(10);
    data = ds1302_read_byte();	 //读出数据
    delay_us(10);
    RTC_CLK = 0;	 	//拉低时钟端
    RTC_CS = 0; 	 	//拉低片选端
    return data;		//返回读出的数据
}



void ds1302_set_time(unsigned char ptTimeD[])
{
    unsigned char i;
    unsigned char addr = 0x80; 			 	  //写入地址从秒寄存器开始
    ds1302_write_data(C_WP|_WR,UPROTECT);      //控制命令,WP位为0,允许写操作
	delay_ms(5);
    for(i=0;i<7;i++)
    {
        ds1302_write_data(addr|_WR,ptTimeD[i]); // 秒 分 时 日 月 星期 年         
        addr+=2;
		delay_ms(1);
    }
    ds1302_write_data(C_WP|_WR,PROTECT); 		//控制命令,WP位为1,不允许写操作
}

void set_rtc_time(unsigned char data,unsigned char addr)
{
    ds1302_write_data(C_WP|_WR,UPROTECT);      //控制命令,WP位为0,允许写操作
	delay_ms(5);
	ds1302_write_data(addr|_WR,data); // 秒 分 时 日 月 星期 年 
    delay_ms(1);
    ds1302_write_data(C_WP|_WR,PROTECT); 		//控制命令,WP位为1,不允许写操作
    
    
}



void ds1302_get_time(void)
{
    unsigned char i;

     
    RTC_CS = 0;	 //拉低片选端
    delay_us(10);
    RTC_CS = 1;	 //拉高片选端
    delay_us(10); 			 	//调整片选脉冲
    ds1302_write_byte(0xbf);	// 0xbf:时钟多字节读取命令 
    for (i=0;i<8;i++)       	//时间数据的存放格式是：
    {                        	//秒，分，时，日，月，星期，年，控制
        time[i]=ds1302_read_byte(); //【7个数据（BCD格式）+1个控制】 
    }				
    RTC_CS = 0; 	//拉低片选端  
    RTC_CLK = 0;	//拉低时钟端(时钟端在不操作时为低)

    bcd_to_hex();//bcd转hex
}




unsigned char ds1302_check(void)
{
	unsigned char exist;
    ds1302_write_data(C_WP|_WR,UPROTECT);		  //写入写允许命令
    ds1302_write_data(C_RAMBASE|_WR,0xA5);		  //RAM0写入0xA5
    exist=ds1302_read_data(C_RAMBASE|_RD);		  //读取RAM0
    if(exist==0xA5)	
	{
	    exist=1;		//如果读取值与写入值相等，返回TRUE
	}
    else 	
	{
	    exist=0;		//如果读取值与写入值不相等，返回FALSE
	}	
	return exist;
}


void ds1302_init(void)
{
    ds1302_write_data(C_WP|_WR,UPROTECT);	//写入写允许命令
    ds1302_write_data(C_SEC|_WR,CLK_START);	//启动振荡器，DS1302开始工作
    ds1302_write_data(C_WP|_WR,PROTECT); 	//控制命令,WP位为1,不允许写操作	  
}

void bcd_to_hex(void)
{

    rtc.second = (time[0]>>4)*10+(time[0]&0x0f);
    rtc.minute = (time[1]>>4)*10+(time[1]&0x0f);
    rtc.hour   = (time[2]>>4)*10+(time[2]&0x0f);
    rtc.date   = (time[3]>>4)*10+(time[3]&0x0f);
    rtc.month  = (time[4]>>4)*10+(time[4]&0x0f);
    rtc.year   = (time[6]>>4)*10+(time[6]&0x0f);
}

void bcd_to_asc(unsigned char BCD,unsigned char ptasc[])
{ 	
	ptasc[0]=(BCD>>4)  |0x30;	//0X58	35  38 //转换十位
	ptasc[1]=(BCD&0x0F)|0x30;	//转换个位
}


void rtc_test(void)
{
    
    
	ds1302_get_time();
	bcd_to_hex();

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"20%02d-%02d-%02d",rtc.year,rtc.month,rtc.date);
	xprint(3,0,0,bufb);	

	memset(bufb,'\0',sizeof(bufb));
	sprintf( bufb,"  %02d:%02d:%02d",rtc.hour,rtc.minute,rtc.second);
	xprint(5,0,0,bufb);	    
	
}
