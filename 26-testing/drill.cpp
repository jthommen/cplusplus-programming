#include<iostream>
#include<fstream>
#include "drill_binsr.cpp"
#include "drill_test.cpp"


int main()
{
    std::ifstream ifs("my_tests.txt");

    int errors = test_all<int>(ifs, binary_search);
    std::cout <<"Number of errors: " << errors << std::endl;

}
