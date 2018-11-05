#include "../lib/Simple_window.h"
#include "../lib/Graph.h"
#include "../lib/Point.h"

int main() 
{
  using namespace Graph_lib;
  
  Point tl{100, 100};
  Simple_window win {tl, 600, 400, "My window"};

  // X axis
  Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"}; // Axis Shape, x=horizontal, starting at 20 300, 280 length, 10 notches, x axis label.
  win.attach(xa);

  // Y axis
  Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::cyan);
  ya.label.set_color(Color::dark_red);
  win.attach(ya);

  // Graphing function
  Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50}; // sine curve, range 0:100, start at 20 150, use 1000 points, scale x 50, scale y 50.
  sine.set_color(Color::blue);
  win.attach(sine);
  
  // Polygon
  Polygon poly;
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});

  poly.set_color(Color::red);
  poly.set_style(Line_style(Line_style::dash, 4));
  win.attach(poly);

  // Rectangle
  Rectangle r {Point{200,200}, 100, 50}; // top left corner, width, height
  r.set_fill_color(Color::yellow);
  win.attach(r);

  // Closed Polyline rectangle
  Closed_polyline poly_rect;
  poly_rect.add(Point{100,50});
  poly_rect.add(Point{200,50});
  poly_rect.add(Point{200,100});
  poly_rect.add(Point{100,100});
  poly_rect.add(Point{50,75});
  poly_rect.set_style(Line_style(Line_style::dash,2));
  poly_rect.set_fill_color(Color::green);
  win.attach(poly_rect);

  // Text
  Text t{Point{150,150}, "Hello, graphical world!"};
  t.set_font(Font::times_bold);
  t.set_font_size(20);
  win.attach(t);

  //Images
  Image i1{Point{100,50}, "space.jpg"};
  i1.move(100,200);
  win.attach(i1);

  // Other
  Circle c {Point{100,200}, 50};
  win.attach(c);
  Ellipse e {Point{100,200}, 75, 25};
  win.attach(e);
  e.set_color(Color::dark_red);
  Mark m {Point{100,200}, 'x'};
  win.attach(m);
  
  ostringstream oss;
  oss << "screen size: " << x_max() << "*" << y_max()
      << "; window size: " << win.x_max() << "*" << win.y_max();
  Text sizes{Point{100,20}, oss.str()};
  win.attach(sizes);

  Image i2 {Point{225, 225}, "space.jpg"};
  i2.set_mask(Point{40,40}, 200, 150);
  win.attach(i2);

  win.wait_for_button();
}