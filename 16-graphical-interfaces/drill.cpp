#include "../lib/Graph.h"
#include "../lib/GUI.h"
#include "../lib/Window.h"

using namespace Graph_lib;

struct Lines_window : Window {
  Lines_window(Point xy, int w, int h, const string& title); // Constructor

private:
  // data
  Open_polyline lines; // Polyline to be constructed by adding points

  // widgets
  Button next_button; // Add next point to the line
  Button quit_button; // Quit program
  In_box next_x; // Input box coordinates
  In_box next_y;
  Out_box xy_out; // Output box showing last point
  Menu color_menu; // Menu to add buttons for color change of the polyline
  Button color_button;
  Menu style_menu;
  Button style_button;

  //  Color menu button actions
  void red_pressed() { change_color(Color::red); hide_color();}
  void blue_pressed() { change_color(Color::blue); hide_color();}
  void black_pressed() { change_color(Color::black); hide_color();}

  void change_color(Color c) {lines.set_color(c); redraw();};

  void color_pressed() { color_button.hide(); color_menu.show();}
  void hide_color() {color_menu.hide(); color_button.show();}

  // Style menu button actions
  void solid_pressed() {change_style(Line_style::solid); hide_style();}
  void dash_pressed() {change_style(Line_style::dash); hide_style();}
  void dot_pressed() {change_style(Line_style::dot); hide_style();}

  void change_style(Line_style ls) {lines.set_style(ls); redraw();}

  void style_pressed() {style_button.hide(); style_menu.show();}
  void hide_style() {style_menu.hide(); style_button.show();}


  // Polyline button actions
  void next();
  void quit();
};

// Lines_window Constructor
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
  :Window{xy,w,h,title}, // handing initializer values to base class window
  next_button{Point{x_max()-150,0}, 70, 20, "Next Point",
    [](Address, Address pw){reference_to<Lines_window>(pw).next();}},
  quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
    [](Address, Address pw){reference_to<Lines_window>(pw).quit();}},
  next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
  next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
  xy_out{Point{100,0}, 100,20, "current (x,y):"},
  color_menu{Point{x_max()-70,40}, 70, 20, Menu::vertical, "color"},
  color_button{Point{x_max()-70, 40}, 70, 20, "color menu",
    [](Address, Address pw) {reference_to<Lines_window>(pw).color_pressed();}},
  style_menu{Point{x_max()-150, 40}, 70, 20, Menu::vertical, "style"},
  style_button{Point{x_max()-150, 40}, 70, 20, "style menu",
  [](Address, Address pw) {reference_to<Lines_window>(pw).style_pressed();}}
{
  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(xy_out);

  // unnamed objects created with new keyword ensure they're not destroyed in a context switch
  color_menu.attach(new Button{Point{0,0},0,0,"red",
    [](Address, Address pw){reference_to<Lines_window>(pw).red_pressed();}});
  color_menu.attach(new Button{Point{0,0},0,0,"blue",
    [](Address, Address pw){reference_to<Lines_window>(pw).blue_pressed();}});
  color_menu.attach(new Button{Point{0,0},0,0,"black",
    [](Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}});
  attach(color_menu);
  color_menu.hide();
  attach(color_button);

  style_menu.attach(new Button{Point{0,0},0,0, "solid",
    [](Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}});
  style_menu.attach(new Button{Point{0,0},0,0, "dash",
    [](Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}});
  style_menu.attach(new Button{Point{0,0},0,0, "dot",
    [](Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}});
  attach(style_menu);
  style_menu.hide();
  attach(style_button);

  attach(lines);
}

// Lines_window function implementations
void Lines_window::next()
// Reads pair of coordinares
// Updates the Open_polyline
// Updates position radout
// Redraws the window
{
  int x = next_x.get_int();
  int y = next_y.get_int();

  lines.add(Point{x,y});

  ostringstream ss;
  ss << '(' << x << ',' << y << ')';
  xy_out.put(ss.str()); // str() gets us the string within the stream

  redraw();
}

void Lines_window::quit()
{
  hide(); // FLTK idiom to delete window
}

int main()
{

try {
  Lines_window win {Point{100,100}, 600, 400, "Lines"};
  return gui_main();
}
catch(exception& e) {
  cerr << "exception: " << e.what() << '\n';
  return 1;
}
catch(...) {
  cerr << "Some exception\n";
  return 2;
}

}
