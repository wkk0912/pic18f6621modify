#ifndef __KEY
#define __KEY

typedef struct KEY
{       
    unsigned char num;
    unsigned char num_p;
    unsigned char num_n;
    unsigned char state;
    unsigned char count;
    unsigned char flag;
}KEY_T;

#define k1 RB4
#define k2 RB5
#define k3 RB6
#define k4 RB7

void key_scan(void);
void key_pin_init(void);
void set_mode_pin_init(void);
void set_mode(void);


#endif
