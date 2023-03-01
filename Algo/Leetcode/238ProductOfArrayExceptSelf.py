class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [1]
        n = len(nums)
        for i in range(1, n):
            res.append(res[-1] * nums[i - 1])

        r = 1
        for i in range(n - 1, -1, -1):
            res[i] *= r
            r *= nums[i]

        return res
