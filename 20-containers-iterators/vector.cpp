#include<iostream>
#include<memory>
#include<string>

// ----------------------------------------------------------------------------
// Custom errors
// ----------------------------------------------------------------------------
struct out_of_range{ };
struct memory_alloc{ };

// ----------------------------------------------------------------------------
// Memory allocator
// ----------------------------------------------------------------------------
template<typename T>
class allocator {
public:
  // allocate spacefor n objects of type T
  T* allocate(int n);

  // deallocate n objects of type T starting at p
  void deallocate(T* p) { free(p); }

  // construct a T with the value v in p
  void construct(T* p, const T&v) { new(p) T(v); }

  // destroy the T in p
  void destroy(T* p) { p->~T(); }
};

template<typename T>
T* allocator<T>::allocate(int n)
// allocate space for n objects of type t
{
  T* p = static_cast<T*>(malloc(n*sizeof(T)));
  if(p==0) throw memory_alloc();
  return p;
}

// ----------------------------------------------------------------------------
// Vector implementation
// ----------------------------------------------------------------------------
template<typename T, typename A = allocator<T>> // type paramter: For all types T
class vector {
/*
  invariant:
  if 0 <= sz, elem[n] is element n
  sz <= space
  if sz < space, there is space for (space-sz) doubles after elem[sz-1]
*/
  A alloc; // use allocate to handle memory for elements

  int sz; // number of elements
  T* elem; // pointer to the first element (of type T)
  int space; // number of elements plus "free space" slots
public:
  vector():sz{0}, elem{nullptr}, space{0} { }; //default constructor
  explicit vector(int s); // simple explicit constructor
  vector(std::initializer_list<T>lst); // initializer-list constructor

  using size_type = unsigned long;
  using value_type = T;
  using iterator = T*;
  using const_iterator = const T*;

  vector(const vector& v); // copy constructor (deep copying)
  vector& operator=(const vector& v); // copy assignment (deep copying)

  vector(vector&& v); // move constructor
  vector& operator=(vector&& v); // move assignment

  // range checked access
  T& at(int n);
  const T& at(int n) const;

  T& operator[](int n); // subscript operator
  const T& operator[](int n) const; // subscript operator with explicit const for compiler

  // vector iteration helper functions
  iterator begin() { return elem; }
  const_iterator begin() const { return elem; }
  iterator end() { return elem+sz; }
  const_iterator end() const { return elem+sz; }

  ~vector() // destructor
  {
    delete[] elem; // free memory
  }

  size_type size() const { return sz; } // return current size
  int capacity() const { return space; } // return current allocated space

  void resize(int newsize, T val = T()); // resizing current vector
  void push_back(const T& d); // adding new element to the end of elems
  void push_front(const T& d); // adding new element to the front of elems
  void reserve(int newalloc); // reserving space for vector expansion

  iterator insert(iterator p, const T& val);
  iterator erase(iterator p);

};

// range checked access
template<typename T, typename A> T& vector<T,A>::at(int n)
{
  if(n<0 || sz <=n) throw out_of_range();
  return elem[n];
}

template<typename T, typename A> const T& vector<T,A>::at(int n) const
{
  if(n<0 || sz <=n) throw out_of_range();
  return elem[n];
}

template<typename T, typename A> vector<T,A>::vector(int s) // simple constructor
  :sz{s}, // initialize sz
  elem{new T[s]}, // initialize elem, new returns pointer to the first elem
  space{s}
{
  for (int i=0; i<s; ++i) elem[i]=0; // initialize elements
}

template<typename T, typename A> vector<T,A>::vector(std::initializer_list<T>lst) // initializer-list constructor
  :sz{int(lst.size())}, elem{new T[sz]} // uninitialized memory with size of initializer list
{
  std::copy(lst.begin(), lst.end(),elem); // initialize elems
}

template<typename T, typename A> vector<T,A>::vector(const vector& v) // copy constructor (deep copying)
// allocate elements, then initialize them by copying
  :sz{v.sz}, elem{new T[v.sz]}
{
  // v.elem+sz: pointer to first T elem address + int = address of last elem!
  std::copy(v.elem, v.elem+sz, elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& v) // copy assignment (deep copying)
// make this a copy of v
{
  if(this == &v) return *this; // self-assignment, no work needed

  if(v.sz<=space) // enough space, no need for new allocation
  {
    std::copy(v.elem, v.elem+sz, elem); // copy elements
    sz = v.sz;
    return *this;
  }

  // not enough space, allocate new one
  T* p = new T[v.sz]; // allocate new space on the free store
  std::copy(v.elem, v.elem+sz, p); // copy elements to p
  delete[] elem; // deallocate old space
  elem = p; // reset elem on this and point them to the new elements in p
  space = sz = v.sz; // set size & space
  return *this; // return a self-reference
}

template<typename T, typename A> vector<T,A>::vector(vector&& v) // move constructor
  :sz{v.sz}, elem{v.elem} // copy a's elem and sz
{
  v.sz = 0; // make v an empty vector
  v.elem = nullptr;
}

template<typename T, typename A> vector<T,A>& vector<T,A>::operator=(vector&& v) // move assignment
{
  delete[] elem; // deallocate old space of this object
  elem = v.elem; // copy v's elem and sz
  sz = v.sz;
  v.elem = nullptr; // set v to empty vector
  v.sz = 0;
  return *this; // return self-reference
}

template<typename T, typename A> T& vector<T,A>::operator[](int n) // subscript operator
{
  return elem[n]; // return reference
}

template<typename T, typename A> const T& vector<T,A>::operator[](int n) const // subscript operator with explicit const for compiler
{
  return elem[n]; // return value
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc) // reserving space for vector expansion
{
  if(newalloc<=space) return; // never decrease allocation
  std::unique_ptr<T[]> p(alloc.allocate(newalloc)); // allocate new space
  for(int i=0; i<sz; ++i) alloc.construct(&p[i], elem[i]); // copy old elements
  for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]); // destroy
  alloc.deallocate(elem); // deallocate old space
  elem = p.release();
  space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val) // resizing current vector
// T(): use T() as default value unless the user says otherwise
// make the vector have newsize elements
// initialize each new element with the default value 0.0
{
  reserve(newsize);
  for(int i=sz; i<newsize; ++i) alloc.construct(&elem[i], val); // construct new
  for(int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]); // destroy old
  sz = newsize;
}

template<typename T, typename A> void vector<T,A>::push_back(const T& d) // adding new elements to the end of elems
// increase vector size by one; initialize the new element with d
{
  if(space == 0) {
    reserve(8); // arbitrarily, start with space for 8 elements
  } else if(sz==space) { // no free space, get some
    reserve(space*2); // arbitrarily, double space
  }
  alloc.construct(&elem[sz], d); // add d at the end
  ++sz; // increase the element count
}

template<typename T, typename A>
void vector<T,A>::push_front(const T& d)
{
  if(space==0) {
    reserve(8);
  } else if(sz==space) {
    reserve(space*2);
  }
  // move all elements by 1 starting from last
  for(int i=sz-1; i>=0; --i)
  {
    alloc.construct(&elem[i],elem[i-1]);
    alloc.destroy(&elem[i-1]);
  }
  alloc.construct(&elem[0], d);
  ++sz;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase(iterator p)
// erasing element by copying all remaining elem to the left one position
{
  if(p==end()) return p;
  for(auto pos = p+1; pos!=end(); ++pos)
  {
    *(pos-1) = *pos; // copy element "one position to the left"
  }
  alloc.destroy(&*(end()-1)); // destroy surplus copy of last element
  --sz;
  return p;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
// Adding element
{
  int index = p-begin(); // pointer arithmetic

  std::cout << "Index: p-begin(): " << index << std::endl;
  std::cout << "p: " << p << std::endl;
  std::cout << "elem: " << elem << std::endl; // first element address
  std::cout << "begin(): " << begin() << std::endl; // first element address
  std::cout << "end(): " << end() << std::endl; // last element address
  std::cout << "elem+sz: " << end() << std::endl; // last element address
  std::cout << "Size: sz: " << size() << std::endl; //number of elements


  if(size()==capacity()) reserve(size()==0?8:size()*2); // ensuring space
  alloc.construct(elem+sz+1,*end()); // copy last elem into uninitialized space
  ++sz;
  iterator pp = begin()+index; // place to put val
  for(auto pos=end()-1; pos!=pp; --pos) *pos = *(pos-1); // copy elem one position to the right
  *(begin()+index) = val; // insert val
  return pp;
}

// ----------------------------------------------------------------------------
// Custom data type without default value initialization
// ----------------------------------------------------------------------------
struct No_default {
  No_default(int) { }; // constructor

};

void print_some(vector<int>& v)
{
  int i = -1;
  while(std::cin >> i && i != -1)
  try{

  }
  catch(out_of_range) {
    std::cout << "bad index: " << i << std::endl;
  }
}

int main()
{
  std::cout << "Vector - insert()/erase()\n";

  vector<double> v1;
  v1.resize(100); // add 100 copies of double(), that is, 0.0
  v1.resize(200, 0.0); // add 100 copies of 0.0 - mentioning 0.0 is redundant
  v1.resize(300, 1.0); // add 100 copies of 1.0

  //vector<No_default> v2(10); // error: tries to make 10 No_defaults
  vector<No_default> v3;
  v3.resize(100, No_default(2)); // add 100 copies of No_default(2)
  //v3.resize(200); // error: tries to add 100 No_defaults
  vector<int> v5 {1,2,3,4,5,6};
  //print_some(v5);

  v1.push_front(4);
  v1.push_front(3);
  v1.push_front(2);
  v1.insert(&v1[5], 9);

  for(int i=0; i < 10; ++i)
  {
    std::cout << "v1[" << i << "]==" << v1[i] << std::endl;
  }
  std::cout << "v1 length: " << v1.size() << std::endl;
  auto begin = v1.begin();
  auto end = v1.end();
  std::cout << "v1 begin() address: " << begin << std::endl;
  std::cout << "v1 end() address: " << end << std::endl;
  std::cout << "v1 begin() value: " << *begin << std::endl;
  std::cout << "v1 end() value: " << *end << std::endl;

   v1.erase(&v1[5]);
     for(int i=0; i < 10; ++i)
  {
    std::cout << "v1[" << i << "]==" << v1[i] << std::endl;
  }
  std::cout << "v1 length: " << v1.size() << std::endl;

}
