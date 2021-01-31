#include <stc\STC89C5xRC.H>
#include <intrins.h>
#include "GtxTX1C.h"



void main(){//行在低四位 列在高四位
	uint8 gundong=0xEE;//1110 1110
	uint8 read1,read2;
	uint32 keyCode=5; //keyCode对应的是丝印上的   5是dummyCode 不代表五号键
	uint8 i;
do{
	for(i=0;i<4||(i=0,keyCode=5);i++){
  P3=gundong|0x0F; //为了读取行 低四位需为1
	read1=P3; //先读取低四位行线
	Delay10ms();
	read2=P3;//抖动消除
	if(read1==read2)
	{
		switch(read2|0xF0)//高四位掩1 对低四位进行判断
		{
			case 0xF7 : keyCode+=4;		 // 0111
		  case 0xFB : keyCode+=4;
	  	case 0xFD : keyCode+=4;
	   	case 0xFE : keyCode+=i+1;// 1110
		}
		//	while(P3|0xF0!=0xFF);//等待按键抬起//鉴于数码管是扫描显示的 这里注释掉了
	}	
	if(keyCode!=5){
		SegDisplay(keyCode);
	}
	gundong=_crol_(gundong,1);
	}
}while(1);	
}
