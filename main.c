#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"

uint32 counter;
void initCounter0();

void main(){
	counter=0;
	initCounter0();
do{
	SegDisplay(counter);
	if(RD==0){
		TR0=1;
	}
	if(WR==0){
		TR0=0;
	}	
}while(1);	
}
//@11.0592MHz 12clock=1085ns
void initCounter0(){//10ms
	TR0=0;
	
	TMOD=0x01;
	
	EA=1;
	ET0=1;
	
	TH0=(56320)/256;
	TL0=(56320)%256;
}
void int_Counter0 () interrupt 1{
	TH0=(56320)/256;
	TL0=(56320)%256;
	
	counter++;
	if(counter>=100000){
		counter=0;
	}
}