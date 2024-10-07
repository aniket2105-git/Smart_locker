#include"header.h"
int c;

int pass_check(char *p){
	char pass[]="aniket\0";
	if(strcmp(p,pass)==0){
		  return 1;
	}
	else{
		 return 0;
	}	
}

int  lcd_msg(int n){
	int i;
	if(n==1){
			for(i=0;i<3;i++){
			lcd_str("#Access Granted#");
			IOSET0=buzzer;
			IOCLR0=LED;
			ms_delay(750);
	   		IOCLR0=buzzer;
			IOSET0=LED;		
			lcd_cmd(0x01);   
			lcd_str("#Access Granted#");
			ms_delay(750);
			lcd_cmd(0x01);
			ms_delay(750);	
			}
			c=0;
	}
	 else{
		for(i=0;i<5;i++){
			lcd_cmd(0x01);
			lcd_str("#Access  Denied#");
			ms_delay(750);
			lcd_cmd(0x01);
			ms_delay(750);
			IOSET0=buzzer;
			IOCLR0=LED;
			ms_delay(750);
	   		IOCLR0=buzzer;
			IOSET0=LED;	
		}
		c++;	
	}
	return c;
}



