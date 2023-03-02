class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n == 1:
            return 1

        fn2 = 1
        fn1 = 0
        res = 1
        for i in range(2, n+1):
            res = fn2 + fn1
            fn1 = fn2
            fn2 = res

        return res