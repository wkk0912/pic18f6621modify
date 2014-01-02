#ifndef __MENU
#define __MENU

#define HOST_INIT  0//主机是否第一次上电记录
#define HOST_ADDR  1//主机地址
#define HOST_BRG   2//通信波特率
#define H_PSW0     3//password0
#define H_PSW1     4//password1
#define H_PSW2     5//password2
#define H_PSW3     6//password3
#define H_PSW4     7//password4
#define H_PSW5     8//password5

#define PARA_V1H   9//电压参数 
#define PARA_V1L   10// 
#define PARA_V2H   11// 
#define PARA_V2L   12// 
#define PARA_V3H   13// 
#define PARA_V3L   14// 

#define PARA_C1H   15//电流参数 
#define PARA_C1L   16// 
#define PARA_C2H   17// 
#define PARA_C2L   18// 
#define PARA_C3H   19// 
#define PARA_C3L   20// 

#define TRAIL_FLAG 21//测试位


#define ERR_TOTAL  22//报警记录总数
#define ERR_INDEX  23//
#define ERR_ADDR_BASE 24

#define MAX_RECORD_NUMBER 100//条记录

#define FEED_DOG RG2^=1



typedef struct FUN
{
    void (*fun)(void);
}FUN_T;


typedef struct _sys
{
    unsigned int uav;//a相电压
    unsigned int ubv;//
    unsigned int ucv;//
    unsigned int iav;//
    unsigned int ibv;//
    unsigned int icv;//
	         int brg;//
	         int brg_buf;
	unsigned char addr;//
	unsigned char addr_buf;        
	
	unsigned char menu_index;//
	int main_menu_phase;//
	int time_set_phase;//

	char password[6];//
    int psw_buf[6];//
	char pswin;//

	unsigned char err_total_number;
	int err_read_index;
	int err_record_index;
	unsigned char err_buf[7];

	int pare_set_phase;

	unsigned char set_mode;
	unsigned char run_mode;


	unsigned int v1;
	unsigned int v2;
	unsigned int v3;
	         int vbf;
	         int v_step;

	unsigned int c1;
	unsigned int c2;
	unsigned int c3;

	         int cbf;
	         int c_step;

	unsigned char err_code;
	unsigned char err_judge_flag;

	unsigned int lcd_fresh_time;
	unsigned char lcd_fresh_flag;

	unsigned int key_scand_time;
	unsigned char key_scand_flag;

	         
    
    union 
    {
        unsigned char byte;
        struct
        {
            unsigned char run  :1;//系统状态字
    
        }bits;
    
    }flag;
}SYS_T;

void display_menu(void);

void fun0(void);
void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);
void fun6(void);
void fun7(void);
void fun8(void);
void fun9(void);
void fun10(void);
void fun11(void);
void fun12(void);
void fun13(void);
void fun14(void);
void fun15(void);
void fun16(void);
void fun17(void);
void fun18(void);
void fun19(void);
void fun20(void);
void fun21(void);
void fun22(void);
void fun23(void);
void fun24(void);
void fun25(void);
void fun26(void);
void fun27(void);
void fun28(void);
void fun29(void);
void fun30(void);
void fun31(void);
void fun32(void);
void fun33(void);
void fun34(void);
void fun35(void);
void fun36(void);
void fun37(void);
void fun38(void);
void fun39(void);
void fun40(void);
void fun41(void);
void fun42(void);
void fun43(void);
void fun44(void);
void fun45(void);
void fun46(void);
void fun47(void);
void fun48(void);
void fun49(void);
void fun50(void);
void fun51(void);
void fun52(void);
void fun53(void);
void fun54(void);
void fun55(void);
void fun56(void);
void fun57(void);
void fun58(void);
void fun59(void);
void fun60(void);
void fun61(void);
void fun62(void);
void fun63(void);
void fun64(void);
void fun65(void);
void fun66(void);
void fun67(void);
void fun68(void);
void fun69(void);
void fun70(void);

void lcd_fresh(void);

#endif
