;*** Functions used by other modules ***

;For Keil A51, $INCLUDE (debug.inc), then the following MACROs can be used:
;
;(Note: ??? means the argument passed to MACRO, see the following definition)
;
;    (1) Debug_clear_LCD
;
;    (2) Debug_show_msg_to_LCD ???
;
;    (3) Debug_show_msg_to_7seg ???
;
;    (4) Debug_set_breakpoint ???
;
;    (5) Debug_show_msg_to_PC ???
;
;    (6) Debug_get_argument_from_PC ???


;MACROs definition:

;(1)---------------------------------------------------------------------------
;Function: Clear the LCD display of the Debugger
;Argument: (N/A)

Debug_clear_LCD MACRO
         CALL   dbg_clear_LCD
         ENDM

;(2)---------------------------------------------------------------------------
;Function: Show a message on the LCD display of the Debugger
;Argument: msg, which is to be shown on the LCD display

Debug_show_msg_to_LCD MACRO msg
         MOV    R7,msg
         CALL   _dbg_show_msg_to_LCD
         ENDM

;(3)---------------------------------------------------------------------------
;Function: Show a message on the 7-segment display of the Debugger
;Argument: msg, which is to be shown on the 7-segment display

Debug_show_msg_to_7seg MACRO msg
         MOV    R7,msg
         CALL   _dbg_show_msg_to_7seg
         ENDM

;(4)---------------------------------------------------------------------------
;Function: Set a breakpoint in the application code, and pressing the "GO-key"
;          on the Debugger to let the application code continue to go
;Argument: BP_no, which is the breakpoint number to be shown on the 7-segment

Debug_set_breakpoint MACRO BP_no
         MOV    R7,BP_no
         CALL   _dbg_set_breakpoint
         ENDM

;(5)---------------------------------------------------------------------------
;Function: Show a message to PC
;Argument: msg, which is to be shown on PC

Debug_show_msg_to_PC MACRO msg
         MOV    R7,msg
         CALL   _dbg_show_msg_to_PC
         ENDM

;(6)---------------------------------------------------------------------------
;Function: Get one byte data from PC, to be used in the application code
;Argement: arg, which is the destination of the data from PC

Debug_get_argument_from_PC MACRO arg
         CALL   dbg_get_argument_from_PC
         MOV    arg,R7
         ENDM

;------------------------------------------------------------------------------


EXTRN    CODE   (dbg_clear_LCD)
EXTRN    CODE   (_dbg_show_msg_to_LCD)
EXTRN    CODE   (_dbg_show_msg_to_7seg)
EXTRN    CODE   (_dbg_set_breakpoint)
EXTRN    CODE   (_dbg_show_msg_to_PC)
EXTRN    CODE   (dbg_get_argument_from_PC)

