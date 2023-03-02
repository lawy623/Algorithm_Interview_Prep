class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        t = set()
        while n != 1:
            m = n
            sumOfSqrt = 0
            while m > 0:
                sumOfSqrt += (m % 10) ** 2
                m /= 10
            n = sumOfSqrt
            if n in t:
                return False
            t.add(n)

        return True
