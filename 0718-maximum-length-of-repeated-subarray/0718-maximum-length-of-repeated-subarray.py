class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        first, second = len(nums1), len(nums2)
        DP = [[0 for _ in range(second + 1)] for _ in range(first + 1)]
        answer = 0
        for i in range(1, first+1):
            for j in range(1, second+1):
                if nums1[i-1] == nums2[j-1]:
                    DP[i][j] += DP[i-1][j-1]+1
                    answer = max(answer, DP[i][j])
        return answer 