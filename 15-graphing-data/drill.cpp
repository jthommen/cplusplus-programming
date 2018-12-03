#include "../lib/Graph.h"
#include "../lib/Window.h"

// supporting graphing function
double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main()
{
  using namespace Graph_lib;

  // constants
  constexpr Point top_left {100,100}; // window start
  constexpr int max = 600; // window size

  // origin
  constexpr int x_orig = 300;
  constexpr int y_orig = 300;
  constexpr Point orig{x_orig, y_orig};

  // axes lengths
  constexpr int xlength = 400;
  constexpr int ylength = 400;

  // axes offsets
  constexpr int x_offset = (max-xlength)/2;
  constexpr int y_offset = (max-ylength)/2;

  // axe scale for notches
  constexpr int x_scale = 20;
  constexpr int y_scale = 20;

  // data range -10, 11
  constexpr int r_min = -10;
  constexpr int r_max = 11;

  // window
  Window win {top_left, max, max, "Function Graphs"};

  // axes
  Axis x{Axis::x, Point{x_offset,max/2}, xlength, xlength/x_scale, "1 == 20 pixels"};
  x.set_color(Color::red);
  Axis y{Axis::y, Point{max/2,y_offset+ylength}, ylength, ylength/y_scale, "1 == 20 pixels"};
  y.set_color(Color::red);

  // graphing functions
  Function s1{one, r_min, r_max, orig, 400, x_scale, y_scale};
  s1.set_color(Color::yellow);
  Function s2{slope, r_min, r_max, orig, 400, x_scale, y_scale};
  Function s3{square, -sqrt(r_max), sqrt(r_max), orig, 400, x_scale, y_scale};
  s3.set_color(Color::green);
  Function s4{static_cast<double (*)(double)>(cos), r_min, r_max, orig, 400, x_scale, y_scale};
  s4.set_color(Color::blue);
  Function s5{[](double x) { return cos(x)+slope(x); }, r_min, r_max, orig, 400, x_scale, y_scale};
  s5.set_color(Color::dark_magenta);

  // graphing function labels
  Text ts2{Point{x_offset, ylength-y_scale}, "x/2"};

  win.attach(x);
  win.attach(y);
  win.attach(s1);
  win.attach(s2);
  win.attach(ts2);
  win.attach(s3);
  win.attach(s4);
  win.attach(s5);
  gui_main();

}
