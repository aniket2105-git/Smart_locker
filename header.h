#include <LPC21xx.H>

#define buzzer (1<<21)

#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)

//================================ Delay ================================

void ms_delay(unsigned int ms);
void sec_delay(unsigned int sec);

//================================ LCD ================================

#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19) 

void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_str(char *p);

//================================ UART ================================

#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

void uart_init(void);
void uart_str(char *p);

//================================ UART INTERRUPT  ================================

 void uart_int_config(void);
 void uart_int_enable(void);

//================================ SPI ================================

#define CS (1<<7)
#define SPIF ((S0SPSR>>7)&1)

void spi_init(void);
unsigned char spi_data(unsigned char);
unsigned int spi_mcp3204(unsigned char);



