
#include<pic18.h>

void timer1_init(void)
{
    T1OSCEN = 0;//�����ر�
    
    TMR1CS  = 0;//FOSC/4
    T1CKPS0 = 1;//8��Ƶ
    T1CKPS1 = 1; 

    TMR1IE = 1;
    TMR1IP = 1;
    TMR1ON = 0;
}


//�ⲿʱ��Ϊ4M
//pllx4 16;
//soc / 4 = 4;
//4 / 8 = 0.5MHz
//
//timer1��ʼֵΪ0xf63b
void start_5ms(void)
{
    TMR1H = 0xf6;
    TMR1L = 0x3b;
    TMR1ON = 1;
}


//timer2��Ϊϵͳʱ��
//ÿ16ms����һ���ж�
//16MHZ / 4 = 4MHZ inc1
//4MHZ  / 16 / 16 =
void timer2_init(void)
{
    T2CKPS0 = 1;//16��Ƶ
    T2CKPS1 = 1;

    T2OUTPS0 = 1;//�ж�16��Ƶ
    T2OUTPS1 = 1;
    T2OUTPS2 = 1;
    T2OUTPS3 = 1;

    TMR2IE = 1;
    TMR2IP = 1;

    TMR2ON = 1;
    
}
