#include "../std_lib_facilities.h"

struct Reading {
  int hour;
  double temperature;
};

int main()
{
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist{iname}; // Initializing ist stream by opening file <iname>
  if(!ist) error("can't open input file ", iname); // Checking if open was successful

  string oname;
  cout << "Please enter output file name: ";
  cin >> oname;
  ofstream ost{oname}; 
  if(!ost) error("can't open output file ", oname);

  vector<Reading> temps; // store read input here
  int hour;
  double temperature;
  while(ist >> hour >> temperature) {
    if(hour < 0 || 23 < hour) error("hour out of range");
    cout << "Time: " << hour << " h, Temperature: " << temperature << " C.\n";
    temps.push_back(Reading{hour, temperature});
  }

  for(int i = 0; i < temps.size(); ++i)
    ost << '(' << temps[i].hour << ','
        << temps[i].temperature << ")\n";
}