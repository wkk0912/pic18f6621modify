#ifndef __LED
#define __LED

#define led1 RF5
#define led2 RF6
#define led3 RF7

#define LED_RUN_ON   RF7=0
#define LED_RUN_OFF  RF7=1

#define LED_MASSAGE_ON RF6=0
#define LED_MASSAGE_OFF RF6=1

#define LED_WARNING_ON RF5=0
#define LED_WARNING_OFF RF5=1

#define BZ_ON RB2=0
#define BZ_OFF RB2=1

#define DLY1_ON RA3=0//D1
#define DLY1_OFF RA3=1//D1
#define DLY2_ON RA4=0//D2
#define DLY2_OFF RA4=1//D2
#define DLY3_ON RA5=0//D3
#define DLY3_OFF RA5=1//D3

void led_pin_init(void);
void syswaring(void);

#endif
