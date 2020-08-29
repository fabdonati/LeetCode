/*
  88. Merge Sorted Array
    Easy
    
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    Note:
    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

    Example:
    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1;
      int j = n-1;
      int k = m+n-1;

      while (i>=0 && j>=0) {
        if (nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i--];
        } else {
          nums1[k--] = nums2[j--];
        }
        while (j>=0) {
          nums1[k--] = nums2[j--];
        }
      }
    }
};

int main() {
  vector<int> input1 = {1,2,3,0,0,0};
  vector<int> input2 = {4,5,6};
  int m = input1.size();
  int n = input2.size();

  Solution solution;
  solution.merge(input1, 3, input2, 3);

  return 0;
}