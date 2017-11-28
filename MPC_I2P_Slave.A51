///////////////////////////////////////////////////
//
//	FILE:		MPC82x54_IAP_Demo.A51
//	AUTHOR:		Neo (Hsin-Chih Lin)
//	COPYRIGHT:	(c) Megawin Technology Co., Ltd.
//	CREATED:	2007.4.11
//	PURPOSE:	Demo IAP & UART Function
//
///////////////////////////////////////////////////
#include "REG_MPC82G516.INC"
#include "DEBUG.INC"

SDA     BIT     P3.2
SCL     BIT     P3.3
ADDR    EQU     0B0H

    	ORG		0000H	
	    JMP		START
    	ORG		0003H	
	    JMP		EXTERNAL_INTERRUPT_0
   	    ORG		10H

///////////////////////////////////////////////////
//	Receive Data
///////////////////////////////////////////////////
RECEIVE_DATA    MACRO
//first bit check Start or Stop
        MOV     R4,#07H
        JNB     SCL,$           //WAIT HIGH
        MOV     C,SDA
        RLC     A
        JB      SDA,CHECK_START
CHECK_STOP:
        JB      SDA,END_INT
        JB      SCL,CHECK_STOP
        JMP     NEXT_7BIT
CHECK_START:
        JNB     SDA,FIRST_BYTE
        JB      SCL,CHECK_START
//Wait Low and check Start or Stop
NEXT_7BIT:
        JNB     SCL,$           //WAIT HIGH
        MOV     C,SDA
        RLC     A
        JB      SCL,$
        DJNZ    R4,NEXT_7BIT
        ENDM
///////////////////////////////////////////////////
//	Ack
///////////////////////////////////////////////////
RETURN_ACK      MACRO
        CLR     SDA
        JNB     SCL,$           //WAIT HIGH
        JB      SCL,$           //WAIT LOW
        SETB    SDA
        ENDM
///////////////////////////////////////////////////
//	Receive Byte
///////////////////////////////////////////////////
RECEIVE_BYTE:
        MOV     R4,#08H
NEXT_BIT:
        JNB     SCL,$           //WAIT HIGH
        MOV     C,SDA
        RLC     A
        JB      SCL,$           //WAIT LOW
        DJNZ    R4,NEXT_BIT
        RET
///////////////////////////////////////////////////
//	Slave I2C
///////////////////////////////////////////////////
SLAVE_I2C:
        MOV     IFADRL,#01H
        MOV     A,SCMD
        ANL     A,0F8H
        CJNE    A,0F0H,END_INT
        CLR     A
FIRST_BYTE:
        JB      SDA,$
        JB      SCL,$           //Wait low
        ACALL   RECEIVE_BYTE
        RETURN_ACK
        CJNE    A,#ADDR,READ    //If Rec Byte != ADDR jmp READ
//word address
        ACALL   RECEIVE_BYTE
        RETURN_ACK
        MOV     DPL,A           //save address
        MOV     R5,#16H         //Max write 16 bytes
REC_DATA:
        RECEIVE_DATA
        RETURN_ACK
        MOVX    @DPTR,A         //save a to word address
        INC     DPL
        DJNZ    R5,REC_DATA
        JMP     END_INT
READ:
        CJNE    A,#ADDR+1,END_INT     //If Rec Byte != ADDR+1 jmp END
SEND_BYTE:
        MOVX    A,@DPTR         //get data from word address
        MOV     R4,#08H
NEXT_BIT1:
        RLC     A
        MOV     SDA,C
        JNB     SCL,$           //WAIT HIGH
        JB      SCL,$           //WAIT LOW
        DJNZ    R4,NEXT_BIT1
        SETB    SDA             //Release SDA

        JNB     SCL,$           //WAIT HIGH
        JB      SDA,END_INT     //If no ack jmp END
        JB      SCL,$           //Wait Low
        INC     DPL
        JMP     SEND_BYTE       //Else send next byte
        JMP     END_INT
END_INT:
        RET
///////////////////////////////////////////////////
//
//	External Interrupt 0
//
///////////////////////////////////////////////////
EXTERNAL_INTERRUPT_0:
        ACALL   SLAVE_I2C
        RETI
///////////////////////////////////////////////////
//
//	MainLoop()
//
///////////////////////////////////////////////////
START:
        MOV     IE,#081H
        MOV     DPTR,#0000H
END_LOOP:
        SJMP    END_LOOP
    	END
