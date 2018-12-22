#include<iostream>
#include<fstream>
#include<string>
#include "drill_binsr.cpp"
#include "drill_test.cpp"


int main()
{
    
    // #1 & #2
    std::ifstream ifs("my_tests.txt");

    int errors = test_all<int>(ifs, binary_search);
    std::cout <<"Number of errors: " << errors << std::endl;

    // #3
    
    int no_of_tests = randint(500);
    std::cout << "Number of tests: " << no_of_tests << std::endl;
    for(int i=0; i<no_of_tests; ++i)
    {
        std::string lab = "rand_test_";
        make_test(lab+std::to_string(i), // label
            randint(500), // n=10
            0, // base = 0
            randint(50)); // spread
    }
    

    // #4
    std::ifstream ifss("my_string_tests.txt");

    // Binary search fails for strings --> have to develop more robust algorithm with iterators
    int string_errors = test_all<std::string>(ifss, binary_search);
    std::cout << "Number of errors: " << string_errors << std::endl;

}
