class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 1

        for i, k in enumerate(nums):
            if abs(k) < n + 1:
                nums[abs(k) - 1] = - abs(nums[abs(k) - 1])

        for i, k in enumerate(nums):
            if k > 0:
                return i + 1

        return n + 1