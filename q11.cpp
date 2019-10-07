/*
Is Unique: Implement an algorithm to determine if a string
has all unique characters what if you cannot use addinitional
data structures.
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool IsUnique(string str){
  set<char> c_set;

  for (size_t i = 0; i < str.size(); i++) {
    if(c_set.find(str[i]) == c_set.end()){
      c_set.insert(str[i]);
    }
    else
      return false;
  }

  return true;
}

bool IsUniqueNoSet(string str){
  sort(str.begin(), str.end());

  for (size_t i = 1; i < str.size(); i++) {
    if(str[i] == str[i-1])
      return false;
  }

  return true;
}

bool BookSolution(string str){
  if(str.size() > 128) return false;

  bool char_set[128] = {false};
  for (size_t i = 0; i < str.size(); i++) {
    if(char_set[str[i]] == true)
      return false;

    char_set[str[i]] = true;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  cout << IsUnique("") << "\n"; // returns true
  cout << IsUnique("asdfgzxcv") << "\n"; // returns true
  cout << IsUnique("asdfaasdf") << "\n"; // returns false

  cout << IsUniqueNoSet("") << "\n"; // returns true
  cout << IsUniqueNoSet("asdfgzxcv") << "\n"; // returns true
  cout << IsUniqueNoSet("asdfaasdf") << "\n"; // returns false

  cout << BookSolution("") << "\n"; // returns true
  cout << BookSolution("asdfgzxcv") << "\n"; // returns true
  cout << BookSolution("asdfaasdf") << "\n"; // returns false
  return 0;
}
