# sort and comp O(nlogn)
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n <= 1:
            return 0

        _nums = sorted(nums)
        left_idx = 0
        right_idx = n-1
        for i in range(n):
            if _nums[i] != nums[i]:
                left_idx = i
            if _nums[n-1-i] != nums[n-1-i]:
                right_idx = n-1-i

        return max((left_idx - right_idx) + 1, 0)

# I am hard to Understand the O(n) solution now, so forgive it