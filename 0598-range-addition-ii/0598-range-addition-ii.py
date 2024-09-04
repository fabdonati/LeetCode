class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        min_m, min_n = m, n
        for op1, op2 in ops:
            min_m = min(min_m, op1)
            min_n = min(min_n, op2)
        return min_m * min_n
    
# When we loop over operations, we're incrementing everything up to op1 and op2. 
# So when all ops are considered the subset of elements having the largest index will be given 
# by the max among all ops1 x max among all ops2. 