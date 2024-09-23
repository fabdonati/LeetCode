# Solution
Use dynamic programming.
- Initialize the dp with n+1 ones
- For each ​element (starting from 1, because 0 and 1 are the base cases, producing 1 as a solution), consider all combos from left and right TreeNode
- Multiply these together and add them to total
- Update TreeNode at that node with total
- Return numTree at location n

# Complexity
?
