#include<bitset>
#include<iostream>

template<typename T>
void print(T i)
{
    std::cout << std::dec << i << "=="
        << std::hex << "0x" << i << "=="
        << std::bitset<sizeof(T)*8>{i} << std::endl;
}

void one_and_two()
{
    unsigned int v = 1;
    std::cout << "bit size of v: " << sizeof(v)*8 << std::endl;
    for(int i=0; i<sizeof(v)*8; ++i) // run loop until bit limit reached
    {
        std::cout << v << ' ';
        v <<=1; // bit shift left: Increaase value by factor 2
    }
    std::cout << std::endl;
}

void three_and_four()
{
    short unsigned int sui; // 65535 /0xffff max
    std::cout << "bit size of sui: " << sizeof(short unsigned)*8 << std::endl;
    
    sui = 0xffff;
    std::cout << "all bits set:\n";
    print(sui);

    sui = 0x1;
    std::cout << "only LO bit set:\n";
    print(sui);

    sui = 0x8000;
    std::cout << "only HO bit set:\n";
    print(sui);

    sui = 0xF;
    std::cout << "only LO byte set:\n";
    print(sui);

    sui = 0xF000;
    std::cout << "only HO byte set:\n";
    print(sui);

    sui = 0x5555;
    std::cout << "every second bit (incl. lowest):\n";
    print(sui);

    sui = 0xAAAA;
    std::cout << "every second bit (incl. highest):\n";
    print(sui);
}

void five()
{
    short unsigned int sui; // 65535 /0xffff max
    std::cout << "bit size of sui: " << sizeof(short unsigned)*8 << std::endl;
    
    sui = ~0;
    std::cout << "all bits set:\n";
    print(sui);

    sui = 1;
    std::cout << "only LO bit set:\n";
    print(sui);

    sui = 1<<15;
    std::cout << "only HO bit set:\n";
    print(sui);

    sui = 1 | 1<<1 | 1<<2 | 1<<3;
    std::cout << "only LO byte set:\n";
    print(sui);

    sui =~0<<12;
    std::cout << "only HO byte set:\n";
    print(sui);

    sui = 1 | 1<<2 | 1<<4 | 1<<6 | 1<<8 | 1<<10 | 1<<12 | 1<< 14;
    std::cout << "every second bit (incl. lowest):\n";
    print(sui);

    sui = 1<<1 | 1<<3 | 1<<5 | 1<<7 | 1<<9 | 1<<11 | 1<< 13 | 1<<15;
    std::cout << "every second bit (incl. highest):\n";
    print(sui);
}

int main()
{
    // #1 & #2
    one_and_two();

    // #3 & #4
    three_and_four();

    // #5
    five();
    
}