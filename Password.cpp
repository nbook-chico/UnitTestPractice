#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  // Initial code didn't account for empty strings
  if(phrase.empty()) return 0;

  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string pass){
  // This was totally unimplemented  
  bool hasUpper = false;
  bool hasLower = false;

  for(char c : pass){
    if (isupper(c)) hasUpper = true;
    if (islower(c)) hasLower = true;
    if (hasUpper && hasLower) return true;
  }
  return false;
}

unsigned int Password::unique_characters(string s)
{
    bool seen[256] = {false};
    unsigned int count = 0;

    for (unsigned char c : s)
    {
        if (!seen[c]) {
            seen[c] = true;
            count++;
        }
    }
    return count;
}