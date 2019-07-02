## DP. O(n) time. O(1) space.
class Solution:
    def Fibonacci(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        f1 = 1
        f2 = 1
        f = 0
        for i in range(2, n):
            f = f1 + f2
            f1 = f2
            f2 = f
        return f
