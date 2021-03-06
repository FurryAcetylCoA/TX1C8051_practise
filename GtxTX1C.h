/*--------------------------------------------------------------------------
GtxTX1C.h

与天翔电子GTX-1C相关的头文件

2021 AcetylCoA
--------------------------------------------------------------------------*/
#ifndef __GtxTX1C_h__
#define __GtxTX1C_h__

#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "Bin2Hex\BintoHex.h"


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
#define true          1
#define false         0


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
		kSEG_WLE = b10000000,
		kSEG_DLE = b01000000,
		kLED_LE  = b00100000,
		kALL_LE  = b11100000
};

enum Lcd1602CmdEnum{
	    cCls          = b00000001, //1.5ms
		cCR           = b00000011, //37us 
	    cEntryModeSet = b00000111,
	    cDisplayOnOff = b00001111,
	    cScreenShift  = b00011111, //向左\右 移动整个屏幕\光标
	    cFunctionSet  = b00111111, //基本配置 需要先设置本条
	    cCGRAMAddSet  = b01111111,
	    cDDRAMAddSet  = b11111111    
};

enum Lcd1602CmdFlagsEnum{
	// flags for display entry mode set
		caEmsEntryRight   = b00000010,
	    caEmsEntryLeft    = b00000000,
	    caEmsShiftEnable  = b00000001,//Shifts the entire display
		caEmsShiftDisable = b00000000,
	// flags for display on/off control
		caDooScreenOn     = b00000100,
	    caDooScreenOff    = b00000000,
		caDooCursorOn     = b00000010,
		caDooCursorOff    = b00000000,
		caDooCurBlinkOn   = b00000001,
	    caDooCurBlinkOff  = b00000000,
		caSsShiftDisplay  = b00001000,
		caSsMoveCursor    = b00000000,
		caSsShiftRight    = b00000100,
		caSsShiftLeft     = b00000000,
	// flags for function set
		caFs8BitMode      = b00010000,
		caFs4BitMode      = b00000000,
	    caFs2Line         = b00001000,
	    caFs1Line         = b00000000,
		caFs5x10Dots      = b00000100,
		caFs5x8Dots       = b00000000
	    
	    
};
#endif // _USING_TX1C_CUSTOM_CONSTS_


#ifdef _USING_TX1C_CUSTOM_FUNCTIONS_
//工具函数

void SingleSegDisplay(uint8 which,uint8 num);//控制某一个数码管(0-5),显示数字
void SegDisplay(uint32 num);         		 //控制数码管显示数字
void Delay992us();							 //延时一个奇怪的时间，供delay函数使用				
void Delay(uint16 ms);						 //延时
void Latch573(enum LatchSelectEnum which,uint8 aData);            //控制板子上的三个锁存器
void Lcd1602Cmd(uint8 Cmd);				     //向1602发送指令
void Lcd1602Data(uint8 aData);				 //向1602发送数据

#endif //_USING_TX1C_CUSTOM_FUNCTIONS_
	
#endif //__GtxTX1C_h__