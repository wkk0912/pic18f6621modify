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
    volatile char channle;       //��ǰad  ͨ��    
    volatile char status;        //ad  ģ�鵱ǰ״̬
    unsigned char ch_num;        //ͨ������
    unsigned int  ad1;           //ĳһͨ����һ�� ���� �� ��׽�жϴ���
    unsigned int  ad2;           //ĳһͨ���о��һ����90����λ�ǣ��ɶ�ʱ������
    unsigned char idle_time;     //ĳһͨ������ʱ�����
    unsigned int  sum_val;       //ĳһͨ��һ�β����ۼ�ֵ
    unsigned int  max_val;       //ĳһͨ��һ�β������ֵ
    unsigned int  min_val;       //ĳһͨ��һ�β�����Сֵ
    unsigned char sam_count;     //ĳһͨ��һ�β�������
	unsigned char time_flag;     //���������־
	unsigned int  time_count;    //���������ʱ
	unsigned char one_ch_finish; //ĳһͨ���������
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
