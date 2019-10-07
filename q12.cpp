/*
Check CheckPermutation: Given two strings, write a method
to decide if one is a permutation of the other.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool CheckPermutation(string str1, string str2){
  if(str1.size() != str2.size()) return false;

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  return str1.compare(str2) == 0;
}

bool CheckPermutation2(string str1, string str2){
  if(str1.size() != str2.size()) return false;

  int counts[128] = {0};

  for (size_t i = 0; i < str1.size(); i++) {
    counts[str1[i]]++;
  }

  for (size_t i = 0; i < str2.size(); i++) {
    counts[str2[i]]--;

    if(counts[str2[i]] < 0)
    return false;
  }

  return true;
}


int main(int argc, char const *argv[]) {

  cout << CheckPermutation("asdasd", "sadsad") << "\n"; // returns true
  cout << CheckPermutation("asdfsa", "asgafa") << "\n"; // returns false

  cout << CheckPermutation2("asdasd", "sadsad") << "\n"; // returns true
  cout << CheckPermutation2("asdfsa", "asgfas") << "\n"; // returns false

  return 0;
}
