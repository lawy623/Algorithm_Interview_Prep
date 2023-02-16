class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        min_len = n + 1
        l, r = 0, 0
        s = 0
        while l < n and r < n:
            s += nums[r]
            while s >= target and l < n:        # you should keep the while loop
                min_len = min(min_len, r - l + 1)
                s -= nums[l]
                l += 1

            r += 1

        return min_len if min_len != n+1 else 0