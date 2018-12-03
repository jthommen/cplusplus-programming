#include "../lib/std_lib_facilities.h"

// custom type
struct Person
{
  Person() { };
  Person(string n1, string n2, int a);
  const string first_name() { return first; }
  const string last_name() { return last; }
  const int age() { return a; }

private:
// can't have the same name as getter functions
  string first;
  string last;
  int a;

};

// checking function for names
bool check_name(string name)
{
  int name_size = name.size();
  string forbidden = ";:\"\'[]*&^%$#@!";
  vector<char> v(forbidden.begin(), forbidden.end());
  for(int i=0; i<name_size; ++i)
  {
    for(int c=0; c<v.size(); c++)
    {
      if(name[i] == v[c]) return false;

    }
  }
  return true;
}

Person::Person(string n1, string n2, int a): first{n1}, last{n2}, a{a}
{
  // Initialization checks
  if(a < 0 || a > 150) error("Age invalid.");

  if(check_name(n1) == false || check_name(n2) == false) {
    error("Name contains invalid characters.");
  }
}

// operator overloading for custom type
istream& operator>>(istream& is, Person& p)
{
  string first = "";
  string last ="";
  int age = 0;
  is >> first >> last >> age;
  if(first == "" || last == "" || age < 1) error("Not enough data to describe a person.");
  if(!is) return is;
  p = Person{first, last, age};
  return is;
}

ostream& operator<<(ostream& os, Person& p)
{
  return os << "Person - First Name: " << p.first_name()
    << ", Last Name: " << p.last_name() << ", Age: " << p.age() << ".\n";
}

int main()
{
  Vector<Person> characters;
  cout << "Please enter characters with first name, last name and age, separated by spaces. Press CTRL + D when you're done.\n";
  Person p;
  while(cin >> p)
  {
    characters.push_back(p);
  }
  cout << endl;
  for(int i=0; i<characters.size(); ++i)
  {
    cout << characters[i] << endl;;
  }

}
