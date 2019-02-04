#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

int main ()
{
    //device ID from i2cdetect
    const int devID = 0x02;

    //Setup i2cdetect
    int fd;
    fd = wiringPiI2CSetup(devID);

    //Write out data
    while(1)
    {
        //int result;
        wiringPiI2CWrite(fd, 0xff);

        delay(100);

        printf("writing data");
        printf("\n");
    }
    
}
