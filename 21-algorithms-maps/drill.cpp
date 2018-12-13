#include<algorithm>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
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
struct input_stream_not_readable { };

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

class Less_than {
  double number;
public:
  Less_than(const double n): number{n} { };
  bool operator()(const double d) const { return number < d; }
};

// -----------------------------------------------------------------------------
// Drill 01
// -----------------------------------------------------------------------------

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

template<typename iter>
void print(iter first, iter last)
{
  while(first!=last)
  {
    std::cout << "Name: " << first -> name
    << "\tNo: " << first -> iid
    << "\tValue: " << first -> value << std::endl;
    ++first;
  }
}

void drill_01a()
{
  std::cout << "---------------------\nDrill_01a\n---------------------\n";
  // 1.1
  std::string from {"i3.txt"};

  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";
  std::vector<Item> vi;
  split(ifs, ',', vi);
  ifs.close();

  // 1.2
  // sort by name asc
  sort(vi.begin(), vi.end(), Cmp_name());

  // 1.3
  // sort by iid asc
  sort(vi.begin(), vi.end(), Cmp_iid());

  // 1.4
  // sort by value asc, print desc
  sort(vi.begin(), vi.end(), Cmp_value());
  reverse(vi.begin(), vi.end());

  // 1.5
  vi.insert(vi.begin(),Item{"horse shoe", 99, 12.34});
  vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});

  // 1.6
  std::vector<Item>::iterator name_it = find_if(vi.begin(), vi.end(), Name_equals("Microsoft Windows 10 Home Englisch"));
  vi.erase(name_it);
  name_it = find_if(vi.begin(), vi.end(), Name_equals("horse shoe"));
  vi.erase(name_it);

  // 1.7
  std::vector<Item>::iterator iid_it  = find_if(vi.begin(), vi.end(), Iid_equals(375697));
  vi.erase(iid_it);
  iid_it = find_if(vi.begin(), vi.end(), Iid_equals(9988));
  vi.erase(iid_it);
  print(vi.begin(), vi.end());
}

void drill_01b()
{
  // 1.8
  std::cout << "---------------------\nDrill_01b\n---------------------\n";

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

  // sort by iid asc
  li.sort(Cmp_iid());

  // sort by value asc, print desc
  li.sort(Cmp_value());
  li.reverse();

  // insert two items
  li.insert(li.begin(),Item{"horse shoe", 99, 12.34});
  li.insert(li.end(), Item{"Canon S400", 9988, 499.95});

  // find and delete two items by name
  li.remove_if(Name_equals("Microsoft Windows 10 Home Englisch"));
  li.remove_if(Name_equals("horse shoe"));

  // find and delete two items by iid
  li.remove_if(Iid_equals(375697));
  li.remove_if(Iid_equals(9988));
  print(li.begin(), li.end());
}

// -----------------------------------------------------------------------------
// Drill 02
// -----------------------------------------------------------------------------

// 2.5
template<typename K, typename V>
void get_input(std::istream& is, std::map<K, V>& m)
{
  K s;
  V i;
  is >> s >> i;
  if(!is) throw input_stream_not_readable();
  m[s]=i;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<K,V>& p)
{
  os << "Key: " << p.first << ", Value: " << p.second << std::endl;
  return os;
}

void drill_02()
{
  std::cout << "---------------------\nDrill_02\n---------------------\n";
  // 2.1
  std::map<std::string, int> msi;

  // 2.2
  // Global Innovation Index Ranking 2018
  msi["Switzerland"]=1;
  msi["Netherlands"]=2;
  msi["Sweden"]=3;
  msi["United Kingdom"]=4;
  msi["Singapore"]=5;
  msi["United States of America"]=6;
  msi["Finland"]=7;
  msi["Denmark"]=8;
  msi["Germany"]=9;
  msi["Ireland"]=10;

  // 2.3
  for(const auto p: msi) std::cout << p;

  // 2.4
  msi.clear();

  // 2.6
  std::cout << "Please enter 10 key value pairs, separated by a space:  ";
  for(int i=0; i<10; ++i) get_input(std::cin, msi);

  // 2.7 & 2.8
  int sum = 0;
  for(const auto p: msi) { std::cout << p; sum += p.second; }
  std::cout << "The sum of the integers: " << sum << std::endl;

  // 2.9
  std::map<int, std::string> mis;

  // 2.10
  for(const auto p: msi)  mis[p.second] = p.first;

  // 2.11
  for(const auto p: mis) std::cout << p;
};

// -----------------------------------------------------------------------------
// Drill 03
// -----------------------------------------------------------------------------
void drill_03()
{
  std::cout << "---------------------\nDrill_03\n---------------------\n";
  // 3.1
  std::string from {"floating.txt"};
  std::ifstream ifs {from};
  if(!ifs) std::cout << "Can't open file.\n";
  std::vector<double> vd;
  double d;
  while(ifs >> d) vd.push_back(d);
  ifs.close();

  // 3.2
  for(int i=0; i<vd.size(); ++i) {
    std::cout << '[' << i << "]==" << vd[i] << std::endl;
  }

  // 3.3

  std::vector<int> vi(vd.size());
  copy(vd.begin(), vd.end(), vi.begin());

  // 3.4 & 3.5 & 3.6
  int sum_vd = 0;
  int sum_vi = 0;
  for(int i=0; i<vd.size(); ++i)
  {
    std::cout << "vd: " << vd[i] << ", vi: " << vi[i] << std::endl;
    sum_vd += vd[i];
    sum_vi += vi[i];
  }
  std::cout << "Sum of vd: " << sum_vd << std::endl;
  std::cout << "Sum of vi: " << sum_vi << std::endl;
  std::cout << "Difference in sum vd - vi: " << (sum_vd-sum_vi) << std::endl;

  // 3.7
  reverse(vd.begin(), vd.end());
  for(auto x : vd) std::cout << x << std::endl;

  // 3.8
  double avg_vd = std::accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
  std::cout << "Average of vd: " << avg_vd << std::endl;

  // 3.9
  std::vector<double> vd2(vd.size());
  copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(avg_vd));
  sort(vd.begin(), vd.end());

  // 3.10
  for(auto x : vd) std::cout << x << std::endl;

}

int main()
try {
  drill_01a();
  drill_01b();
  drill_02();
  drill_03();

} catch(wrong_input_format) {
  std::cout << "Wrong input format.\n";

} catch(...) {
  std::cout << "An error occured.\n";
}
