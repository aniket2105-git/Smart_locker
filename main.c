#include"header.h"
 extern char str[15];
 extern int f;
 int c;
 int main(){
	
	uart_init();
	uart_int_config();
 	uart_int_enable();
	while(1){
	 c++;
	 if(f==1){
		f=0;
		uart_str(str);
		uart_str("\r\n");
	 }
	}
 }
