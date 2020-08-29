/* 
  76. Minimum Window Substring
    Hard
    Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

    Example:
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"

    Note:
    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    // no need for a proper map, only needs a vector
    vector<int> map(128, 0);
    for (auto c : t) { map[c]++; }
    // begin and end pointer and counter for size of the string to find
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size()) {
      if (map[s[end++]]-- > 0) counter--;
      while (counter == 0) {
        if (end - begin < d) d = end - (head=begin);
        if (map[s[begin++]]++ == 0) counter++;
      }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
  }
};

int main() {
  string input1 = "ADOBECODEBANC";
  string input2 = "ABC";
  Solution solution;
  string output = solution.minWindow(input1, input2);   
  return 0;
}