#include "../lib/Matrix.h"
#include "../lib/MatrixIO.h"
#include<iostream>
#include<cmath>
#include<complex>

// Drill for the numerics part
// 4
void get_sqrt()
{
  std::cout << "sqrt():\n" << "Enter a number: ";
  int n1, root;

  while(std::cin >> n1)
  {
    root = sqrt(n1);
    if(errno == EDOM) std::cerr << "sqrt() not defined for negative argument.";
    std::cout << "Square root of " << n1 << ": " << root << std::endl;
    std::cout << "Enter a number: ";
  }

}

// 5
void fill_and_print_matrix(int n)
{
  Numeric_lib::Matrix<double> md(n);
  double elem;

  std::cout << "Enter 10 decimal numbers, separated by space: ";
  // 1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.0

  for(int i=0; i<md.dim1(); ++i)
  {
    std::cin >> elem;
    md[i]=elem;
  }

  std::cout << md;
  std::cout << std::endl;
}

// 6
void muliplication_table()
// [0,n)*[0,m)
{
  int m,n;
  std::cout << "Enter two full numbers, separated by space: ";
  std::cin >> m >> n;
  Numeric_lib::Matrix<int,2> mi(m+1,n+1);

  for(int i=0; i<mi.dim1(); ++i)
  {
    for(int j=0; j<mi.dim2(); ++j)
    {
      mi[i][j] = i*j;
    }
  }

  std::cout << mi;
  std::cout << std::endl;

}

// 7
void complex_numbers(int n)
{
  Numeric_lib::Matrix<std::complex<double>> mc(n);
  std::complex<double> elem;
  std::complex<double> sum;

  std::cout << "Enter 10 complex doubles, separated by space: ";
  // 1.1i 2.2i 3.3i 4.4i 5.5i 6.6i 7.7i 8.8i 9.9i 10.0i

  for(int i=0; i<mc.dim1(); ++i)
  {
    std::cin >> elem;
    mc[i]=elem;
    sum += elem;
  }

  std::cout << sum;
  std::cout << std::endl;
}

void matrix_2d()
{
  Numeric_lib::Matrix<int,2> mi(2,3);
  int elem;

  std::cout << "Enter 6 integers, separated by space: ";
  // 1 2 3 4 5 6

  for(int i=0; i<mi.dim1(); ++i)
  {
    for(int j=0; j<mi.dim2(); ++j)
    {
      std::cin >> elem;
      mi[i][j] = elem;
    }
  }

  std::cout << mi;
  std::cout << std::endl;
}

int main()
{
  // 1
  std::cout << "Data Type Sizes\n-----\n";
  std::cout << "char: " << sizeof(char) << std::endl;
  std::cout << "short: " << sizeof(short) << std::endl;
  std::cout << "int: " << sizeof(int) << std::endl;
  std::cout << "long: " << sizeof(long) << std::endl;
  std::cout << "float: " << sizeof(float) << std::endl;
  std::cout << "double: " << sizeof(double) << std::endl;
  std::cout << "int*: " << sizeof(int*) << std::endl;
  std::cout << "double*: " << sizeof(double*) << std::endl;
  std::cout << "-----\n";

  // 2
  std::cout << "Matrix Sizes\n-----\n";
  Numeric_lib::Matrix<int> a(10);
  std::cout << "Matrix<int> a(10): " << sizeof(a) << std::endl;
  Numeric_lib::Matrix<int> b(100);
  std::cout << "Matrix<int> b(100): " << sizeof(b) << std::endl;
  Numeric_lib::Matrix<double> c(10);
  std::cout << "Matrix<double> c(10): " << sizeof(c) << std::endl;
  Numeric_lib::Matrix<int,2> d(10,10);
  std::cout << "Matrix<int,2> d(10,10): " << sizeof(d) << std::endl;
  Numeric_lib::Matrix<int,3> e(10,10,10);
  std::cout << "Matrix<int,3> e(10,10,10): " << sizeof(e) << std::endl;

  // 3
  std::cout << "a.size(): " << a.size() << std::endl;
  std::cout << "b.size(): " << b.size() << std::endl;
  std::cout << "c.size(): " << c.size() << std::endl;
  std::cout << "d.size(): " << d.size() << std::endl;
  std::cout << "e.size(): " << e.size() << std::endl;

  // 4
  //get_sqrt();

  // 5
  //fill_and_print_matrix(10);

  // 6
  //muliplication_table();

  // 7
  //complex_numbers(10);

  // 8
  matrix_2d();
}
