#include<iostream>
#include<string>
#include<vector>

void sizes(char ch, int i, int* p, bool b, double d, std::string s, std::string* sp)
{
  std::cout << "the size of a char is " << sizeof(char) << ' ' << sizeof(ch) << std::endl;
  std::cout << "the size of a int is " << sizeof(int) << ' ' << sizeof(i) << std::endl;
  std::cout << "the size of a int* is " << sizeof(int*) << ' ' << sizeof(p) << std::endl;
  std::cout << "the size of a bool is " << sizeof(bool) << ' ' << sizeof(b) << std::endl;
  std::cout << "the size of a double is " << sizeof(double) << ' ' << sizeof(d) << std::endl;
  std::cout << "the size of a string is " << sizeof(std::string) << ' ' << sizeof(s) << std::endl;
  std::cout << "the size of a string* is " << sizeof(std::string*) << ' ' << sizeof(sp) << std::endl;

  // Bonus: Vector
  std::vector<int> v(1000);
  std::cout << "the size of std::vector<int>(1000) is " << sizeof(v) << std::endl;

}

int main()
{
  std::cout << "Vectors and Free Store\n";

  int x = 4;
  double e = 2.71828;

  int* pi = &x; // Pointer to int / int pointer
  double* pd = &e; // Pointer to double / double pointer

  std::cout << "pi==" << pi << "; contents of pi==" << *pi << std::endl;
  std::cout << "pd==" << pd << "; contents of pd==" << *pd << std::endl;

  *pi = 27; // possible to use content of: * operator to assign value at place where pi points to

  std::cout << "x==" << x << "; pi==" << pi << "; contents of pi==" << *pi << std::endl;


  // Printing sizes in bytes
  std::string s = "This string is dynamic and should change in length I think. Not sure it does though? Seems to be 24 bytes still.";
  std::string* sp = &s;
  sizes('j', x, pi, true, 3.14, s, sp);

}
