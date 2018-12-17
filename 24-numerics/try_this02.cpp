#include<iostream>

void f(int i, double fpd)
{
  char c = i;
  std::cout << "c: " << c << std::endl;
  short s = i;
  std::cout << "s: " << s << std::endl;
  i = i+1;
  std::cout << "i: " << i << std::endl;
  long lg = i*i;
  std::cout << "lg: " << lg << std::endl;
  float fps = fpd;
  std::cout << "fps: " << fps << std::endl;
  i = fpd;
  std::cout << "i: " << i << std::endl;
  fps = i;
  std::cout << "fps: " << fps << std::endl;

}

void g()
{
  char ch = 0;
  for(int i=0; i<500; ++i) std::cout << int(ch++) << '\t';
  std::cout << std::endl;
}

int main()
try {

  f(96, 4.4);
  g();
}catch(...)
{
  std::cerr << "An error occured.\n";
}