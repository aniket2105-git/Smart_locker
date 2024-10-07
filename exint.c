#include"header.h"
  int flag;
 void sw_eint_handler()__irq{
			 flag=1;
			 EXTINT=1;
			 VICVectAddr=0;
			 
 }
 void eint_config(void){
 
  VICIntSelect=0;
  VICVectAddr1=(unsigned int )sw_eint_handler;
  VICVectCntl1=14|(1<<5);
  VICIntEnable|=(1<<14);


 }
 void eint_enble(){
    PINSEL1|=1;
  EXTPOLAR=0;
  EXTMODE=1;
 }







