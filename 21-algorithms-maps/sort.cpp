#include<string>
#include<vector>
#include<iostream>

struct No_case { // not getting called
  bool operator()(const std::string&x, const std::string& y) const
  {
    for(int i=0; i<x.length(); ++i)
    {
      if(i==y.length()) return false;
      char xx = tolower(x[i]);
      char yy = tolower(y[i]);
      if(xx<yy) return false;
      if(yy<xx) return true;
    }
    if(x.length()==y.length()) return false;
    return true;
  }
};

void sort_and_print(std::vector<std::string>& vc)
{
  std::sort(vc.begin(), vc.end(), No_case());
  for(const auto& s: vc)
  {
    std::cout << s << "\n";
  }
}

int main()
{
  std::vector<std::string> sv {"Here", "are", "some", "random", "words", "to", "sort", "through"};

  sort_and_print(sv);
}
