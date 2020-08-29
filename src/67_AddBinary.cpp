/*
  67. Add Binary
    Easy

    Given two binary strings, return their sum (also a binary string).
    The input strings are both non-empty and contains only characters 1 or 0.

    Example 1:

    Input: a = "11", b = "1"
    Output: "100"
    Example 2:

    Input: a = "1010", b = "1011"
    Output: "10101"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string output;
    int i = a.size()-1, j = b.size()-1, carry = 0;
    while (i>=0 || j>=0 || carry>0) {
      int sum = carry;
      if (i>=0) {
        sum += a[i--] - '0';
      }
      if (j>=0) {
        sum += b[j--] - '0';
      }
      output.insert(output.begin(),sum%2 + '0');
      carry = sum/2;
    }
    return output;        
  }
};

int main() {
  string input1 = "11";
  string input2 = "1";
  Solution solution;
  string output = solution.addBinary(input1, input2);   
  return 0;
}