/*
  125. Valid Palindrome
    Easy

    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: For the purpose of this problem, we define empty string as valid palindrome.

    Example 1:
    Input: "A man, a plan, a canal: Panama"
    Output: true
    Example 2:

    Input: "race a car"
    Output: false

    Constraints:
    s consists only of printable ASCII characters.
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int i = 0;
      int j = s.size()-1;
      
      while (i<j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (i < j && tolower(s[i]) != tolower(s[j])) {
          return false;
        }
        i++;
        j--;
      }
      return true;
    }
};


int main() {
  string input = "A man, a plan, a canal: Panama";

  Solution solution;
  cout << "Palindrome? " << solution.isPalindrome(input) << endl;

  return 0;
}