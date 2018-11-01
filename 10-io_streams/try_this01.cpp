#include "../std_lib_facilities.h"

struct Reading {
  int hour;
  double temperature;
};

int main()
{
  // Getting input file
  cout << "Please enter input file name: ";
  string iname;
  cin >> iname;
  ifstream ist{iname}; // Initializing ist stream by opening file <iname>
  if(!ist) error("can't open input file ", iname); // Checking if open was successful

  // Storing input from file in memory
  vector<Reading> temps; // store read input here
  int hour;
  double temperature;
  while(ist >> hour >> temperature) {
    if(hour < 0 || 23 < hour) error("hour out of range");
    cout << "Time: " << hour << " h, Temperature: " << temperature << " C.\n";
    temps.push_back(Reading{hour, temperature});
  }
  ist.close();

  // Getting output file
  string oname;
  cout << "Please enter output file name: ";
  cin >> oname;
  ofstream ost{oname, ios_base::app}; 
  if(!ost) error("can't open output file ", oname);

  cout << "Output: \n";
  // Storing output from memory in file
  for(int i=0; i < temps.size(); ++i)
  {
    cout << '(' << temps[i].hour << ','
        << temps[i].temperature << ")\n";
    ost << '(' << temps[i].hour << ','
        << temps[i].temperature << ")\n";
  }
    
}