

 /* header file for the MICROCHIP PIC18 microcontrollers
	PIC18F6527
	PIC18F6622
	PIC18F8527
	PIC18F8622
	PIC18F6627
	PIC18F6722
	PIC18F8627
	PIC18F8722
 */

#ifndef	__PIC18FXX22_H

#define	__PIC18FXX22_H

static volatile near unsigned char	TOSU		@ 0xFFF;
static volatile near unsigned char	TOSH		@ 0xFFE;
static volatile near unsigned char	TOSL		@ 0xFFD;
static volatile near unsigned char	STKPTR		@ 0xFFC;
static volatile near unsigned char	PCLATU		@ 0xFFB;
static volatile near unsigned char	PCLATH		@ 0xFFA;
static volatile near unsigned char	PCL		@ 0xFF9;
static volatile far  unsigned char *	TBLPTR		@ 0xFF6;
static volatile near unsigned char	TBLPTRU		@ 0xFF8;
static volatile near unsigned char	TBLPTRH		@ 0xFF7;
static volatile near unsigned char	TBLPTRL		@ 0xFF6;
static volatile near unsigned char	TABLAT		@ 0xFF5;
static volatile near unsigned char	PRODH		@ 0xFF4;
static volatile near unsigned char	PRODL		@ 0xFF3;
static volatile near unsigned char	INTCON		@ 0xFF2;
static          near unsigned char	INTCON2		@ 0xFF1;
static volatile near unsigned char	INTCON3		@ 0xFF0;
static volatile near unsigned char	INDF0		@ 0xFEF;
static volatile near unsigned char	POSTINC0	@ 0xFEE;
static volatile near unsigned char	POSTDEC0	@ 0xFED;
static volatile near unsigned char	PREINC0		@ 0xFEC;
static volatile near unsigned char	PLUSW0		@ 0xFEB;
static volatile near unsigned char	FSR0H		@ 0xFEA;
static volatile near unsigned char	FSR0L		@ 0xFE9;
static volatile near unsigned char	WREG		@ 0xFE8;
static volatile near unsigned char	INDF1		@ 0xFE7;
static volatile near unsigned char	POSTINC1	@ 0xFE6;
static volatile near unsigned char	POSTDEC1	@ 0xFE5;
static volatile near unsigned char	PREINC1		@ 0xFE4;
static volatile near unsigned char	PLUSW1		@ 0xFE3;
static volatile near unsigned char	FSR1H		@ 0xFE2;
static volatile near unsigned char	FSR1L		@ 0xFE1;
static          near unsigned char	BSR		@ 0xFE0;
static volatile near unsigned char	INDF2		@ 0xFDF;
static volatile near unsigned char	POSTINC2	@ 0xFDE;
static volatile near unsigned char	POSTDEC2	@ 0xFDD;
static volatile near unsigned char	PREINC2		@ 0xFDC;
static volatile near unsigned char	PLUSW2		@ 0xFDB;
static volatile near unsigned char	FSR2H		@ 0xFDA;
static volatile near unsigned char	FSR2L		@ 0xFD9;
static volatile near unsigned char	STATUS		@ 0xFD8;
static volatile near unsigned char	TMR0H		@ 0xFD7;
static volatile near unsigned char	TMR0L		@ 0xFD6;
// 16-Bit definition
static volatile near unsigned int	TMR0		@ 0xFD6;
static          near unsigned char	T0CON		@ 0xFD5;
static volatile near unsigned char	OSCCON		@ 0xFD3;
static volatile near unsigned char	HLVDCON		@ 0xFD2;
static volatile near unsigned char	WDTCON		@ 0xFD1;
static volatile near unsigned char	RCON		@ 0xFD0;
static volatile near unsigned char	TMR1H		@ 0xFCF;
static volatile near unsigned char	TMR1L		@ 0xFCE;
// 16-Bit definition
static volatile near unsigned int	TMR1		@ 0xFCE;
static          near unsigned char	T1CON		@ 0xFCD;
static volatile near unsigned char	TMR2		@ 0xFCC;
static          near unsigned char	PR2		@ 0xFCB;
static          near unsigned char	T2CON		@ 0xFCA;
static volatile near unsigned char	SSP1BUF		@ 0xFC9;
static          near unsigned char	SSP1ADD		@ 0xFC8;
static volatile near unsigned char	SSP1STAT	@ 0xFC7;
static volatile near unsigned char	SSP1CON1	@ 0xFC6;
static volatile near unsigned char	SSP1CON2	@ 0xFC5;
static volatile near unsigned char	ADRESH		@ 0xFC4;
static volatile near unsigned char	ADRESL		@ 0xFC3;
// 16-Bit definition
static volatile near unsigned int	ADRES		@ 0xFC3;
static volatile near unsigned char	ADCON0		@ 0xFC2;
static          near unsigned char	ADCON1		@ 0xFC1;
static          near unsigned char	ADCON2		@ 0xFC0;
static volatile near unsigned char	CCPR1H		@ 0xFBF;
static volatile near unsigned char	CCPR1L		@ 0xFBE;
// 16-Bit definition
static volatile near unsigned int	CCPR1		@ 0xFBE;
static volatile near unsigned char	CCP1CON		@ 0xFBD;
static volatile near unsigned char	CCPR2H		@ 0xFBC;
static volatile near unsigned char	CCPR2L		@ 0xFBB;
// 16-Bit definition
static volatile near unsigned int	CCPR2		@ 0xFBB;
static volatile near unsigned char	CCP2CON		@ 0xFBA;
static volatile near unsigned char	CCPR3H		@ 0xFB9;
static volatile near unsigned char	CCPR3L		@ 0xFB8;
// 16-Bit definition
static volatile near unsigned int	CCPR3		@ 0xFB8;
static volatile near unsigned char	CCP3CON		@ 0xFB7;
#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
static volatile near unsigned char	ECCP1AS		@ 0xFB6;
#endif
static volatile near unsigned char	CVRCON		@ 0xFB5;
static volatile near unsigned char	CMCON		@ 0xFB4;
static volatile near unsigned char	TMR3H		@ 0xFB3;
static volatile near unsigned char	TMR3L		@ 0xFB2;
// 16-Bit definition
static volatile near unsigned int	TMR3		@ 0xFB2;
static          near unsigned char	T3CON		@ 0xFB1;
static volatile near unsigned char	PSPCON		@ 0xFB0;
static          near unsigned char	SPBRG1		@ 0xFAF;
static volatile near unsigned char	RCREG1		@ 0xFAE;
static volatile near unsigned char	TXREG1		@ 0xFAD;
static volatile near unsigned char	TXSTA1		@ 0xFAC;
static volatile near unsigned char	RCSTA1		@ 0xFAB;
static          near unsigned char	EEADRH		@ 0xFAA;
static          near unsigned char	EEADR		@ 0xFA9;
static volatile near unsigned char	EEDATA		@ 0xFA8;
static volatile near unsigned char	EECON2		@ 0xFA7;
static volatile near unsigned char	EECON1		@ 0xFA6;
static          near unsigned char	IPR3		@ 0xFA5;
static volatile near unsigned char	PIR3		@ 0xFA4;
static          near unsigned char	PIE3		@ 0xFA3;
static          near unsigned char	IPR2		@ 0xFA2;
static volatile near unsigned char	PIR2		@ 0xFA1;
static          near unsigned char	PIE2		@ 0xFA0;
static          near unsigned char	IPR1		@ 0xF9F;
static volatile near unsigned char	PIR1		@ 0xF9E;
static          near unsigned char	PIE1		@ 0xF9D;
#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
static          near unsigned char	MEMCON		@ 0xF9C;
#endif
static          near unsigned char	OSCTUNE		@ 0xF9B;
#if defined(_18F8627) || defined(_18F8722)
static volatile near unsigned char	TRISJ		@ 0xF9A;
static volatile near unsigned char	TRISH		@ 0xF99;
#endif
static volatile near unsigned char	TRISG		@ 0xF98;
static volatile near unsigned char	TRISF		@ 0xF97;
static volatile near unsigned char	TRISE		@ 0xF96;
static volatile near unsigned char	TRISD		@ 0xF95;
static volatile near unsigned char	TRISC		@ 0xF94;
static volatile near unsigned char	TRISB		@ 0xF93;
static volatile near unsigned char	TRISA		@ 0xF92;
#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
static volatile near unsigned char	LATJ		@ 0xF91;
static volatile near unsigned char	LATH		@ 0xF90;
#endif
static volatile near unsigned char	LATG		@ 0xF8F;
static volatile near unsigned char	LATF		@ 0xF8E;
static volatile near unsigned char	LATE		@ 0xF8D;
static volatile near unsigned char	LATD		@ 0xF8C;
static volatile near unsigned char	LATC		@ 0xF8B;
static volatile near unsigned char	LATB		@ 0xF8A;
static volatile near unsigned char	LATA		@ 0xF89;
#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
static volatile near unsigned char	PORTJ		@ 0xF88;
static volatile near unsigned char	PORTH		@ 0xF87;
#endif
static volatile near unsigned char	PORTG		@ 0xF86;
static volatile near unsigned char	PORTF		@ 0xF85;
static volatile near unsigned char	PORTE		@ 0xF84;
static volatile near unsigned char	PORTD		@ 0xF83;
static volatile near unsigned char	PORTC		@ 0xF82;
static volatile near unsigned char	PORTB		@ 0xF81;
static volatile near unsigned char	PORTA		@ 0xF80;
static          near unsigned char	SPBRGH1		@ 0xF7F;
static volatile near unsigned char	BAUDCON1	@ 0xF7E;
static          near unsigned char	SPBRGH2		@ 0xF7D;
static volatile near unsigned char	BAUDCON2	@ 0xF7C;
static          near unsigned char	ECCP1DEL	@ 0xF79;
static volatile near unsigned char	TMR4		@ 0xF78;
static          near unsigned char	PR4		@ 0xF77;
static          near unsigned char	T4CON		@ 0xF76;
static volatile near unsigned char	CCPR4H		@ 0xF75;
static volatile near unsigned char	CCPR4L		@ 0xF74;
// 16-Bit definition
static volatile near unsigned int	CCPR4		@ 0xF74;
static volatile near unsigned char	CCP4CON		@ 0xF73;
static volatile near unsigned char	CCPR5H		@ 0xF72;
static volatile near unsigned char	CCPR5L		@ 0xF71;
// 16-Bit definition
static volatile near unsigned int	CCPR5		@ 0xF71;
static volatile near unsigned char	CCP5CON		@ 0xF70;
static          near unsigned char	SPBRG2		@ 0xF6F;
static volatile near unsigned char	RCREG2		@ 0xF6E;
static volatile near unsigned char	TXREG2		@ 0xF6D;
static volatile near unsigned char	TXSTA2		@ 0xF6C;
static volatile near unsigned char	RCSTA2		@ 0xF6B;
static volatile near unsigned char	ECCP3AS		@ 0xF6A;
static          near unsigned char	ECCP3DEL	@ 0xF69;
static volatile near unsigned char	ECCP2AS		@ 0xF68;
static          near unsigned char	ECCP2DEL	@ 0xF67;
static volatile near unsigned char	SSP2BUF		@ 0xF66;
static          near unsigned char	SSP2ADD		@ 0xF65;
static volatile near unsigned char	SSP2STAT	@ 0xF64;
static volatile near unsigned char	SSP2CON1	@ 0xF63;
static volatile near unsigned char	SSP2CON2	@ 0xF62;


/* Definitions for STKPTR register */
static volatile near bit	STKUNF		@ ((unsigned)&STKPTR*8)+6;
static volatile near bit	STKFUL		@ ((unsigned)&STKPTR*8)+7;

/* Definitions for INTCON register */
static volatile near bit	RBIF		@ ((unsigned)&INTCON*8)+0;
static volatile near bit	INT0IF		@ ((unsigned)&INTCON*8)+1;
static volatile near bit	TMR0IF		@ ((unsigned)&INTCON*8)+2;
static          near bit	RBIE		@ ((unsigned)&INTCON*8)+3;
static          near bit	INT0IE		@ ((unsigned)&INTCON*8)+4;
static          near bit	TMR0IE		@ ((unsigned)&INTCON*8)+5;
static          near bit	PEIE		@ ((unsigned)&INTCON*8)+6;
static          near bit	GIE		@ ((unsigned)&INTCON*8)+7;
/* Alternate definitions for INTCON register */
static          near bit	GIEL		@ ((unsigned)&INTCON*8)+6;
static          near bit	GIEH		@ ((unsigned)&INTCON*8)+7;

/* Definitions for INTCON2 register */
static          near bit	RBIP		@ ((unsigned)&INTCON2*8)+0;
static          near bit	INT3IP		@ ((unsigned)&INTCON2*8)+1;
static          near bit	TMR0IP		@ ((unsigned)&INTCON2*8)+2;
static          near bit	INTEDG3		@ ((unsigned)&INTCON2*8)+3;
static          near bit	INTEDG2		@ ((unsigned)&INTCON2*8)+4;
static          near bit	INTEDG1		@ ((unsigned)&INTCON2*8)+5;
static          near bit	INTEDG0		@ ((unsigned)&INTCON2*8)+6;
static          near bit	RBPU		@ ((unsigned)&INTCON2*8)+7;

/* Definitions for INTCON3 register */
static volatile near bit	INT1IF		@ ((unsigned)&INTCON3*8)+0;
static volatile near bit	INT2IF		@ ((unsigned)&INTCON3*8)+1;
static volatile near bit	INT3IF		@ ((unsigned)&INTCON3*8)+2;
static          near bit	INT1IE		@ ((unsigned)&INTCON3*8)+3;
static          near bit	INT2IE		@ ((unsigned)&INTCON3*8)+4;
static          near bit	INT3IE		@ ((unsigned)&INTCON3*8)+5;
static          near bit	INT1IP		@ ((unsigned)&INTCON3*8)+6;
static          near bit	INT2IP		@ ((unsigned)&INTCON3*8)+7;

/* Definitions for STATUS register */
static volatile near bit	CARRY		@ ((unsigned)&STATUS*8)+0;
static volatile near bit	DC		@ ((unsigned)&STATUS*8)+1;
static volatile near bit	ZERO		@ ((unsigned)&STATUS*8)+2;
static volatile near bit	OV		@ ((unsigned)&STATUS*8)+3;
static volatile near bit	NEGATIVE	@ ((unsigned)&STATUS*8)+4;

/* Definitions for T0CON register */
static          near bit	T0PS0		@ ((unsigned)&T0CON*8)+0;
static          near bit	T0PS1		@ ((unsigned)&T0CON*8)+1;
static          near bit	T0PS2		@ ((unsigned)&T0CON*8)+2;
static          near bit	PSA		@ ((unsigned)&T0CON*8)+3;
static          near bit	T0SE		@ ((unsigned)&T0CON*8)+4;
static          near bit	T0CS		@ ((unsigned)&T0CON*8)+5;
static          near bit	T08BIT		@ ((unsigned)&T0CON*8)+6;
static          near bit	TMR0ON		@ ((unsigned)&T0CON*8)+7;

/* Definitions for OSCCON register */
static          near bit	SCS0		@ ((unsigned)&OSCCON*8)+0;
static          near bit	SCS1		@ ((unsigned)&OSCCON*8)+1;
static volatile near bit	IOFS		@ ((unsigned)&OSCCON*8)+2;
static volatile near bit	OSTS		@ ((unsigned)&OSCCON*8)+3;
static          near bit	IRCF0		@ ((unsigned)&OSCCON*8)+4;
static          near bit	IRCF1		@ ((unsigned)&OSCCON*8)+5;
static          near bit	IRCF2		@ ((unsigned)&OSCCON*8)+6;
static          near bit	IDLEN		@ ((unsigned)&OSCCON*8)+7;

/* Definitions for HLVDCON register */
static          near bit	HLVDL0		@ ((unsigned)&HLVDCON*8)+0;
static          near bit	HLVDL1		@ ((unsigned)&HLVDCON*8)+1;
static          near bit	HLVDL2		@ ((unsigned)&HLVDCON*8)+2;
static          near bit	HLVDL3		@ ((unsigned)&HLVDCON*8)+3;
static          near bit	HLVDEN		@ ((unsigned)&HLVDCON*8)+4;
static volatile near bit	IRVST		@ ((unsigned)&HLVDCON*8)+5;
static          near bit	VDIRMAG		@ ((unsigned)&HLVDCON*8)+7;

/* Definitions for WDTCON register */
static          near bit	SWDTEN		@ ((unsigned)&WDTCON*8)+0;

/* Definitions for RCON register */
static volatile near bit	BOR		@ ((unsigned)&RCON*8)+0;
static volatile near bit	POR		@ ((unsigned)&RCON*8)+1;
static volatile near bit	PD		@ ((unsigned)&RCON*8)+2;
static volatile near bit	TO		@ ((unsigned)&RCON*8)+3;
static volatile near bit	RI		@ ((unsigned)&RCON*8)+4;
static          near bit	SBOREN		@ ((unsigned)&RCON*8)+6;
static          near bit	IPEN		@ ((unsigned)&RCON*8)+7;

/* Definitions for T1CON register */
static          near bit	TMR1ON		@ ((unsigned)&T1CON*8)+0;
static          near bit	TMR1CS		@ ((unsigned)&T1CON*8)+1;
static          near bit	T1SYNC		@ ((unsigned)&T1CON*8)+2;
static          near bit	T1OSCEN		@ ((unsigned)&T1CON*8)+3;
static          near bit	T1CKPS0		@ ((unsigned)&T1CON*8)+4;
static          near bit	T1CKPS1		@ ((unsigned)&T1CON*8)+5;
static          near bit	T1RUN		@ ((unsigned)&T1CON*8)+6;
static          near bit	T1RD16		@ ((unsigned)&T1CON*8)+7;

/* Definitions for T2CON register */
static          near bit	T2CKPS0		@ ((unsigned)&T2CON*8)+0;
static          near bit	T2CKPS1		@ ((unsigned)&T2CON*8)+1;
static          near bit	TMR2ON		@ ((unsigned)&T2CON*8)+2;
static          near bit	T2OUTPS0	@ ((unsigned)&T2CON*8)+3;
static          near bit	T2OUTPS1	@ ((unsigned)&T2CON*8)+4;
static          near bit	T2OUTPS2	@ ((unsigned)&T2CON*8)+5;
static          near bit	T2OUTPS3	@ ((unsigned)&T2CON*8)+6;

/* Definitions for SSP1STAT register */
static volatile near bit	BF		@ ((unsigned)&SSP1STAT*8)+0;
static volatile near bit	UA		@ ((unsigned)&SSP1STAT*8)+1;
static volatile near bit	RW		@ ((unsigned)&SSP1STAT*8)+2;
static volatile near bit	START		@ ((unsigned)&SSP1STAT*8)+3;
static volatile near bit	STOP		@ ((unsigned)&SSP1STAT*8)+4;
static volatile near bit	DA		@ ((unsigned)&SSP1STAT*8)+5;
static          near bit	CKE		@ ((unsigned)&SSP1STAT*8)+6;
static          near bit	SMP		@ ((unsigned)&SSP1STAT*8)+7;
/* Alternate definitions for SSP1STAT register */
static volatile near bit	BF1		@ ((unsigned)&SSP1STAT*8)+0;
static volatile near bit	UA1		@ ((unsigned)&SSP1STAT*8)+1;
static volatile near bit	RW1		@ ((unsigned)&SSP1STAT*8)+2;
static volatile near bit	START1		@ ((unsigned)&SSP1STAT*8)+3;
static volatile near bit	STOP1		@ ((unsigned)&SSP1STAT*8)+4;
static volatile near bit	DA1		@ ((unsigned)&SSP1STAT*8)+5;
static          near bit	CKE1		@ ((unsigned)&SSP1STAT*8)+6;
static          near bit	SMP1		@ ((unsigned)&SSP1STAT*8)+7;

/* Definitions for SSP1CON1 register */
static          near bit	SSPM0		@ ((unsigned)&SSP1CON1*8)+0;
static          near bit	SSPM1		@ ((unsigned)&SSP1CON1*8)+1;
static          near bit	SSPM2		@ ((unsigned)&SSP1CON1*8)+2;
static          near bit	SSPM3		@ ((unsigned)&SSP1CON1*8)+3;
static          near bit	CKP		@ ((unsigned)&SSP1CON1*8)+4;
static          near bit	SSPEN		@ ((unsigned)&SSP1CON1*8)+5;
static volatile near bit	SSPOV		@ ((unsigned)&SSP1CON1*8)+6;
static volatile near bit	WCOL		@ ((unsigned)&SSP1CON1*8)+7;
/* Alternate definitions for SSP1CON1 register */
static          near bit	SSPM01		@ ((unsigned)&SSP1CON1*8)+0;
static          near bit	SSPM11		@ ((unsigned)&SSP1CON1*8)+1;
static          near bit	SSPM21		@ ((unsigned)&SSP1CON1*8)+2;
static          near bit	SSPM31		@ ((unsigned)&SSP1CON1*8)+3;
static          near bit	CKP1		@ ((unsigned)&SSP1CON1*8)+4;
static          near bit	SSPEN1		@ ((unsigned)&SSP1CON1*8)+5;
static volatile near bit	SSPOV1		@ ((unsigned)&SSP1CON1*8)+6;
static volatile near bit	WCOL1		@ ((unsigned)&SSP1CON1*8)+7;

/* Definitions for SSP1CON2 register */
static          near bit	SEN		@ ((unsigned)&SSP1CON2*8)+0;
static volatile near bit	RSEN		@ ((unsigned)&SSP1CON2*8)+1;
static volatile near bit	PEN		@ ((unsigned)&SSP1CON2*8)+2;
static volatile near bit	RCEN		@ ((unsigned)&SSP1CON2*8)+3;
static volatile near bit	ACKEN		@ ((unsigned)&SSP1CON2*8)+4;
static volatile near bit	ACKDT		@ ((unsigned)&SSP1CON2*8)+5;
static volatile near bit	ACKSTAT		@ ((unsigned)&SSP1CON2*8)+6;
static          near bit	GCEN		@ ((unsigned)&SSP1CON2*8)+7;
/* Alternate definitions for SSP1CON2 register */
static          near bit	SEN1		@ ((unsigned)&SSP1CON2*8)+0;
static volatile near bit	RSEN1		@ ((unsigned)&SSP1CON2*8)+1;
static volatile near bit	PEN1		@ ((unsigned)&SSP1CON2*8)+2;
static volatile near bit	RCEN1		@ ((unsigned)&SSP1CON2*8)+3;
static volatile near bit	ACKEN1		@ ((unsigned)&SSP1CON2*8)+4;
static volatile near bit	ACKDT1		@ ((unsigned)&SSP1CON2*8)+5;
static volatile near bit	ACKSTAT1	@ ((unsigned)&SSP1CON2*8)+6;
static          near bit	GCEN1		@ ((unsigned)&SSP1CON2*8)+7;

/* Definitions for ADCON0 register */
static          near bit	ADON		@ ((unsigned)&ADCON0*8)+0;
static volatile near bit	GODONE		@ ((unsigned)&ADCON0*8)+1;
static          near bit	CHS0		@ ((unsigned)&ADCON0*8)+2;
static          near bit	CHS1		@ ((unsigned)&ADCON0*8)+3;
static          near bit	CHS2		@ ((unsigned)&ADCON0*8)+4;
static          near bit	CHS3		@ ((unsigned)&ADCON0*8)+5;

/* Definitions for ADCON1 register */
static          near bit	PCFG0		@ ((unsigned)&ADCON1*8)+0;
static          near bit	PCFG1		@ ((unsigned)&ADCON1*8)+1;
static          near bit	PCFG2		@ ((unsigned)&ADCON1*8)+2;
static          near bit	PCFG3		@ ((unsigned)&ADCON1*8)+3;
static          near bit	VCFG0		@ ((unsigned)&ADCON1*8)+4;
static          near bit	VCFG1		@ ((unsigned)&ADCON1*8)+5;

/* Definitions for ADCON2 register */
static          near bit	ADCS0		@ ((unsigned)&ADCON2*8)+0;
static          near bit	ADCS1		@ ((unsigned)&ADCON2*8)+1;
static          near bit	ADCS2		@ ((unsigned)&ADCON2*8)+2;
static          near bit	ACQT0		@ ((unsigned)&ADCON2*8)+3;
static          near bit	ACQT1		@ ((unsigned)&ADCON2*8)+4;
static          near bit	ACQT2		@ ((unsigned)&ADCON2*8)+5;
static          near bit	ADFM		@ ((unsigned)&ADCON2*8)+7;

/* Definitions for CCP1CON register */
static          near bit	CCP1M0		@ ((unsigned)&CCP1CON*8)+0;
static          near bit	CCP1M1		@ ((unsigned)&CCP1CON*8)+1;
static          near bit	CCP1M2		@ ((unsigned)&CCP1CON*8)+2;
static          near bit	CCP1M3		@ ((unsigned)&CCP1CON*8)+3;
static          near bit	DC1B0		@ ((unsigned)&CCP1CON*8)+4;
static          near bit	DC1B1		@ ((unsigned)&CCP1CON*8)+5;
static          near bit	P1M0		@ ((unsigned)&CCP1CON*8)+6;
static          near bit	P1M1		@ ((unsigned)&CCP1CON*8)+7;

/* Definitions for CCP2CON register */
static          near bit	CCP2M0		@ ((unsigned)&CCP2CON*8)+0;
static          near bit	CCP2M1		@ ((unsigned)&CCP2CON*8)+1;
static          near bit	CCP2M2		@ ((unsigned)&CCP2CON*8)+2;
static          near bit	CCP2M3		@ ((unsigned)&CCP2CON*8)+3;
static          near bit	DC2B0		@ ((unsigned)&CCP2CON*8)+4;
static          near bit	DC2B1		@ ((unsigned)&CCP2CON*8)+5;
static          near bit	P2M0		@ ((unsigned)&CCP2CON*8)+6;
static          near bit	P2M1		@ ((unsigned)&CCP2CON*8)+7;

/* Definitions for CCP3CON register */
static          near bit	CCP3M0		@ ((unsigned)&CCP3CON*8)+0;
static          near bit	CCP3M1		@ ((unsigned)&CCP3CON*8)+1;
static          near bit	CCP3M2		@ ((unsigned)&CCP3CON*8)+2;
static          near bit	CCP3M3		@ ((unsigned)&CCP3CON*8)+3;
static          near bit	DC3B0		@ ((unsigned)&CCP3CON*8)+4;
static          near bit	DC3B1		@ ((unsigned)&CCP3CON*8)+5;
static          near bit	P3M0		@ ((unsigned)&CCP3CON*8)+6;
static          near bit	P3M1		@ ((unsigned)&CCP3CON*8)+7;

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
/* Definitions for ECCP1AS register */
static          near bit	PSS1BD0		@ ((unsigned)&ECCP1AS*8)+0;
static          near bit	PSS1BD1		@ ((unsigned)&ECCP1AS*8)+1;
static          near bit	PSS1AC0		@ ((unsigned)&ECCP1AS*8)+2;
static          near bit	PSS1AC1		@ ((unsigned)&ECCP1AS*8)+3;
static          near bit	ECCP1AS0	@ ((unsigned)&ECCP1AS*8)+4;
static          near bit	ECCP1AS1	@ ((unsigned)&ECCP1AS*8)+5;
static          near bit	ECCP1AS2	@ ((unsigned)&ECCP1AS*8)+6;
static volatile near bit	ECCP1ASE	@ ((unsigned)&ECCP1AS*8)+7;
#endif

/* Definitions for CVRCON register */
static          near bit	CVR0		@ ((unsigned)&CVRCON*8)+0;
static          near bit	CVR1		@ ((unsigned)&CVRCON*8)+1;
static          near bit	CVR2		@ ((unsigned)&CVRCON*8)+2;
static          near bit	CVR3		@ ((unsigned)&CVRCON*8)+3;
static          near bit	CVRSS		@ ((unsigned)&CVRCON*8)+4;
static          near bit	CVRR		@ ((unsigned)&CVRCON*8)+5;
static          near bit	CVROE		@ ((unsigned)&CVRCON*8)+6;
static          near bit	CVREN		@ ((unsigned)&CVRCON*8)+7;

/* Definitions for CMCON register */
static          near bit	CM0		@ ((unsigned)&CMCON*8)+0;
static          near bit	CM1		@ ((unsigned)&CMCON*8)+1;
static          near bit	CM2		@ ((unsigned)&CMCON*8)+2;
static          near bit	CIS		@ ((unsigned)&CMCON*8)+3;
static          near bit	C1INV		@ ((unsigned)&CMCON*8)+4;
static          near bit	C2INV		@ ((unsigned)&CMCON*8)+5;
static volatile near bit	C1OUT		@ ((unsigned)&CMCON*8)+6;
static volatile near bit	C2OUT		@ ((unsigned)&CMCON*8)+7;

/* Definitions for T3CON register */
static          near bit	TMR3ON		@ ((unsigned)&T3CON*8)+0;
static          near bit	TMR3CS		@ ((unsigned)&T3CON*8)+1;
static          near bit	T3SYNC		@ ((unsigned)&T3CON*8)+2;
static          near bit	T3CCP1		@ ((unsigned)&T3CON*8)+3;
static          near bit	T3CKPS0		@ ((unsigned)&T3CON*8)+4;
static          near bit	T3CKPS1		@ ((unsigned)&T3CON*8)+5;
static          near bit	T3CCP2		@ ((unsigned)&T3CON*8)+6;
static          near bit	T3RD16		@ ((unsigned)&T3CON*8)+7;

/* Definitions for PSPCON register */
static          near bit	PSPMODE		@ ((unsigned)&PSPCON*8)+4;
static volatile near bit	IBOV		@ ((unsigned)&PSPCON*8)+5;
static volatile near bit	OBF		@ ((unsigned)&PSPCON*8)+6;
static volatile near bit	IBF		@ ((unsigned)&PSPCON*8)+7;

/* Definitions for TXSTA1 register */
static volatile near bit	TX9D		@ ((unsigned)&TXSTA1*8)+0;
static volatile near bit	TRMT		@ ((unsigned)&TXSTA1*8)+1;
static          near bit	BRGH		@ ((unsigned)&TXSTA1*8)+2;
static          near bit	SENDB		@ ((unsigned)&TXSTA1*8)+3;
static          near bit	SYNC		@ ((unsigned)&TXSTA1*8)+4;
static          near bit	TXEN		@ ((unsigned)&TXSTA1*8)+5;
static          near bit	TX9		@ ((unsigned)&TXSTA1*8)+6;
static          near bit	CSRC		@ ((unsigned)&TXSTA1*8)+7;

/* Definitions for RCSTA1 register */
static volatile near bit	RX9D		@ ((unsigned)&RCSTA1*8)+0;
static volatile near bit	OERR		@ ((unsigned)&RCSTA1*8)+1;
static volatile near bit	FERR		@ ((unsigned)&RCSTA1*8)+2;
static          near bit	ADDEN		@ ((unsigned)&RCSTA1*8)+3;
static          near bit	CREN		@ ((unsigned)&RCSTA1*8)+4;
static          near bit	SREN		@ ((unsigned)&RCSTA1*8)+5;
static          near bit	RX9		@ ((unsigned)&RCSTA1*8)+6;
static          near bit	SPEN		@ ((unsigned)&RCSTA1*8)+7;

/* Definitions for EECON1 register */
static volatile near bit	RD		@ ((unsigned)&EECON1*8)+0;
static volatile near bit	WR		@ ((unsigned)&EECON1*8)+1;
static          near bit	WREN		@ ((unsigned)&EECON1*8)+2;
static volatile near bit	WRERR		@ ((unsigned)&EECON1*8)+3;
static volatile near bit	FREE		@ ((unsigned)&EECON1*8)+4;
static          near bit	CFGS		@ ((unsigned)&EECON1*8)+6;
static          near bit	EEPGD		@ ((unsigned)&EECON1*8)+7;

/* Definitions for IPR3 register */
static          near bit	CCP3IP		@ ((unsigned)&IPR3*8)+0;
static          near bit	CCP4IP		@ ((unsigned)&IPR3*8)+1;
static          near bit	CCP5IP		@ ((unsigned)&IPR3*8)+2;
static          near bit	TMR4IP		@ ((unsigned)&IPR3*8)+3;
static          near bit	TX2IP		@ ((unsigned)&IPR3*8)+4;
static          near bit	RC2IP		@ ((unsigned)&IPR3*8)+5;
static          near bit	BCL2IP		@ ((unsigned)&IPR3*8)+6;
static          near bit	SSP2IP		@ ((unsigned)&IPR3*8)+7;

/* Definitions for PIR3 register */
static volatile near bit	CCP3IF		@ ((unsigned)&PIR3*8)+0;
static volatile near bit	CCP4IF		@ ((unsigned)&PIR3*8)+1;
static volatile near bit	CCP5IF		@ ((unsigned)&PIR3*8)+2;
static volatile near bit	TMR4IF		@ ((unsigned)&PIR3*8)+3;
static volatile near bit	TX2IF		@ ((unsigned)&PIR3*8)+4;
static volatile near bit	RC2IF		@ ((unsigned)&PIR3*8)+5;
static volatile near bit	BCL2IF		@ ((unsigned)&PIR3*8)+6;
static volatile near bit	SSP2IF		@ ((unsigned)&PIR3*8)+7;

/* Definitions for PIE3 register */
static          near bit	CCP3IE		@ ((unsigned)&PIE3*8)+0;
static          near bit	CCP4IE		@ ((unsigned)&PIE3*8)+1;
static          near bit	CCP5IE		@ ((unsigned)&PIE3*8)+2;
static          near bit	TMR4IE		@ ((unsigned)&PIE3*8)+3;
static          near bit	TX2IE		@ ((unsigned)&PIE3*8)+4;
static          near bit	RC2IE		@ ((unsigned)&PIE3*8)+5;
static          near bit	BCL2IE		@ ((unsigned)&PIE3*8)+6;
static          near bit	SSP2IE		@ ((unsigned)&PIE3*8)+7;

/* Definitions for IPR2 register */
static          near bit	CCP2IP		@ ((unsigned)&IPR2*8)+0;
static          near bit	TMR3IP		@ ((unsigned)&IPR2*8)+1;
static          near bit	HLVDIP		@ ((unsigned)&IPR2*8)+2;
static          near bit	BCL1IP		@ ((unsigned)&IPR2*8)+3;
static          near bit	EEIP		@ ((unsigned)&IPR2*8)+4;
static          near bit	CMIP		@ ((unsigned)&IPR2*8)+6;
static          near bit	OSCFIP		@ ((unsigned)&IPR2*8)+7;

/* Definitions for PIR2 register */
static volatile near bit	CCP2IF		@ ((unsigned)&PIR2*8)+0;
static volatile near bit	TMR3IF		@ ((unsigned)&PIR2*8)+1;
static volatile near bit	HLVDIF		@ ((unsigned)&PIR2*8)+2;
static volatile near bit	BCL1IF		@ ((unsigned)&PIR2*8)+3;
static volatile near bit	EEIF		@ ((unsigned)&PIR2*8)+4;
static volatile near bit	CMIF		@ ((unsigned)&PIR2*8)+6;
static volatile near bit	OSCFIF		@ ((unsigned)&PIR2*8)+7;

/* Definitions for PIE2 register */
static          near bit	CCP2IE		@ ((unsigned)&PIE2*8)+0;
static          near bit	TMR3IE		@ ((unsigned)&PIE2*8)+1;
static          near bit	HLVDIE		@ ((unsigned)&PIE2*8)+2;
static          near bit	BCL1IE		@ ((unsigned)&PIE2*8)+3;
static          near bit	EEIE		@ ((unsigned)&PIE2*8)+4;
static          near bit	CMIE		@ ((unsigned)&PIE2*8)+6;
static          near bit	OSCFIE		@ ((unsigned)&PIE2*8)+7;

/* Definitions for IPR1 register */
static          near bit	TMR1IP		@ ((unsigned)&IPR1*8)+0;
static          near bit	TMR2IP		@ ((unsigned)&IPR1*8)+1;
static          near bit	CCP1IP		@ ((unsigned)&IPR1*8)+2;
static          near bit	SSP1IP		@ ((unsigned)&IPR1*8)+3;
static          near bit	TX1IP		@ ((unsigned)&IPR1*8)+4;
static          near bit	RC1IP		@ ((unsigned)&IPR1*8)+5;
static          near bit	ADIP		@ ((unsigned)&IPR1*8)+6;
static          near bit	PSPIP		@ ((unsigned)&IPR1*8)+7;

/* Definitions for PIR1 register */
static volatile near bit	TMR1IF		@ ((unsigned)&PIR1*8)+0;
static volatile near bit	TMR2IF		@ ((unsigned)&PIR1*8)+1;
static volatile near bit	CCP1IF		@ ((unsigned)&PIR1*8)+2;
static volatile near bit	SSP1IF		@ ((unsigned)&PIR1*8)+3;
static volatile near bit	TX1IF		@ ((unsigned)&PIR1*8)+4;
static volatile near bit	RC1IF		@ ((unsigned)&PIR1*8)+5;
static volatile near bit	ADIF		@ ((unsigned)&PIR1*8)+6;
static volatile near bit	PSPIF		@ ((unsigned)&PIR1*8)+7;

/* Definitions for PIE1 register */
static          near bit	TMR1IE		@ ((unsigned)&PIE1*8)+0;
static          near bit	TMR2IE		@ ((unsigned)&PIE1*8)+1;
static          near bit	CCP1IE		@ ((unsigned)&PIE1*8)+2;
static          near bit	SSP1IE		@ ((unsigned)&PIE1*8)+3;
static          near bit	TX1IE		@ ((unsigned)&PIE1*8)+4;
static          near bit	RC1IE		@ ((unsigned)&PIE1*8)+5;
static          near bit	ADIE		@ ((unsigned)&PIE1*8)+6;
static          near bit	PSPIE		@ ((unsigned)&PIE1*8)+7;

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
/* Definitions for MEMCON register */
static          near bit	WM0		@ ((unsigned)&MEMCON*8)+0;
static          near bit	WM1		@ ((unsigned)&MEMCON*8)+1;
static          near bit	WAIT0		@ ((unsigned)&MEMCON*8)+4;
static          near bit	WAIT1		@ ((unsigned)&MEMCON*8)+5;
static          near bit	EBDIS		@ ((unsigned)&MEMCON*8)+7;
#endif

/* Definitions for OSCTUNE register */
static          near bit	TUN0		@ ((unsigned)&OSCTUNE*8)+0;
static          near bit	TUN1		@ ((unsigned)&OSCTUNE*8)+1;
static          near bit	TUN2		@ ((unsigned)&OSCTUNE*8)+2;
static          near bit	TUN3		@ ((unsigned)&OSCTUNE*8)+3;
static          near bit	TUN4		@ ((unsigned)&OSCTUNE*8)+4;
static          near bit	PLLEN		@ ((unsigned)&OSCTUNE*8)+6;
static          near bit	INTSRC		@ ((unsigned)&OSCTUNE*8)+7;

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
/* Definitions for TRISJ register */
static volatile near bit	TRISJ0		@ ((unsigned)&TRISJ*8)+0;
static volatile near bit	TRISJ1		@ ((unsigned)&TRISJ*8)+1;
static volatile near bit	TRISJ2		@ ((unsigned)&TRISJ*8)+2;
static volatile near bit	TRISJ3		@ ((unsigned)&TRISJ*8)+3;
static volatile near bit	TRISJ4		@ ((unsigned)&TRISJ*8)+4;
static volatile near bit	TRISJ5		@ ((unsigned)&TRISJ*8)+5;
static volatile near bit	TRISJ6		@ ((unsigned)&TRISJ*8)+6;
static volatile near bit	TRISJ7		@ ((unsigned)&TRISJ*8)+7;

/* Definitions for TRISH register */
static volatile near bit	TRISH0		@ ((unsigned)&TRISH*8)+0;
static volatile near bit	TRISH1		@ ((unsigned)&TRISH*8)+1;
static volatile near bit	TRISH2		@ ((unsigned)&TRISH*8)+2;
static volatile near bit	TRISH3		@ ((unsigned)&TRISH*8)+3;
static volatile near bit	TRISH4		@ ((unsigned)&TRISH*8)+4;
static volatile near bit	TRISH5		@ ((unsigned)&TRISH*8)+5;
static volatile near bit	TRISH6		@ ((unsigned)&TRISH*8)+6;
static volatile near bit	TRISH7		@ ((unsigned)&TRISH*8)+7;
#endif

/* Definitions for TRISG register */
static volatile near bit	TRISG0		@ ((unsigned)&TRISG*8)+0;
static volatile near bit	TRISG1		@ ((unsigned)&TRISG*8)+1;
static volatile near bit	TRISG2		@ ((unsigned)&TRISG*8)+2;
static volatile near bit	TRISG3		@ ((unsigned)&TRISG*8)+3;
static volatile near bit	TRISG4		@ ((unsigned)&TRISG*8)+4;

/* Definitions for TRISF register */
static volatile near bit	TRISF0		@ ((unsigned)&TRISF*8)+0;
static volatile near bit	TRISF1		@ ((unsigned)&TRISF*8)+1;
static volatile near bit	TRISF2		@ ((unsigned)&TRISF*8)+2;
static volatile near bit	TRISF3		@ ((unsigned)&TRISF*8)+3;
static volatile near bit	TRISF4		@ ((unsigned)&TRISF*8)+4;
static volatile near bit	TRISF5		@ ((unsigned)&TRISF*8)+5;
static volatile near bit	TRISF6		@ ((unsigned)&TRISF*8)+6;
static volatile near bit	TRISF7		@ ((unsigned)&TRISF*8)+7;

/* Definitions for TRISE register */
static volatile near bit	TRISE0		@ ((unsigned)&TRISE*8)+0;
static volatile near bit	TRISE1		@ ((unsigned)&TRISE*8)+1;
static volatile near bit	TRISE2		@ ((unsigned)&TRISE*8)+2;
static volatile near bit	TRISE3		@ ((unsigned)&TRISE*8)+3;
static volatile near bit	TRISE4		@ ((unsigned)&TRISE*8)+4;
static volatile near bit	TRISE5		@ ((unsigned)&TRISE*8)+5;
static volatile near bit	TRISE6		@ ((unsigned)&TRISE*8)+6;
static volatile near bit	TRISE7		@ ((unsigned)&TRISE*8)+7;

/* Definitions for TRISD register */
static volatile near bit	TRISD0		@ ((unsigned)&TRISD*8)+0;
static volatile near bit	TRISD1		@ ((unsigned)&TRISD*8)+1;
static volatile near bit	TRISD2		@ ((unsigned)&TRISD*8)+2;
static volatile near bit	TRISD3		@ ((unsigned)&TRISD*8)+3;
static volatile near bit	TRISD4		@ ((unsigned)&TRISD*8)+4;
static volatile near bit	TRISD5		@ ((unsigned)&TRISD*8)+5;
static volatile near bit	TRISD6		@ ((unsigned)&TRISD*8)+6;
static volatile near bit	TRISD7		@ ((unsigned)&TRISD*8)+7;

/* Definitions for TRISC register */
static volatile near bit	TRISC0		@ ((unsigned)&TRISC*8)+0;
static volatile near bit	TRISC1		@ ((unsigned)&TRISC*8)+1;
static volatile near bit	TRISC2		@ ((unsigned)&TRISC*8)+2;
static volatile near bit	TRISC3		@ ((unsigned)&TRISC*8)+3;
static volatile near bit	TRISC4		@ ((unsigned)&TRISC*8)+4;
static volatile near bit	TRISC5		@ ((unsigned)&TRISC*8)+5;
static volatile near bit	TRISC6		@ ((unsigned)&TRISC*8)+6;
static volatile near bit	TRISC7		@ ((unsigned)&TRISC*8)+7;

/* Definitions for TRISB register */
static volatile near bit	TRISB0		@ ((unsigned)&TRISB*8)+0;
static volatile near bit	TRISB1		@ ((unsigned)&TRISB*8)+1;
static volatile near bit	TRISB2		@ ((unsigned)&TRISB*8)+2;
static volatile near bit	TRISB3		@ ((unsigned)&TRISB*8)+3;
static volatile near bit	TRISB4		@ ((unsigned)&TRISB*8)+4;
static volatile near bit	TRISB5		@ ((unsigned)&TRISB*8)+5;
static volatile near bit	TRISB6		@ ((unsigned)&TRISB*8)+6;
static volatile near bit	TRISB7		@ ((unsigned)&TRISB*8)+7;

/* Definitions for TRISA register */
static volatile near bit	TRISA0		@ ((unsigned)&TRISA*8)+0;
static volatile near bit	TRISA1		@ ((unsigned)&TRISA*8)+1;
static volatile near bit	TRISA2		@ ((unsigned)&TRISA*8)+2;
static volatile near bit	TRISA3		@ ((unsigned)&TRISA*8)+3;
static volatile near bit	TRISA4		@ ((unsigned)&TRISA*8)+4;
static volatile near bit	TRISA5		@ ((unsigned)&TRISA*8)+5;
static volatile near bit	TRISA6		@ ((unsigned)&TRISA*8)+6;
static volatile near bit	TRISA7		@ ((unsigned)&TRISA*8)+7;

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
/* Definitions for LATJ register */
static volatile near bit	LATJ0		@ ((unsigned)&LATJ*8)+0;
static volatile near bit	LATJ1		@ ((unsigned)&LATJ*8)+1;
static volatile near bit	LATJ2		@ ((unsigned)&LATJ*8)+2;
static volatile near bit	LATJ3		@ ((unsigned)&LATJ*8)+3;
static volatile near bit	LATJ4		@ ((unsigned)&LATJ*8)+4;
static volatile near bit	LATJ5		@ ((unsigned)&LATJ*8)+5;
static volatile near bit	LATJ6		@ ((unsigned)&LATJ*8)+6;
static volatile near bit	LATJ7		@ ((unsigned)&LATJ*8)+7;

/* Definitions for LATH register */
static volatile near bit	LATH0		@ ((unsigned)&LATH*8)+0;
static volatile near bit	LATH1		@ ((unsigned)&LATH*8)+1;
static volatile near bit	LATH2		@ ((unsigned)&LATH*8)+2;
static volatile near bit	LATH3		@ ((unsigned)&LATH*8)+3;
static volatile near bit	LATH4		@ ((unsigned)&LATH*8)+4;
static volatile near bit	LATH5		@ ((unsigned)&LATH*8)+5;
static volatile near bit	LATH6		@ ((unsigned)&LATH*8)+6;
static volatile near bit	LATH7		@ ((unsigned)&LATH*8)+7;
#endif

/* Definitions for LATG register */
static volatile near bit	LATG0		@ ((unsigned)&LATG*8)+0;
static volatile near bit	LATG1		@ ((unsigned)&LATG*8)+1;
static volatile near bit	LATG2		@ ((unsigned)&LATG*8)+2;
static volatile near bit	LATG3		@ ((unsigned)&LATG*8)+3;
static volatile near bit	LATG4		@ ((unsigned)&LATG*8)+4;

/* Definitions for LATF register */
static volatile near bit	LATF0		@ ((unsigned)&LATF*8)+0;
static volatile near bit	LATF1		@ ((unsigned)&LATF*8)+1;
static volatile near bit	LATF2		@ ((unsigned)&LATF*8)+2;
static volatile near bit	LATF3		@ ((unsigned)&LATF*8)+3;
static volatile near bit	LATF4		@ ((unsigned)&LATF*8)+4;
static volatile near bit	LATF5		@ ((unsigned)&LATF*8)+5;
static volatile near bit	LATF6		@ ((unsigned)&LATF*8)+6;
static volatile near bit	LATF7		@ ((unsigned)&LATF*8)+7;

/* Definitions for LATE register */
static volatile near bit	LATE0		@ ((unsigned)&LATE*8)+0;
static volatile near bit	LATE1		@ ((unsigned)&LATE*8)+1;
static volatile near bit	LATE2		@ ((unsigned)&LATE*8)+2;
static volatile near bit	LATE3		@ ((unsigned)&LATE*8)+3;
static volatile near bit	LATE4		@ ((unsigned)&LATE*8)+4;
static volatile near bit	LATE5		@ ((unsigned)&LATE*8)+5;
static volatile near bit	LATE6		@ ((unsigned)&LATE*8)+6;
static volatile near bit	LATE7		@ ((unsigned)&LATE*8)+7;

/* Definitions for LATD register */
static volatile near bit	LATD0		@ ((unsigned)&LATD*8)+0;
static volatile near bit	LATD1		@ ((unsigned)&LATD*8)+1;
static volatile near bit	LATD2		@ ((unsigned)&LATD*8)+2;
static volatile near bit	LATD3		@ ((unsigned)&LATD*8)+3;
static volatile near bit	LATD4		@ ((unsigned)&LATD*8)+4;
static volatile near bit	LATD5		@ ((unsigned)&LATD*8)+5;
static volatile near bit	LATD6		@ ((unsigned)&LATD*8)+6;
static volatile near bit	LATD7		@ ((unsigned)&LATD*8)+7;

/* Definitions for LATC register */
static volatile near bit	LATC0		@ ((unsigned)&LATC*8)+0;
static volatile near bit	LATC1		@ ((unsigned)&LATC*8)+1;
static volatile near bit	LATC2		@ ((unsigned)&LATC*8)+2;
static volatile near bit	LATC3		@ ((unsigned)&LATC*8)+3;
static volatile near bit	LATC4		@ ((unsigned)&LATC*8)+4;
static volatile near bit	LATC5		@ ((unsigned)&LATC*8)+5;
static volatile near bit	LATC6		@ ((unsigned)&LATC*8)+6;
static volatile near bit	LATC7		@ ((unsigned)&LATC*8)+7;

/* Definitions for LATB register */
static volatile near bit	LATB0		@ ((unsigned)&LATB*8)+0;
static volatile near bit	LATB1		@ ((unsigned)&LATB*8)+1;
static volatile near bit	LATB2		@ ((unsigned)&LATB*8)+2;
static volatile near bit	LATB3		@ ((unsigned)&LATB*8)+3;
static volatile near bit	LATB4		@ ((unsigned)&LATB*8)+4;
static volatile near bit	LATB5		@ ((unsigned)&LATB*8)+5;
static volatile near bit	LATB6		@ ((unsigned)&LATB*8)+6;
static volatile near bit	LATB7		@ ((unsigned)&LATB*8)+7;

/* Definitions for LATA register */
static volatile near bit	LATA0		@ ((unsigned)&LATA*8)+0;
static volatile near bit	LATA1		@ ((unsigned)&LATA*8)+1;
static volatile near bit	LATA2		@ ((unsigned)&LATA*8)+2;
static volatile near bit	LATA3		@ ((unsigned)&LATA*8)+3;
static volatile near bit	LATA4		@ ((unsigned)&LATA*8)+4;
static volatile near bit	LATA5		@ ((unsigned)&LATA*8)+5;
static volatile near bit	LATA6		@ ((unsigned)&LATA*8)+6;
static volatile near bit	LATA7		@ ((unsigned)&LATA*8)+7;

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
/* Definitions for PORTJ register */
static volatile near bit	RJ0		@ ((unsigned)&PORTJ*8)+0;
static volatile near bit	RJ1		@ ((unsigned)&PORTJ*8)+1;
static volatile near bit	RJ2		@ ((unsigned)&PORTJ*8)+2;
static volatile near bit	RJ3		@ ((unsigned)&PORTJ*8)+3;
static volatile near bit	RJ4		@ ((unsigned)&PORTJ*8)+4;
static volatile near bit	RJ5		@ ((unsigned)&PORTJ*8)+5;
static volatile near bit	RJ6		@ ((unsigned)&PORTJ*8)+6;
static volatile near bit	RJ7		@ ((unsigned)&PORTJ*8)+7;

/* Definitions for PORTH register */
static volatile near bit	RH0		@ ((unsigned)&PORTH*8)+0;
static volatile near bit	RH1		@ ((unsigned)&PORTH*8)+1;
static volatile near bit	RH2		@ ((unsigned)&PORTH*8)+2;
static volatile near bit	RH3		@ ((unsigned)&PORTH*8)+3;
static volatile near bit	RH4		@ ((unsigned)&PORTH*8)+4;
static volatile near bit	RH5		@ ((unsigned)&PORTH*8)+5;
static volatile near bit	RH6		@ ((unsigned)&PORTH*8)+6;
static volatile near bit	RH7		@ ((unsigned)&PORTH*8)+7;
#endif

/* Definitions for PORTG register */
static volatile near bit	RG0		@ ((unsigned)&PORTG*8)+0;
static volatile near bit	RG1		@ ((unsigned)&PORTG*8)+1;
static volatile near bit	RG2		@ ((unsigned)&PORTG*8)+2;
static volatile near bit	RG3		@ ((unsigned)&PORTG*8)+3;
static volatile near bit	RG4		@ ((unsigned)&PORTG*8)+4;
static volatile near bit	RG5		@ ((unsigned)&PORTG*8)+5;

/* Definitions for PORTF register */
static volatile near bit	RF0		@ ((unsigned)&PORTF*8)+0;
static volatile near bit	RF1		@ ((unsigned)&PORTF*8)+1;
static volatile near bit	RF2		@ ((unsigned)&PORTF*8)+2;
static volatile near bit	RF3		@ ((unsigned)&PORTF*8)+3;
static volatile near bit	RF4		@ ((unsigned)&PORTF*8)+4;
static volatile near bit	RF5		@ ((unsigned)&PORTF*8)+5;
static volatile near bit	RF6		@ ((unsigned)&PORTF*8)+6;
static volatile near bit	RF7		@ ((unsigned)&PORTF*8)+7;

/* Definitions for PORTE register */
static volatile near bit	RE0		@ ((unsigned)&PORTE*8)+0;
static volatile near bit	RE1		@ ((unsigned)&PORTE*8)+1;
static volatile near bit	RE2		@ ((unsigned)&PORTE*8)+2;
static volatile near bit	RE3		@ ((unsigned)&PORTE*8)+3;
static volatile near bit	RE4		@ ((unsigned)&PORTE*8)+4;
static volatile near bit	RE5		@ ((unsigned)&PORTE*8)+5;
static volatile near bit	RE6		@ ((unsigned)&PORTE*8)+6;
static volatile near bit	RE7		@ ((unsigned)&PORTE*8)+7;

/* Definitions for PORTD register */
static volatile near bit	RD0		@ ((unsigned)&PORTD*8)+0;
static volatile near bit	RD1		@ ((unsigned)&PORTD*8)+1;
static volatile near bit	RD2		@ ((unsigned)&PORTD*8)+2;
static volatile near bit	RD3		@ ((unsigned)&PORTD*8)+3;
static volatile near bit	RD4		@ ((unsigned)&PORTD*8)+4;
static volatile near bit	RD5		@ ((unsigned)&PORTD*8)+5;
static volatile near bit	RD6		@ ((unsigned)&PORTD*8)+6;
static volatile near bit	RD7		@ ((unsigned)&PORTD*8)+7;

/* Definitions for PORTC register */
static volatile near bit	RC0		@ ((unsigned)&PORTC*8)+0;
static volatile near bit	RC1		@ ((unsigned)&PORTC*8)+1;
static volatile near bit	RC2		@ ((unsigned)&PORTC*8)+2;
static volatile near bit	RC3		@ ((unsigned)&PORTC*8)+3;
static volatile near bit	RC4		@ ((unsigned)&PORTC*8)+4;
static volatile near bit	RC5		@ ((unsigned)&PORTC*8)+5;
static volatile near bit	RC6		@ ((unsigned)&PORTC*8)+6;
static volatile near bit	RC7		@ ((unsigned)&PORTC*8)+7;

/* Definitions for PORTB register */
static volatile near bit	RB0		@ ((unsigned)&PORTB*8)+0;
static volatile near bit	RB1		@ ((unsigned)&PORTB*8)+1;
static volatile near bit	RB2		@ ((unsigned)&PORTB*8)+2;
static volatile near bit	RB3		@ ((unsigned)&PORTB*8)+3;
static volatile near bit	RB4		@ ((unsigned)&PORTB*8)+4;
static volatile near bit	RB5		@ ((unsigned)&PORTB*8)+5;
static volatile near bit	RB6		@ ((unsigned)&PORTB*8)+6;
static volatile near bit	RB7		@ ((unsigned)&PORTB*8)+7;

/* Definitions for PORTA register */
static volatile near bit	RA0		@ ((unsigned)&PORTA*8)+0;
static volatile near bit	RA1		@ ((unsigned)&PORTA*8)+1;
static volatile near bit	RA2		@ ((unsigned)&PORTA*8)+2;
static volatile near bit	RA3		@ ((unsigned)&PORTA*8)+3;
static volatile near bit	RA4		@ ((unsigned)&PORTA*8)+4;
static volatile near bit	RA5		@ ((unsigned)&PORTA*8)+5;
static volatile near bit	RA6		@ ((unsigned)&PORTA*8)+6;
static volatile near bit	RA7		@ ((unsigned)&PORTA*8)+7;

/* Definitions for BAUDCON1 register */
static volatile near bit	ABDEN1		@ ((unsigned)&BAUDCON1*8)+0;
static volatile near bit	WUE1		@ ((unsigned)&BAUDCON1*8)+1;
static          near bit	BRG161		@ ((unsigned)&BAUDCON1*8)+3;
static volatile near bit	SCKP1		@ ((unsigned)&BAUDCON1*8)+4;
static volatile near bit	RCIDL1		@ ((unsigned)&BAUDCON1*8)+6;
static volatile near bit	ABDOVF1		@ ((unsigned)&BAUDCON1*8)+7;

/* Definitions for BAUDCON2 register */
static volatile near bit	ABDEN2		@ ((unsigned)&BAUDCON2*8)+0;
static volatile near bit	WUE2		@ ((unsigned)&BAUDCON2*8)+1;
static          near bit	BRG162		@ ((unsigned)&BAUDCON2*8)+3;
static volatile near bit	SCKP2		@ ((unsigned)&BAUDCON2*8)+4;
static volatile near bit	RCIDL2		@ ((unsigned)&BAUDCON2*8)+6;
static volatile near bit	ABDOVF2		@ ((unsigned)&BAUDCON2*8)+7;

/* Definitions for ECCP1DEL register */
static          near bit	P1DC0		@ ((unsigned)&ECCP1DEL*8)+0;
static          near bit	P1DC1		@ ((unsigned)&ECCP1DEL*8)+1;
static          near bit	P1DC2		@ ((unsigned)&ECCP1DEL*8)+2;
static          near bit	P1DC3		@ ((unsigned)&ECCP1DEL*8)+3;
static          near bit	P1DC4		@ ((unsigned)&ECCP1DEL*8)+4;
static          near bit	P1DC5		@ ((unsigned)&ECCP1DEL*8)+5;
static          near bit	P1DC6		@ ((unsigned)&ECCP1DEL*8)+6;
static          near bit	P1RSEN		@ ((unsigned)&ECCP1DEL*8)+7;

/* Definitions for T4CON register */
static          near bit	T4CKPS0		@ ((unsigned)&T4CON*8)+0;
static          near bit	T4CKPS1		@ ((unsigned)&T4CON*8)+1;
static          near bit	TMR4ON		@ ((unsigned)&T4CON*8)+2;
static          near bit	T4OUTPS0	@ ((unsigned)&T4CON*8)+3;
static          near bit	T4OUTPS1	@ ((unsigned)&T4CON*8)+4;
static          near bit	T4OUTPS2	@ ((unsigned)&T4CON*8)+5;
static          near bit	T4OUTPS3	@ ((unsigned)&T4CON*8)+6;

/* Definitions for CCP4CON register */
static          near bit	CCP4M0		@ ((unsigned)&CCP4CON*8)+0;
static          near bit	CCP4M1		@ ((unsigned)&CCP4CON*8)+1;
static          near bit	CCP4M2		@ ((unsigned)&CCP4CON*8)+2;
static          near bit	CCP4M3		@ ((unsigned)&CCP4CON*8)+3;
static          near bit	DC4B0		@ ((unsigned)&CCP4CON*8)+4;
static          near bit	DC4B1		@ ((unsigned)&CCP4CON*8)+5;

/* Definitions for CCP5CON register */
static          near bit	CCP5M0		@ ((unsigned)&CCP5CON*8)+0;
static          near bit	CCP5M1		@ ((unsigned)&CCP5CON*8)+1;
static          near bit	CCP5M2		@ ((unsigned)&CCP5CON*8)+2;
static          near bit	CCP5M3		@ ((unsigned)&CCP5CON*8)+3;
static          near bit	DC5B0		@ ((unsigned)&CCP5CON*8)+4;
static          near bit	DC5B1		@ ((unsigned)&CCP5CON*8)+5;

/* Definitions for TXSTA2 register */
static volatile near bit	TX9D2		@ ((unsigned)&TXSTA2*8)+0;
static volatile near bit	TRMT2		@ ((unsigned)&TXSTA2*8)+1;
static          near bit	BRGH2		@ ((unsigned)&TXSTA2*8)+2;
static          near bit	SENDB2		@ ((unsigned)&TXSTA2*8)+3;
static          near bit	SYNC2		@ ((unsigned)&TXSTA2*8)+4;
static          near bit	TXEN2		@ ((unsigned)&TXSTA2*8)+5;
static          near bit	TX92		@ ((unsigned)&TXSTA2*8)+6;
static          near bit	CSRC2		@ ((unsigned)&TXSTA2*8)+7;

/* Definitions for RCSTA2 register */
static volatile near bit	RX9D2		@ ((unsigned)&RCSTA2*8)+0;
static volatile near bit	OERR2		@ ((unsigned)&RCSTA2*8)+1;
static volatile near bit	FERR2		@ ((unsigned)&RCSTA2*8)+2;
static          near bit	ADDEN2		@ ((unsigned)&RCSTA2*8)+3;
static          near bit	CREN2		@ ((unsigned)&RCSTA2*8)+4;
static          near bit	SREN2		@ ((unsigned)&RCSTA2*8)+5;
static          near bit	RX92		@ ((unsigned)&RCSTA2*8)+6;
static          near bit	SPEN2		@ ((unsigned)&RCSTA2*8)+7;

/* Definitions for ECCP3AS register */
static          near bit	PSS3BD0		@ ((unsigned)&ECCP3AS*8)+0;
static          near bit	PSS3BD1		@ ((unsigned)&ECCP3AS*8)+1;
static          near bit	PSS3AC0		@ ((unsigned)&ECCP3AS*8)+2;
static          near bit	PSS3AC1		@ ((unsigned)&ECCP3AS*8)+3;
static          near bit	ECCP3AS0	@ ((unsigned)&ECCP3AS*8)+4;
static          near bit	ECCP3AS1	@ ((unsigned)&ECCP3AS*8)+5;
static          near bit	ECCP3AS2	@ ((unsigned)&ECCP3AS*8)+6;
static volatile near bit	ECCP3ASE	@ ((unsigned)&ECCP3AS*8)+7;

/* Definitions for ECCP3DEL register */
static          near bit	P3DC0		@ ((unsigned)&ECCP3DEL*8)+0;
static          near bit	P3DC1		@ ((unsigned)&ECCP3DEL*8)+1;
static          near bit	P3DC2		@ ((unsigned)&ECCP3DEL*8)+2;
static          near bit	P3DC3		@ ((unsigned)&ECCP3DEL*8)+3;
static          near bit	P3DC4		@ ((unsigned)&ECCP3DEL*8)+4;
static          near bit	P3DC5		@ ((unsigned)&ECCP3DEL*8)+5;
static          near bit	P3DC6		@ ((unsigned)&ECCP3DEL*8)+6;
static          near bit	P3RSEN		@ ((unsigned)&ECCP3DEL*8)+7;

/* Definitions for ECCP2AS register */
static          near bit	PSS2BD0		@ ((unsigned)&ECCP2AS*8)+0;
static          near bit	PSS2BD1		@ ((unsigned)&ECCP2AS*8)+1;
static          near bit	PSS2AC0		@ ((unsigned)&ECCP2AS*8)+2;
static          near bit	PSS2AC1		@ ((unsigned)&ECCP2AS*8)+3;
static          near bit	ECCP2AS0	@ ((unsigned)&ECCP2AS*8)+4;
static          near bit	ECCP2AS1	@ ((unsigned)&ECCP2AS*8)+5;
static          near bit	ECCP2AS2	@ ((unsigned)&ECCP2AS*8)+6;
static volatile near bit	ECCP2ASE	@ ((unsigned)&ECCP2AS*8)+7;

/* Definitions for ECCP2DEL register */
static          near bit	P2DC0		@ ((unsigned)&ECCP2DEL*8)+0;
static          near bit	P2DC1		@ ((unsigned)&ECCP2DEL*8)+1;
static          near bit	P2DC2		@ ((unsigned)&ECCP2DEL*8)+2;
static          near bit	P2DC3		@ ((unsigned)&ECCP2DEL*8)+3;
static          near bit	P2DC4		@ ((unsigned)&ECCP2DEL*8)+4;
static          near bit	P2DC5		@ ((unsigned)&ECCP2DEL*8)+5;
static          near bit	P2DC6		@ ((unsigned)&ECCP2DEL*8)+6;
static          near bit	P2RSEN		@ ((unsigned)&ECCP2DEL*8)+7;

/* Definitions for SSP2STAT register */
static volatile near bit	BF2		@ ((unsigned)&SSP2STAT*8)+0;
static volatile near bit	UA2		@ ((unsigned)&SSP2STAT*8)+1;
static volatile near bit	RW2		@ ((unsigned)&SSP2STAT*8)+2;
static volatile near bit	START2		@ ((unsigned)&SSP2STAT*8)+3;
static volatile near bit	STOP2		@ ((unsigned)&SSP2STAT*8)+4;
static volatile near bit	DA2		@ ((unsigned)&SSP2STAT*8)+5;
static          near bit	CKE2		@ ((unsigned)&SSP2STAT*8)+6;
static          near bit	SMP2		@ ((unsigned)&SSP2STAT*8)+7;

/* Definitions for SSP2CON1 register */
static          near bit	SSPM02		@ ((unsigned)&SSP2CON1*8)+0;
static          near bit	SSPM12		@ ((unsigned)&SSP2CON1*8)+1;
static          near bit	SSPM22		@ ((unsigned)&SSP2CON1*8)+2;
static          near bit	SSPM32		@ ((unsigned)&SSP2CON1*8)+3;
static          near bit	CKP2		@ ((unsigned)&SSP2CON1*8)+4;
static          near bit	SSPEN2		@ ((unsigned)&SSP2CON1*8)+5;
static volatile near bit	SSPOV2		@ ((unsigned)&SSP2CON1*8)+6;
static volatile near bit	WCOL2		@ ((unsigned)&SSP2CON1*8)+7;

/* Definitions for SSP2CON2 register */
static          near bit	SEN2		@ ((unsigned)&SSP2CON2*8)+0;
static volatile near bit	RSEN2		@ ((unsigned)&SSP2CON2*8)+1;
static volatile near bit	PEN2		@ ((unsigned)&SSP2CON2*8)+2;
static volatile near bit	RCEN2		@ ((unsigned)&SSP2CON2*8)+3;
static volatile near bit	ACKEN2		@ ((unsigned)&SSP2CON2*8)+4;
static volatile near bit	ACKDT2		@ ((unsigned)&SSP2CON2*8)+5;
static volatile near bit	ACKSTAT2	@ ((unsigned)&SSP2CON2*8)+6;
static          near bit	GCEN2		@ ((unsigned)&SSP2CON2*8)+7;


#define EEPROM_SIZE 1024

// Configuration Bit Values

// Configuration register 1H
// Oscillator
 #define EXTCLKO	0xFFFF 	// 11XX EXT RC-CLKOUT on RA6 
 #define INTCLKO	0xF9FF 	// INT RC-CLKOUT on RA6,Port on RA7 
 #define INTIO		0xF8FF 	// INT RC-Port on RA6,Port on RA7 
 #define EXTIO		0xF7FF 	// EXT RC-Port on RA6 
 #define HSPLL		0xF6FF 	// HS-PLL enabled freq=4xFosc1 
 #define ECIO		0xF5FF 	// EC-Port on RA6 
 #define ECCLKO		0xF4FF 	// EC-CLKOUT on RA6 
 #define HS		0xF2FF 	// HS Oscillator 
 #define XT		0xF1FF 	// XT Oscillator 
 #define LP		0xF0FF 	// LP Oscillator 
// Fail-Safe Clock Monitor Enable
 #define FCMDIS		0xBFFF 	// Disabled 
 #define FCMEN		0xFFFF 	// Enabled 
// Internal External Switch Over Mode
 #define IESODIS	0x7FFF 	// Disabled 
 #define IESOEN		0xFFFF 	// Enabled 

// Configuration register 2L
// Power Up Timer
 #define PWRTDIS	0xFFFF 	// Disabled 
 #define PWRTEN		0xFFFE 	// Enabled 
// Brown Out Detect
 #define BOREN		0xFFFF 	// Enabled in hardware, SBOREN disabled 
 #define BOREN_XSLP	0xFFFD 	// Enabled while active,disabled in SLEEP,SBOREN disabled 
 #define SWBOREN	0xFFFB 	// Controlled with SBOREN bit 
 #define BORDIS		0xFFF9 	// Disabled in hardware, SBOREN disabled 
// Brown Out Voltage
 #define BORV21		0xFFFF 	// 2.1V 
 #define BORV28		0xFFF7 	// 2.8V 
 #define BORV43		0xFFEF 	// 4.3V 
 #define BORV46		0xFFE7 	// 4.6V 

// Configuration register 2H
// Watchdog Timer
 #define WDTEN		0xFFFF 	// Enabled 
 #define WDTDIS		0xFEFF 	// Disabled-Controlled by SWDTEN bit 
// Watchdog Postscaler
 #define WDTPS32K	0xFFFF 	// 1:32768 
 #define WDTPS16K	0xFDFF 	// 1:16384 
 #define WDTPS8K	0xFBFF 	// 1:8192 
 #define WDTPS4K	0xF9FF 	// 1:4096 
 #define WDTPS2K	0xF7FF 	// 1:2048 
 #define WDTPS1K	0xF5FF 	// 1:1024 
 #define WDTPS512	0xF3FF 	// 1:512 
 #define WDTPS256	0xF1FF 	// 1:256 
 #define WDTPS128	0xEFFF 	// 1:128 
 #define WDTPS64	0xEDFF 	// 1:64 
 #define WDTPS32	0xEBFF 	// 1:32 
 #define WDTPS16	0xE9FF 	// 1:16 
 #define WDTPS8		0xE7FF 	// 1:8 
 #define WDTPS4		0xE5FF 	// 1:4 
 #define WDTPS2		0xE3FF 	// 1:2 
 #define WDTPS1		0xE1FF 	// 1:1 

#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
// Configuration register 3L
// External bus wait enable
 #define WAITEN		0xFF7F 	// WAIT mode active & determined by WAIT1:WAIT0 bits 
 #define WAITDIS	0xFFFF 	// WAIT mode inactive 
// External data bus width select
 #define BW16		0xFFFF 	// 16-Bit external data bus width 
 #define BW8		0xFFBF 	// 8-Bit external data bus width 
// External Address bus width select
 #define ABW20		0xFFFF 	// 20-Bit external address bus width 
 #define ABW16		0xFFEF 	// 16-Bit external address bus width 
 #define ABW12		0xFFDF 	// 12-Bit external address bus width 
 #define ABW8		0xFFCF 	// 8-Bit external address bus width 
// Processor data mode
 #define MCU		0xFFFF 	// select microcontroller mode 
 #define MPU		0xFFFE 	// select microprocessor mode 
 #define MPUBB		0xFFFD 	// select microprocessor mode with boot block mode 
 #define XMCU		0xFFFC 	// select extended microcontroller mode 
#endif

// Configuration register 3H
// CCP2 Mux
 #define CCP2RC1	0xFFFF 	// RC1 
 #define CCP2RE7	0xFEFF 	// RE7 
// if in XMCU or MPUB modes
 #define CCP2RB3	0xFEFF 	// RB3 
#if defined(_18F8527) || defined(_18F8622) || defined(_18F8627) || defined(_18F8722)
// ECCP Mux
 #define ECCPRE		0xFFFF 	// ECCP multiplexed on Port E 
 #define ECCPRH		0xFDFF 	// ECCP multiplexed on Port H 
#endif
// Low Power Timer1 Osc enable
 #define LPT1EN		0xFFFF 	// Enabled 
 #define LPT1DIS	0xFBFF 	// Disabled 
// Master Clear Enable
 #define MCLREN		0xFFFF 	// MCLR Enabled,RE3 Disabled 
 #define MCLRDIS	0x7FFF 	// MCLR Disabled,RE3 Enabled 

// Configuration register 4L
// Stack Overflow Reset
 #define STVREN		0xFFFF 	// Enabled 
 #define STVRDIS	0xFFFE 	// Disabled 
// Low voltage program enable
 #define LVPEN		0xFFFF 	// Low voltage ISP enabled 
 #define LVPDIS		0xFFFB 	// Low voltage ISP disabled 
// Extended CPU Enable
 #define XINSTEN	0xFFFF 	// Enabled 
 #define XINSTDIS	0xFFBF 	// Disabled 
// Boot block size select
 #define BBSIZ4K	0xFFFF 	// Boot block is 4K 
 #define BBSIZ2K	0xFFDF 	// Boot block is 2K 
 #define BBSIZ1K	0xFFCF 	// Boot block is 1K 
// Background Debug
 #define DEBUGDIS	0xFFFF 	// Disabled 
 #define DEBUGEN	0xFF7F 	// Enabled 

// Configuration register 5L
// Code Protection
 #define UNPROTECT	0xFFFF 	// Do not protect code 
 #define CP0		0xFFFE 	// Code Protect block 0 
 #define CP1		0xFFFD 	// Code Protect block 1 
 #define CP2		0xFFFB 	// Code Protect block 2 
#if !defined(_18F6527) && !defined(_18F8527)
 #define CP3		0xFFF7 	// Code Protect block 3 
#if !defined(_18F6622) && !defined(_18F8622)
 #define CP4		0xFFEF 	// Code Protect block 4 
 #define CP5		0xFFDF 	// Code Protect block 5 
#if !defined(_18F6627) && !defined(_18F8627)
 #define CP6		0xFFBF 	// Code Protect block 6 
 #define CP7		0xFF7F 	// Code Protect block 7 
#endif
#endif
#endif
 #define CPA		0xFF00	// protect all code blocks
 #define CPD		0x7FFF 	// Code Protect data 
 #define CPB		0xBFFF 	// Code Protect boot block 
 #define CPALL		(CPA & CPD & CPB)

// Configuration register 6L
// Write Protection
 #define WRTEN		0xFFFF 	// Do write protect 
 #define WP0		0xFFFE 	// Write Protect block 0 
 #define WP1		0xFFFD 	// Write Protect block 1 
 #define WP2		0xFFFB 	// Write Protect block 2 
#if !defined(_18F6527) && !defined(_18F8527)
 #define WP3		0xFFF7 	// Write Protect block 3 
#if !defined(_18F6622) && !defined(_18F8622)
 #define WP4		0xFFEF 	// Write Protect block 4 
 #define WP5		0xFFDF 	// Write Protect block 5 
#if !defined(_18F6627) && !defined(_18F8627)
 #define WP6		0xFFBF 	// Write Protect block 6 
 #define WP7		0xFF7F 	// Write Protect block 7 
#endif
#endif
#endif
 #define WPA		0xFF00	// Write Protect all code blocks
 #define WPD		0x7FFF 	// Write Protect data 
 #define WPB		0xBFFF 	// Write Protect boot block 
 #define WPC		0xDFFF 	// Write Protect config area 
 #define WPALL		(WPA & WPD & WPB & WPC)

// Configuration register 7L
// Table read Protection
 #define TREN		0xFFFF 	// Do table read protect 
 #define TRP0		0xFFFE 	// Table read protect block 0 
 #define TRP1		0xFFFD 	// Table read protect block 1 
 #define TRP2		0xFFFB 	// Table read protect block 2 
#if !defined(_18F6527) && !defined(_18F8527)
 #define TRP3		0xFFF7 	// Table read protect block 3 
#if !defined(_18F6622) && !defined(_18F8622)
 #define TRP4		0xFFEF 	// Table read protect block 4 
 #define TRP5		0xFFDF 	// Table read protect block 5 
#if !defined(_18F6627) && !defined(_18F8627)
 #define TRP6		0xFFBF 	// Table read protect block 6 
 #define TRP7		0xFF7F 	// Table read protect block 7 
#endif
#endif
#endif
 #define TRPA		0xFF00	// Table read protect all code blocks
 #define TRPB		0xBFFF 	// Table read protect boot block 
 #define TRPALL		(TRPA & TRPB)

#endif
