;for Megawin MPC82G516

;------------------------------------------------------------------------------
;Standard SFRs
;------------------------------------------------------------------------------

;8051 Registers

P0       DATA   80H
P1       DATA   90H
P2       DATA   0A0H
P3       DATA   0B0H
PSW      DATA   0D0H
ACC      DATA   0E0H
B        DATA   0F0H
SP       DATA   81H
DPL      DATA   82H
DPH      DATA   83H
PCON     DATA   87H
TCON     DATA   88H
TMOD     DATA   89H
TL0      DATA   8AH
TL1      DATA   8BH
TH0      DATA   8CH
TH1      DATA   8DH
IE       DATA   0A8H
IP       DATA   0B8H
SCON     DATA   98H
SBUF     DATA   99H

;(PSW)
CY       BIT    PSW.7
AC       BIT    PSW.6
F0       BIT    PSW.5
RS1      BIT    PSW.4
RS0      BIT    PSW.3
OV       BIT    PSW.2
P        BIT    PSW.0

;(TCON)
TF1      BIT    TCON.7
TR1      BIT    TCON.6
TF0      BIT    TCON.5
TR0      BIT    TCON.4
IE1      BIT    TCON.3
IT1      BIT    TCON.2
IE0      BIT    TCON.1
IT0      BIT    TCON.0

;(IE)
EA       BIT    IE.7
ES       BIT    IE.4
ET1      BIT    IE.3
EX1      BIT    IE.2
ET0      BIT    IE.1
EX0      BIT    IE.0

;(IP)
PS       BIT    IP.4
PT1      BIT    IP.3
PX1      BIT    IP.2
PT0      BIT    IP.1
PX0      BIT    IP.0

;(SCON)
SM0      BIT    SCON.7
SM1      BIT    SCON.6
SM2      BIT    SCON.5
REN      BIT    SCON.4
TB8      BIT    SCON.3
RB8      BIT    SCON.2
TI       BIT    SCON.1
RI       BIT    SCON.0

;(P3 alternate)
RD       BIT    P3.7
WR       BIT    P3.6
T1       BIT    P3.5
T0       BIT    P3.4
INT1     BIT    P3.3
INT0     BIT    P3.2
TXD      BIT    P3.1
RXD      BIT    P3.0

;8052 Extensions

T2CON    DATA   0C8H
RCAP2L   DATA   0CAH
RCAP2H   DATA   0CBH
TL2      DATA   0CCH
TH2      DATA   0CDH

;(IE)
ET2      BIT    IE.5

;(IP)
PT2      BIT    IP.5

;(T2CON)
TF2      BIT    T2CON.7
EXF2     BIT    T2CON.6
RCLK     BIT    T2CON.5
TCLK     BIT    T2CON.4
EXEN2    BIT    T2CON.3
TR2      BIT    T2CON.2
C_T2     BIT    T2CON.1
CP_RL2   BIT    T2CON.0

;(P1 alternate)
T2EX     BIT    P1.1
T2       BIT    P1.0

;------------------------------------------------------------------------------
;New-defined SFRs
;------------------------------------------------------------------------------

;MPC82G516 Extensions

AUXR     DATA   8Eh
AUXR1    DATA   0A2h
SADDR    DATA   0A9h
SADEN    DATA   0B9h
WDTCR    DATA   0E1h
PCON2    DATA   0C7h
EVRCR    DATA   97h
STRETCH  DATA   8Fh
AUXR2    DATA   0A6h

;for I/O
P4       DATA   0E8h
P0M0     DATA   93h
P0M1     DATA   94h
P1M0     DATA   91h
P1M1     DATA   92h
P2M0     DATA   95h
P2M1     DATA   96h
P3M0     DATA   0B1h
P3M1     DATA   0B2h
P4M0     DATA   0B3h
P4M1     DATA   0B4h

;for ISP
IFD      DATA   0E2h
IFADRH   DATA   0E3h
IFADRL   DATA   0E4h
IFMT     DATA   0E5h
SCMD     DATA   0E6h
ISPCR    DATA   0E7h

;for interrupt
XICON    DATA   0C0h
AUXIE    DATA   0ADh
IPH      DATA   0B7h
AUXIP    DATA   0AEh
AUXIPH   DATA   0AFh

;for Timer2
T2MOD    DATA   0C9h

;for UART2
S2CON    DATA   0AAh
S2BRT    DATA   0BAh
S2BUF    DATA   9Ah

;for Keypad Interrupt
KBPATN   DATA   0D5h
KBCON    DATA   0D6h
KBMASK   DATA   0D7h

;for ADC
ADCTL    DATA   0C5h
ADCH     DATA   0C6h
ADCL     DATA   0BEh
ADC      DATA   0C6h ;the same as ADCH: ADC result, higher 8 bits

;for PCA
CCON     DATA   0D8h
CMOD     DATA   0D9h
CCAPM0   DATA   0DAh
CCAPM1   DATA   0DBh
CCAPM2   DATA   0DCh
CCAPM3   DATA   0DDh
CCAPM4   DATA   0DEh
CCAPM5   DATA   0DFh
CL       DATA   0E9h
CH       DATA   0F9h
CCAP0L   DATA   0EAh
CCAP0H   DATA   0FAh
CCAP1L   DATA   0EBh
CCAP1H   DATA   0FBh
CCAP2L   DATA   0ECh
CCAP2H   DATA   0FCh
CCAP3L   DATA   0EDh
CCAP3H   DATA   0FDh
CCAP4L   DATA   0EEh
CCAP4H   DATA   0FEh
CCAP5L   DATA   0EFh
CCAP5H   DATA   0FFh
PCAPWM0  DATA   0F2h
PCAPWM1  DATA   0F3h
PCAPWM2  DATA   0F4h
PCAPWM3  DATA   0F5h
PCAPWM4  DATA   0F6h
PCAPWM5  DATA   0F7h

;for SPI
SPSTAT   DATA   84h
SPCTL    DATA   85h
SPDAT    DATA   86h

;for OCD
SVAR     DATA   0CEh
SBK      DATA   0CFh

;(CCON)
CF       BIT    CCON.7
CR       BIT    CCON.6
CCF5     BIT    CCON.5
CCF4     BIT    CCON.4
CCF3     BIT    CCON.3
CCF2     BIT    CCON.2
CCF1     BIT    CCON.1
CCF0     BIT    CCON.0

;(SCON)
FE       BIT    SCON.7

;(XICON)
PX3      BIT    XICON.7
EX3      BIT    XICON.6
IE3      BIT    XICON.5
IT3      BIT    XICON.4
PX2      BIT    XICON.3
EX2      BIT    XICON.2
IE2      BIT    XICON.1
IT2      BIT    XICON.0

;(P1 alternate)
CEX5     BIT    P1.7
CEX4     BIT    P1.6
CEX3     BIT    P1.5
CEX2     BIT    P1.4
CEX1     BIT    P1.3
CEX0     BIT    P1.2
ECI      BIT    P1.1

SPI_CLK  BIT    P1.7
SPI_MISO BIT    P1.6
SPI_MOSI BIT    P1.5
SPI_SS   BIT    P1.4

S2TXD    BIT    P1.3
S2RXD    BIT    P1.2

;(P2 alternate)
KBI7     BIT    P2.7
KBI6     BIT    P2.6
KBI5     BIT    P2.5
KBI4     BIT    P2.4
KBI3     BIT    P2.3
KBI2     BIT    P2.2
KBI1     BIT    P2.1
KBI0     BIT    P2.0

;(P3 alternate)
S2CKO    BIT    P3.5
T0CKO    BIT    P3.4

;(P4 alternate)
INT3     BIT    P4.2
INT2     BIT    P4.3

