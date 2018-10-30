
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

const string prompt = "> ";
const string result = "= ";
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

// Token creation
// Constructor for numbers, operators or variables.
struct Token
{
  char kind;
  double value;
  string name;
  Token(char ch) : kind(ch), value(0) {} // Operator
  Token(char ch, double val) : kind(ch), value(val) {} // Floating-point literal
  Token(char ch, string val) : kind(ch), name(val) {} // Variable
};

// Stream of token to read in for grammar execution
// Has a buffer capable of holding one token
class Token_stream
{
  bool full; // Full when a character is held
  Token buffer; // Token to but in buffer

public:
  Token_stream() : full(0), buffer(0) {} // Initialize with empty buffer

  Token get();

  // Puts token in the buffer
  // TODO(jthommen): Check if buffer full
  void unget(Token t)
  {
    buffer = t;
    full = true;
  }

  void ignore(char);
};

// Retrieve from buffer or standard input
Token Token_stream::get()
{
  if (full)
  {
    full = false;
    return buffer;
  }
  char ch;
  cin >> ch;
  switch (ch)
  {
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case ';':
  case '=':
  case 'Q':
    return Token(ch);
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  {
    cin.unget(); // Put extracted char back in the stream
    double val;
    cin >> val;
    return Token(number, val);
  }
  default: // applies when no number or operator was found

  // variable name is constructed here
  // must start with a char and can consist of chars and digits
    if (isalpha(ch)) // checks for alphabetic
    {
      string s;
      s += ch;
      while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
        s += ch;
      cin.unget();
      if (s == "let")
        return Token(let); // name & let are constants here
      if (s == "quit")
        return Token(quit); 
      return Token(name, s); // name is constant and s is variable, confusing.
    }
    error("Bad token");
    return Token(' ');
  }
}

// Ignores all chars up to and including argument char given
void Token_stream::ignore(char c)
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }
  full = false;

  char ch;
  while (cin >> ch)
    if (ch == c)
      return;
}

// Structure for variables, initialized as name-value pair
struct Variable
{
  string name;
  double value;
  Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> names; // Vector holding variable names

// Get variable value by name
double get_value(string s)
{
  for (int i = 0; i < names.size(); ++i)
    if (names[i].name == s)
      return names[i].value;
  error("get: undefined name ", s);
}

// Set variable value
void set_value(string s, double d)
{
  for (int i = 0; i <= names.size(); ++i)
    if (names[i].name == s)
    {
      names[i].value = d;
      return;
    }
  error("set: undefined name ", s);
}

// Check if variable exist
bool is_declared(string s)
{
  for (int i = 0; i < names.size(); ++i)
    if (names[i].name == s)
      return true;
  return false;
}

// Object holding tokens
Token_stream ts;

// Variable declaration so it can be referenced in primary
double expression();

double primary()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '(':
  {
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("'(' expected");
  }
  case '-':
    return -primary(); // Handling negative numbers
  case number:
    return t.value;
  case name:
    return get_value(t.name);
  default:
    error("primary expected");
  }
}

double term()
{
  double left = primary();
  while (true)
  {
    Token t = ts.get();
    switch (t.kind)
    {
    case '*':
      left *= primary();
      break;
    case '/':
    {
      double d = primary();
      if (d == 0)
        error("divide by zero");
      left /= d;
      break;
    }
    case '%':
    {
      double d = primary();
      if(d == 0) error("%: divide by zero.");
      left = fmod(left, d);
      break;
    }
    default:
      ts.unget(t);
      return left;
    }
  }
}

double expression()
{
  double left = term();
  while (true)
  {
    Token t = ts.get();
    switch (t.kind)
    {
    case '+':
      left += term();
      break;
    case '-':
      left -= term();
      break;
    default:
      ts.unget(t);
      return left;
    }
  }
}

// Declare variable and store in vector
double declaration()
{
  Token t = ts.get();
  if (t.kind != 'a')
    error("name expected in declaration");
  string name = t.name;
  if (is_declared(name))
    error(name, " declared twice");
  Token t2 = ts.get();
  if (t2.kind != '=')
    error("= missing in declaration of ", name);
  double d = expression();
  names.push_back(Variable(name, d));
  return d;
}

double statement()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case let:
    return declaration();
  default:
    ts.unget(t);
    return expression();
  }
}

// Bad naming, allow continuing after error occured
void clean_up_mess()
{
  ts.ignore(print);
}

// Main calculator function
// Looking for input and triggering variable declaration and calculation
void calculate()
{
  while (true)
    try
    {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        t = ts.get();
      if (t.kind == quit)
        return;
      ts.unget(t);
      cout << result << statement() << endl;
    }
    catch (runtime_error &e)
    {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}


int main() try
{

  cout << "This is a simple calculator.\n";
  cout << "Please enter floating point numbers only.\n";
  cout << "Operators available are: +, -, *, / and %.\n";
  cout << "You can set variables. e.g. let name = 5.\n";
  cout << "Type ; to print a value or Q to quit.\n"; 

  calculate();
  return 0;
}
catch (exception &e)
{
  cerr << "exception: " << e.what() << endl;
  char c;
  while (cin >> c && c != ';')
    ;
  return 1;
}
catch (...)
{
  cerr << "exception\n";
  char c;
  while (cin >> c && c != ';')
    ;
  return 2;
}
