#include<string>
#include<vector>
#include<iostream>


template<typename T>
struct S {
  explicit S(T v):val{v} { };

  T& get();
  const T& get() const;
  
  void set(T v);

  T& operator=(const T& t); // deep copy assignment

private:
  T val;
};

template<typename T>
T& S<T>::get()
{
  return val;
}

template<typename T>
const T& S<T>::get() const
{
  return val;
}

template<typename T>
void S<T>::set(T v)
{
  val = v;
  return;
}

// read from cin into val
template<typename T>
void read_val(T& v)
{
  std::cin >> v;
}

// output stream overloading to display vectors<T>
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

// input stream overloading to read into vector<T>
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
  char ch1, ch2;
  T buf;
  std::vector<T> v_buf;
  is >> ch1;
  if(!is) return is;
  if(ch1 != '{') {
    is.clear(std::ios_base::failbit);
    return is;
  }
  while(is >> buf >> ch2 && ch2==',') {
    v_buf.push_back(buf);
  }
  if(ch2!='}') {
    is.clear(std::ios_base::failbit);
    return is;
  }
  v_buf.push_back(buf);

  v = v_buf;

  return is;
}

// input stream overloading to read in value of S<T>
template<typename T>
std::istream& operator>>(std::istream& is, S<T>& s)
{
  T buf;
  is >> buf;
  if(!is) return is;
  s = buf;
  return is;
}

// deep copy assignment
template<typename T>
T& S<T>::operator=(const T& t)
{
  if(val == t) return val;
  val = t;
  return val;
}

int main()
{
  S<int> i {4};
  S<char> c {'j'};
  S<double> d{3.3};
  S<std::string> s {"Hi"};
  S<std::vector<int>> v{std::vector<int>{1,2,3,4}};

  std::cout << i.get() << std::endl;
  std::cout << c.get() << std::endl;
  std::cout << d.get() << std::endl;
  std::cout << s.get() << std::endl;
  std::cout << v.get() << std::endl;

  s.set("Hello");
  std::cout << s.get() << std::endl;

  // std::cout << "Read into int: ";
  // read_val(i);
  // std::cout << "Read into char: ";
  // read_val(c);
  // std::cout << "Read into double: ";
  // read_val(d);
  // std::cout << "Read into string: ";
  // read_val(s);
  std::cout << "Read into vector: ";
  read_val(v);

  std::cout << "New Values:\n----------------\n";
  std::cout << i.get() << std::endl;
  std::cout << c.get() << std::endl;
  std::cout << d.get() << std::endl;
  std::cout << s.get() << std::endl;
  std::cout << v.get() << std::endl;

}
