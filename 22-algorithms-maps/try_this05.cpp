#include<string>
#include<iostream>
#include<fstream>
#include<set>

int main()
{
  std::string from, to;
  std::cin >> from >> to; // get source and target file names

  std::ifstream is{from}; // open input stream
  std::ofstream os{to}; // open output stream

  std::istream_iterator<std::string> ii {is}; // make input iterator for stream
  std::istream_iterator<std::string> eof; // input sentinel, end of file
  std::ostream_iterator<std::string> oo {os,"\n"}; // make output iterator for stream

  std::set<std::string> b {ii, eof}; // b is a vector initialized from input range (iterators)
  std::copy(b.begin(), b.end(), oo);  // copy the buffer to output
}
