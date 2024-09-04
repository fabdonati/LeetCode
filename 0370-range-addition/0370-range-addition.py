class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        ans = [0]*length
        increments = [0]*length
        for start, end, increment in updates:
            increments[start] += increment
            if end != length-1:
                increments[end+1] -= increment
        ans[0] = increments[0]
        for i in range(1, length):
            ans[i] = ans[i-1] + increments[i] 
        return ans
        