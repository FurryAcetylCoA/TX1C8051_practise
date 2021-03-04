#include "GtxTX1C.h"


uint8c SegmentDisplay7CC[]={0x3F,0x06,0x5B,0x4F,0x66,0X6D,0X7D,0X07,0X7F,0X6F};


void Delay(uint16 ms){//@11.0592MHz
	while(ms--){
		Delay992us();
	}
}

void Delay992us(){ //函数跳转和Delay函数中的自减需要8ns 所以这里用延迟992us实现延迟1ms

	unsigned char i, j;

	_nop_();
	i = 2;
	j = 196;
	do
	{
		while (--j);
	} while (--i);
}

void SingleSegDisplay(uint8 which,uint8 num){
	P26=0;
	P27=0;
	P0=0xFF^(1<<which);
	P27=1;
	P27=0;
	P0=SegmentDisplay7CC[num];
	P26=1;
	P26=0;
}

void SegDisplay(uint32 num){	//控制数码管显示数字,右对齐
	uint8 ii=5;	
	do{
		SingleSegDisplay(ii,num%10);
		num=num/10;
	}while(num!=0&&ii--!=0);	
}

void Latch573(enum LatchSelectEnum which,uint8 aData){   //控制锁存器
	P2=P2&(~kALL_LE);//禁用所有锁存器
	if(which!=kLED_LE){ //LED_LE位于P1总线，而其他锁存器位于P0总线
		P0=aData;		 
	}
	else{
		P1=aData;
	}
	P2=P2|which;	 //使能对应的锁存器
	P2=P2^which;
}


