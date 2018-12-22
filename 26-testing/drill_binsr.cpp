#pragma once
#include<string>
#include<vector>
#include<iostream>


template<typename T>
bool binary_search(std::vector<T>& vr, T t, int debug=0)
{
    int upper = vr.size()-1;
    int lower = 0;
    int middle = vr.size()/2-1;
    int runs = 15;

    // checks
    if(vr.size() < 1)
    {
        if(debug) std::cerr << "Invalid sequence.\n";
        return false;
    }
    if(vr.size()==1 && vr[0]==t) return true;

    while(upper!=lower && runs > 1)
    {   
        if(debug)
        {
            std::cout << "Lower: " << lower << '\t' << "vr[lower]==" << vr[lower] << '\t'
                << "Middle: " << middle << '\t' <<"vr[middle]==" << vr[middle] << '\t'
                 << "Upper Index: " << upper << '\t' <<"vr[upper]==" << vr[upper] << '\t'
                << "runs: " << runs << std::endl;
            --runs;
        }
        if(vr[middle]==t)
        {
            if(debug) std::cout << "Result: " << vr[middle] << std::endl;
            return true;
        }

        else if(vr[middle] < t) // binary on right part
        {
            lower = middle;
            middle = lower+(upper-lower)/2; // buggy!!
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
    return false;
}
