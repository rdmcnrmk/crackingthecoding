/*
String Comparison: Implement a method to perform basic string Comparison
using the counts of repeated characters.
For example the string aabcccccaaa would become a2b1c5a3.
If the compressed string would not become smaller than the original
string, your method should return the original string. You can assume the string has only uppercase and lowercase letters.
*/

#include <string>
#include <iostream>

using namespace std;

int CounterLength(int counter);

int StringLengthCounter(string s){
  int result = 0;
  int counter = 1;

  if(s.size() < 2) return s.size();

  for (size_t i = 1; i < s.size(); i++) {
    if(s[i] == s[i-1]) counter++;
    else{
      result += 1 + CounterLength(counter);
      counter = 1;
    }
  }
  result = result + CounterLength(counter);
  cout << result << endl;
  return result;
}

int CounterLength(int counter){
  int result = 0;
  do{
    counter = counter / 10;
    result++;
  } while(counter > 0);

  return result;
}

string CompressString(string s){
  int index = 0;
  int counter = 1;

  if(StringLengthCounter(s) >= s.size()) return s;

  for (int i = 1; i < s.size(); i++) {
    if(s[i] == s[i-1]){
      counter++;
    }else {
      s[index] = s[i-1];
      index++;
      string c = to_string(counter);
      for (int j = 0; j < c.size(); j++) {
        s[index++] = c[j];
      }
    }
  }
  s[index] = s[s.size()-1];
  index++;
  string c = to_string(counter);
  for (int j = 0; j < c.size(); j++) {
    s[index++] = c[j];
  }

  return s;
}

int main(int argc, char const *argv[]) {

  cout << CompressString("aabcccccaaa") << endl;

  return 0;
}
