class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        curSum = 0
        prefixSums = {0 : 1}
        for n in nums:
            curSum += n # calculate the updated sum
            diff = curSum - k # get the normalized difference
            res += prefixSums.get(diff, 0) # add to the result the count of prefixes such that 
            prefixSums[curSum] = 1 + prefixSums.get(curSum, 0)
        return res