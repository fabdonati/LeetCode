# Solution
The DP formula dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 ensures that:
- We can only form a larger square if all three neighboring squares can also form squares.
- This maintains the square property (equal width and height) by checking adjacent squares.

# Complexity
Time: O(m * n) because we traverse each cell once.
Space: O(m * n) for the DP table. However, space can be optimized to O(n) since we only need the previous row's values.​
