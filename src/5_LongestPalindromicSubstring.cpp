/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      if (s.length()==0) return "";
      int len1, len2, len, start=0, end=0;
      for (int i=0; i<s.length(); i++) {
        len1 = expandFromCenter(s, i, i  );
        len2 = expandFromCenter(s, i, i+1);
        len = max(len1, len2);
        if (len > end-start) { // if found anything
          start = i - (len-1)/2;
          end = i + len/2;
        }
      }
      return string(s.begin()+start, s.begin()+end+1);
    }
  
    int expandFromCenter(string s, int left, int right) {
      while (s[left] == s[right] && left>=0 && right<s.length()) {
        left--;
        right++;
      }
      return left-right+1;
    }
};
