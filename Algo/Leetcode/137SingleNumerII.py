class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in range(32):
            c = 0
            for n in nums:
                if n & 1<<i:
                    c += 1

            if c%3 != 0:
                if i == 31:         # python needs special compare
                    res -= (1<<i)
                else:
                    res |= (1<<i)
        return res

