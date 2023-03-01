class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        diff = 0
        for i in range(32):
            if (x & 1<<i) != (y & 1<<i):
                diff += 1

        return diff