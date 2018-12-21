#include"dcmotor.h"

void baluser1()
{
			 static int g=1000;
			 lcd_cmd(0x1);
			 lcd_cmd(0x80);
			 lcd_string("Prev.Bal:");
			 lcd_integer(g);
			 g=g-50;
			 lcd_cmd(0xc0);
			 lcd_string("Curr.Bal:");
			 lcd_integer(g);
	delay_ms(3000);
			 if(g!=0)
			  dcmotor();
			  else
			  {
			   lcd_cmd(0x1);
			   lcd_string("Bal.Not Avl");
			  return;
			  }

}

void baluser2()
{
			 static int g=100;
			 lcd_cmd(0x1);
			 lcd_cmd(0x80);
			 lcd_string("Prev.Bal:");
			 lcd_integer(g);
			 g=g-50;
			 lcd_cmd(0xc0);
			 lcd_string("Curr.Bal:");
			 lcd_integer(g);
	delay_ms(3000);
			 if(g!=0)
			  dcmotor();
			  else
			  {
			   lcd_cmd(0x1);
			   lcd_string("Bal.Not Avl");
			  return;
			  }

}