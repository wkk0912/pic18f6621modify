#ifndef _adc
#define _adc


#define OPEN_UA_CHANNLE  RF2=0;RF3=0;RF1=0;RA2=1;
#define OPEN_UB_CHANNLE  RF2=1;RF3=0;RF1=0;RA2=1;
#define OPEN_UC_CHANNLE  RF2=0;RF3=1;RF1=0;RA2=1;
#define OPEN_IA_CHANNLE  RF2=0;RF3=0;RF1=1;RA2=0;
#define OPEN_IB_CHANNLE  RF2=1;RF3=0;RF1=1;RA2=0;
#define OPEN_IC_CHANNLE  RF2=0;RF3=1;RF1=1;RA2=0;



	



#define c_ad0 ADCON0&=0xc3;ADCON0|=0X02
#define c_ad1 ADCON0&=0xc3;ADCON0|=0X06

#define START_AD  RF2=0;RF3=0;RF1=0;RA2=1

#define c_ua  RF2=0;RF3=0;RF1=0;RA2=1;ADCON0&=0xc3;ADCON0|=0X06//c_ad1//UA
#define c_uc  RF2=0;RF3=1;RF1=0;RA2=1;ADCON0&=0xc3;ADCON0|=0X06//c_ad1//Uc
#define c_ub  RF2=1;RF3=0;RF1=0;RA2=1;ADCON0&=0xc3;ADCON0|=0X06//c_ad1//Ub

#define c_ia  RF2=0;RF3=0;RF1=1;RA2=0;ADCON0&=0xc3;ADCON0|=0X02//c_ad0//IA
#define c_ic  RF2=0;RF3=1;RF1=1;RA2=0;ADCON0&=0xc3;ADCON0|=0X02//c_ad0//IB
#define c_ib  RF2=1;RF3=0;RF1=1;RA2=0;ADCON0&=0xc3;ADCON0|=0X02//c_ad0//IC

#define CLOSE_AD_CHANNLE RF1=1;RA2=1

#define AD_IDEL     0
#define AD_STEP1    1
#define AD_STEP2    2
#define AD_STEP3    3


#define TH_CHANG_VAL 2

typedef struct ad_buf
{
    volatile char channle;       //当前ad  通道    
    volatile char status;        //ad  模块当前状态
    unsigned char ch_num;        //通道总数
    unsigned int  ad1;           //某一通道第一次 采用 由 捕捉中断触发
    unsigned int  ad2;           //某一通道中距第一采样90度相位角，由定时器触发
    unsigned char idle_time;     //某一通道空闲时间记数
    unsigned int  sum_val;       //某一通道一次采样累加值
    unsigned int  max_val;       //某一通道一次采样最大值
    unsigned int  min_val;       //某一通道一次采样最小值
    unsigned char sam_count;     //某一通道一次采样次数
	unsigned char time_flag;     //采样间隔标志
	unsigned int  time_count;    //采样间隔计时
	unsigned char one_ch_finish; //某一通道采样完成
}AD_T;


typedef struct fault
{
    unsigned char last;
    unsigned char new;
}FAULT_T;


void ad_buffer_init(void);
void adc_init(void);
void capture_init(void);
void short_once_ad(void);
void testad(void);
long root(long source);
void cal_an_channle(void);
void judge_val(void);
void cal_channle_val(void);
void judge_sys_val(void);
void ad_sequence_sample(void);

#endif
