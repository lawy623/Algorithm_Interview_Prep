class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return n

        f1 = 1
        f2 = 2
        for i in range(3, n+1):
            f = f1 + f2
            f1 = f2
            f2 = f

        return f