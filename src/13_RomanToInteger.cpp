#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int romanToInt(string str) {
      unordered_map<char, int> charToInt = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
      int result = 0;
      int index = str.length()-1;
      int preInt = 0;
      while (index>=0) {
        char ch = str[index];
        int curInt = charToInt[ch];
        if (curInt >= preInt) {
          result += curInt;
        } else {
          result -= curInt;
        }
        preInt = curInt;
        index--;
      }
      return result;
    }
};