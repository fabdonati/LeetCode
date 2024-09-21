class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        d = abs(dividend)
        dv = abs(divisor)
        res = 0
        
        while d>=dv:
            tmp = dv
            mul = 1
            while d>=tmp:
                d-=tmp
                res+=mul
                tmp+=tmp
                mul+=mul
                
        if (dividend>=0 and divisor<0) or (dividend<=0 and divisor>0):
            res = -res
        return min(2147483647, max(-2147483648, res))
                                          