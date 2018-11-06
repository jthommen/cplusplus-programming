#include "../lib/Simple_window.h"
#include "../lib/Graph.h"
#include "../lib/Point.h"

int main() 
{
  using namespace Graph_lib;
  
  constexpr Point p{100, 100};
  Simple_window win{p, 800, 800, "Grid"};

  // Setting up grid size
  int grid_size = win.y_max();
  int square_size = 100;

  Lines grid;
  Vector_ref<Rectangle> diagonal;
  for(int x=0; x<(grid_size/square_size); x++)
  {
    grid.add(Point{x*square_size, 0}, Point{x*square_size, grid_size});
    grid.add(Point{0, x*square_size}, Point{grid_size, x*square_size});
    diagonal.push_back(new Rectangle {Point{x*square_size,x*square_size}, square_size, square_size});
    diagonal[x].set_fill_color(Color::dark_magenta);
    win.attach(diagonal[x]);

  }
  win.attach(grid);

  Image r1 {Point{0, 200}, "rocket.jpg"};
  Image r2 {Point{0, 500}, "rocket.jpg"};
  Image r3 {Point{500, 0}, "rocket.jpg"};
  Image r4 {Point{600, 400}, "rocket.jpg"};
  win.attach(r1);
  win.attach(r2);
  win.attach(r3);
  win.attach(r4);


  for(int x=7; x>0; x--)
  {
    
    Image moon{Point{x*square_size,x*square_size}, "moon.jpg"};
    win.attach(moon);
    win.wait_for_button(); 
  }
}
