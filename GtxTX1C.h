/*--------------------------------------------------------------------------
GtxTX1C.h

与天翔电子GTX-1C相关的头文件

2021 AcetylCoA
--------------------------------------------------------------------------*/

#include <stc\STC89C5xRC.H>
#include <intrins.h>


#ifndef __GtxTX1C_h__
#define __GtxTX1C_h__
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


//码表
extern uint8c SegmentDisplay7CC[10];

//工具函数

void SingleSegDisplay(uint8 which,uint8 num);//控制某一个数码管(0-5),显示数字
void SegDisplay(uint32 num);         //控制数码管显示数字

#endif //__GtxTX1C_h__