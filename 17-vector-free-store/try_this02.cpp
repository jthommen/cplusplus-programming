#include<iostream>
#include<string>


class B {
public:
  B()
  {
    std::cout << "Constructor of 'B' called.\n";
    std::cout << "-----------------------------\n";
  }

  virtual ~B() {
    std::cout << "Destructor of 'B' called.\n";
    std::cout << "-----------------------------\n";
    }

};

class D:B {
public:
  D() // First calls default constructor of B and then of D.
  {
    std::cout << "Constructor of 'D' called.\n";
    std::cout << "-----------------------------\n";
  }

  // If no destructor, uses destructor of B.
  ~D()
  {
    std::cout << "Destructor of 'D' called.\n";
    std::cout << "-----------------------------\n";
  }

};

int main()
{
  // Order of Constructor / Destructor calls

  // Base class objet
  // std::cout << "Object of 'base' class created: \n";
  // B b;

  // Derived class object
  std::cout << "Object of 'derived' class created: \n";
  D d;
}
