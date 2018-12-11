#include<iostream>
#include<fstream>
#include<string>
#include<vector>

struct Item {
  std::string name;
  int iid;
  double value;
  Item() { };
  Item(const std::string& n, int id, double v): name{n}, iid{id}, value{v} { };
};

std::istream& operator>>(std::istream& is, Item& p)
{
  char ch1;
  std::string name;
  char ch2;
  int iid;
  char ch3;
  double price;
  char ch4;

  is >> ch1 >> name >> ch2 >> iid >> ch3 >> price >> ch4;
  if(!is) return is;
  if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
  {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }
  p = Item{name, iid, price};
  return is;
}

int main()
{

  // get input file name
  std::string from;
  std::cin >> from;

  // open input stream
  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";

  // copy elements into vector
  std::vector<Item> vi;

  Item i;
  while(ifs >> i) vi.push_back(i);

  std::cout << vi[4].name;

}
