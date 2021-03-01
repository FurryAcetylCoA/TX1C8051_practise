/*--------------------------------------------------------------------------
GtxTX1C.h

与天翔电子GTX-1C相关的头文件

2021 AcetylCoA
--------------------------------------------------------------------------*/
#ifndef __GtxTX1C_h__
#define __GtxTX1C_h__

#include <stc\STC89C5xRC.H>
#include <intrins.h>



#define _DEPENDANCY_OF_TX1C_C_FILE_ //注释此宏后 本头文件将不再依赖GtxTX1C.c



#ifdef _DEPENDANCY_OF_TX1C_C_FILE_  //提高可迁移性
#define _USING_TX1C_CUSTOM_FUNCTIONS_ 
#define _USING_TX1C_CUSTOM_CONSTS_ 
#endif // _DEPENDANCY_OF_TX1C_C_FILE_

//基础8051类型别名

typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;

typedef uint8  code   uint8c;
typedef uint16 code   uint16c;
typedef uint32 code   uint32c;

typedef signed char   int8;
typedef signed int    int16;
typedef signed long   int32;

typedef bit           bool;
#define true          1;
#define false         0;


//管脚
sbit DB0 = P1^0;
sbit DB1 = P1^1;
sbit DB2 = P1^2;
sbit DB3 = P1^3;
sbit DB4 = P1^4;
sbit DB5 = P1^5;
sbit DB6 = P1^6;
sbit DB7 = P1^7;

sbit D0  = P0^0;
sbit D1  = P0^1;
sbit D2  = P0^2;
sbit D3  = P0^3;
sbit D4  = P0^4;
sbit D5  = P0^5;
sbit D6  = P0^6;
sbit D7  = P0^7;

sbit DAC_CS = P3^2;

sbit LCD_EN = P3^4;
sbit LCD_RS = P3^5;


sbit SEG_WLE  = P2^7;
sbit SEG_DLE  = P2^6;
sbit LED_LE   = P2^5;

sbit BUZZER   = P2^3;
sbit DS18B20  = P2^2;
sbit C02_SCL  = P2^1;
sbit C02_SDA  = P2^0;

#ifdef _USING_TX1C_CUSTOM_CONSTS_
//码表
extern uint8c SegmentDisplay7CC[10];

enum LatchSelectEnum{
		kSEG_DLE=0x80,
		kSEG_WLE=0x40,
		kLED_LE=0x20
};
#endif // _USING_TX1C_CUSTOM_CONSTS_


#ifdef _USING_TX1C_CUSTOM_FUNCTIONS_
//工具函数

void SingleSegDisplay(uint8 which,uint8 num);//控制某一个数码管(0-5),显示数字
void SegDisplay(uint32 num);         //控制数码管显示数字
void Delay10ms();
void Delay();
void Latch573(enum LatchSelectEnum which,uint8 aData);            //控制板子上的三个锁存器

#endif //_USING_TX1C_CUSTOM_FUNCTIONS_
	
#endif //__GtxTX1C_h__