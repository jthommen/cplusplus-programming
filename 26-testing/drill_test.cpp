#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<functional>

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
   
    while(is >> elem)
    {
        seq.push_back(elem);
        // breaks when T is not found anymore in stream
        // fail_bit is set
    }
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


template<typename T>
int test_all(std::istream& is,  bool (*f)(std::vector<T>&, T, int))
{
    int error_count = 0;
    Test<T> t;
    while(is>>t)
    {
        bool r = f(t.seq, t.val, 0);
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