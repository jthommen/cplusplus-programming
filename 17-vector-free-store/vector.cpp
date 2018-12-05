#include<iostream>
#include<string>
#include<vector>

class vector {
  int sz; // size
  double* elem; // pointer to the first element (of type double)
public:
  vector(int s) // constructor
    :sz{s}, // initialize sz
    elem{new double[s]} // initialize elem, new returns pointer to the first elem
    {
      for (int i=0; i<s; ++i) elem[i]=0; // initialize elements
    }

  ~vector() // destructor
  {
    delete[] elem; // free memory
  }

  int size() const { return sz; } // return current size

  double get(int n) const { return elem[n]; } // access: read
  void set(int n, double v) {elem[n]=v; } // access: write

};


int main()
{
  std::cout << "Vectors and Free Store\n";

  vector v{5};
  for (int i=0; i<v.size(); ++i)
  {
    v.set(i, 1.1*i);
    std::cout << "v[" << i << "]==" << v.get(i) << std::endl;
  }

}
