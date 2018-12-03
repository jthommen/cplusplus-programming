#include "../lib/Graph.h"
#include "../lib/Point.h"
#include "../lib/Simple_window.h"
#include "../lib/Window.h"

// graphing setup functions
double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main()
{
  using namespace Graph_lib;

  // window size
  constexpr int xmax = 600;
  constexpr int ymax = 400;

  // 0,0 or the window center
  constexpr int x_orig = xmax/2;
  constexpr int y_orig = ymax/2;
  constexpr Point orig{x_orig, y_orig};

  // range from -10,11
  constexpr int r_min = -10;
  constexpr int r_max = 11;

  // number of points used in the range
  constexpr int n_points = 800;

  // scaling factors
  constexpr int x_scale = 30;
  constexpr int y_scale = 30;

  // create a window
  Simple_window win {Point{100,100}, xmax, ymax, "Function  Graphing"};

  // graph functions with setup variables
  Function s{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function s4{static_cast<double (*)(double)>(cos), r_min, r_max, orig, 400, 30, 30};
  s4.set_color(Color::dark_yellow);
  Function s5{[](double x) { return cos(x)+slope(x); }, r_min, r_max, orig, 400, 30, 30};
  s5.set_color(Color::dark_red);

  // creating labels
  Text ts{Point{100,y_orig-40}, "one"};
  Text ts2{Point{100,y_orig+y_orig/2-20}, "x/2"};
  Text ts3{Point{x_orig-100,20}, "x*x"};
  win.set_label("Function graphing: label functions");

  // creating axes
  constexpr int xlength = xmax-40;
  constexpr int ylength = ymax-40;

  Axis x{Axis::x, Point{20,y_orig},xlength, xlength/x_scale, "one notch == 1"};
  x.label.move(-160,0);
  Axis y{Axis::y, Point{x_orig, ylength+20}, ylength, ylength/y_scale, "one notch == 1"};

  x.set_color(Color::dark_blue);
  y.set_color(Color::dark_blue);

  // attaching elements to the window
  win.attach(s);
  win.attach(s2);
  win.attach(s3);
  win.attach(s4);
  win.attach(s5);
  win.attach(ts);
  win.attach(ts2);
  win.attach(ts3);
  win.attach(x);
  win.attach(y);
  win.wait_for_button();

}
