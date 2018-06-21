#include "../std_lib_facilities.h"

// function prototype
int square(int);

int main() 
{
    for(int i=0; i<100; ++i)
    {
        cout<< i << '\t' << square(i) << endl;
    }
}

int square(int x)
{
    int square = 0;

    for(int i = x; i > 0; --i)
    {
        square += x;
    }

    return square;
}
