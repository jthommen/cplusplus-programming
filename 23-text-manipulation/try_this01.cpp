#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

typedef std::vector<std::string>::const_iterator Line_iter; // type alias

class Message {
  Line_iter first;
  Line_iter last;
public:
  Message(Line_iter p1, Line_iter p2): first{p1},last{p2} {};
  Line_iter begin() const { return first; }
  Line_iter end() const { return last; }
};

using Mess_iter = std::vector<Message>::const_iterator; // alternative type alias

struct Mail_file {
  std::string name; // file name
  std::vector<std::string> lines; // lines in order
  std::vector<Message> m; // messages in order

  Mail_file(const std::string& n); // constructor reading file n into lines

  Mess_iter begin() const { return m.begin(); }
  Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const std::string& n)
// open file named n
// read lines from n into lines
// find the messages in the lines andcompose them in m
// for simplicity assume every message is ended by a ---- line
{
  std::ifstream in {n}; // open the file
  if(!in) {
    std::cerr << "no " << n << std::endl;
    exit(1);
  }

  for(std::string s; getline(in, s);) lines.push_back(s); // build line vector

  auto first = lines.begin(); // build vector of messages
  for(auto p = lines.begin(); p!=lines.end(); ++p)
  {
    if(*p == "----") // end of messages
    {
      m.push_back(Message(first,p));
      first = p+1; // not part of the message
    }
  }
}

int is_prefix(const std::string& s, const std::string& p)
// is p the prefix of s?
{
  int n = p.size();
  if(std::string(s,0,n)==p) return n;
  return 0;
}

bool find_from_addr(const Message* m, std::string& s)
// find the name of the sender message
// return true if found
// if found, save sender's name in s
{
  for(const auto& x : *m)
    if(int n = is_prefix(x, "From: ")) {
      s = std::string(x,n);
      return true;
    }
    return false;
}

std::string find_subject(const Message* m)
// return the subject of the Message, otherwise return empty string
{
  for(const auto& x: *m)
    if(int n= is_prefix(x, "Subject: ")) return std::string(x,n);
    return "";
}

void print_message(const Message* m)
// Iterating over lines in messages
// printing line for line
{
  int count = 0;
  for(const auto& x : *m)
  {
    count++;
    std::cout << "Line " << count<< ": " <<std::string(x,0) << std::endl;
    std::cout << "----\n";
  }
}

void print_message2(const Message* m)
{
  // This is...
  for(const auto& x: *m)
  {
    std::cout << "x: '" << x << "'\n";
  }
  
  // ....equivalent to: 
  // (Line_iter = std::vector<std::string>::const_iterator)
  // for(Line_iter i=m->begin(); i<m->end(); ++i)
  // {
  //   std::cout << "i: '" << *i << "'\n";
  // }
}

int main()
{
  Mail_file mfile{"my-mail-file.txt"};

  // 1. gather messages from each sender in multimap
  std::multimap<std::string, const Message*> sender;

  for (const auto& m : mfile)
  {
    std::string s;
    if(find_from_addr(&m, s))
      sender.insert(std::make_pair(s, &m));
  }

  // Printing out messages
  // int count = 0;
  // for(const auto& x : mfile.m) // Iterating over messages
  // {
  //   count++;
  //   std::cout << "Message: " << count << std::endl;;
  //   print_message(&x);
  // }
  print_message2(&mfile.m[1]);

  // 2. iterate through multimap, extract subjects of specified sender
  auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
  for(auto p = pp.first; p!=pp.second; ++p)
    std::cout << find_subject(p->second) << std::endl;
}
