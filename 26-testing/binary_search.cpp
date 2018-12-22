#include<iostream>
#include<vector>
#include<chrono>

// Binary search with vector and subscripting
// Could also have written it with iterators...

template<typename T>
bool binary_search(std::vector<T>& vr,T t)
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
        return false;
    }
    if(t > vr.size())
    {
        std::cerr << "Number not here.\n";
        return false;
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
            return true;
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
    return false;
}

template<typename T>
void timing_binary_search(std::vector<T>& v, T t)
{
    auto t1 = std::chrono::system_clock::now();
    binary_search(v, t); // found
    auto t2 = std::chrono::system_clock::now();
    std::cout << "Binary Search took: " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
        << " milliseconds.\n";
}

int main()
{
    std::vector<int> data;
    // initialize
    // needs to be sorted
    for(int i=0; i<10; ++i) data.push_back(i);
    for(auto n:data) std::cout << n << '\t';
    std::cout << std::endl;

    timing_binary_search(data, 4); // found, 1ms
    timing_binary_search(data, 1); // found
    timing_binary_search(data, 0); // found
    timing_binary_search(data, 10); // found
    timing_binary_search(data, 8); // found
    timing_binary_search(data, -1); // error
    timing_binary_search(data, 15); // error
    timing_binary_search(data, 5); // found

}

// correct because
// - tested as I developed: make -> run
// - tested with invalid cases: negative index, out of range
// - tested with edge cases: highest and lowest element in range
// - printed out lot of messages to see how the program runs
