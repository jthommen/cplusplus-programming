#include<iostream>
#include<string>
#include<vector>

class vector {
  int sz; // size
  double* elem; // pointer to the first element (of type double)
public:
  explicit vector(int s); // simple explicit constructor
  vector(std::initializer_list<double>lst); // initializer-list constructor

  vector(const vector& v); // copy constructor (deep copying)
  vector& operator=(const vector& v); // copy assignment (deep copying)

  vector(vector&& v); // move constructor
  vector& operator=(vector&& v); // move assignment

  double& operator[](int n); // subscript operator
  double operator[](int n) const; // subscript operator with explicit const for compiler

  ~vector() // destructor
  {
    delete[] elem; // free memory
  }

  int size() const { return sz; } // return current size

  double get(int n) const { return elem[n]; } // access: read
  void set(int n, double v) {elem[n]=v; } // access: write

};

vector::vector(int s) // simple constructor
  :sz{s}, // initialize sz
  elem{new double[s]} // initialize elem, new returns pointer to the first elem
{
  for (int i=0; i<s; ++i) elem[i]=0; // initialize elements
}

vector::vector(std::initializer_list<double>lst) // initializer-list constructor
  :sz{int(lst.size())}, elem{new double[sz]} // uninitialized memory with size of initializer list
{
  std::copy(lst.begin(), lst.end(),elem); // initialize elems
}

vector::vector(const vector& v) // copy constructor (deep copying)
// allocate elements, then initialize them by copying
  :sz{v.sz}, elem{new double[v.sz]}
{
  // v.elem+sz: pointer to first double elem addrss + int = address of last elem!
  std::copy(v.elem, v.elem+sz, elem);
}

vector& vector::operator=(const vector& v) // copy assignment (deep copying)
// make this a copy of v
{
  double* p = new double[v.sz]; // allocate new space on the free store
  std::copy(v.elem, v.elem+sz, p); // copy elements to p
  delete[] elem; // deallocate old space
  elem = p; // reset elem on this and point them to the new elements in p
  sz = v.sz; // set size
  return *this; // return a self-reference
}

vector::vector(vector&& v) // move constructor
  :sz{v.sz}, elem{v.elem} // copy a's elem and sz
{
  v.sz = 0; // make v an empty vector
  v.elem = nullptr;
}

vector& vector::operator=(vector&& v) // move assignment
{
  delete[] elem; // deallocate old space of this object
  elem = v.elem; // copy v's elem and sz
  sz = v.sz;
  v.elem = nullptr; // set v to empty vector
  v.sz = 0;
  return *this; // return self-reference
}

double& vector::operator[](int n) // subscript operator
{
  return elem[n]; // return reference
}

double vector::operator[](int n) const // subscript operator with explicit const for compiler
{
  return elem[n]; // return value
}


int main()
{
  std::cout << "Vectors and Free Store\n";

  vector v(5);

  for (int i=0; i<v.size(); ++i)
  {
    v.set(i, 1.1*i);
    std::cout << "[" << i << "]==" << v.get(i) << std::endl;
  }

  vector v2 = v;
  // similar: vector v2 {v};

  vector v3(10);
  for(int i=0; i<v.size(); ++i)
  {
    v3[i] = i;
    std::cout << v3[i] << std::endl;
  }

}
