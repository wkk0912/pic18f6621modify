#ifndef _DS1302
#define _DS1302

/******************RTC常量******************/
#define RTC_CLK   	RC5
#define RTC_DATA  	RC4
#define RTC_CS    	RC3
	//命令
#define _RD	  		0x01
#define _WR	  		0x00
#define C_SEC		0x80	//秿
#define C_MIN		0x82	//刿
#define C_HR		0x84	//旿
#define C_DAY		0x86	//旿
#define C_MTH		0x88	//朿
#define C_WK		0x8A	//星期 DATE
#define C_YR		0x8C	//广
#define C_WP		0x8E	//控制(写保抿
#define C_CHARGE	0x90	//涓流充电
#define C_BURST		0xBE	//时钟多字芿
	//配置
#define CLK_HALT		0x80	//停止时钟控制使   SECOND	bit7
#define CLK_START		0x00	//启动时钟
#define M12_24			0x80	//12/24小时值选择使HOUR		bit7 
#define PROTECT			0x80	//写保护控制位      CONTROL	bit7 
#define UPROTECT		0x00	//写保护控制位      CONTROL	bit7 
	//涓流充电控制常量
#define TC_D1R2			0xA5	//high 1 Diode +2K Resistors  
#define TC_D2R8			0xAB	//low  2 Diodes+8K Resistors  
#define TC_DISABLED		0x00	//Disabled(TCS<>1010 or DS=00 or RS=00)
	//RAM 命令
#define C_RAMBASE		0xC0	//RAM0~RAM30<<1 地址需左移一使


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
