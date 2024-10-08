#include"header.h"
void uart_init(void){
   PINSEL0|=0x5;
   U0LCR=0x83;
   U0DLL=97;
   U0DLM=0;
   U0LCR=0x3;
}	
void uart_data(char data){
 	U0THR=data;
		while(THRE==0);

}
   void uart_str(char *p){
	while(*p){
		U0THR=*p;
		while(THRE==0);	
		 p++;
	}
}

 void uart_int(int n){
	char a[20];
	int i=0;
	if(n==0){
		uart_data('0');   	
		return;
	}
	if(n<0){
	 uart_data('-');
	 n=-n;
	}
	while(n>0){
	 a[i++]=n%10+48;
	 n/=10;
	}
	for(i--;i>=0;i--){
	   uart_data(a[i]);
	}

}

