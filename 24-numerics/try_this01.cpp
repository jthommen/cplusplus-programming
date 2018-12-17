#include<iostream>
#include<iomanip>



int main()
{
  std::cout << "Floating Point Approximation\n-----\n";
  float x = 1.0/333;
  float sum = 0;
  for(int i=0; i<333; ++i) sum+=x;
  std::cout << std::setprecision(15) << sum << std::endl;

  x = 1.0/10;
  sum = 0;
  for(int i=0; i<10; ++i) sum+=x;
  std::cout << std::setprecision(15) << sum << std::endl;
  std::cout << "-----\n";

  std::cout << "Data Type Sizes\n-----\n";
  std::cout << "char: " << sizeof(char) << std::endl;
  std::cout << "short: " << sizeof(short) << std::endl;
  std::cout << "int: " << sizeof(int) << std::endl;
  std::cout << "long: " << sizeof(long) << std::endl;
  std::cout << "float: " << sizeof(float) << std::endl;
  std::cout << "double: " << sizeof(double) << std::endl;
  std::cout << "-----\n";

}