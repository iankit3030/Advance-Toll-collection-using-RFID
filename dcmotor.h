
sbit clk=P1^0;
sbit anticlk=P1^1;
void dcmotor()
{
	clk=anticlk=0;
 lcd_init();
clk=1;
lcd_cmd(0x1);
lcd_string("clkwise");
	
	delay_ms(4000);
clk=0;
	
		delay_ms(4000);
anticlk=1;
lcd_cmd(0x1);
lcd_string("Anticlk");
delay_ms(4000);
	anticlk=0;
}
