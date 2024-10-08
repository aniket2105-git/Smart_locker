#include"header.h"

void lcd_data(unsigned char data){
//================================ HIGHER ================================
	IOCLR1=0xFE<<16;
	IOSET1=(data&0xF0)<<16;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	ms_delay(2);
	IOCLR1=EN;

//================================ LOWER ================================

	IOCLR1=0xFE<<16;
	IOSET1=(data&0x0F)<<20;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	ms_delay(2);
	IOCLR1=EN;
}
void lcd_cmd(unsigned char data){
  //================================ HIGHER ================================
	IOCLR1=0xFE<<16;
	IOSET1=(data&0xF0)<<16;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	ms_delay(2);
	IOCLR1=EN;

//================================ LOWER ================================

	IOCLR1=0xFE<<16;
	IOSET1=(data&0x0F)<<20;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	ms_delay(2);
	IOCLR1=EN;
}
void lcd_init(void){
  IODIR1|=0xFE<<16;
  PINSEL2=0x0;
   lcd_cmd(0x03);
   lcd_cmd(0x02);
   lcd_cmd(0x0E);
   lcd_cmd(0x28);
}

void lcd_str(char *p){
	while(*p){
	 lcd_data(*p);	
	 p++;
	}
}

void lcd_int(int n){
	char a[20];
	int i=0;
	if(n==0){
		lcd_data('0');   	
		return;
	}
	if(n<0){
	 lcd_data('-');
	 n=-n;
	}
	while(n>0){
	 a[i++]=n%10+48;
	 n/=10;
	}
	for(i--;i>=0;i--){
	   lcd_data(a[i]);
	}

}



