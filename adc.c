#include<pic18.h>
#include<pic18fxx22.h>
#include"adc.h"
#include"lcd.h"
#include"menu.h"
#include"eeprom.h"

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


#define EN_U_CHANNLE CCP4IE=1;
#define DIS_U_CHANNLE CCP4IE=0;
#define EN_I_CHANNLE CCP5IE=1;
#define DIS_I_CHANNLE CCP5IE=0;


AD_T adm;
extern SYS_T sys;

extern unsigned char bufb[100];
unsigned char ua_err;
unsigned char ub_err;
unsigned char uc_err;
unsigned char ia_err;
unsigned char ib_err;
unsigned char ic_err;




void ad_buffer_init(void)
{
    adm.ad1 	= 0;
    adm.ad2 	= 0;
    adm.status 	= 0;
    adm.channle = 0;
    adm.time_count = 0;
    adm.time_flag = 0;
}




void adc_init(void)
{
    //a0,a1 pin analog input,other are i/0 pin
    PCFG0 = 1;
    PCFG1 = 0;
    PCFG2 = 1;
    PCFG3 = 1;

    //VREF+=AVDD,VREF-=AVSS
    VCFG1 = 0;
    VCFG0 = 0;

    //a0,a1 set input
    TRISA0 = 1;
    TRISA1 = 1;
    
    
    ADFM = 1;//AD Right justified

    ACQT0 = 1;//��������ʱ��Ϊ20tad
    ACQT1 = 1;
    ACQT2 = 1;

    ADCS0 = 0;//20mhz ʱ������Ϊ3.2us
    ADCS1 = 1;
    ADCS2 = 1;

    ADON = 1;//����adģ��
    
    TRISA2 = 0;//��������ʹ��
    TRISF1 = 0;//��ѹ����ʹ��
    
    TRISF2 = 0;//������ѹ���� ��ַ�� 0
    TRISF3 = 0;//������ѹ���� ��ַ�� 1

	
    

    ad_buffer_init();
}




void capture_init(void)
{
    //T3CON :RD16 T3CCP2 T3CKPS1 T3CKPS0 T3CCP1 T3SYNC TMR3CS TMR3ON 
    //        1     1      0       0       1      0      0       1
    //Enables register read/write of Timer3 in one 16-bit operation
    //Timer3 and Timer4 are the clock sources for ECCP1 through CCP5
    //1:1 Prescale value
    T3CON = 0xc9;
    
    //RG3 ����
    TRISG3 = 1;
    TRISG4 = 1;

    CCP4CON = 0x04;//0x04�½��ز�׽0x05�����ز�׽RG3
    CCP5CON = 0X05;//0x04�½��ز�׽0x05�����ز�׽RG4

    CCP4IE = 1;
    CCP5IE = 1;   
    CCP4IP = 1; 
    CCP5IP = 1;
}



void clear_one_ad_val(void)
{
    switch(adm.channle)
    {
    case 0:sys.uav = 0;break;
    case 1:sys.ubv = 0;break;
    case 2:sys.ucv = 0;break;
    case 3:sys.iav = 0;break;
    case 4:sys.ibv = 0;break;
    case 5:sys.icv = 0;break;
    default:break;
    }
}

void ad_sequence_sample(void)
{
	
    switch(adm.status)
    {
    
    case 0:						/*�л�ͨ��*/        

   
    	if(adm.channle == 0)     
    	{
    		DIS_I_CHANNLE
    		EN_U_CHANNLE
    		OPEN_UA_CHANNLE
    	}
    	else if(adm.channle == 1)
    	{    
    		DIS_I_CHANNLE
    		EN_U_CHANNLE
    		OPEN_UB_CHANNLE
    	}
		else if(adm.channle == 2)
		{			
    		DIS_I_CHANNLE
    		EN_U_CHANNLE
    		OPEN_UC_CHANNLE
		}
		else if(adm.channle == 3)
		{
			DIS_U_CHANNLE
    		EN_I_CHANNLE
			OPEN_IA_CHANNLE
		}
		else if(adm.channle == 4)
		{
			DIS_U_CHANNLE
    		EN_I_CHANNLE
			OPEN_IB_CHANNLE
		}
		else if(adm.channle == 5)
		{
			DIS_U_CHANNLE
    		EN_I_CHANNLE
			OPEN_IC_CHANNLE
		} 	
		adm.status = 1;
		break;

    case 1:		/*�ɲ�׽���� �ڲ�׽�ж��д��������ﲻ�ô���*/		
        adm.idle_time++;			 
        if(adm.idle_time == 3)   
        {
            adm.idle_time = 0; 	 
            clear_one_ad_val();	 
            
            if(adm.channle ==0)ua_err = 4;
            else if(adm.channle ==1)ub_err = 4;
            else if(adm.channle ==2)uc_err = 4;
            else if(adm.channle ==3)ia_err = 4;
            else if(adm.channle ==4)ib_err = 4;
            else if(adm.channle ==5)ic_err = 4;

            adm.channle++;		 
            if(adm.channle >= (adm.ch_num))
            {
            	adm.channle = 0;
            	sys.err_judge_flag = 1;
            }
            adm.status = 0;
        }    
        break;
    
    case 2:/*��time1��5ms��ʱ�жϴ��������ﲻ�ô���*/	
    	adm.idle_time=0;           
        break;
    
    case 3:
        adm.idle_time = 0;		
        cal_channle_val(); 
        adm.status = 0;
        break;
    }
}

long root(long source)
{
    
    long temp;
	unsigned int i;

    temp = source >> 7;
    temp +=31;

    for(i = 0; i < 6; i++)
    {
        temp = (temp + source / temp) / 2;
    }
    return temp;
}


void cal_channle_val(void)
{
    unsigned long d1,d2,d3,d,temp;
    

	/**/
    d1 = adm.ad1;
    d2 = adm.ad2;
    //d  = d2;
    
    d3 = d1*d1 + d2*d2;    
    d  = root(d3);
	/*ÿһͨ��������ֵ�ۼ�5�Σ�ȥ������ֵ����Сֵ��ƽ�����ж�*/
    
    if(adm.sam_count == 0)
    {
        adm.max_val = d;
        adm.min_val = d;        
        adm.sum_val = d;
    }
    else
    {
        adm.sum_val = adm.sum_val + d;//�ۼ�    
        if(d > adm.max_val)adm.max_val = d;       
        if(d < adm.min_val)adm.min_val = d;
        
    }

    adm.sam_count++;
    if(adm.sam_count >= 10)
    {
    	adm.sam_count = 0;    	
        adm.sum_val = adm.sum_val - adm.max_val - adm.min_val;
		temp= adm.sum_val;
		
        temp= temp / 8;
        temp = temp * 500;/*�ο���ѹΪ5*/
        temp = temp / 1024;
       
        switch(adm.channle)
        {
        case 0:
            temp = temp*10/33;
            sys.uav = temp;
            
			/*
            if(sys.uav == 0)ua_err = 4;            
            else if(sys.uav > sys.v1 + TH_CHANG_VAL)ua_err = 3;
            else if((sys.uav <= sys.v1 - TH_CHANG_VAL)&&(sys.uav > sys.v2+ TH_CHANG_VAL))ua_err = 2;
            else if((sys.uav <= sys.v2 - TH_CHANG_VAL)&&(sys.uav > sys.v3+ TH_CHANG_VAL))ua_err = 1;
            else ua_err = 0;
            */
            if((ua_err== 4)||(ua_err == 0))
			{
				if(sys.uav > sys.v1)ua_err= 3;
            	else if((sys.uav <= sys.v1)&&(sys.uav > sys.v2))ua_err = 2;
            	else if((sys.uav <= sys.v2)&&(sys.uav > sys.v3))ua_err = 1;
            	else if((sys.uav <= sys.v3)&&(sys.uav >  0))ua_err = 0;
            	else if(sys.uav == 0)ua_err = 4;
			}
			else if(ua_err == 3)
			{
				if(sys.uav > sys.v1)ua_err = 3;
            	else if((sys.uav <= sys.v1-TH_CHANG_VAL)&&(sys.uav > sys.v2))ua_err = 2;
            	else if((sys.uav <= sys.v2)&&(sys.uav > sys.v3))ua_err = 1;
            	else if((sys.uav <= sys.v3)&&(sys.uav>0))ua_err = 0;
            	else if(sys.uav == 0)ua_err = 4;
			}
			else if(ua_err == 2)
			{
				if(sys.uav > sys.v1)ua_err = 3;
            	else if((sys.uav <= sys.v1)&&(sys.uav > sys.v2))ua_err = 2;
            	else if((sys.uav <= sys.v2-TH_CHANG_VAL)&&(sys.uav > sys.v3))ua_err = 1;
            	else if((sys.uav <= sys.v3)&&(sys.uav>0))ua_err = 0;
            	else if(sys.uav == 0)ua_err = 4;
			}
			else if(ua_err == 1)
			{
				if(sys.uav > sys.v1)ua_err = 3;
            	else if((sys.uav <= sys.v1)&&(sys.uav > sys.v2))ua_err = 2;
            	else if((sys.uav <= sys.v2)&&(sys.uav > sys.v3))ua_err = 1;
            	else if((sys.uav <= sys.v3-TH_CHANG_VAL)&&(sys.uav>0))ua_err = 0;
            	else if(sys.uav == 0)ua_err = 4;
				
			}       			

			adm.channle = 1;			
            break;

        case 1:

        	
            temp = temp*10/33;            
            sys.ubv = temp; 
            /*
            if(sys.ubv == 0){ub_err = 4;}
            else if(sys.ubv > sys.v1+ TH_CHANG_VAL){ub_err = 3;}
            else if((sys.ubv <= sys.v1- TH_CHANG_VAL)&&(sys.ubv > sys.v2+ TH_CHANG_VAL)){ub_err=2;}
            else if((sys.ubv <= sys.v2- TH_CHANG_VAL)&&(sys.ubv > sys.v3+ TH_CHANG_VAL)){ub_err=1;}
            else {ub_err = 0;sys.err_code = 0;}
            */
			if((ub_err== 4)||(ub_err == 0))
			{
				if(sys.ubv > sys.v1)ub_err= 3;
            	else if((sys.ubv <= sys.v1)&&(sys.ubv > sys.v2))ub_err = 2;
            	else if((sys.ubv <= sys.v2)&&(sys.ubv > sys.v3))ub_err = 1;
            	else if((sys.ubv <= sys.v3)&&(sys.ubv >  0))ub_err = 0;
            	else if(sys.ubv == 0)ub_err = 4;
			}
			else if(ub_err == 3)
			{
				if(sys.ubv > sys.v1)ub_err = 3;
            	else if((sys.ubv <= sys.v1-TH_CHANG_VAL)&&(sys.ubv > sys.v2))ub_err = 2;
            	else if((sys.ubv <= sys.v2)&&(sys.ubv > sys.v3))ub_err = 1;
            	else if((sys.ubv <= sys.v3)&&(sys.ubv>0))ub_err = 0;
            	else if(sys.ubv == 0)ub_err = 4;
			}
			else if(ub_err == 2)
			{
				if(sys.ubv > sys.v1)ub_err = 3;
            	else if((sys.ubv <= sys.v1)&&(sys.ubv > sys.v2))ub_err = 2;
            	else if((sys.ubv <= sys.v2-TH_CHANG_VAL)&&(sys.ubv > sys.v3))ub_err = 1;
            	else if((sys.ubv <= sys.v3)&&(sys.ubv>0))ub_err = 0;
            	else if(sys.ubv == 0)ub_err = 4;
			}
			else if(ub_err == 1)
			{
				if(sys.ubv > sys.v1)ub_err = 3;
            	else if((sys.ubv <= sys.v1)&&(sys.ubv > sys.v2))ub_err = 2;
            	else if((sys.ubv <= sys.v2)&&(sys.ubv > sys.v3))ub_err = 1;
            	else if((sys.ubv <= sys.v3-TH_CHANG_VAL)&&(sys.ubv>0))ub_err = 0;
            	else if(sys.ubv == 0)ub_err = 4;
				
			}       	
           
            adm.channle = 2;
            break;

        case 2:
            temp = temp*10/33;
            sys.ucv = temp;
            /*
            if(sys.ucv == 0)uc_err = 4;
            else if(sys.ucv > sys.v1+ TH_CHANG_VAL)uc_err = 3;
            else if((sys.ucv <= sys.v1- TH_CHANG_VAL)&&(sys.ucv > sys.v2+ TH_CHANG_VAL))uc_err = 2;
            else if((sys.ucv <= sys.v2- TH_CHANG_VAL)&&(sys.ucv > sys.v3+ TH_CHANG_VAL))uc_err=1;
            else uc_err = 0;
            */

            if((uc_err== 4)||(uc_err == 0))
			{
				if(sys.ucv > sys.v1)uc_err= 3;
            	else if((sys.ucv <= sys.v1)&&(sys.ucv > sys.v2))uc_err = 2;
            	else if((sys.ucv <= sys.v2)&&(sys.ucv > sys.v3))uc_err = 1;
            	else if((sys.ucv <= sys.v3)&&(sys.ucv >  0))uc_err = 0;
            	else if(sys.ucv == 0)uc_err = 4;
			}
			else if(uc_err == 3)
			{
				if(sys.ucv > sys.v1)uc_err = 3;
            	else if((sys.ucv <= sys.v1-TH_CHANG_VAL)&&(sys.ucv > sys.v2))uc_err = 2;
            	else if((sys.ucv <= sys.v2)&&(sys.ucv > sys.v3))uc_err = 1;
            	else if((sys.ucv <= sys.v3)&&(sys.ucv>0))uc_err = 0;
            	else if(sys.ucv == 0)uc_err = 4;
			}
			else if(uc_err == 2)
			{
				if(sys.ucv > sys.v1)uc_err = 3;
            	else if((sys.ucv <= sys.v1)&&(sys.ucv > sys.v2))uc_err = 2;
            	else if((sys.ucv <= sys.v2-TH_CHANG_VAL)&&(sys.ucv > sys.v3))uc_err = 1;
            	else if((sys.ucv <= sys.v3)&&(sys.ucv>0))uc_err = 0;
            	else if(sys.ucv == 0)uc_err = 4;
			}
			else if(uc_err == 1)
			{
				if(sys.ucv > sys.v1)uc_err = 3;
            	else if((sys.ucv <= sys.v1)&&(sys.ucv > sys.v2))uc_err = 2;
            	else if((sys.ucv <= sys.v2)&&(sys.ucv > sys.v3))uc_err = 1;
            	else if((sys.ucv <= sys.v3-TH_CHANG_VAL)&&(sys.ucv>0))uc_err = 0;
            	else if(sys.ucv == 0)uc_err = 4;
				
			}       
            
            adm.channle = 3;
            break;

        case 3:/*����ϵ��*/
			
            temp = temp *11;
            sys.iav = temp;

            /*
            if(sys.iav == 0)ia_err = 4;
            else if(sys.iav > sys.c1+ TH_CHANG_VAL)ia_err = 3;
            else if((sys.iav <= sys.c1- TH_CHANG_VAL)&&(sys.iav > sys.c2+ TH_CHANG_VAL))ia_err=2;
            else if((sys.iav <= sys.c2- TH_CHANG_VAL)&&(sys.iav > sys.c3+ TH_CHANG_VAL))ia_err=1;
            else ia_err = 0;      */

			if((ia_err== 4)||(ia_err == 0))
			{
				if(sys.iav > sys.c1)ia_err= 3;
            	else if((sys.iav <= sys.c1)&&(sys.iav > sys.c2))ia_err = 2;
            	else if((sys.iav <= sys.c2)&&(sys.iav > sys.c3))ia_err = 1;
            	else if((sys.iav <= sys.c3)&&(sys.iav >  0))ia_err = 0;
            	else if(sys.iav == 0)ia_err = 4;
			}
			else if(ia_err == 3)
			{
				if(sys.iav > sys.c1)ia_err = 3;
            	else if((sys.iav <= sys.c1-TH_CHANG_VAL)&&(sys.iav > sys.c2))ia_err = 2;
            	else if((sys.iav <= sys.c2)&&(sys.iav > sys.c3))ia_err = 1;
            	else if((sys.iav <= sys.c3)&&(sys.iav>0))ia_err = 0;
            	else if(sys.iav == 0)ia_err = 4;
			}
			else if(ia_err == 2)
			{
				if(sys.iav > sys.c1)ia_err = 3;
            	else if((sys.iav <= sys.c1)&&(sys.iav > sys.c2))ia_err = 2;
            	else if((sys.iav <= sys.c2-TH_CHANG_VAL)&&(sys.iav > sys.c3))ia_err = 1;
            	else if((sys.iav <= sys.c3)&&(sys.iav>0))ia_err = 0;
            	else if(sys.iav == 0)ia_err = 4;
			}
			else if(ia_err == 1)
			{
				if(sys.iav > sys.c1)ia_err = 3;
            	else if((sys.iav <= sys.c1)&&(sys.iav > sys.c2))ia_err = 2;
            	else if((sys.iav <= sys.c2)&&(sys.iav > sys.c3))ia_err = 1;
            	else if((sys.iav <= sys.c3-TH_CHANG_VAL)&&(sys.iav>0))ia_err = 0;
            	else if(sys.iav == 0)ia_err = 4;
				
			}       			
            
            
            if(adm.ch_num == 4)	
            {
                adm.channle= 0;
                sys.err_judge_flag = 1;               
            }
            else
            {
                adm.channle= 4;
            }
            break;

        case 4:
            temp = temp *11;
            sys.ibv = temp;
			/*
            if(sys.ibv == 0)ib_err = 4;
            else if(sys.ibv > sys.c1+ TH_CHANG_VAL)ib_err=3;
            else if((sys.ibv <= sys.c1- TH_CHANG_VAL)&&(sys.ibv > sys.c2+ TH_CHANG_VAL))ib_err=2;
            else if((sys.ibv <= sys.c2- TH_CHANG_VAL)&&(sys.ibv > sys.c3+ TH_CHANG_VAL))ib_err=1;
            else ib_err =0;
			*/
			if((ib_err== 4)||(ib_err == 0))
			{
				if(sys.ibv > sys.c1)ib_err= 3;
            	else if((sys.ibv <= sys.c1)&&(sys.ibv > sys.c2))ib_err = 2;
            	else if((sys.ibv <= sys.c2)&&(sys.ibv > sys.c3))ib_err = 1;
            	else if((sys.ibv <= sys.c3)&&(sys.ibv >  0))ib_err = 0;
            	else if(sys.ibv == 0)ib_err = 4;
			}
			else if(ib_err == 3)
			{
				if(sys.ibv > sys.c1)ib_err = 3;
            	else if((sys.ibv <= sys.c1-TH_CHANG_VAL)&&(sys.ibv > sys.c2))ib_err = 2;
            	else if((sys.ibv <= sys.c2)&&(sys.ibv > sys.c3))ib_err = 1;
            	else if((sys.ibv <= sys.c3)&&(sys.ibv>0))ib_err = 0;
            	else if(sys.ibv == 0)ib_err = 4;
			}
			else if(ib_err == 2)
			{
				if(sys.ibv > sys.c1)ib_err = 3;
            	else if((sys.ibv <= sys.c1)&&(sys.ibv > sys.c2))ib_err = 2;
            	else if((sys.ibv <= sys.c2-TH_CHANG_VAL)&&(sys.ibv > sys.c3))ib_err = 1;
            	else if((sys.ibv <= sys.c3)&&(sys.ibv>0))ib_err = 0;
            	else if(sys.ibv == 0)ib_err = 4;
			}
			else if(ib_err == 1)
			{
				if(sys.ibv > sys.c1)ib_err = 3;
            	else if((sys.ibv <= sys.c1)&&(sys.ibv > sys.c2))ib_err = 2;
            	else if((sys.ibv <= sys.c2)&&(sys.ibv > sys.c3))ib_err = 1;
            	else if((sys.ibv <= sys.c3-TH_CHANG_VAL)&&(sys.ibv>0))ib_err = 0;
            	else if(sys.ibv == 0)ib_err = 4;
				
			}       			
           
          
            adm.channle = 5;
            break;
        case 5:
            temp = temp *11;
            sys.icv = temp;            
            /*
            if(sys.icv == 0)ic_err = 4;
            else if(sys.icv > sys.c1+ TH_CHANG_VAL)ic_err=3;
            else if((sys.icv <= sys.c1- TH_CHANG_VAL)&&(sys.icv > sys.c2+ TH_CHANG_VAL))ic_err=2;
            else if((sys.icv <= sys.c2- TH_CHANG_VAL)&&(sys.icv > sys.c3+ TH_CHANG_VAL))ic_err=1;
            else ic_err = 0; 
            */
			if((ic_err== 4)||(ic_err == 0))
			{
				if(sys.icv > sys.c1)ic_err= 3;
            	else if((sys.icv <= sys.c1)&&(sys.icv > sys.c2))ic_err = 2;
            	else if((sys.icv <= sys.c2)&&(sys.icv > sys.c3))ic_err = 1;
            	else if((sys.icv <= sys.c3)&&(sys.icv >  0))ic_err = 0;
            	else if(sys.icv == 0)ic_err = 4;
			}
			else if(ic_err == 3)
			{
				if(sys.icv > sys.c1)ic_err = 3;
            	else if((sys.icv <= sys.c1-TH_CHANG_VAL)&&(sys.icv > sys.c2))ic_err = 2;
            	else if((sys.icv <= sys.c2)&&(sys.icv > sys.c3))ic_err = 1;
            	else if((sys.icv <= sys.c3)&&(sys.icv>0))ic_err = 0;
            	else if(sys.icv == 0)ic_err = 4;
			}
			else if(ic_err == 2)
			{
				if(sys.icv > sys.c1)ic_err = 3;
            	else if((sys.icv <= sys.c1)&&(sys.icv > sys.c2))ic_err = 2;
            	else if((sys.icv <= sys.c2-TH_CHANG_VAL)&&(sys.icv > sys.c3))ic_err = 1;
            	else if((sys.icv <= sys.c3)&&(sys.icv>0))ic_err = 0;
            	else if(sys.icv == 0)ic_err = 4;
			}
			else if(ic_err == 1)
			{
				if(sys.icv > sys.c1)ic_err = 3;
            	else if((sys.icv <= sys.c1)&&(sys.icv > sys.c2))ic_err = 2;
            	else if((sys.icv <= sys.c2)&&(sys.icv > sys.c3))ic_err = 1;
            	else if((sys.icv <= sys.c3-TH_CHANG_VAL)&&(sys.icv>0))ic_err = 0;
            	else if(sys.icv == 0)ic_err = 4;
				
			}       		
            
            sys.err_judge_flag = 1;

            adm.channle = 0;
        }
        
    	adm.sam_count = 0;
    	adm.sum_val = 0;
    }
    
}
