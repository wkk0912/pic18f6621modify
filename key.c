//#include<pic18f6x2x.h>
#include<pic18.h>
#include"key.h"
#include"menu.h"

KEY_T key;
extern SYS_T sys;

void key_pin_init(void)
{
    TRISB4 = 1;
    TRISB5 = 1;
    TRISB6 = 1;
    TRISB7 = 1;
    key.count=0;
    key.num = 0;
    key.num_n = 0;
    key.num_p = 0;
    key.state = 0;
    
}

void key_scan(void)
{
  
    unsigned char temp = 0;

    if(RB4 == 0)temp = 2;
    else if(RB5 == 0)temp = 1;
    else if(RB6 == 0)temp = 3;
    else if(RB7 == 0)temp = 4;
    else temp = 0;
    
    

    
    switch(key.state)
    {
        case 0:
        if(temp!=0)
        {
            key.num_p = temp;
			key.state =1;
        }
        break;

        case 1:
		
        key.num_n= temp;
        
        if(key.num_n!= key.num_p)
        {
            key.count = 0;
            key.state =0;
            key.num_n= 0;
            key.num_p= 0;
        }
		else
		{
        	key.count++;
        	if(key.count >= 3)
        	{
                key.count = 0;
            	key.state = 2;
            	key.num = key.num_n;
            	key.flag = 1;
        	}
		}
        break;

        case 2:
		
        if(temp == 0)
        {
            key.count=0;          
            key.num_n = 0;
            key.num_p = 0;
            key.state = 0;
        }
        break;

        default:break;
        
    }
    
}

void set_mode_pin_init(void)
{
    TRISD0=1;//12V
    TRISF0=1;//12V1
    TRISC1=1;//12V2
}
//0xf7
void set_mode(void)
{
    if(RD0 == 0){sys.set_mode |= 0x01;}
    else{sys.set_mode &= 0xfe;}

    if(RF0 == 0){sys.set_mode |= 0x02;}
    else{sys.set_mode &= 0xfd;}

    if(RC1 == 0){sys.set_mode |= 0x04;}
    else{sys.set_mode &= 0xfb;}
}



