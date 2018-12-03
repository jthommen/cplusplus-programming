#include "../lib/Graph.h"
#include "../lib/Point.h"
#include "../lib/Simple_window.h"
#include "../lib/Window.h"

// factorial function: factorial(n); n!
double fac(int n)
{
  double r = 1;
  while (n>1) {
    r*=n;
    --n;
  }
  return r;
}

// graph setup function
double term(double x, int n) { return pow(x,n)/fac(n); }

// exponential function
double expe(double x, int n)
{
  double sum = 0;
  for(int i=0; i<n; ++i) sum+=term(x,i);
  return sum;
}

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
  constexpr int n_points = 200;

  // scaling factors
  constexpr int x_scale = 30;
  constexpr int y_scale = 30;

  // create a window
  Simple_window win {Point{100,100}, xmax, ymax, "Exponential Approximation"};

  // creating axes
  constexpr int xlength = xmax-40;
  constexpr int ylength = ymax-40;

  Axis x{Axis::x, Point{20,y_orig},xlength, xlength/x_scale, "one notch == 1"};
  x.label.move(-160,0);
  Axis y{Axis::y, Point{x_orig, ylength+20}, ylength, ylength/y_scale, "one notch == 1"};

  x.set_color(Color::dark_blue);
  y.set_color(Color::dark_blue);

  // std lib exp function
  // Adapted static cast to work around the error using a capture list with normal function pointers in Graph.h
  // https://groups.google.com/forum/#!topic/ppp-public/WBHYlwS6m3g
  Function real_exp{ static_cast<double (*)(double)>(exp), r_min, r_max, orig, 200, x_scale, y_scale };
  real_exp.set_color(Color::blue);

  win.attach(x);
  win.attach(y);
  win.attach(real_exp);

  for(int n=0; n<50; ++n) {
    ostringstream ss;
    ss << "exp approximation; n==" << n;
    win.set_label(ss.str());
    // next approximation
    Function e{[n](double x) { return expe(x,n); },
      r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(e);
    win.wait_for_button();
    win.detach(e);
  }
  win.wait_for_button();

}
