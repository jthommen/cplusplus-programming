#include<algorithm>
#include<iostream>
#include<list>
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

// error handling
struct wrong_input_format { };

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

// function object as predicate for find_if function
class Name_equals {
  std::string name;
public:
  Name_equals(const std::string& n): name{n} { };
  bool operator()(const Item& i) const { return i.name == name; }
};

class Iid_equals {
  int iid;
public:
  Iid_equals(const int id): iid{id} { };
  bool operator()(const Item& i) const { return i.iid == iid; }
};

// -----------------------------------------------------------------------------
// Drill 01
// -----------------------------------------------------------------------------
template<typename iter>
void print_vector(iter first, iter last)
{
  while(first!=last)
  {
    std::cout << "Name: " << first -> name
    << "\tNo: " << first -> iid
    << "\tValue: " << first -> value << std::endl;
    ++first;
  }
}

// Item file parsing
template<typename T>
void split(std::ifstream& ifs, char delim, T& vi)
{
  std::vector<std::string> vs;
  std::string token;
  Item it;

  // read string stream into vector
  while(std::getline(ifs, token, delim)) vs.push_back(token);

  // build Items out of strings in vector
  if(vs.size()%3 !=0) throw wrong_input_format();

  // build items and add them to output vector
  for(int i=0; i<vs.size(); i +=3)
  {
    std::string name = vs[i];
    name.erase(std::find(name.begin(), name.end(), '\n')); // Erase line breaks
    int iid = std::stoi(vs[i+1]);
    double value = std::stod(vs[i+2]);

    it = Item{name, iid, value};
    vi.push_back(it);
  }

}

void drill_01a()
{
  // 1
  std::string from {"i3.txt"};
  std::cout << "Input File: " << from << std::endl;

  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";
  std::vector<Item> vi;
  split(ifs, ',', vi);
  ifs.close();

  // 2
  // sort by name asc
  sort(vi.begin(), vi.end(), Cmp_name());

  // 3
  // sort by iid asc
  sort(vi.begin(), vi.end(), Cmp_iid());

  // 4
  // // sort by value asc, print desc
  sort(vi.begin(), vi.end(), Cmp_value());
  reverse(vi.begin(), vi.end());

  // 5
  vi.insert(vi.begin(),Item{"horse shoe", 99, 12.34});
  vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});

  // 6
  std::vector<Item>::iterator name_it = find_if(vi.begin(), vi.end(), Name_equals("Microsoft Windows 10 Home Englisch"));
  vi.erase(name_it);
  name_it = find_if(vi.begin(), vi.end(), Name_equals("horse shoe"));
  vi.erase(name_it);

  // 7
  std::vector<Item>::iterator iid_it  = find_if(vi.begin(), vi.end(), Iid_equals(375697));
  vi.erase(iid_it);
  iid_it = find_if(vi.begin(), vi.end(), Iid_equals(9988));
  vi.erase(iid_it);
  print_vector(vi.begin(), vi.end());
}

void drill_01b()
{
  // 8

  // parse input file
  std::string from {"i3.txt"};
  std::cout << "Input File: " << from << std::endl;

  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";
  std::list<Item> li;
  split(ifs, ',', li);
  ifs.close();

  // sort by name asc
  li.sort(Cmp_name());

}

int main()
try {
  drill_01a();
  drill_01b();

} catch(wrong_input_format) {
  std::cout << "Wrong input format.\n";

} catch(...) {
  std::cout << "An error occured.\n";
}
