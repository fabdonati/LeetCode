// Medium
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    int len1 = num1.size()-1;
    int len2 = num2.size()-1;

    for (int i = len1; i>=0; i--) {
      int carry = 0;
      for (int j = len2; j>=0; j--) {

        int tmp = (sum[i+j+1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
        sum[i+j+1] = tmp%10 + '0'; // +1 shifts as in multiplication
        carry = tmp/10;
      }
      sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
      return sum.substr(startpos);
    }
    return "";
  }
};

int main() {
  string number1 = "234";
  string number2 = "56";

  Solution solution;
  string sol = solution.multiply(number1, number2);   
  cout << sol << endl;
  return 0;
}