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



