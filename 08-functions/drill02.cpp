#include "../std_lib_facilities.h"

void  swap_v(int a, int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
};

void  swap_r(int& a, int& b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
};

/*
void  swap_cr(const int& a, const int& b)
{
  int temp; 
  temp=a;
  a=b; // Can't change const & type: Compile error
  b=temp; // Can't change const & type: Compile error
};
*/

int main() 
{
  int x = 7;
  int y = 9;

  swap_v(x,y); // Copy by value, originals not swapped
  cout << "swap_v(x,y) Args: " << x << " " << y << endl;
  swap_r(x,y); // Originals changed, swap occured
  cout << "swap_r(x,y) Args: " << x << " " << y << endl;

  const int cx = 7;
  const int cy = 9;
  swap_v(cx,cy); // Copy by value, originals not swapped
  cout << "swap_v(cx,cy) Args: " << cx << " " << cy << endl;
  // swap_r(cx,cy); // Doesn't compile. Can't change const

  swap_v(7.7, 9.9); // Compiles but won't swap because no variables in param.
  // swap_r(7.7, 9.9) // Doesn't compile, expects reference not expression

  double dx = 7.7;
  double dy = 9.9;
  swap_v(dx, dy); // Compiles but implicit conversion floors doubles. No swap occurs.
  cout << "swap_v(dx, dy) Args: " << dx << " " << dy << endl;
  // swap_r(dx, dy); // Doesn't compile since coercion from double to int& isn't possible.
  
}