class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0

        if x < 0:
            rev = -self.reverse(-x)
            return 0 if rev < -2 ** 31 else rev

        res = 0
        while x > 0:
            res = res * 10 + x % 10
            x /= 10

        return 0 if res > 2 ** 31 else res
