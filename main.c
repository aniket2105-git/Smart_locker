#include"header.h"
 extern char str[15];
 extern int f,flag;
 

 int main(){

 //================================   INIT  ================================
	int r,c;
	IODIR0|= buzzer|LED;
	IOSET0|= LED;
	uart_init();
	lcd_init();
//================================   INTERRUPT  ================================
	uart_int_config();
 	uart_int_enable();

	eint_config();
	eint_enble();
//================================   LCD  ================================		
	lcd_cmd(0x80);
	lcd_str("#ENTER PASSWORD#");
	lcd_cmd(0xC0);
	while(1){

//================================   PASS CHECK  ================================
	 if(f==1){
		f=0;
		r=pass_check(str);
		c=lcd_msg(r);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_str("#ENTER PASSWORD#");
		lcd_cmd(0xC0);
		if(c==3){
			goto exit;
		}
	
	 }
//================================   LOCKER BREAK  ================================	 
	 if(flag==1){
			   flag=0;
			   lcd_cmd(0x1);
			   lcd_str("LOCKER BREAK\r\n");
		   	   lcd_cmd(0x01);

			   lcd_cmd(0x80);
			   lcd_str("#ENTER PASSWORD#");
			   lcd_cmd(0xC0);
			   	
	 }
	 
	 
	}
	exit:
	 lcd_str("UNACCESSED");
	 
 }
