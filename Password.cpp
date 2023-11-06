#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
  */
  bool has_mixed_case(string phrase) {
    bool has_lowercase = false;
    bool has_uppercase = false;
    int index = 0;

    while( index < phrase.length()-1 && (!has_lowercase || !has_uppercase)) {

      if (phrase[index] >= 'a' && phrase[index] <= 'a') {
        has_lowercase = true;
      } else if (phrase[index] >= 'A' && phrase[index] <= 'Z') {
        has_uppercase = true;
      }
      index++;
    }
  }