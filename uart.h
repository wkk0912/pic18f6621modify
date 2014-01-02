#ifndef _UART
#define _UART

#define R_IDEL  0
#define R_ING   1
#define R_ED    2
#define MAX_TIME  20


typedef struct uart_t
{
    unsigned char r_buf[20];
    unsigned char s_buf[20];
    unsigned char count;
    unsigned int  time;
    unsigned char flag;
}UART_T;

void set_uart_brg(void);
void uart_init(void);
void send_a_char(unsigned char byte);
void send_array(void);
void uart_receive_deal(void);

#endif
