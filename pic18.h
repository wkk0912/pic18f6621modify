#ifndef	_PIC18_H
#define	_PIC18_H

#if	defined(_18C242) || defined(_18C252) || defined(_18C442) || defined(_18C452) 
#include	<pic18xx2.h>
#endif

#if	defined(_18C658) || defined(_18C858) || defined(_18C958)
#include	<pic18xx8.h>
#endif

#if	defined(_18C601) || defined(_18C801)
#include	<pic18xx1.h>
#endif

#if	defined(_18F010) || defined(_18F020)
#include	<pic18f0x0.h>
#endif

#if	defined(_18F242) || defined(_18F252) || defined(_18F442) || defined(_18F452)
#include	<pic18fxx2.h>
#endif

#if	defined(_18F248) || defined(_18F258) || defined(_18F448) || defined(_18F458)
#include	<pic18fxx8.h>
#endif

#if	defined(_18F6520) || defined(_18F6620) || defined(_18F6720) || \
	defined(_18F8520) || defined(_18F8620) || defined(_18F8720)
#include	<pic18fxx20.h>
#endif

#if	defined(_18F2525) || defined(_18F2620) || defined(_18F4525) || \
	defined(_18F4620)
#include	<pic18f4620.h>
#endif

#if	defined(_18F1220) || defined(_18F1320)
#include	<pic18f1220.h>
#endif

#if	defined(_18F2220) || defined(_18F2320) || defined(_18F4220) || defined(_18F4320)
#include	<pic18f2320.h>
#endif

#if	defined(_18F2331) || defined(_18F2431) || defined(_18F4331) || defined(_18F4431)
#include	<pic18fxx31.h>
#endif

#if	defined(_18F2410) || defined(_18F2510) || defined(_18F2515) || defined(_18F2610) ||\
	defined(_18F4410) || defined(_18F4510) || defined(_18F4515) || defined(_18F4610)
#include	<pic18f2x1x.h>
#endif

#if	defined(_18F2439) || defined(_18F2539) || defined(_18F4439) || defined(_18F4539)
#include	<pic18fxx39.h>
#endif

#if	defined(_18F6585) || defined(_18F6680) || defined(_18F8585) || defined(_18F8680)
#include	<pic18fxx8x.h>
#endif

#if	defined(_18F2585) || defined(_18F2680) || defined(_18F4585) || defined(_18F4680)
#include	<pic18f2x8x.h>
#endif

#if	defined(_18F6310) || defined(_18F6410) || defined(_18F8310) || defined(_18F8410)
#include	<pic18f6x10.h>
#endif

#if	defined(_18F6525) || defined(_18F6621) || defined(_18F8525) || defined(_18F8621)
#include	<pic18f6x2x.h>
#endif

#if	defined(_18F6390) || defined(_18F6490) || defined(_18F8390) || defined(_18F8490)
#include	<pic18fx490.h>
#endif

#if	defined(_18F2420) || defined(_18F2520) || defined(_18F4420) || defined(_18F4520)
#include	<pic18f4520.h>
#endif

#if	defined(_18F2480) || defined(_18F2580) || defined(_18F4480) || defined(_18F4580)
#include	<pic18f4580.h>
#endif

#if	defined(_18F2455) || defined(_18F2550) || defined(_18F4455) || defined(_18F4550)
#include	<pic18f4550.h>
#endif

#if	defined(_18F6627) || defined(_18F6722) || defined(_18F8627) || defined(_18F8722) || \
	defined(_18F6527) || defined(_18F6622) || defined(_18F8527) || defined(_18F8622)
#include	<pic18fxx22.h>
#endif

#if	defined(_18F65J10) || defined(_18F65J15) || defined(_18F66J10) || defined(_18F66J15) || \
       	defined(_18F67J10) || defined(_18F85J10) || defined(_18F85J15) || defined(_18F86J10) || \
	defined(_18F86J15) || defined(_18F87J10)
#include	<pic18f87j10.h>
#endif

/* Macros to access bytes within words and words within longs */
#define LOW_BYTE(x)     ((unsigned char)((x)&0xFF))
#define HIGH_BYTE(x)    ((unsigned char)(((x)>>8)&0xFF))
#define LOW_WORD(x)     ((unsigned short)((x)&0xFFFF))
#define HIGH_WORD(x)    ((unsigned short)(((x)>>16)&0xFFFF))

/* C access to assembler insructions */	
#define	CLRWDT()	asm(" clrwdt")
#define	NOP()		asm(" nop")
#define	RESET()		asm(" reset")
#define SLEEP()		asm(" sleep")

#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

/* Store a word value to a particular configuration word register eg.
 * __CONFIG(4, DEBUGEN & LVPDIS); // write to config word 4
 * config mask attributes (such as DEBUGEN) defined in chip-specific
 * header file. */
#define	__CONFIG(n, x)	asm("\tpsect config,class=CONFIG");\
			asm("global config_word" ___mkstr(n)); \
			asm("\torg ("___mkstr(n)"-1)*2"); \
			asm("config_word" ___mkstr(n)":"); \
			asm("\tdw "___mkstr(x))

#define __IDLOC(w)      asm("\tpsect idloc,class=IDLOC");\
			asm("\tglobal\tidloc_word"); \
			asm("idloc_word:"); \
			asm("\tirpc\t__arg," ___mkstr(w)); \
			asm("\tdb 0f&__arg&h"); \
			asm("\tendm")


/* Address definitions for config word registers
 * (NOT TO BE USED WITH __CONFIG MACRO!) */
#define CONFIG1L	0x300000
#define CONFIG1H	0x300001
#define CONFIG2L	0x300002
#define CONFIG2H	0x300003
#define CONFIG3L	0x300004
#define CONFIG3H	0x300005
#define CONFIG4L	0x300006
#define CONFIG4H	0x300007
#define CONFIG5L	0x300008
#define CONFIG5H	0x300009
#define CONFIG6L	0x30000A
#define CONFIG6H	0x30000B
#define CONFIG7L	0x30000C
#define CONFIG7H	0x30000D


/* Initialise device EEPROM (if available) with 8 bytes of data at a time eg.
 * // store initial values to first 16-bytes of EEPROM address range.
 * __EEPROM_DATA(0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07);
 * __EEPROM_DATA(0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F);*/
#if defined(EEPROM_SIZE)
#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
			 asm("\tpsect eeprom_data,class=EEDATA"); \
			 asm("\tdb\t" ___mkstr(a) "," ___mkstr(b) "," ___mkstr(c) "," ___mkstr(d) "," \
				      ___mkstr(e) "," ___mkstr(f) "," ___mkstr(g) "," ___mkstr(h))

// Special cases that need errata workarounds
#if defined(_18F242) || defined(_18F252) || defined(_18F442) || defined(_18F452) || \
	defined(_18F4320) || defined(_18F1220) || defined(_18F1320)
#define __BAD_EEDATA
#endif
	
// MACROS for EEPROM Access
/* macro versions of EEPROM read and write */
#if	EEPROM_SIZE > 256
	/* For versions which use EEADRH */
#define	EEPROM_READ(addr) \
	(wait_on_wr(), \
	EEADRH=(((addr)>>8)&0xFF),EEADR=((addr)&0xFF), \
	EECON1&=0x3F,RD=1, \
	(EEDATA))
#elif defined(__BAD_EEDATA)
	/* This version is for chips who must read EEDATA immediately after
	 * RD is set. EEDATA is read into temp variable EEADR for cases where
	 * the result of EEPROM_READ is returned to an indirect object, it may
	 * take several instructions to set up access to the indirect object. */
#define EEPROM_READ(addr) \
	(wait_on_wr(), \
	EEADR=(addr),\
	CARRY=GIE,GIE=0, \
	EECON1&=0x3F,RD=1, \
	EEADR=EEDATA, \
	GIE=CARRY, \
	(EEADR))
#else
	/* Plain and simple version */
#define EEPROM_READ(addr) \
	(wait_on_wr(), \
	EEADR=(addr),\
	EECON1&=0x3F,RD=1, \
	(EEDATA))
#endif
	
#if	EEPROM_SIZE > 256
#define	EEPROM_WRITE(addr, value) \
	wait_on_wr(); \
	EEADRH=(((addr)>>8)&0xFF);EEADR=((addr)&0xFF); \
	EEDATA=(value); \
	EECON1&=0x3F; \
	CARRY=0;if(GIE)CARRY=1;GIE=0; \
	WREN=1;EECON2=0x55;EECON2=0xAA;WR=1; \
	EEIF=0;WREN=0; \
	if(CARRY)GIE=1
#else
#define	EEPROM_WRITE(addr, value) \
	wait_on_wr(); \
	EEADR=((addr)&0xFF); \
	EEDATA=(value); \
	EECON1&=0x3F; \
	CARRY=0;if(GIE)CARRY=1;GIE=0; \
	WREN=1;EECON2=0x55;EECON2=0xAA;WR=1; \
	EEIF=0;WREN=0; \
	if(CARRY)GIE=1
#endif
	
/* macro Flash operations*/
/* erasing a flash program memory row */	
#if defined(SMALL_DATA)
#define FLASH_ERASE(addr) \
	wait_on_wr(); \
	TBLPTRU=0;\
	TBLPTR=(far unsigned char *)addr; \
	EECON1|=0x94;EECON1&=0xBF; \
	CARRY=0;if(GIE)CARRY=1;GIE=0;\
	EECON2=0x55;EECON2=0xAA;WR=1; \
	asm("\tNOP"); \
	if(CARRY)GIE=1
#else
#define FLASH_ERASE(addr) \
	wait_on_wr(); \
	TBLPTR=(far unsigned char *)addr; \
	EECON1|=0x94;EECON1&=0xBF; \
	CARRY=0;if(GIE)CARRY=1;GIE=0;\
	EECON2=0x55;EECON2=0xAA;WR=1; \
	asm("\tNOP"); \
	if(CARRY)GIE=1
#endif

/* read/write EEPROM data memory */
extern unsigned char eeprom_read(unsigned int address);
extern void eeprom_write(unsigned int address,unsigned char data);

/* read/write/erase sections of program memory */
extern unsigned char flash_read(unsigned long addr);
extern void flash_write(far unsigned char *,unsigned char,far unsigned char *);
extern void flash_erase(unsigned long addr);

/* read/write device configuration registers */
extern unsigned int config_read(unsigned char reg_no);
extern void config_write(unsigned char reg_no, unsigned int dataword);

/* read factory-programmed device ID code */
extern unsigned int device_id_read(void);

/* read/write to user ID regs */
extern unsigned char idloc_read(unsigned char reg_no);
extern void idloc_write(unsigned char reg_no,unsigned char data);

/* general purpose EE/flash init sequence used by above functions */
extern void initiate_write(void);
extern void wait_on_wr(void);

#endif

/* Accurate read/write macros for 16-Bit timers */
/*** please note, the timer needs to be enabled ***
 *** to handle 16-Bit read/write operations for ***
 *** these routines to be of benefit ***/
#define T1RD16ON  T1CON|=0x80
#define T3RD16ON  T3CON|=0x80
#define WRITETIMER0(x) TMR0H=(x>>8);TMR0L=(x&0xFF)
#define WRITETIMER1(x) TMR1H=(x>>8);TMR1L=(x&0xFF)
#define WRITETIMER3(x) TMR3H=(x>>8);TMR3L=(x&0xFF)
#define READTIMER0 (TMR0)
#define READTIMER1 (TMR1)
#define READTIMER3 (TMR3)

/* General purpose 8-bit summative checksum routines
 * parameter 1: start address
 * parameter 2: length of address to calculate (end - start) */
extern unsigned char checksum8(unsigned long startAddr, unsigned long length);
extern unsigned int checksumi16(unsigned long startAddr, unsigned long length);
extern unsigned long checksum32(unsigned long startAddr, unsigned long length);

/* Macro expansions to the above routines.
 * In the macro version the second parameter is the end address - not length */
#define CHECKSUM8(START, END)	checksum8((START),((END)-(START)))
#define CHECKSUM16(START, END)	checksum16((START),((END)-(START)))
#define CHECKSUM32(START, END)	checksum32((START),((END)-(START)))

/* Global Interrupt Enable */
#ifndef	ei
#define	ei()	(GIE = 1) 	// Interrupts of Hi/Lo Priority or Peripheral interrupts 
#endif

/* Global Interrupt Disable */
#ifndef	di
#define	di()	(GIE = 0)	// Interrupts of Hi/Lo Priority or Peripheral interrupts 
#endif


#endif	/* _PIC18_H */
