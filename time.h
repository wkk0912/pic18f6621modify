#ifndef _TIMER 
#define _TIMER


void timer1_init(void);
void start_5ms(void);
void timer2_init(void);

#define START_5MS TMR1H=0xf6;TMR1L=0x1b;TMR1ON=1;//TMR1L=3b

#endif
