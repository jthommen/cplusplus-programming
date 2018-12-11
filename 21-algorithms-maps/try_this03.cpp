#include<iostream>
#include<numeric>
#include<string>
#include<vector>


struct Record {
  double unit_price;
  int units;
};

// accumulate operator to sum up total prices
double price(double v, const Record& r)
{
  return v + r.unit_price * r.units;
}

int main()
{
  std::vector<Record> vr;
  vr.push_back({3.3, 5});
  vr.push_back({2.7, 3});
  vr.push_back({7.3, 4});
  vr.push_back({1.8, 8});
  for(int i=0; i < vr.size(); ++i)
  {
    std::cout << "Record " << i << ": " << vr[i].unit_price
    << ", " << vr[i].units << std::endl;
  }
  std::cout << "Total prices of all units: "
  << std::accumulate(vr.begin(), vr.end(), 0.0, price) << std::endl;

}
