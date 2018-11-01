#include "../std_lib_facilities.h"

int main() {

  // Integers representations
  int birth_year = 1987;
  int age = 31;

  cout << "Birth year:\n";
  cout << showbase << birth_year << "\t(decimal)\n";
  cout << hex << birth_year << "\t(hexadecimal)\n";
  cout << oct << birth_year << "\t(octal)\n";
  cout << endl;
  cout << "Age:\n";
  cout << dec << age << "\t(decimal)\n";
  cout << hex << age << "\t(hexadecimal)\n";
  cout << oct << birth_year << noshowbase <<"\t(octal)\n";

  // Floating-point representations
  float constexpr pi = 3.14159265359;
  cout << pi << "\t\t(default float)\n";
  cout << fixed <<pi << "\t(fixed)\n";
  cout << scientific <<pi << "\t(scientific)\n";
}