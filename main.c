#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"

void LCD_Init();
void main(){

	P2=P2&(~kALL_LE);//½ûÓÃËùÓÐËø´æÆ÷
	Delay(1);
	
	Lcd1602Cmd(cFunctionSet,cfFs8BitMode|cfFs2Line|cfFs5x8Dots);
	Lcd1602Cmd(cDisplayOnOff,cfDooScreenOn|cfDooCursorOff|cfDooCurBlinkOff);
	
	Delay(100);
	Lcd1602Data('a');
	while(true);
}
void LCD_Init(){

	
}