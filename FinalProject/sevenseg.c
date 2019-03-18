
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <time.h>

const unsigned int  zero = 0x3F;  /* 0 */
const unsigned int one = 0x06;    /* 1 */
const unsigned int two = 0x5B;    /* 2 */
const unsigned int three = 0x4F;  /* 3 */
const unsigned int four = 0x66;   /* 4 */

int main(void) {
    //chip specific constants
    const unsigned int ADDRESS = 0x70;       //i2c address
    const unsigned int BLINK_CMD = 0x80;     //blinking command
    const unsigned int DISPLAY_ON = 0x01;
	const unsigned int BLINK_OFF = 0x00;
    const unsigned int SETUP = 0x20;
	const unsigned int BRIGHT = 0xEF;
	const unsigned int OSCILL = 0x01;  

	//return code
	int returnCode = 0;

	//initialize gpio input
    returnCode = wiringPiSetup();
	assert(returnCode != 0);

    //set pin as input
    pinMode(22, INPUT);

	//initialize display 
	int fd;
	fd = wiringPiI2CSetup(ADDRESS);
	assert(fd == -1);

	//write setup
	returnCode = wiringPiI2CWrite(fd, 0x21);
	assert(returnCode < 0);

	//set blink 
	returnCode = wiringPiI2CWrite(fd, 0x81);
	assert(returnCode < 0);

	//set brightness to max (0-15)
	returnCode = wiringPiI2CWrite(fd, 0xEF);
	assert(returnCode < 0);

	printf("initialized moisture sensor and display");

	while (1) {
    	//read in moisture sensor value
    	int sensor_data = digitalRead(22);
		//Check sensor_data is 0 or 1
		assert(sensor_data < 0);
		assert(sensor_data > 1);
    	
		//print to console to ensure it's working
    	printf("%d", sensor_data);
		printf(" \n");

		//clear display buffers
		unsigned int buffer_wet[16];  
		for (int i = 0; i < 16; i++)
		{
			buffer_wet[i] = 0x00;
		} 

		unsigned int buffer_dry[16];  
		for (int i = 0; i < 16; i++)
		{
			buffer_dry[i] = 0x00;
		}

		//set digits to 1 for wet
		buffer_wet[0] = 0x06;
		buffer_wet[2] = 0x06;
		buffer_wet[6] = 0x06;
		buffer_wet[8] = 0x06;		

		//set digits to 0 for dry 
		buffer_dry[0] = 0x3F;
		buffer_dry[2] = 0x3F;
		buffer_dry[6] = 0x3F;
		buffer_dry[8] = 0x3F;	

		//write to display
		for (int i = 0; i < 16; i++)
		{
			if (sensor_data == 1)
			{
				returnCode = wiringPiI2CWriteReg8(fd,i, buffer_wet[i]);
				assert(returnCode < 0);
			}
			else if (sensor_data == 0)
			{
				returnCode = wiringPiI2CWriteReg8(fd,i, buffer_dry[i]);
				assert(returnCode < 0);
			}
			
		}
		
		printf("writing to display");
		printf("\n");

		//delay
		delay(100);
	}
    
}

