#ifndef __LCD
#define __LCD

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define cs1 RD1
#define cs2 RD2
#define rs  RD3
#define rw  RD4
#define e   RD5
#define bl  RD6




#define lcd_page  0xb8
#define lcd_col   0x40
#define lcd_row   0xc0
#define lcd_on    0x3f
#define lcd_off   0x3e








#define LCD_CLR 0x01
#define LCD_REST_ADR 0x20
#define LCD_ON 0x0c //00001100
#define LCD_OFF 0x08

void lcd_pin_init(void);
void init_lcd(void);
int xprint(int x,int y,unsigned char flag, const char *buf);
void lcd_clear(void);
void dis_signle_char(int x, int y, unsigned char acsii,unsigned char flag);
void fill_bit_picture(void);
int xprintf(int x, int y,unsigned char flag,const char *fmt, ...);
#endif 
