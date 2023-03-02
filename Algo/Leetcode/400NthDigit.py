class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        digit = 0

        while n > 9 * 10 ** digit * (digit + 1):
            n -= 9 * 10 ** digit * (digit + 1)
            digit += 1

        start = 10 ** digit
        remain = start + (n - 1) / (digit + 1)

        return int(str(remain)[(n - 1) % (digit + 1)])
