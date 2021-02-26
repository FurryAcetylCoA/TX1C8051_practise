#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"


void main(){

	
		
	Latch573(kSEG_WLE,0xFF^(1<<4));
	_nop_();
	Latch573(kSEG_DLE,SegmentDisplay7CC[2]);
		SingleSegDisplay(3,4);
//Delay();


}
