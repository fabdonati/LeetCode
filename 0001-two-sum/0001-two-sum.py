class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {} # contains diff and index
        for i in range(len(nums)):
            diff = target - nums[i]
            if nums[i] in map:
                return [i, map[nums[i]]]
            map[diff] = i
