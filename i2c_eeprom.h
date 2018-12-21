unsigned char rf[]="0123456789",j=0,rf1[]="9876543210";

void i2c_eeprom()
{
  for(j=0;rf[j];j++)
  i2c_device_write(0xA0,j,rf[j]);

 for(j=0;rf1[j];j++)
  i2c_device_write(0xA2,j,rf1[j]);

}