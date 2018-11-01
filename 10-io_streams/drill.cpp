#include "../std_lib_facilities.h"

struct Point {
  int x;
  int y;
};

istream& operator>>(istream& is, Point& p)
// Parsing point coordinates of form: (x,y)
{
  
  // Checking if the format is okay
  char ch1;
  int x;
  char ch2;
  int y;
  char ch3;
  is >> ch1 >> x >> ch2 >> y >> ch3;
  if(!is) return is;
  if(ch1!='(' || ch2!=',' || ch3!=')') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  p = Point{x,y};
  return is;
}

ostream& operator<<(ostream& os, Point& p)
// Formating point coordinates for output: 
{
  return os << '(' << p.x << ',' << p.y << ')' << endl;
}

bool operator!=(Point& p1, Point& p2)
{
  return (p1.x == p2.x && p1.y == p2.y) ? false : true;
}

void points_to_file(vector<Point>& points, string& name){
  ofstream ost{name};
  if(!ost) error("can't open output file.");
  for(Point p: points) ost << p;
}

bool compare_point_vectors(vector<Point>& v1, vector<Point>& v2)
{
  bool similar = true;

  for(int i=0; i<v1.size(); i++) {
    if(v1[i] != v2[i]) similar = false; break;
  }
  return similar;
}

string bool_to_String(bool& b) 
{
  return b ? "true" : "false";
}

int main()
{
  Vector<Point> original_points;
  int input_number = 2;
  string data_file = "mydata.txt";

  // Asking for inputs and feeding them into the vector
  cout << "Please enter " << input_number << " coordinate pairs (x,y): \n";
  for(int i=0; i < input_number; i++){
    Point p;
    cin >> p; // Overloaded operator
    original_points.push_back(p);
  }
  cout << "Thanks!\n";
  for(Point p: original_points) cout << "Original: " << p;

  // Put data in file
  points_to_file(original_points, data_file);

  // Read points from file into vector
  Vector<Point> processed_points;
  ifstream ist{data_file};
  if(!ist) error("can't open input file.");
  while(true)
  {
    Point p;
    if(!(ist >> p)) break;
    processed_points.push_back(p);
  }

  // Compare vectors
  for(Point p: processed_points) cout << "Processed: " << p;
  bool similar = compare_point_vectors(original_points, processed_points);
  
  cout << "Vectors are equal: " << bool_to_String(similar) << endl;

}