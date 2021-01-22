#include <stc\STC89C5xRC.H>
#include <intrins.h>
void Delay();
unsigned char code SegmentDisplay7CC[]={0x3F,0x06,0x5B,0x4F,0x66,0X6D,0X7D,0X07,0X7F,0X6F};
void main(){
	unsigned char num;
	
	
	P26=0;
	P27=0;
	P0=0xFE;
	P27=1;
	P27=0;
	
	for(num=0;num<=9||(num=0,1);num++){
	P0=SegmentDisplay7CC[num];
	P26=1;
	P26=0;
	Delay();
	}
	
}
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
