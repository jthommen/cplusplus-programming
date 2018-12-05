#include <iostream>
#include <vector>

void initialize_array(int* a, int n, int r)
{
  for(int i=0; i<n; ++i) a[i] = r+i;
};

void print_array(std::ostream& os, int* a, int n)
{
  for(int i=0; i<n; ++i) os << a[i] << std::endl;
};

void initialize_vector(std::vector<int>& v, int r)
{
  for(int i=0; i<v.size(); ++i) v[i] = r+i;
};

void print_vector(std::ostream& os, std::vector<int>& v)
{
  for(int i=0; i<v.size(); ++i) os << v[i] << std::endl;
}


int main()
{
  // Drill 1: 1-4
  int* ip = new int[10];
  print_array(std::cout, ip, 10);
  delete[] ip;

  // 5 - 7
  int* ip2 = new int[10];
  initialize_array(ip2, 10, 100);
  print_array(std::cout, ip2, 10);
  delete[] ip2;

  int* ip3 = new int[11];
  initialize_array(ip3, 11, 100);
  print_array(std::cout, ip3, 11);
  delete[] ip3;

  // 8-9
  int* ip4 = new int[20];
  initialize_array(ip4, 20, 100);
  print_array(std::cout, ip4, 20);
  delete[] ip4;

  // 10
  std::vector<int> iv(10);
  initialize_vector(iv, 100);
  print_vector(std::cout, iv);
  // built in destructor

  std::vector<int> iv2(11);
  initialize_vector(iv2, 100);
  print_vector(std::cout, iv2);
  // built in destructor

  std::vector<int> iv3(20);
  initialize_vector(iv3, 100);
  print_vector(std::cout, iv3);
  // built in destructor
}
