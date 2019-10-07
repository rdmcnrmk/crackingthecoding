/*
One Away: There are three types of edits that can be performed on strings:
Insert a character remove a character or replace a character.
Given two string, write a function to check if they are one edit away.
Example:
pale->ple = True
pale->pales = True
pale->bale = True
pale->base = True

*/

#include <string>
#include <iostream>

using namespace std;

bool CheckReplace(string a, string b){
  bool replaced = false;
  for (int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]){
      if(replaced) return false;
      else replaced = true;
    }
  }
  return true;
}

bool CheckRemove(string a, string b){
  bool removed = false;
  int j = 0;
  for (size_t i = 0; i < a.size(); i++) {
    if(a[i] == b[j]) j++;
    else {
      if(removed) return false;
      else removed = true;
    }
  }
  return true;
}

bool CheckOps(string a, string b){
  if(a.size() == b.size()) return CheckReplace(a, b);
  if(a.size() - b.size() == 1) return CheckRemove(a, b);
  if(b.size() - a.size() == 1) return CheckRemove(b, a);
  return false;
}

int main(int argc, char const *argv[]) {

  cout << CheckOps("pale", "ple") << endl;
  cout << CheckOps("pale", "pales") << endl;
  cout << CheckOps("pale", "bale") << endl;
  cout << CheckOps("pale", "bae") << endl;

  return 0;
}
