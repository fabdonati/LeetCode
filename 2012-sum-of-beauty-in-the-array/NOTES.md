# Solution
Solve easily with a double pass for the maxLeft values (max value seen up to i-th index at its left) and the minRight values (min value seen up to the i-th index at its right). 
We then check for the maxLeft[i] and minRight[i] vs. our nums[i] value.
- Is maxLeft[i] < nums[i] < minRight[i], then it means that the i-th element has all left values smaller and all right values larger, therefore the beauty score is +2.
If the condition is not met, we check if nums[i-1]<​nums[i]<​​nums[i+1]. In that case the i-th beauty score is +1.

# Complexity
Time: O(n)
Space: O(n)
