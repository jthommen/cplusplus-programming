#include<algorithm>
#include<array>
#include<iostream>
#include<list>
#include<string>
#include<vector>

// 6
template<typename Iter1, typename Iter2>
Iter2 custom_copy(Iter1 f1, Iter1 e1, Iter2 f2);


int main()
{
  // 1-3
  std::array<int, 10> ia{0,1,2,3,4,5,6,7,8,9};
  std::vector<int> iv{0,1,2,3,4,5,6,7,8,9};
  std::list<int> il{0,1,2,3,4,5,6,7,8,9};

  // 4
  std::array<int, 10> ia2 = ia;
  std::vector<int> iv2 = iv;
  std::list<int> il2 = il;

  // 5
  for(auto& x: ia) x*=2;
  for(auto& x: iv) x+=3;
  for(auto& x: il) x+=5;

  // 7
  custom_copy(ia.begin(), ia.end(), iv.begin());
  custom_copy(il.begin(), il.end(), ia.begin());

  auto result1 = std::find(iv.begin(), iv.end(), 3);
  int index1 = std::distance(iv.begin(), result1);

  auto result2 = std::find(il.begin(), il.end(), 27);
  int index2 = std::distance(il.begin(), result2);

  // distance
  // typename iterator_traits<_InputIter>::difference_type __r(0);
  //   for (; __first != __last; ++__first)
  //       ++__r;
  //   return __r;


  if(result1 != iv.end()) {
    std::cout << "3 Position: " << index1 << "\n--------------\n";
    for(auto x: iv) std::cout << x << std::endl;
    std::cout << "--------------\n";
  } else {
    std::cout << "3 Not found:\n--------------\n";
    for(auto x: iv) std::cout << x << std::endl;
    std::cout << "--------------\n";
  }
  if(result2 != il.end()){
    std::cout << "27 Position: " << index2 << "\n--------------\n";
    for(auto x: iv) std::cout << x << std::endl;
    std::cout << "--------------\n";
  } else {
    std::cout << "27 Not found:\n--------------\n";
    for(auto x: il) std::cout << x << std::endl;
    std::cout << "--------------\n";
  }

}

// 6
template<typename Iter1, typename Iter2>
Iter2 custom_copy(Iter1 f1, Iter1 e1, Iter2 f2)
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
// copies [f1,e1] to [f2,f2+(e1-f1)] and returns f2+(e1-f1)
// if f1==e1 sequence is empty
{
  while(f1!=e1)
  {
    *f2 = *f1;
    ++f1;
    ++f2;
  }
  return f2;
}
