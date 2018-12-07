#include<string>
#include<vector>
#include<iostream>


template<typename T>
struct S {
  explicit S(T v):val{v} { };
  T& get();

private:
  T val;
};

template<typename T>
T& S<T>::get() {
  return val;
}

// output stream overloading to display vectors of type S
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
  os << "{";
  for(int i=0; i<v.size(); ++i)
  {
    os << v[i] << (i < v.size() -1 ? ",": "");
  }
  os << "}\n";

  return os;
}

int main()
{
  S<int> i {4};
  S<char> c {'j'};
  S<double> d{3.3};
  S<std::string> s {"Juri"};
  S<std::vector<int>> v{std::vector<int>{1,2,3,4}};

  std::cout << i.get() << std::endl;
  std::cout << c.get() << std::endl;
  std::cout << d.get() << std::endl;
  std::cout << s.get() << std::endl;
  std::cout << v.get() << std::endl;

}
