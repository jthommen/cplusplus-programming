#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

// -----------------------------------------------------------------------------
// General
// -----------------------------------------------------------------------------
struct Item {
  std::string name;
  int iid;
  double value;
  Item() { };
  Item(const std::string& n, int id, double v): name{n}, iid{id}, value{v} { };
};

std::istream& operator>>(std::istream& is, Item& i)
// Overloaded operator for input parsing
// only works for whitespace separated components (how to improve?)
// e.g.: (Gainward_GeForce_RTX_2080_Phoenix_GS , 9417587 , 879)
{
  char ch1;
  std::string name;
  char ch2;
  int iid;
  char ch3;
  double value;
  char ch4;

  is >> ch1 >> name >> ch2 >> iid >> ch3 >> value >> ch4;
  if(!is) return is;
  if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
  {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }
  i = Item{name, iid, value};
  return is;
}

void split(std::stringstream& ss, char delim, std::vector<Item>& vi)
{
  std::string token;
  while(std::getline(ss, token, delim))
  {
    std::cout << token << std::endl;
  }
}

// User specified comparison criteria for vector<Item> sorting
struct Cmp_name {
  bool operator()(const Item& a, const Item& b) const
  {
    return a.name < b.name;
  }
};

struct Cmp_iid {
  bool operator()(const Item& a, const Item& b) const
  {
    return a.iid < b.iid;
  }
};

struct Cmp_value {
  bool operator()(const Item& a, const Item& b) const
  {
    return a.value < b.value;
  }
};

// -----------------------------------------------------------------------------
// Drill 01
// -----------------------------------------------------------------------------
template<typename iter>
void print_vector(iter first, iter last)
{
  while(first!=last)
  {
    std::cout << "No:\t" << first -> iid
    << "\tValue:\t" << first -> value
    << "\tName:\t" << first -> name << std::endl;
    ++first;
  }
  std::cout << "\n\n";
}

void drill_01()
{
  std::string from {"i2.txt"};
  std::cout << "Input File: " << from << std::endl;

  // open input stream
  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";

  // copy to stringstream
  std::stringstream ss;
  copy(
    std::istreambuf_iterator<char>(ifs),
    std::istreambuf_iterator<char>(),
    std::ostreambuf_iterator<char>(ss));

  // copy elements into vector
  std::vector<Item> vi;
  split(ss, ',', vi);
  // Item i;
  // while(ifs >> i) vi.push_back(i);

  // sort by name asc
  //sort(vi.begin(), vi.end(), Cmp_name());

  // sort by iid asc
  //sort(vi.begin(), vi.end(), Cmp_iid());

  // sort by value asc, print desc
  // sort(vi.begin(), vi.end(), Cmp_value());
  // reverse(vi.begin(), vi.end());
  // print_vector(vi.begin(), vi.end());
}

int main()
try {
  drill_01();

} catch(...) {
  std::cout << "An error occured.\n";
}
