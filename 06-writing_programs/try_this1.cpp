#include "../std_lib_facilities.h"

double term();
double primary();
double expression();

int main() 
try {
  while(cin)
    cout << "boilerplate" << endl;
}
catch(exception& e) {
  cerr << e.what() << endl;
  return 1;
}
catch(...) {
  cerr << "exception\n";
  return 2;
}