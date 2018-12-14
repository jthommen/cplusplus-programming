#include<regex>
#include<iostream>
#include<string>
#include<fstream>

int main()
{
  std::ifstream in {"file.txt"};
  if(!in) std::cerr << "no file!\n";

  std::regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};
  int line_no = 0;

  for(std::string line; getline(in,line);)
  {
    ++line_no;
    std::smatch matches;
    if(std::regex_search(line, matches, pat))
      std::cout << line_no << ": " << matches[0] << std::endl; // whole match
      if(1<matches.size() && matches[1].matched)
        std::cout << "\t: " << matches[1] << std::endl; // sub-match
  }
}
