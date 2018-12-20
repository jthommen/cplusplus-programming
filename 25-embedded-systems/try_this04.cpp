#include<iostream>

int main()
{
    int si = 128;
    char c = si; // -128
    unsigned char uc = si; // 128
    signed char sc = si; // -128
    std::cout << si << '\t' << int(c) << '\t' << int(uc) << '\t' << int(sc) << std::endl;
}