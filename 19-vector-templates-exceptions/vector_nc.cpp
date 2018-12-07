#include<iostream>
#include<string>
#include<vector>

template<typename T>
class vector {
/*
  invariant:
  if 0 <= sz, elem[n] is element n
  sz <= space
  if sz < space, there is space for (space-sz) doubles after elem[sz-1]
*/
  int sz;
  T* elem;
  int space;
public:
  vector():sz{0}, elem{nullptr}, space{0} { };
  explicit vector(int s);
  vector(std::initializer_list<T>lst);

  vector(const vector& v);
  vector& operator=(const vector& v);

  vector(vector&& v);
  vector& operator=(vector&& v);

  T& operator[](int n);
  const T& operator[](int n) const;

  ~vector()
  {
    delete[] elem;
  }

  int size() const { return sz; }
  int capacity() const { return space; }

  void resize(int newsize, T def = T());
  void push_back(const T& d);
  void reserve(int newalloc);

};

template<typename T> vector<T>::vector(int s)
  :sz{s},
  elem{new T[s]},
  space{s}
{
  for (int i=0; i<s; ++i) elem[i]=0;
}

template<typename T> vector<T>::vector(std::initializer_list<T>lst)
  :sz{int(lst.size())}, elem{new T[sz]}
{
  std::copy(lst.begin(), lst.end(),elem);
}

template<typename T> vector<T>::vector(const vector& v)
  :sz{v.sz}, elem{new T[v.sz]}
{
  std::copy(v.elem, v.elem+sz, elem);
}

template<typename T> vector<T>& vector<T>::operator=(const vector& v)
{
  if(this == &v) return *this;

  if(v.sz<=space)
  {
    std::copy(v.elem, v.elem+sz, elem);
    sz = v.sz;
    return *this;
  }

  T* p = new T[v.sz];
  std::copy(v.elem, v.elem+sz, p);
  delete[] elem;
  elem = p;
  space = sz = v.sz;
  return *this;
}

template<typename T> vector<T>::vector(vector&& v)
  :sz{v.sz}, elem{v.elem}
{
  v.sz = 0;
  v.elem = nullptr;
}

template<typename T> vector<T>& vector<T>::operator=(vector&& v)
{
  delete[] elem;
  elem = v.elem;
  sz = v.sz;
  v.elem = nullptr;
  v.sz = 0;
  return *this;
}

template<typename T> T& vector<T>::operator[](int n)
{
  return elem[n];
}

template<typename T> const T& vector<T>::operator[](int n) const
{
  return elem[n];
}

template<typename T> void vector<T>::reserve(int newalloc)
{
  if(newalloc<=space) return;
  T* p = new T[newalloc];
  for(int i=0; i<sz; ++i) p[i] = elem[i];
  delete[] elem;
  elem = p;
  space = newalloc;
}

template<typename T>void vector<T>::resize(int newsize, T def)
{
  reserve(newsize);
  for(int i=sz; i<newsize; ++i) elem[i] = 0;
  sz = newsize;
}

template<typename T> void vector<T>::push_back(const T& d)
{
  if(space == 0) {
    reserve(8);
  } else if(sz==space) {
    reserve(space*2);
  }
  elem[sz] = d;
  ++sz;
}
