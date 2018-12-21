#include<reg51.h>
#include<string.h>
#include"delay.h"
#include"lcd8bit.h"
#include"uart.h"
#include"i2c.h"
#include"i2c_device.h"
#include"i2c_eeprom.h"
#include"bal.h"
unsigned char buf[11],i=0,buf1[11],buf2[11],k=0,l=0;


void uart_hndlr(void) interrupt 4
{
if(RI==1)
{
RI=0;//imp
buf[i++]=SBUF;
}
if(TI==1)
{
TI=0;//imp
}
}

main()
{	
 uart_init(9600);
	 ES=EA=1;//uart intr enab
	 i2c_eeprom();
	 lcd_init();
	lcd_string("RFID_BASED_TP");
     
	
	
	while(1)
	{
	 for(k=0;k<10;)
	 buf1[k++]=i2c_device_read(0xA0,k);
	 buf1[k]='\0';
	 l=0;

	 for(l=0;l<10;)
	 buf2[l++]=i2c_device_read(0xA2,l);
	   buf2[l]='\0';
	//   lcd_cmd(0x01);
	//	lcd_cmd(0x80);
	 //  lcd_string(buf1);
	 //  lcd_cmd(0xc0);
	//   lcd_string(buf2);
/*	  
  	if(i==10)
	{
     buf[i]='\0';
	lcd_cmd(0x1);
	lcd_string(buf);
	
	/*for(k=0;k<9;k++)
			vv[k]=buf[k+1];
		
		vv[k]='\0';
		lcd_cmd(0x1);
		lcd_string(vv);
	*/	
					if(strcmp(buf,buf1)==0)
					{
					lcd_cmd(0xc0);
					lcd_string("RFID1 Match");
					delay_ms(3000);
					baluser1();	 
					}
						else if(strcmp(buf,buf2)==0)
						{
						lcd_cmd(0xc0);
						lcd_string("RFID2 Match");
						delay_ms(3000);
						baluser2();
						}
							else																							  
							{
							lcd_cmd(0xc0);
							lcd_string("RFID Not Match");
							}  

i=0;	 
}
}