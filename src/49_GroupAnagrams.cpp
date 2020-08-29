/*  
  49. Group Anagrams
    Medium
    Given an array of strings, group anagrams together.

    Example:

    Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
    Output:
    [
      ["ate","eat","tea"],
      ["nat","tan"],
      ["bat"]
    ]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> map;
      for (string str : strs) {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        map[tmp].push_back(str);
      }
      vector<vector<string>> anagrams;
      for (auto p : map) {
        anagrams.push_back(p.second);
      }
      return anagrams;
    }
};

int main() {
  vector<string> input = {"eat","tea","tan","ate","nat","bat"};
  Solution solution;
  vector<vector<string>> output = solution.groupAnagrams(input);   
  return 0;
}