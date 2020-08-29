// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int k = nums.size()-2;
      // finds index at which inequality is not valid anymore
      while (k >= 0 && nums[k] >=  nums[k+1]) {
        k--;
      }
      // handles case when number is already the biggest possible
      if (k == -1) {
        sort(nums.begin(), nums.end());
        return;
      }
      // finds smallest 
      for (int i = nums.size()-1; i>k; i--) {
        if (nums[i] > nums[k]) {
          int tmp = nums[k];
          nums[k] = nums[i];
          nums[i] = tmp;
          break;
        }
      }
      sort(nums.begin()+k+1, nums.end());
    }
};

int main() {
  vector<int> input = {1,2,3};
  Solution solution;
  solution.nextPermutation(input); 
  return 0;
}