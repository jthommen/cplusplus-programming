#include "../std_lib_facilities.h"

int main()
{

    constexpr int uppercase_start = 65;
    constexpr int lowercase_start = 97;

    for(int i=0; i<26; ++i)
    {
        cout << char(i+uppercase_start) << '\t' << i+uppercase_start << '\n';
        cout << char(i+lowercase_start) << '\t' << i+lowercase_start << '\n';
    }
}
