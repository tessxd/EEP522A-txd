#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main (void)
{
    //set up libraries
    wiringPiSetup();
    //set pin as input
    pinMode(22, INPUT);
    //read in value
    int value = digitalRead(22);
    //print to console to ensure it's working
    printf("%d", value);
}