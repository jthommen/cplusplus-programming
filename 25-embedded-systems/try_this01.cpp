#include<iostream>

struct Message
{
  double a;
  int b;
  int c;
};

struct Node
{
  int a;
  int b;
  int c;
};

void fragmentation()
{
  Message* p1 = new Message();

  for(int i=0; i<100; ++i)
  {
    Message* p = new Message();
    Node* n1 = new Node();
    delete p;
    Node* n2 = new Node();
  }

  Message* p2 = new Message();
  std::cout << "Memory use with fragmentation: " << p2-p1 << std::endl;
}

void no_fragmentation()
{
  Message* p1 = new Message();


  for(int i=0; i<100; ++i)
  {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Message* p = new Message();
    delete p;
  }

  Message* p2 = new Message();

  std::cout << "Memory use without fragmentation: " << p2-p1 << std::endl;
}

int main()
{
  std::cout << "sizeof(Message): " << sizeof(Message) << std::endl;
  std::cout << "sizeof(Node): " << sizeof(Node) << std::endl;
  fragmentation();
  no_fragmentation();
}
