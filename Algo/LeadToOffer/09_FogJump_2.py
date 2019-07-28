## By induction, you can prove f1=1, f2=2, fn = fn-1+fn-2+...+f1+1 = 2^(n-1). O(1) time.
class Solution:
    def jumpFloorII(self, number):
        if number == 0:
            return 0
        return 2 ** (number-1)
