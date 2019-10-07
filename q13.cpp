/*
URLify: Write a method to replace all spaces in a string with '%20'.
You may assume that the string has sufficient space at the ent to hold the additional
characters, and that true length of string.
Example: "Mr John Smith    ", 13
Output:  "Mr%20John%20Smith"
*/

#include <string>
#include <iostream>

using namespace std;

string Urlify(string str, int length) {
  int spaces = 0;
  for (size_t i = 0; i < length; i++) {
    if(str[i] == ' ') spaces++;
  }

  int index = length + 2 * spaces;
  int counter = length-1;

  for (int i = index-1; i >= 0; i--) {
    if(str[counter] == ' '){
      str[i--] = '0';
      str[i--] = '2';
      str[i] = '%';
    }
    else{
      str[i] = str[counter];
    }

    counter--;
  }

  return str;
}

int main(int argc, char const *argv[]) {
  string str = "Mr John Smith    ";
  cout << Urlify(str, 13) << endl;

  return 0;
}
