#include"header.h"
char str[15];
int i,f;
void uart_str_handler()__irq{
	int r;
	r=((U0IIR>>1)&0x7);
	if(r==2){
		while(RDR==0);
	   str[i]=U0RBR;
	   U0THR='*';
	   if(str[i]=='\r'){
	   		  f=1;
	   		  str[i]='\0';
			  i=-1;
	   }
	   i++;
	}
	VICVectAddr=0;
}

void uart_int_config(void){
 VICIntSelect=0;
 VICVectAddr0|=(unsigned int)uart_str_handler;
 VICVectCntl0=6|(1<<5);
 VICIntEnable|=(1<<6);

}
 void uart_int_enable(void){
   U0IER=0x3;
 }



