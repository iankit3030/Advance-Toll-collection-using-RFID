void uart_init(int baud)
{
SCON=0x50;
TMOD=0x20;
switch(baud)
{

case 9600:TH1=253;break;

}
TR1=1;
}

void uart_tx(unsigned char ch)
{
SBUF=ch;
while(TI==0);
TI=0;
}

unsigned char uart_rx()
{
while(RI==0);
RI=0;
return SBUF;
}

void uart_string(char *s)
{
while(*s)
	uart_tx(*s++);
} 