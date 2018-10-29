#include "../std_lib_facilities.h"

int main()
try {
  // 9
  string s ="ape";
  bool c =  true;
  if(c) cout << "Success!\n";
  //

  return 0;
}
catch(exception& e) {
  cerr << "error: " << e.what() <<'\n';
  return 1;
}
catch(...) {
  cerr << "Oops: unkown exception!\n";
  return 2;
}