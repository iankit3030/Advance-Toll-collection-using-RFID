sbit sda=P2^0;
sbit scl=P2^1;

void i2c_start()
{
scl=1;
	sda=1;
	sda=0;
}

void i2c_stop()
{
scl=0;
	sda=0;
	scl=1;
	sda=1;
}


void i2c_write(unsigned char d)
{
signed char i;//if unsigned char is used then infinite loop
	for(i=7;i>=0;i--)
	{
scl=0;
	sda=(d&(1<<i))?1:0;
scl=1;		
}
}

unsigned char i2c_read()
{
signed char i;
	unsigned char temp=0;
	for(i=7;i>=0;i--)
	{
scl=1;
		if(sda==1)
			temp|=1<<i;
		scl=0;
}
return temp;
}

void i2c_ack()
{
scl=0;
	sda=1;
	scl=1;//9th clkpulse/ACK clkpulse
	while(sda==1);
	scl=0;
		
}


void i2c_noack()
{
	//scl=0;
sda=1;
	scl=1;//ACK clkpulse/9th clkpulse
}