#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include <stdio.h>
#include "GtxTX1C.h"


void main(){

	P2=P2&(~kALL_LE);//½ûÓÃËùÓÐËø´æÆ÷
	Delay(1);
	
	Lcd1602Cmd(cFunctionSet,cfFs8BitMode|cfFs2Line|cfFs5x8Dots);
	Lcd1602Cmd(cDisplayOnOff,cfDooScreenOn|cfDooCursorOff|cfDooCurBlinkOn);
	printf("Hi %u",14u);
	//Lcd1602Data('a');
	while(true);
}
