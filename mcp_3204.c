#include"header.h"

void spi_init(void){
	PINSEL0|=0x1500;
	IODIR0|=CS;
	IOSET0=CS;
	S0SPCR=0x20;
	S0SPCCR=15;

}
unsigned char spi_data(unsigned char data){
	S0SPDR =data;
	while(SPIF==0);
	return S0SPDR;
}	   
unsigned int spi_mcp3204(unsigned char ch_num){
	unsigned int res=0;
	unsigned char hByte,lByte;
	IOCLR0=CS;
	ch_num<<=6;
	spi_data(0x0);
	hByte=spi_data(ch_num);
	lByte=spi_data(0x0);
	IOSET0=CS;
	hByte&=0xF;
	res=(hByte<<8)|lByte;
	return res;


}


