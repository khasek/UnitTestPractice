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
  if (phrase == "") {
    return 0;
  }

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
bool Password::has_mixed_case(string phrase) {
  bool has_lowercase = false;
  bool has_uppercase = false;
  int index = 0;

  if (phrase == "") {
    return false;
  }

  while( index < phrase.length() && (!has_lowercase || !has_uppercase) ) {

    if (phrase[index] >= 'a' && phrase[index] <= 'z') {
      has_lowercase = true;
    } else if (phrase[index] >= 'A' && phrase[index] <= 'Z') {
      has_uppercase = true;
    }
    index++;
  }

  return (has_lowercase && has_uppercase);
}


/*
constructor sets the default password to "ChicoCA-95929"
*/
Password::Password() {
  pass_history.push_back("ChicoCA-95929");
}


/*
receives a password and sets the latest in pass_history to it if and only
if it meets all criteria:
  1. The password is at least 8 letters long
  2. It has no more than 3 of the same leading characters
  3. It has mixed case (at least one upper case and at least one lower case)
  4. It was not a previous password in the history
*/
void Password::set(string phrase) {
  if (phrase.length() >= 8 &&
      count_leading_characters(phrase) <= 3 &&
      has_mixed_case(phrase) &&
      phrase != pass_history[pass_history.size()-1]
  ) {
    pass_history.push_back(phrase);
  }
}


/*
receives a string and authenticates it against the latest password in the
pass_history, returning true for an exact match or false when it does not match
or if a password has not been set.
*/
bool Password::authenticate(string phrase) {
  if (pass_history.size() > 0 && 
      pass_history[pass_history.size()-1] == phrase
  ) {
    return true;
  }
  return false;
}