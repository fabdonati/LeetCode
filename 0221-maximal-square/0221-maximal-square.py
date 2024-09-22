class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        maxlength = 0
        m = len(matrix) # num rows
        n = len(matrix[0]) # num cols
        dp = [[0]*(n+1) for _ in range(m+1)]
        
        for i in range(1,m+1):
            for j in range(1,n+1):
                if matrix[i-1][j-1] == '1':
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1
                maxlength = max(maxlength, dp[i][j])
        return maxlength**2