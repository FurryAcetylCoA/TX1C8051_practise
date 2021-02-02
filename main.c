#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"

uint32 counter;
void initCounter2();

void main(){
	counter=0;
	initCounter2();
do{
	SegDisplay(counter);
	if(RD==0){
		TR2=1;
	}
	if(WR==0){
		TR2=0;
	}	
}while(1);	
}
//@11.0592MHz 12clock=1085ns
void initCounter2(){//10ms
	TR2=0;
	
	C_T2=C_T2&0xC0;
	
	EA=1;
	ET2=1;
	
	RCAP2H=TH2=(56320)/256;
	RCAP2L=TL2=(56320)%256;
}
void int_Counter2 () interrupt 5{
	TF2=0;
	
	counter++;
	if(counter>=100000){
		counter=0;
	}
}