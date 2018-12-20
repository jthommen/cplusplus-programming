#include<iostream>

void infinite()
{
    unsigned char max = 160; // max value 255 (0xff)
    
    // signed char max  value 127
    // i will overflow when above 127 to min number for signed char -128
    // therefore never reach the loop exit condition of 160
    for(signed char i=0; i<max; ++i) std::cout << int(i) << std::endl;
}

int main()
{
    infinite();
}