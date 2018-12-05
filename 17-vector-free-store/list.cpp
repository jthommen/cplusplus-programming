#include <iostream>
#include <string>

class Link {
public:
  std::string value;

  Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
    :value{v}, prev{p}, succ{s} { }

  Link* insert(Link* n);
  Link* add(Link* n);
  Link* erase();
  Link* find(const std::string&s);
  // const Link* find(const string&s) const;
  Link* advance(int n);

  Link* next() const { return succ; }
  Link* previous() const { return prev; }

private:
  Link* prev;
  Link* succ;

};

Link* Link::insert(Link* n) // insert n before p = this
{
  if(n==nullptr) return this;
  n -> succ = this; // p comes after n
  if(prev) prev -> succ = n; // n comes after what used to be p's predecessor
  n -> prev = prev; // p's predecessor becomes n's predecessor
  prev = n; // n becomes p's predecessor
  return n;
}

Link* Link::add(Link* n) // insert n after p = this
{
  if(n==nullptr) return this;
  n -> prev = this; // n comes after p
  if(succ) succ -> prev = n; // n comes after what used to be p's successor
  n -> succ = succ; // p's predecessor becomes n's predecessor
  succ = this; // n becomes p's successor
  return n;
}

Link* Link::erase() // remove *p from list; return p's (this) predecessor
{
  if(succ) succ -> prev = prev;
  if(prev) prev -> succ = succ;
  return succ;
}

Link* Link::find(const std::string& s)
// find s in list
// return nullptr for "not found"
{
    if(value == s) return this;
    return succ -> find(s);
}

Link* Link::advance(int n) // move n positions in list
// return nullptr for "not found"
// positive n moves forward, n backward
{
  Link* p = this;
  if(p==nullptr) return nullptr;
  if(n>0){
    while(n--) {
      if(p -> succ == nullptr) return nullptr;
      p = p -> succ;
    }
  } else if(n<0) {
    while(n++) {
      if(p -> prev == nullptr) return nullptr;
      p = p -> prev;
    }
  }
  return p;
}

void print_all(Link* p)
{
  std::cout << "{ ";
  while(p){
    std::cout << p -> value;
    if(p-> next()) std::cout << ", ";
    p = p -> next();
  }
  std::cout << " }";
}

int main()
{
  Link* norse_gods = new Link("Thor");
  norse_gods = norse_gods -> insert(new Link{"Odin"});
  norse_gods = norse_gods -> insert(new Link{"Zeus"});
  norse_gods = norse_gods -> insert(new Link{"Freia"});

  Link* greek_gods = new Link("Hera");
  greek_gods = greek_gods -> insert(new Link{"Athena"});
  greek_gods = greek_gods -> insert(new Link{"Mars"});
  greek_gods = greek_gods -> insert(new Link{"Poseidon"});

  // correcting mistakes
  Link* pg = greek_gods -> find("Mars"); // Bug won't get found
  if(pg) { pg -> value = "Ares"; }

  Link* pn = norse_gods -> find("Zeus");
  if(pn) {
    // if erased pointer is the one pointed to by norse_gods we're in trouble
    if(pn == norse_gods) norse_gods = pn -> next();
    pn->erase(); // doesn't really delete the link or change the pointer p
    greek_gods = greek_gods -> insert(pn);
  }

  print_all(norse_gods);
  std::cout << std::endl;

  print_all(greek_gods);
  std::cout << std::endl;
}
