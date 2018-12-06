// Array Drill
#include <iostream>
#include <string>

int ga[10] = {1,2,4,8,16,32,64,128,256,512};

void f(int a[], int n)
{
  int la[10];
  for(int i = 0; i<n; ++i)
  {
    la[i] = a[i];
    std::cout << "la[" << i << "]==" << la[i] << std::endl;
  }

  int* p = new int[n];
  for(int i = 0; i<n; i++)
  {
    p[i] = a[i];
    std::cout << "p[" << i << "]==" << p[i] << std::endl;
  }

  delete[] p;
}

int main()
{
  f(ga, 10);

  int aa[10];
  // possible to optimize with memoization and recursion
  for(int i=0; i<10; ++i)
  {
    aa[i] = 1;
    for(int j=0; j<=i; ++j)
    {
      aa[i] *= j+1;
    }
  }

  f(aa, 10);
}
