#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"


void main(){


	Latch573(kSEG_WLE,0xFF^(1<<4));

	Latch573(kSEG_DLE,SegmentDisplay7CC[2]);

	while(1){}
}
