sfr lcd=0x80;
sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;

void lcd_cmd(unsigned char c)
{
lcd=c;
rs=0;
rw=0;
en=1;
delay_ms(2);
en=0;
}

void lcd_data(unsigned char d)
{
lcd=d;
rs=1;
rw=0;
en=1;
delay_ms(2);
en=0;
}

void lcd_init()
{
lcd_cmd(0x02);//set cursor at home position
lcd_cmd(0x38);//8bit initialization
lcd_cmd(0x6);//right shift
lcd_cmd(0xE);//cursor on
lcd_cmd(0x1);//clr lcd
}


void lcd_string(char *s)
{
while(*s)
lcd_data(*s++);
}


void lcd_integer( long int i)
{
 long int num;
  int k=0,r=0;
	 char a[40];
 num=i;
 if(num<0)
 {
 lcd_data('-');
 num=-num;
 }
 if(num==0)
 {
 lcd_data('0');
	return;
}
 while(num)
 {
	r=num%10;
 a[k++]=r+48;
 num=num/10;
 }
 while(k--)
 lcd_data(a[k]);
 
 }
