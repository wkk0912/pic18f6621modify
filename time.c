
#include<pic18.h>

void timer1_init(void)
{
    T1OSCEN = 0;//振荡器关闭
    
    TMR1CS  = 0;//FOSC/4
    T1CKPS0 = 1;//8分频
    T1CKPS1 = 1; 

    TMR1IE = 1;
    TMR1IP = 1;
    TMR1ON = 0;
}


//外部时钟为4M
//pllx4 16;
//soc / 4 = 4;
//4 / 8 = 0.5MHz
//
//timer1初始值为0xf63b
void start_5ms(void)
{
    TMR1H = 0xf6;
    TMR1L = 0x3b;
    TMR1ON = 1;
}


//timer2作为系统时钟
//每16ms产生一个中断
//16MHZ / 4 = 4MHZ inc1
//4MHZ  / 16 / 16 =
void timer2_init(void)
{
    T2CKPS0 = 1;//16分频
    T2CKPS1 = 1;

    T2OUTPS0 = 1;//中断16分频
    T2OUTPS1 = 1;
    T2OUTPS2 = 1;
    T2OUTPS3 = 1;

    TMR2IE = 1;
    TMR2IP = 1;

    TMR2ON = 1;
    
}
