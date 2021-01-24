#include "GtxTX1C.h"

uint8c SegmentDisplay7CC[]={0x3F,0x06,0x5B,0x4F,0x66,0X6D,0X7D,0X07,0X7F,0X6F};
 
void Delay()		//@11.0592MHz
{//1s
	unsigned char i, j, k;
	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
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