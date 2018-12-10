#include<iostream>
#include<string>

void copy(int* f1, int* e1, int* f2)
// Copies the elements of an array of ints
// defined by [f1:e1] into another [f2:f2+(e1-f1)]
{
  for(int* i=f1; i!=e1+1; ++i)
  {
    *f2 = *i;
    ++f2;
  }
}


int main()
{
  int source[]{1,2,4,8,16};
  int dest[5];

  int* sf = &source[0];
  int* se = &source[4];

  copy(sf, se, dest);
  for(int i=0; i<5; ++i)
  {
    std::cout << '[' << i << "]==" << dest[i] << std::endl;
  }

}
