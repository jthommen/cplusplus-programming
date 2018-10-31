#include "../std_lib_facilities.h"


// Version 9.7.4 - const member functions
enum class Month {
  jan=1, feb, mar, apr, mai, jun, jul, aug, sep, okt, nov, dec
};

class Year {
public:
  class Invalid {};
  Year(int x): y{x} {if(x<min || max<=x) throw Invalid{};}
  int year() {return y;}
private:
  int y;
  static const int min = 1800;
  static const int max = 2100;
};

class Date {
public:
  // Constructor
  Date(Year y, Month m, int d);
  
  // Getters
  Year year() const {return y;}
  Month month() const {return m;}
  int day() const {return d;}
  
  // Modifying operations
  void add_day(int n);
private:
  Year y;
  Month m;
  int d;
};

// Operator overloading
ostream& operator<<(ostream& os, Date& d)
{
  return os << "Date: " << d.year().year() // Double call since both class variables are private
            << '.' << int(d.month()) // Explicit cast to int needed for enum class
            << '.' << d.day() << endl;
}

Date::Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd}
{
  // Initialization checks
  if(mm < Month::jan || Month::dec < mm) error("Invalid month.");
  if(dd < 1 || 31 < dd) error("Invalid day.");
}

void Date::add_day(int n)
{
  d += n; // Ignore checks for wrapping to months or years
}

int main()
{
  Date today{Year{1998}, Month::sep, 25};
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Today: " << endl << today << endl;
  cout << "Tomorrow: " << endl << tomorrow << endl;
}
