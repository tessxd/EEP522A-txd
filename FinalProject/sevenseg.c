
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "sevenseg.h"
#include <time.h>

const uint8_t zero = 0x3F;  /* 0 */
const uint8_t one = 0x06;   /* 1 */
const uint8_t two = 0x5B;   /* 2 */
const uint8_t three = 0x4F; /* 3 */
const uint8_t four = 0x66;  /* 4 */

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
    const uint8_t ADDRESS = 0x70;       //i2c address
    const uint8_t BLINK_CMD = 0x80;     //blinking command
    const uint8_t BLINK_ON = 0x01;
	const uint8_t BLINK_OFF = 0x00;
    const uint8_t SETUP = 0x20;
	const uint8_t BRIGHT = 0xE0;
	const uint8_t OSCILL = 0x01;  

	//initialize display 
	int fd;
	fd = wiringPiI2CSetup(ADDRESS);

	//write setup
	wiringPiI2CWrite(fd, SETUP | OSCILL);
	//set blink 
	wiringPiI2CWrite(fd, BLINK_OFF);
	//set brightness to max (0-15)
	wiringPiI2CWrite(fd, BRIGHT | 15);


	while (true) {
		//TODO: read in and save sensor data

		//clear display buffer
		uint16_t buffer[16];  
		for (i = 0; i < 16; i++)
		{
			buffer[i] = 0;
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
		time.sleep(0.25);
	}
    
}

///ADD ASSERT STATEMENTS YA GOON