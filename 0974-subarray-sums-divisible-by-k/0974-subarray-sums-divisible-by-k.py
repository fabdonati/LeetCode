class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefixMod, result = 0, 0
        modGroups = [0]*k # k modGroups (from 0 to k-1)
        modGroups[0] = 1
        
        for num in nums:
            # take the modulo twice to avoid negative remainders
            prefixMod = (prefixMod + num%k + k)%k
            result += modGroups[prefixMod]
            modGroups[prefixMod] += 1
        return result