#include <iostream>
#include <string>

// using string
/*
bool is_palindrome(const std::string& s)
{
  int first = 0;
  int last = s.length()-1;
  while(first < last)
  {
    if (s[first]!=s[last]) return false;
    ++first;
    --last;
  }
  return true;
}
*/

/*
// using arrays
bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
  int first = 0;
  int last = n-1;
  while(first < last)
  {
    if(s[first]!=s[last]) return false;
    ++first;
    --last;
  }
  return true;
}
*/

// using pointers
bool is_palindrome(const char* first, const char* last)
//first points to the first letter, last to the last letter
{
  while(first < last)
  {
    if(*first!=*last) return false;
    ++first; // pointer arithmetic
    --last;
  }
  return true;
}

// helper function to get characters into the array
std::istream& read_word(std::istream& is, char* buffer, int max)
// read at most max-1 characters from is into buffer
{
  is.width(max); // read most max-1 characters in the next >>
  is >> buffer; // read whitespace-terminated word (alternative getline), terminate with zero
  return is;
}

int main()
{

  // using string
  /*
  for(std::string s; std::cin >> s;)
  {
    std::cout << s << " is";
    if(!is_palindrome(s)) std::cout << " not";
    std::cout << " a palindrome\n";
  }
  */

  /*
  // using arrays
  constexpr int max = 128; // buffer size
  for(char b[max]; read_word(std::cin, b, max);)
  {
    std::cout << b << " is";
    // using std::strlen() to determine C string by looking for terminating null character
    if(!is_palindrome(b, strlen(b))) std::cout << " not";
    std::cout << " a palindrome\n";
  }
  */

  // using pointers
  constexpr int max = 128;
  for(char s[max]; read_word(std::cin, s, max);)
  {
    std::cout << s << " is";
    if(!is_palindrome(&s[0], &s[strlen(s)-1])) std::cout << " not";
    std::cout << " a palindrome.\n";
  }
}
