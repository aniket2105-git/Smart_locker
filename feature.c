#include"header.h"

void pass_check(char *p){
	int i;
	char pass[]="aniket\0";
	lcd_cmd(0xC0);
	lcd_str("                ");
	if(strcmp(p,pass)==0){
		IOCLR0=buzzer;
		sec_delay(1);
		IOSET0=buzzer;
		for(i=0;i<3;i++){
			lcd_str("Access Granted");
			sec_delay(1);
			lcd_str("                ");
			sec_delay(1);	
		}
	}
	else{
		for(i=0;i<3;i++){
			IOCLR0=buzzer;
			sec_delay(1);
			IOSET0=buzzer;
			for(i=0;i<3;i++){
				lcd_str("Access Denied");
				sec_delay(1);
				lcd_str("                ");
				sec_delay(1);
			}
		}
	}
	
}





