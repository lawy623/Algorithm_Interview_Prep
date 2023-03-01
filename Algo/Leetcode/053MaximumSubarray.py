class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        max_sum = -2**31
        for n in nums:
            res += n
            max_sum = max(max_sum, res)
            if res < 0:
                res = 0

        return max_sum