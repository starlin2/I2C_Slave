/*** Functions used by other modules ***/

/*
For Keil C51, #include "debug.h", then the following functions can be used:

;(Note: see the following description)

  (1) Debug_clear_LCD(); //(No return value)

  (2) Debug_show_msg_to_LCD(unsigned char msg); //(No return value)

  (3) Debug_show_msg_to_7seg(unsigned char msg); //(No return value)

  (4) Debug_set_breakpoint(unsigned char BP_number); //(No return value)

  (5) Debug_show_msg_to_PC(unsigned char msg); //(No return value)

  (6) arg=Debug_get_argument_from_PC(); //return value: unsigned char arg


Description:

(1) Clear the LCD display of the Debug Tool

(2) Show a message on the LCD display of the Debug Tool

(3) Show a message on the 7-segment display of the Debug Tool

(4) Set a breakpoint in the application code, and pressing the "GO-key"
    on the Debug Tool to let the application code continue to go

(5) Show a message to PC

(6) Get one byte data from PC, to be used in the application code

*/


//Prototype definition

extern void dbg_clear_LCD(void);
extern void dbg_show_msg_to_LCD(unsigned char msg);
extern void dbg_show_msg_to_7seg(unsigned char msg);
extern void dbg_set_breakpoint(unsigned char BP_number);
extern void dbg_show_msg_to_PC(unsigned char msg);
extern unsigned char dbg_get_argument_from_PC();


//Mnemonic definition

#define Debug_clear_LCD            dbg_clear_LCD
#define Debug_show_msg_to_LCD      dbg_show_msg_to_LCD
#define Debug_show_msg_to_7seg     dbg_show_msg_to_7seg
#define Debug_set_breakpoint       dbg_set_breakpoint
#define Debug_show_msg_to_PC       dbg_show_msg_to_PC
#define Debug_get_argument_from_PC dbg_get_argument_from_PC

