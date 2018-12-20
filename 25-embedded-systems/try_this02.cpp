#include<iostream>
#include<bitset>

int main()
{

    // prints integer values in dec, hex and as bitsets
    std::cout << "Please enter an integer: ";
    for(unsigned i; std::cin >> i;) {
        std::cout << std::dec << i << "==" // format input stream to dec
            << std::hex << "0x" << i << "==" // format input stream to hex
            << std::bitset<8*sizeof(unsigned)>{i} << std::endl;
        std::cout << "Please enter an integer: ";
    }
}