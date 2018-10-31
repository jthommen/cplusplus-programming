#include "../std_lib_facilities.h"

// Version 9.4.1 - Struct and functions
struct Date {
  int y;
  int m;
  int d;
};

// Helper functions
void init_day(Date& dd, int y, int m, int d)
{
  if(y < 1800 || 2018 < y) error("Invalid year.");
  if(m < 1 || 12 < m) error("Invalid month.");
  if(d < 1 || 31 < d) error("Invalid day.");

  dd.y = y;
  dd.m = m;
  dd.d = d;
}

void add_day(Date& dd, int n)
{
  dd.d += n; // Ignore checks for wrapping to months or years
}

int main()
{
  Date today;
  init_day(today, 1978, 06, 25);
  Date tomorrow = today;
  add_day(tomorrow, 1);
  cout << "Today: " << today.y << "." << today.m << "." << today.d << endl;
  cout << "Tomorrow: " << tomorrow.y << "." << tomorrow.m << "." << tomorrow.d << endl;
}