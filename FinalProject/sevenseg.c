
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <time.h>

const unsigned int  zero = 0x3F;  /* 0 */
const unsigned int one = 0x06;   /* 1 */
const unsigned int two = 0x5B;   /* 2 */
const unsigned int three = 0x4F; /* 3 */
const unsigned int four = 0x66;  /* 4 */

/*	
	0x6D, /* 5 
	0x7D, /* 6 
	0x07, /* 7 
	0x7F, /* 8 
	0x6F, /* 9 
	0x77, /* a 
	0x7C, /* b 
	0x39, /* C 
	0x5E, /* d 
	0x79, /* E 
	0x71, /* F 
}; */

int main(void) {
    //chip specific constants
    const unsigned int ADDRESS = 0x70;       //i2c address
    const unsigned int BLINK_CMD = 0x80;     //blinking command
    const unsigned int DISPLAY_ON = 0x01;
	const unsigned int BLINK_OFF = 0x00;
    const unsigned int SETUP = 0x20;
	const unsigned int BRIGHT = 0xEF;
	const unsigned int OSCILL = 0x01;  

	//initialize display 
	int fd;
	fd = wiringPiI2CSetup(ADDRESS);

	//write setup
	wiringPiI2CWrite(fd, SETUP | OSCILL);
	//set blink 
	wiringPiI2CWrite(fd, BLINK_CMD | BLINK_OFF | DISPLAY_ON);
	//set brightness to max (0-15)
	wiringPiI2CWrite(fd, BRIGHT);


	while (1) {
		//TODO: read in and save sensor data

		//clear display buffer
		unsigned int buffer[16];  
		for (int i = 0; i < 16; i++)
		{
			buffer[i] = 0x00;
		} 

		//set digit 0
		buffer[0] = one & 0xFF; 

		//set digit 1 

		//set digit 2
		//int offset = 1;

		//set digit 3

		//write to display
		wiringPiI2CWrite(fd, buffer[0]);

		//delay
		delay(100);
	}
    
}

///ADD ASSERT STATEMENTS YA GOON
