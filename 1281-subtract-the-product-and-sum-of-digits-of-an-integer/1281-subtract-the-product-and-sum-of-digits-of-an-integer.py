class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        prod = 1
        sm = 0
        while n//10 != 0:
          prod *= n%10
          sm += n%10
          n = n//10
        return prod*n - (sm+n)
          