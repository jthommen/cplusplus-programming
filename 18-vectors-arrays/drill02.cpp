#include <iostream>
#include <vector>

std::vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(std::vector<int> v)
{
  std::vector<int> lv(10);
  lv = v;
  for(int i=0; i<lv.size(); ++i)
  {
    std::cout << "lv[" << i << "]==" << lv[i] << std::endl;
  }

  std::vector<int> lv2 = lv;
    for(int i=0; i<lv2.size(); ++i)
  {
    std::cout << "lv2[" << i << "]==" << lv2[i] << std::endl;
  }
}

int main()
{
  f(gv);
  std::vector<int> vv(10);

  // possible to optimize with memoization and recursion
  for(int i=0; i<10; ++i)
  {
    vv[i] = 1;
    for(int j=0; j<=i; ++j)
    {
      vv[i] *= j+1;
    }
  }

  f(vv);
}
