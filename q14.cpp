/*
Palindrome Permutation: Given a string, write a function to Check
if its a permutation of a palindrome. A palindrome is a word
or a phrase that is the same forwards and backwards. The Palindrome
does not need to be limited to just dictionary words.
Example: 'tactcoa'
Output: True
*/

#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(string str){
  int counter = 0;
  int chars[128] = {0};
  for (size_t i = 0; i < str.size(); i++) {
    int val = str[i];
    chars[val]++;
    if(chars[val]%2 == 0) counter--;
    else counter++;
  }
  if(counter > 1) return false;
  else return true;
}

int main(int argc, char const *argv[]) {

  cout << IsPalindrome("tactcoa") << endl;

  return 0;
}
