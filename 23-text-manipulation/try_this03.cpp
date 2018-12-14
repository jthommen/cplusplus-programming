#include<regex>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

// accept a pattern and a set of lines from input
// check the pattern and search for lines with that pattern

int main()
{
  std::regex pattern;

  std::string pat;
  std::cout << " enter pattern: ";
  getline(std::cin, pat); // read pattern

  try {
    pattern = pat;
    std::cout << "pattern: " << pat << std::endl;
  }
  catch(std::regex_error) {
    std::cout << pat << " is not a valid regular expression.\n";
    exit(1);
  }

  std::cout << "now enter lines:\n";
  int line_no = 0;

  for(std::string line; getline(std::cin, line);)
  {
    ++line_no;
    std::smatch matches;
    if(std::regex_search(line, matches, pattern))
    {
      std::cout << "line " << line_no << ": " << line << std::endl;
      for(int i=0; i<matches.size(); ++i)
      {
        std::cout << "\tmatches[" << i << "]: "
          << matches[i] << std::endl;
      }
    }
    else
      std::cout << "didn't match\n";
  }

}