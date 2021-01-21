#include <stc\STC89C5xRC.H>
#include <intrins.h>
void Delay100ms();
void main(){
	unsigned char tP0=0xFC;
	//P26=0;
	do{
		P1=tP0;
	  Delay100ms();
		tP0=_crol_(tP0,1);
	}while(1);
	
}
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 10;
	do
	{
		while (--j);
	} while (--i);
}
