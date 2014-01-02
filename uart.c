#include<pic18.h>
#include"uart.h"
#include"menu.h"
#include"eeprom.h"

#define R_485 RC0=1
#define S_485 RC0=0

extern UART_T uart;
extern SYS_T sys;
/*
   
   

   查询帧
   帧头0   帧头1   包长    地址    序号    命令码  校验
   0xfe    0xfe    0x04    0x01       0    0x11    0x00 地址
   0xfe    0xfe    0x04    0x01       1    0x11    0x00 波特率
   0xfe    0xfe    0x04    0x01       2    0x11    0x00 ua
   0xfe    0xfe    0x04    0x01       3    0x11    0x00 ub
   0xfe    0xfe    0x04    0x01       4    0x11    0x00 uc
   0xfe    0xfe    0x04    0x01       5    0x11    0x00 ia
   0xfe    0xfe    0x04    0x01       6    0x11    0x00 ib
   0xfe    0xfe    0x04    0x01       7    0x11    0x00 ic
   0xfe    0xfe    0x04    0x01       8    0x11    0x00 u1
   0xfe    0xfe    0x04    0x01       9    0x11    0x00 u2
   0xfe    0xfe    0x04    0x01      10    0x11    0x00 u3
   0xfe    0xfe    0x04    0x01      11    0x11    0x00 i1
   0xfe    0xfe    0x04    0x01      12    0x11    0x00 i2
   0xfe    0xfe    0x04    0x01      13    0x11    0x00 i3  

   查询回复帧
   帧头0   帧头1   包长    地址    序号    命令码  高字节 低字节  校验
   0xfe    0xfe    0x06    0x01       0    0x11    0x00   0x00    0x00 地址
   0xfe    0xfe    0x06    0x01       1    0x11    0x00   0x00    0x00 波特率
   0xfe    0xfe    0x06    0x01       2    0x11    0x00   0x00    0x00 ua
   0xfe    0xfe    0x06    0x01       3    0x11    0x00   0x00    0x00 ub
   0xfe    0xfe    0x06    0x01       4    0x11    0x00   0x00    0x00 uc
   0xfe    0xfe    0x06    0x01       5    0x11    0x00   0x00    0x00 ia
   0xfe    0xfe    0x06    0x01       6    0x11    0x00   0x00    0x00 ib
   0xfe    0xfe    0x06    0x01       7    0x11    0x00   0x00    0x00 ic
   0xfe    0xfe    0x06    0x01       8    0x11    0x00   0x00    0x00 u1
   0xfe    0xfe    0x06    0x01       9    0x11    0x00   0x00    0x00 u2
   0xfe    0xfe    0x06    0x01      10    0x11    0x00   0x00    0x00 u3
   0xfe    0xfe    0x06    0x01      11    0x11    0x00   0x00    0x00 i1
   0xfe    0xfe    0x06    0x01      12    0x11    0x00   0x00    0x00 i2
   0xfe    0xfe    0x06    0x01      13    0x11    0x00   0x00    0x00 i3


   设置帧
   帧头0   帧头1   包长    地址    序号    命令码  高字节 低字节  校验
   0xfe    0xfe    0x06    0x01      14    0x33    0x00   0x00    0x00 地址
   0xfe    0xfe    0x06    0x01      15    0x33    0x00   0x00    0x00 波特率
   0xfe    0xfe    0x06    0x01      16    0x33    0x00   0x00    0x00 u1
   0xfe    0xfe    0x06    0x01      17    0x33    0x00   0x00    0x00 u2
   0xfe    0xfe    0x06    0x01      18    0x33    0x00   0x00    0x00 u3
   0xfe    0xfe    0x06    0x01      19    0x33    0x00   0x00    0x00 i1
   0xfe    0xfe    0x06    0x01      20    0x33    0x00   0x00    0x00 i2
   0xfe    0xfe    0x06    0x01      21    0x33    0x00   0x00    0x00 i3

   设置回复帧
   帧头0   帧头1   包长    地址    序号    命令码  确认码  校验
   0xfe    0xfe    0x05    0x01      14    0x33    0x00    0x00 地址
   0xfe    0xfe    0x05    0x01      15    0x33    0x00    0x00 波特率
   0xfe    0xfe    0x05    0x01      16    0x33    0x00    0x00 u1
   0xfe    0xfe    0x05    0x01      17    0x33    0x00    0x00 u2
   0xfe    0xfe    0x05    0x01      18    0x33    0x00    0x00 u3
   0xfe    0xfe    0x05    0x01      19    0x33    0x00    0x00 i1
   0xfe    0xfe    0x05    0x01      20    0x33    0x00    0x00 i2
   0xfe    0xfe    0x05    0x01      21    0x33    0x00    0x00 i3
*/

//4800   51
//9600   25
//115200 1



void uart_init(void)
{
    SPBRGH1 = 0;
    SPBRG1 = 25;//9600

    TXSTA1= 0X20;//00100000
    RCSTA1= 0X90;//10010000
    TRISC6 = 0;
    TRISC7 = 1;
    TRISC0 = 0;
    RC1IE = 1;
    RC1IP = 1;  
    R_485;
}

const unsigned char uart_brg_word[3][2]={
0,51,
0,25,
0,1};

void set_uart_brg(void)
{
    SPBRGH1 = uart_brg_word[sys.brg][0];
    SPBRG1  = uart_brg_word[sys.brg][1];
    
}




void send_a_char(unsigned char byte) 
{
	 
	while(!TRMT)continue;
	TXREG1 = byte;
}

void send_array(void)
{
    unsigned char i;
    unsigned char t;
    t = uart.s_buf[2]+2;
    
    S_485;
    for(i=0;i<t;t++)
    {
        send_a_char(uart.s_buf[i]);
    }
    R_485;    
}

void uart_receive_deal(void)
{
    unsigned char temp = 0,i;
    if(uart.r_buf[0]!= 0xfe)return;
    if(uart.r_buf[1]!= 0xfe)return;
    if(uart.r_buf[3]!= sys.addr)return;

    if(uart.r_buf[2] > 20)  return;
    
    for(i=0;i<uart.r_buf[2];i++)
    {
        temp = temp + uart.r_buf[2+i];
    }

    temp = 0xff - temp +1;

    if(temp != uart.r_buf[2+uart.r_buf[2]])return;

    uart.s_buf[0] = 0xfe;       //帧头0    
    uart.s_buf[1] = 0xfe;       //帧头1
    uart.s_buf[3] = sys.addr;   //地址
    uart.s_buf[4] = uart.r_buf[4];//序号

    if(((uart.r_buf[4]=0)||(uart.r_buf[4]>0))&&(uart.r_buf[4]<14))
    {
        uart.s_buf[2] = 0x06;//回复包长
        uart.s_buf[5] = 0x11;//命令码
        switch(uart.s_buf[4])
        {
        case 0:
            uart.s_buf[6]=0;
            uart.s_buf[7]=sys.addr;
            break;
        case 1:
            uart.s_buf[6]=0;
            uart.s_buf[7]=sys.brg;
            break;
        case 2:
            uart.s_buf[6]=(sys.uav & 0xff00)>>8;
            uart.s_buf[7]=(sys.uav & 0x00ff);
            break;
        case 3:
            uart.s_buf[6]=(sys.ubv & 0xff00)>>8;
            uart.s_buf[7]=(sys.ubv & 0x00ff);
            break;
        case 4:
            uart.s_buf[6]=(sys.ucv & 0xff00)>>8;
            uart.s_buf[7]=(sys.ucv & 0x00ff);
            break;
        case 5:
            uart.s_buf[6]=(sys.iav & 0xff00)>>8;
            uart.s_buf[7]=(sys.iav & 0x00ff);
            break;
        case 6:
            uart.s_buf[6]=(sys.ibv & 0xff00)>>8;
            uart.s_buf[7]=(sys.ibv & 0x00ff);
            break;
        case 7:
            uart.s_buf[6]=(sys.icv & 0xff00)>>8;
            uart.s_buf[7]=(sys.icv & 0x00ff);
            break;
        case 8:
            uart.s_buf[6]=(sys.v1 & 0xff00)>>8;
            uart.s_buf[7]=(sys.v1 & 0x00ff);
            break;
        case 9:
            uart.s_buf[6]=(sys.v2 & 0xff00)>>8;
            uart.s_buf[7]=(sys.v2 & 0x00ff);
            break;
        case 10:
            uart.s_buf[6]=(sys.v3 & 0xff00)>>8;
            uart.s_buf[7]=(sys.v3 & 0x00ff);
            break;
        case 11:
            uart.s_buf[6]=(sys.c1 & 0xff00)>>8;
            uart.s_buf[7]=(sys.c1 & 0x00ff);
            break;
        case 12:
            uart.s_buf[6]=(sys.c2 & 0xff00)>>8;
            uart.s_buf[7]=(sys.c2 & 0x00ff);
            break;
        case 13:
            uart.s_buf[6]=(sys.c3 & 0xff00)>>8;
            uart.s_buf[7]=(sys.c3 & 0x00ff);
            break;
        
        }
        temp = 0;
        temp += uart.s_buf[2];
        temp += uart.s_buf[3];
        temp += uart.s_buf[4];
        temp += uart.s_buf[5];
        temp += uart.s_buf[6];
        temp += uart.s_buf[7];
        temp = 0xff-temp+1;
        uart.s_buf[8] = temp;
        

        
        
    }
    //    0       1     2       3       4         5       6
    //帧头0   帧头1   包长    地址    序号    命令码  确认码  校验
    //帧头0   帧头1   包长    地址    序号    命令码  高字节 低字节  校验
    else if((uart.r_buf[4]>13)&&(uart.r_buf[4]<21))
    {
        uart.s_buf[2] = 0x05;
        uart.s_buf[5] = 0x33;
        switch(uart.s_buf[4])
        {
        case 14://addr
            if(uart.r_buf[6] > 0){uart.s_buf[6] = 0x55;}
            else
            {
                uart.s_buf[6] = 0xaa;
                sys.addr = uart.r_buf[7];
               // write_data_to_eeprom(HOST_ADDR,sys.addr);
            }        
            break;
        case 15://brg
            if((uart.r_buf[6] > 0)||(uart.r_buf[7]>2))
            {
                uart.s_buf[6] = 0x55;
            }
            else
            {
                uart.s_buf[6] = 0xaa;
                sys.brg = uart.r_buf[7];
                write_data_to_eeprom(HOST_BRG,sys.brg);
            }
            break;
        case 16://v1
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_V1H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_V1L,uart.r_buf[7]);
            sys.v1 = uart.r_buf[6];
            sys.v1 = sys.v1 << 8;
            sys.v1 = sys.v1 + uart.r_buf[7];            
            break;
        case 17://v2
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_V2H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_V2L,uart.r_buf[7]);
            sys.v2 = uart.r_buf[6];
            sys.v2 = sys.v2 << 8;
            sys.v2 = sys.v2 + uart.r_buf[7]; 
            
            break;
        case 18://v3
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_V3H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_V3L,uart.r_buf[7]);
            sys.v3 = uart.r_buf[6];
            sys.v3 = sys.v3 << 8;
            sys.v3 = sys.v3 + uart.r_buf[7]; 
            
            break;
        case 19://i1
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_C1H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_C1L,uart.r_buf[7]);
            sys.c1 = uart.r_buf[6];
            sys.c1 = sys.c1 << 8;
            sys.c1 = sys.c1 + uart.r_buf[7]; 
           
            break;
        case 20://i2
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_C2H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_C2L,uart.r_buf[7]);
            sys.c2 = uart.r_buf[6];
            sys.c2 = sys.c2 << 8;
            sys.c2 = sys.c2 + uart.r_buf[7]; 
            
            break;
        case 21://i3
            uart.s_buf[6] = 0xaa;
            write_data_to_eeprom(PARA_C3H,uart.r_buf[6]);
            write_data_to_eeprom(PARA_C3L,uart.r_buf[7]);
            sys.c3 = uart.r_buf[6];
            sys.c3 = sys.c3 << 8;
            sys.c3 = sys.c3 + uart.r_buf[7]; 
            break;
        
        }
        temp = 0;
        temp += uart.s_buf[2];
        temp += uart.s_buf[3];
        temp += uart.s_buf[4];
        temp += uart.s_buf[5];
        temp += uart.s_buf[6];        
        temp = 0xff-temp+1;
        uart.s_buf[7] = temp;
        
    }    
    send_array();    
}

