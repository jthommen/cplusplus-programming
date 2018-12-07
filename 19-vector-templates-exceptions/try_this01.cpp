#include <iostream>

// class/struct template example
// container where the number of elements is known at compile time
template<typename T, int N> struct array {
  T elem[N]; // hold elements in member array

  // rely on default constructors, destructors and assignment of array

  T& operator[] (int n) { return elem[n]; } // access: return reference
  const T& operator[] (int n) const { return elem[n]; }

  T* data() {return elem;} // conversion to T*
  const T* data() const { return elem; }

  int size() const { return N; }
};

array<int, 256> gb; // size of 256 integers
array<double, 6> ad = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
const int max = 1024;

void some_fct(int n)
{
  array<char, max> loc;
  //array<char, n> // error: n not known at compile time
  array<char, max> loc2 = loc; // make backup copy

  loc = loc2; // restore
}


// function template example
template<class T, int N> void fill(array<T, N>&a, const T& val)
{
  for(int i=0; i<N; ++i) a[i]=val;
}

array<char, 1024> buf;
array<double, 10> b2;

void f()
{
  fill(buf, 'x');
  fill(b2, 0.0);
}

int main()
{
  std::cout << "Class/struct Template Example: Fixed Array (Container)\n";
  some_fct(4);

  std::cout << "Function Template Example: Initializing Arrays\n";
  f();
}
