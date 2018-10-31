#include "../std_lib_facilities.h"


// Version 9.4.3 - Keep details private
class Date {
  int y, m, d;
public:
  Date(int y, int m, int d);
  void add_day(int n);
  int year() {return y;}
  int month() {return m;}
  int day() {return d;}
};

// Helper functions
Date::Date(int y, int m, int d): y{y}, m{m}, d{d}
{
  if(y < 1800 || 2018 < y) error("Invalid year.");
  if(m < 1 || 12 < m) error("Invalid month.");
  if(d < 1 || 31 < d) error("Invalid day.");
}

void Date::add_day(int n)
{
  d += n; // Ignore checks for wrapping to months or years
}

int main()
{
  Date today{1978, 06, 25};
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Today: " << today.year() << "." << today.month() << "." << today.day() << endl;
  cout << "Tomorrow: " << tomorrow.year() << "." << tomorrow.month() << "." << tomorrow.day() << endl;
}
