#include"header.h"
void uart_init(void){
   PINSEL0|=0x5;
   U0LCR=0x83;
   U0DLL=97;
   U0DLM=0;
   U0LCR=0x3;
}
   void uart_str(char *p){
	while(*p){
		U0THR=*p;
		while(THRE==0);	
		 p++;
	}
}


