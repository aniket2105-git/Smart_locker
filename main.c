#include"header.h"
 extern char str[15];
 extern int f,flag;
 

 int main(){

 //================================   INIT  ================================
	int r,c=0,n=0;
	IODIR0|= buzzer|LED;
	IOSET0|= LED;
	uart_init();
	lcd_init();
	spi_init();
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
		if(c<2){
			lcd_clr();
		}
		if(c==2){
		
			lcd_str("LAST CHANCE");

		}
		if(c==3){
			c=0;
			goto exit;
		}
			lcd_clr();
	 }
//================================   LOCKER BREAK  ================================	 
	 if(flag==1){
			   flag=0;
			   while(flag==0){
				   	n=spi_mcp3204(2);
					buzzer_on(n);
				}			   	
	 } 
	}
	exit:
		loc_block();
	 
 }
