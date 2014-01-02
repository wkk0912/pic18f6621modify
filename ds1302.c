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
 
    for(i=0;i<8;i++)        //8λ���ݼ���
    {
	    RTC_CLK = 0;        //����ʱ�Ӷ�
        if(byte&0x01)       //��ǰλ�Ƿ���1
        {
            RTC_DATA = 1;   //��ǰλ��1���������ݶ�
        }
        else						  
        {
            RTC_DATA = 0;   //��ǰλ��0���������ݶ�
        }  
        delay_us(10);       //����ʱ�Ӻ�������
        RTC_CLK = 1;        //ʱ�������أ�DS1302�������ݣ�
        byte>>=1;           //��������1λ��Ϊ�ͳ�������λ��׼��
    }
}



unsigned char ds1302_read_byte(void)
{
    unsigned char i,byte=0;
    TRISC4 = 1;		     //�����ݶ˿�����Ϊ����		  
    RTC_DATA = 0;		 //����������
    for(i=0;i<8;i++)	 //8λ���ݼ���
    {
        byte>>=1;  		 //������������λ
        RTC_CLK = 1;	 //ʱ��������
        delay_us(10);	 //��ʱ������ʱ��������
        RTC_CLK = 0;	 //ʱ���½��أ�DS1302�������λ
        delay_us(10);	 //�ȴ����ݱ仯��MEGA16̫�죬����ȴ�DS1302������λ�������������ȷ������
        if(RTC_DATA)	 //��ǰλ�Ƿ��Ǹߵ�ƽ
        {
            byte |= 0x80;//�Ǹߵ�ƽ�ͽ��������ݵĵ�ǰλ��1
        }         
    }
    TRISC4 = 0;		    //������ݶ˿�����Ϊ���
    return byte;		//���ض���������
}



void ds1302_write_data(unsigned char addr,unsigned char data)
{
    RTC_CS = 0;	 		//����Ƭѡ��
    RTC_CLK = 0;	 	//����ʱ�Ӷ�
    delay_us(10);
    RTC_CS = 1;	 		//����Ƭѡ��
    delay_us(10); 		//����Ƭѡ����
    ds1302_write_byte(addr);	 //д����������ַ��
    delay_us(10);
    RTC_CLK = 0;	 	//����ʱ�Ӷ�
    delay_us(10);
    ds1302_write_byte(data);//д������
    RTC_CLK = 0;	 		//����ʱ�Ӷ�
    delay_us(10);			//����Ƭѡ����
    RTC_CS = 0;	 			//����Ƭѡ��
}



unsigned char ds1302_read_data(unsigned char addr)
{
    unsigned char data;

    RTC_CS = 0;	 		//����Ƭѡ��
    RTC_CLK = 0;	 	//����ʱ�Ӷ�
    delay_us(10);
    RTC_CS = 1;	 		//����Ƭѡ��
    delay_us(10); 		//����Ƭѡ����
    ds1302_write_byte(addr);	 //д����������ַ��
    delay_us(10);
    data = ds1302_read_byte();	 //��������
    delay_us(10);
    RTC_CLK = 0;	 	//����ʱ�Ӷ�
    RTC_CS = 0; 	 	//����Ƭѡ��
    return data;		//���ض���������
}



void ds1302_set_time(unsigned char ptTimeD[])
{
    unsigned char i;
    unsigned char addr = 0x80; 			 	  //д���ַ����Ĵ�����ʼ
    ds1302_write_data(C_WP|_WR,UPROTECT);      //��������,WPλΪ0,����д����
	delay_ms(5);
    for(i=0;i<7;i++)
    {
        ds1302_write_data(addr|_WR,ptTimeD[i]); // �� �� ʱ �� �� ���� ��         
        addr+=2;
		delay_ms(1);
    }
    ds1302_write_data(C_WP|_WR,PROTECT); 		//��������,WPλΪ1,������д����
}

void set_rtc_time(unsigned char data,unsigned char addr)
{
    ds1302_write_data(C_WP|_WR,UPROTECT);      //��������,WPλΪ0,����д����
	delay_ms(5);
	ds1302_write_data(addr|_WR,data); // �� �� ʱ �� �� ���� �� 
    delay_ms(1);
    ds1302_write_data(C_WP|_WR,PROTECT); 		//��������,WPλΪ1,������д����
    
    
}



void ds1302_get_time(void)
{
    unsigned char i;

     
    RTC_CS = 0;	 //����Ƭѡ��
    delay_us(10);
    RTC_CS = 1;	 //����Ƭѡ��
    delay_us(10); 			 	//����Ƭѡ����
    ds1302_write_byte(0xbf);	// 0xbf:ʱ�Ӷ��ֽڶ�ȡ���� 
    for (i=0;i<8;i++)       	//ʱ�����ݵĴ�Ÿ�ʽ�ǣ�
    {                        	//�룬�֣�ʱ���գ��£����ڣ��꣬����
        time[i]=ds1302_read_byte(); //��7�����ݣ�BCD��ʽ��+1�����ơ� 
    }				
    RTC_CS = 0; 	//����Ƭѡ��  
    RTC_CLK = 0;	//����ʱ�Ӷ�(ʱ�Ӷ��ڲ�����ʱΪ��)

    bcd_to_hex();//bcdתhex
}




unsigned char ds1302_check(void)
{
	unsigned char exist;
    ds1302_write_data(C_WP|_WR,UPROTECT);		  //д��д��������
    ds1302_write_data(C_RAMBASE|_WR,0xA5);		  //RAM0д��0xA5
    exist=ds1302_read_data(C_RAMBASE|_RD);		  //��ȡRAM0
    if(exist==0xA5)	
	{
	    exist=1;		//�����ȡֵ��д��ֵ��ȣ�����TRUE
	}
    else 	
	{
	    exist=0;		//�����ȡֵ��д��ֵ����ȣ�����FALSE
	}	
	return exist;
}


void ds1302_init(void)
{
    ds1302_write_data(C_WP|_WR,UPROTECT);	//д��д��������
    ds1302_write_data(C_SEC|_WR,CLK_START);	//����������DS1302��ʼ����
    ds1302_write_data(C_WP|_WR,PROTECT); 	//��������,WPλΪ1,������д����	  
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
	ptasc[0]=(BCD>>4)  |0x30;	//0X58	35  38 //ת��ʮλ
	ptasc[1]=(BCD&0x0F)|0x30;	//ת����λ
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
