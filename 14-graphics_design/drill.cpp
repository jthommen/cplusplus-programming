#include "../lib/std_lib_facilities.h"

class B1 {
  public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    virtual void pvf() =0;
};

class B2 {
  public:
    virtual void pvf() =0;
};


class D1: public B1 {
  public:
    void vf() override { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

class D2: public D1 {
  public:
    void pvf() { cout << "D2::pvf()\n"; }
};

class D21: public B2 {
  public:
    void pvf() { cout << "D21::pvf(): " << m << endl; }
  private:
    const string m = "Hello virtual!";
};

class D22: public B2 {
  public:
    void pvf() { cout << "D22::pvf(): " << m << endl; }
  private:
    const int m = 42;
};

void f(B2& obj) {
  obj.pvf();
}

int main() {
  /*
  cout << "B1 object: \n";
  B1 b; // Error can't create instance of interface
  b.vf();
  b.f();

  cout << "D1 object: \n";
  D1 d1; // Have to overwrite pure virtual before instantiation of subl cass
  d1.vf();
  d1.f();

  cout << "B1 Reference initialized to d1: \n";
  B1& b1r = d1;
  // Reference to B1 takes overwritten function from assigned sub class object
  b1r.vf();
  b1r.f();
  */

  cout << "D2 object:\n";
  D2 d2;
  d2.vf();
  d2.f();
  d2.pvf();

  cout << "D21 & D22 objects:\n";
  D21 d21;
  D22 d22;
  f(d21);
  f(d22);
}
