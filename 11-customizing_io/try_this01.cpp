#include "../std_lib_facilities.h"

int main() {

  // unset default arguments for cin
  cin.unsetf(ios::dec);
  cin.unsetf(ios::oct);
  cin.unsetf(ios::hex);

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  //cin >> a >> hex >> b >> oct >> c >> d;
  cout << a << '\t' << b << '\t' << c << '\t'  << d << '\n' ;
}