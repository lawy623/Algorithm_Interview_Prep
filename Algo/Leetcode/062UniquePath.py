class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return self.f(m+n-2) / (self.f(m-1) * self.f(n-1))

    def f(self, n):
        res = 1
        while n > 1:
            res *= n
            n -= 1

        return res