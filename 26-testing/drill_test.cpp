#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<functional>
#include<random>

template<typename T>
struct Test
{
    std::string label;
    T val;
    std::vector<T> seq;
    bool res;
};

template<typename T>
std::istream& operator>>(std::istream& is, Test<T>& t)
// { 1.1 4  {1 2 3 4 5 6 7 8 9 10 } 1 }
{
    char ch1;
    char ch2;
    char ch3;
    char ch4;
    std::string label;
    T val;
    std::vector<T> seq;
    T elem;
    bool res;

    is >> ch1 >> label >> val >> ch2;
    if(!is) return is;
    if(ch1!='{' || ch2!='{')
    {        
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
   
    while(is >> elem && elem != "}")
    {
        seq.push_back(elem);
        // breaks when T is not found anymore in stream
        // fail_bit is set
    }
    if(elem == "}") is.unget();
    is.clear();
    is >> ch3 >> res >> ch4;

    if(!is) return is;
    if(ch3!='}' || ch4!= '}')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    t.label = label;
    t.seq = seq;
    t.val = val;
    t.res = res;
    return is;
}

int randint(int min, int max)
{
    /* Not working.... only returns 0 
    static std::default_random_engine ran;
    return std::uniform_int_distribution<>{min, max}(ran);
    */
   return rand() % max + min;
}

int randint(int max)
{
    return randint(0, max);
}

void make_test(const std::string& lab, int n, int base, int spread)
// Generate a test with:
// lab = label
// sequence of n elements starting at base
// average distance between elements is uniformly distributed [0:spread]
{
    // generate numbers
    std::cout << '{' << lab << n << '{';
    std::vector<int> v;
    int elem = base;
    for(int i=0; i<n; ++i)
    {
        elem+=randint(spread);
        v.push_back(elem);
    }

    // run test on generic linear search
    int val = base + randint(elem-base);
    bool found = false;
    for(int i=0; i<n; ++i)
    {
        if(v[i]==val) found = true;
        std::cout << v[i] << " ";
    }
    std::cout << '}' << found << std::endl;
}


template<typename T>
int test_all(std::istream& is,  bool (*f)(std::vector<T>&, T, int))
{
    int error_count = 0;
    Test<T> t;
    while(is>>t)
    {
        bool r = f(t.seq, t.val, 1);
        if(r!=t.res)
        {
            std::cout << "Failure!\ttest: " << t.label
                << "\tsequence size: " << t.seq.size() 
                << " elements,\tval==" << t.val
                << "\texpected result: " << t.res << std::endl;
            f(t.seq, t.val, 1);
            std::cout << "----\n";
            ++error_count;
        }
    }
    return error_count;
}