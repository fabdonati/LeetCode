#include <algorithm>
#include <vector>
using namespace std;

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int count = 0;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) return result;
    for (int i=0; i<nums.size()-2; i++) {
      if (i==0 || (i>0 && nums[i]!=nums[i-1])) { // skips numbers if equal, i is the pointer for the index, low and high the moving pointers at extrema of the vector
        int low = i+1;
        int high = nums.size()-1;
        int sum = -nums[i];
        while (low<high) {
          if (nums[low]+nums[high]==sum) {
            result.push_back({nums[i], nums[low], nums[high]});
            while (low<high && nums[low]==nums[low+1]) low++;     // increases numbers if equal for the moving pointers
            while (low<high && nums[high]==nums[high-1]) high--;  // increases numbers if equal for the moving pointers
            low++;
            high--;
          } else if (nums[low]+nums[high]>sum) {
            high--;
          } else {
            low++;
          }
        } 
      }
    }
    return result;
  }
};