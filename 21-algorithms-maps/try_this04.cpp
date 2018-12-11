#include<iostream>
#include<map>
#include<numeric>
#include<string>

// Data maps
std::map<std::string,double> dow_price = {
  // December 10th, 2018
  {"MSFT", 107.59},
  {"INTC", 47.21},
  {"AAPL", 169.60},
  {"CSCO", 46.86}
};

std::map<std::string,double> dow_weight = {
  // December 10th, 2018
  {"MSFT", 2.99},
  {"INTC", 1.31},
  {"AAPL", 4.71},
  {"CSCO", 1.3}
};

std::map<std::string,std::string> dow_name = {
  // December 10th, 2018
  {"MSFT", "Microsoft"},
  {"INTC", "Intel"},
  {"AAPL", "Apple"},
  {"CSCO", "Cisco Systems"}
};

// Calculating weighted value based on DJI
double weighted_value(
  const std::pair<std::string, double>& a,
  const std::pair<std::string, double>& b)
  {
    return a.second * b.second;
  }


int main()
{
  // Printing out values
  for(const auto& p: dow_price)
  {
    std::cout << p.first << '\t'
    << p.second << '\t'
    << dow_name[p.first] << std::endl;
  }

  // Calculating inner_produt
  double dji_index = std::inner_product(
    dow_price.begin(), // start of the price map
    dow_price.end(), // end of the price map
    dow_weight.begin(), // start of the weight map
    0.0, // initial value
    std::plus<double>(), // adding products
    weighted_value); // multiplying prices and weights for given key

  std::cout << "Tech Index Value: " << dji_index << std::endl;
}
