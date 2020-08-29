#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    unordered_set<int> hash_set;
    for (auto n : nums) {
      if (hash_set.find(n) == hash_set.end()) {
        hash_set.insert(n);
      }
    }
    return hash_set.size();
  }
};

int main() {
  vector<int> input = {1,1,2};
  Solution solution;
  int sol = solution.removeDuplicates(input); 
  return 0;
}