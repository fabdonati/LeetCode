/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> result;
  
  void solve(vector<int>& nums, int l, int r) {
    if (l==r) result.push_back(nums);
    
    for (int i=l; i<=r; i++) {
      swap(nums[l], nums[i]);
      solve(nums,l+1,r);
      swap(nums[i], nums[l]);
    }
  }
    
  vector<vector<int>> permute(vector<int>& nums) {
    solve(nums, 0, nums.size()-1);
    return result;
  }
};