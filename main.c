#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"



void main(){
	uint8 cod=0;
do{
    if(LCD_EN==0){
			Delay10ms();
		  if(LCD_EN==0){
				SegDisplay(++cod);
				while(LCD_EN==0);
			}
		}
	
	}while(1);	
}
