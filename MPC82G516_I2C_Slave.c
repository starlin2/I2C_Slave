///////////////////////////////////////////////////
//
//	FILE:       MPC82G516_I2C_Function.c
//	AUTHOR:     Neo (Hsin-Chih Lin)
//	COPYRIGHT:  (c) Megawin Technology Co., Ltd.
//	CREATED:    2007.6.6
//	PURPOSE:    Demo 2 UART Function for all speed
//
///////////////////////////////////////////////////
#define DEBUG
#include "REG_MPC82G516.H"
#ifdef DEBUG
#include "debug.h"
#endif

sbit SCL    = P3^3;
sbit SDA    = P3^2;

unsigned char bdata a;//set a is bit data
sbit MSB    = a^7;
sbit LSB    = a^0;
bit bdata NACK;
bit bdata nackFlag;
unsigned char DeviceAddress = 0xa0;
unsigned char xdata rbuf[256];

unsigned char recbyte()
{
//    unsigned char idata temp;
    unsigned char i;
	for(i=0;i<8;i++)
    {
        while(!SCL){}//Check High
        LSB = SDA;
        a = a << 1;
        while(SCL){}//Check Low
    }
    return a;
}
void Check_Start()
{
    while(SDA){}//Waiting Low
    while(SCL){}//Waiting Low
}
void Init_Interrupt()
{
    IE = 0x81;
}
void External_Interrupt() interrupt 0 using 1
{
    unsigned char addr;
    unsigned char end=1;
    unsigned char rw;
    unsigned char i;
    unsigned char page_w;

//    IE = 0x01;
//    while(SDA){}//Waiting Low
//    while(SCL){}//Waiting Low
//    Check_Start();
Receive_Control:
    i=8;
    while(i--)
    {
        while(!SCL){}//Waiting High
        LSB = SDA;
        a = a << 1;
        while(SCL){}//Waiting Low
    }
        Debug_show_msg_to_LCD(a);
        while(1){}//Waiting Low

    if((a&0xfe)==DeviceAddress)
    {
//        while(!SCL){}//Waiting High
        SDA = 0;//Return ack
//        Debug_show_msg_to_LCD(a);
    }
    else
        goto End_interrupt;
    if((a&0x01)==1)
        rw = 1;//read
    else
        rw = 0;//write
//
    if(rw)//read
    {
        while(end)
        {
            i=8;
            a = rbuf[addr];
            SDA = MSB;
            while(i--)
            {
                while(!SCL){}//Waiting High
                while(SCL)//Waiting Low
                {
                    if((LSB == 1)&&(LSB != SDA))//start
                        goto Receive_Control;
                    if((LSB == 0)&&(LSB != SDA))//stop
                        goto End_interrupt;
                }
                a = a << 1;
                SDA = MSB;
            }
            while(!SCL){}//Waiting High
            if(SDA==1)//no ack
                end = 0;//end transmit
            else
                addr++;//transmit next byte
            while(SCL){}//Waiting Low
        }
    }
    else//write
    {
        i=8;
        while(i--)
        {
            while(!SCL){}//Check High
            LSB = SDA;
            a = a << 1;
            while(SCL){}//Waiting Low
        }
        SDA = 0;//Return ack
        addr = a;
        page_w=8;
        while(page_w--)
        {
            i=8;
            while(i--)
            {
                while(!SCL){}//Check High
                LSB = SDA;
                a = a << 1;
                while(SCL)//Waiting Low
                {
                    if((LSB == 1)&&(LSB != SDA))//start
                        goto Receive_Control;
                    if((LSB == 0)&&(LSB != SDA))//stop
                        goto End_interrupt;
                }
            }
            SDA = 0;//Return ack
            rbuf[addr++]=a;
        }
    }
End_interrupt:
    SDA =1;
    SCL =1;
    IE = 0x81;
//        Debug_show_msg_to_LCD(a);
	for(i=0x20;i<0x30;i++)
        Debug_show_msg_to_LCD(rbuf[i]);
}
///////////////////////////////////////////////////
//
//	MainLoop()
//
///////////////////////////////////////////////////
void main(void)
{
//    unsigned char i;
	unsigned char numbyte=16;
//    unsigned char idata wbuf[16];
//    unsigned char idata rbuf[16];
    Init_Interrupt();
//    SDA = 1;
//    SCL = 1;
    Debug_clear_LCD();
//    I2C_Write_byte(SLAdd,i,i);
//    delay5ms();
//    rbuf[0]=I2C_Read_byte(SLAdd,i);
/*
    for(i=0;i<numbyte;i++)
        wbuf[i] = i+0x33;
    I2C_Write_nByte(SLAdd,0x40,&wbuf,numbyte);
    for(i=0;i<100;i++)
        delay5ms();
    I2C_Read_nByte(SLAdd,0x40,&rbuf,numbyte);
    for(i=0;i<16;i++)
        Debug_show_msg_to_LCD(rbuf[i]);
*/
    while(1);
}
void delay5us()
{
    unsigned int i;
//    for(i=0;i<FREQ;i++);
}
void delay5ms()
{
    unsigned int i;
    for(i=0;i<950;i++)
        delay5us();
}
void start(void)
{
    SDA = 1;
    SCL = 1;
    delay5us();
    SDA = 0;
    delay5us();
    SCL = 0;
    delay5us();
}

void stop(void)
{
    SDA = 0;
    SCL = 1;
    delay5us();
    SDA = 1;
    delay5us();
    SCL = 0;
    delay5us();
}

void ack(void)
{
    SDA = 0;
}
void n_ack(void)
{
    SDA = 1;
    SCL = 1;
    delay5us();
    SDA = 0;
    SCL = 0;
    delay5us();
}

void checkack(void)
{
    SDA = 1;
    SCL = 1;
    delay5us();
    nackFlag = 0;
    if(SDA == 1)
        nackFlag = 1;
    SCL = 0;
    delay5us();
}
void sendbyte(unsigned char idata w_data)
{
    unsigned char idata n = 8;
    while(n--)
    {
        if((w_data&0x80) ==0x80)
        {
            SDA = 1;
            SCL = 1;
            delay5us();
            SDA = 0;
            SCL = 0;
        }
        else
        {
            SDA = 0;
            SCL = 1;
            delay5us();
            SCL = 0;
        }
        delay5us();
        w_data = w_data << 1;
    }
}