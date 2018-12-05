#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n)
{
  for(int i=0; i<n; ++i) os << a[i] << std::endl;
};

void initialize_vector(std::vector<int>& v)
{
  int n = 1;
  for(int i=0; i<v.size(); ++i)
  {
    v[i] = n;
    n *= 2;
    }
};

void print_vector(std::ostream& os, std::vector<int>& v)
{
  for(int i=0; i<v.size(); ++i) os << v[i] << std::endl;
}

int main()
{
  // 1-2
  int i = 7;
  int* p1 = &i;

  std::cout << "i: " << i << std::endl;
  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p1 dereferenced: " << *p1 << std::endl;

  // 3
  int* p2 = new int[7];
  int n = 1;
  for(int i=0; i<7; ++i)
  {
    p2[i] = n;
    n *= 2;
  }

  // 4
  std::cout << "p2: " << p2 << std::endl;
  print_array(std::cout, p2, 7);

  // 5 - 9
  int* p3 = p2;
  p1 = p2;
  p3 = p2;
  std::cout << "p1: " << p1 << std::endl;
  print_array(std::cout, p1, 7);
  std::cout << "p2: " << p2 << std::endl;
  print_array(std::cout, p2, 7);

  delete[] p2;
  print_array(std::cout, p2, 7);
  // values are still there, probably not overwritten yet

  // 10 - 12
  p1 = new int[10];
  n = 1;
  for(int i=0; i<10; ++i)
  {
    p1[i] = n;
    n *= 2;
  }
  p2 = new int[10];
  std::cout << "-------\n";
  std::cout << "Array 1\n";
  print_array(std::cout, p1, 10);
  std::cout << "Array 2\n";
  print_array(std::cout, p2, 10);

  for(i=0; i<10; ++i)
  {
    p2[i] = p1[i];
  }

  std::cout << "Array 1\n";
  print_array(std::cout, p1, 10);
  std::cout << "Array 2\n";
  print_array(std::cout, p2, 10);

  // 13
  std::vector<int> v1(10);
  initialize_vector(v1);
  std::vector<int> v2(10);
  std::cout << "-------\n";
  std::cout << "Vector 1\n";
  print_vector(std::cout, v1);
  std::cout << "Vector 2\n";
  print_vector(std::cout, v2);

  for(i=0; i<v1.size(); ++i)
  {
    v2[i] = v1[i];
  }

  std::cout << "Vector 1\n";
  print_vector(std::cout, v1);
  std::cout << "Vector 2\n";
  print_vector(std::cout, v2);


}
