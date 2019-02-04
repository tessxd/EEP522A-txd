
#include <stdio.h>
#include <wiringPi.h>


int main ()
{
    //Set up chip select to CE1
    //const int CHANNEL = 1;

    //Setup SPI
    //int setup;
    wiringPiSetup ();
    //setup = wiringPiSPISetup(CHANNEL, 500000);

    //print result of setup
    //printf("%d", setup);

    //Send SPI data in a loop
    while(1)
    {
        //write a random buffer to the PI
        wiringPiSPIDataRW(CHANNEL, 0x58, 1);

        //delay between writes
        sleep(5);
    }

    return 0;
}


