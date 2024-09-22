class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        left = [0]*n      
        right = [0]*n        
        res = 0
        left[0] = nums[0]
        right[n-1] = nums[n-1]
        for i in range(1,n-1):
            left[i] = max(nums[i-1], left[i-1])
        for i in range(n-2,0,-1):
            right[i] = min(nums[i+1], right[i+1])
        for i in range(1,n-1):
            if left[i]<nums[i]<right[i]:
                res += 2
            elif nums[i-1]<nums[i] and nums[i]<nums[i+1]:
                res += 1
                
        return res