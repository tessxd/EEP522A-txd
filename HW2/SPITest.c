
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <linux/spi/spidev.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

int main ()
{
    //Set up chip select to CE0
    const int CHANNEL = 0;
	
	//Set up buffer
	unsigned char buf[100];
	buf[0] = 0xff;
	buf[1] = 0xff;

    //Setup SPI
    int setup;
    setup = wiringPiSPISetup(CHANNEL, 8000000);
    //wiringPiSetup ();

    //print result of setup
    printf("%d", setup);

    //Send SPI data in a loop
    while(1)
    {
        //write a random buffer to the PI
        wiringPiSPIDataRW(0, buf, 1);

        //delay between writes
        delay(100);
        
        //print a confirmation
        printf("writing data");
        printf("\n");
    }

    return 0;
}


