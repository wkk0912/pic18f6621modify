#ifndef _DS1302
#define _DS1302

/******************RTC����******************/
#define RTC_CLK   	RC5
#define RTC_DATA  	RC4
#define RTC_CS    	RC3
	//����
#define _RD	  		0x01
#define _WR	  		0x00
#define C_SEC		0x80	//��
#define C_MIN		0x82	//��
#define C_HR		0x84	//�J
#define C_DAY		0x86	//�J
#define C_MTH		0x88	//�c
#define C_WK		0x8A	//���� DATE
#define C_YR		0x8C	//��
#define C_WP		0x8E	//����(д����
#define C_CHARGE	0x90	//������
#define C_BURST		0xBE	//ʱ�Ӷ����e
	//����
#define CLK_HALT		0x80	//ֹͣʱ�ӿ���ʹ   SECOND	bit7
#define CLK_START		0x00	//����ʱ��
#define M12_24			0x80	//12/24Сʱֵѡ��ʹHOUR		bit7 
#define PROTECT			0x80	//д��������λ      CONTROL	bit7 
#define UPROTECT		0x00	//д��������λ      CONTROL	bit7 
	//��������Ƴ���
#define TC_D1R2			0xA5	//high 1 Diode +2K Resistors  
#define TC_D2R8			0xAB	//low  2 Diodes+8K Resistors  
#define TC_DISABLED		0x00	//Disabled(TCS<>1010 or DS=00 or RS=00)
	//RAM ����
#define C_RAMBASE		0xC0	//RAM0~RAM30<<1 ��ַ������һʹ


typedef struct RTC
{
    int second;
    int minute;
    int hour;
    int date;
    int month;
    int year;
}RTC_T;

void delay_us(unsigned int us); 
void delay_ms(unsigned int MS); 
void ds1302_pin_init(void); 
void ds1302_write_byte(unsigned char byte); 
unsigned char ds1302_read_byte(void); 
void ds1302_write_data(unsigned char addr,unsigned char data); 
unsigned char ds1302_read_data(unsigned char addr); 
void ds1302_set_time(unsigned char ptTimeD[]); 
void ds1302_get_time(void); 
unsigned char ds1302_check(void); 
void ds1302_init(void);
void bcd_to_asc(unsigned char BCD,unsigned char ptasc[]);
void bcd_to_hex(void);
void set_rtc_time(unsigned char data,unsigned char addr);

#endif
