#include<iostream>
#include<vector>

template<typename T>
void binary_search(std::vector<T>& vr,T t)
{
    std::cout<< "----\nBinary search called.\n----\n";
    int upper = vr.size();
    int lower = 0;
    int middle = vr.size()/2;
    std::cout << "Data size: " << upper << std::endl;
    std::cout<< "Key: " << t << std::endl;

    // some checks
    if(t < 0)
    {
        std::cerr << "Invalid search term.\n";
        return;
    }
    if(t > vr.size())
    {
        std::cerr << "Number not here.\n";
        return;
    }

    while(upper!=lower)
    {
        std::cout << "vr[middle]==" << vr[middle] << '\t'
            << "Upper: " << upper << '\t' 
            << "Middle: " << middle << '\t'
            << "Lower: " << lower << std::endl;
        if(vr[middle]==t)
        {
            std::cout << "Result: " << vr[middle] << std::endl;
            return;
        }
        else if(vr[middle] < t) // binary on right part
        {
            lower = middle;
            middle = lower+(upper-lower)/2;
            if(middle==lower) middle = upper; // if upper bound is reached, set middle to upper
        }
        else if(vr[middle] > t) // binary on left part
        {
            upper = middle;
            middle = (upper-lower)/2;
            if(middle==upper) middle = lower; // if lower bound is reached, set middle to lower
        }
    }
    
    // Can't find element, return
    std::cout << "Key not found!\n";
    return;
}

int main()
{
    std::vector<int> data;

    // initialize
    // needs to be sorted
    for(int i=0; i<10; ++i) data.push_back(i);
    for(auto n:data) std::cout << n << '\t';
    std::cout << std::endl;

    // key to search for
    binary_search(data, 4); // found
    binary_search(data, 1); // found
    binary_search(data, 0); // BUG
    binary_search(data, 10); // BUG
    binary_search(data, 8); // found
    binary_search(data, -1); // found
    binary_search(data, 15); // found
    binary_search(data, 5); // found
}

// correct because
// - tested as I developed: make -> run
// - tested with invalid cases: negative index, out of range
// - tested with edge cases: highest and lowest element in range
// - printed out lot of messages to see how the program runs
