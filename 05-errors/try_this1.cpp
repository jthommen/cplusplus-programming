#include "../std_lib_facilities.h"

// Function headers
int area(int length, int width);
int framed_area(int length, int width);
void f(int x, int y, int z);

// a type specifically for reproting errors from area()
class Bad_area {};

int main()
{
  try {
    int x = -1;
    int y = 2;
    int z = 4;

    f(x,y,z);
  } catch(Bad_area) {
    cout << "Oops! Bad arguments to area()\n";
  }
}

// Arguments checked by function
// throw a Bad_area exception incae of a bad argument
int area(int length, int width)
{
  if(length <= 0 || width <= 0) throw Bad_area{};
  return length * width;
}

int framed_area(int length, int width) // calculate area within frame
{
  constexpr int frame_width = 2;
  if(length-frame_width <= 0 || width-frame_width <=0)
    error("non-positive area() argument called by framed_area()");
  return area(length-frame_width, width-frame_width);
}

void f(int x, int y, int z)
{
  int area1 = area(x,y);
  if(area1 <= 0) error("non-positive area.");
  int area2 = framed_area(3,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1)/area3;  
}