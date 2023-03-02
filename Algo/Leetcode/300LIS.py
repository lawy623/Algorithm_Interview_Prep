class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [1] * n
        max_len = 1

        for i in range(1, n):
            dp[i] = max([dp[j]+1 if nums[i]>nums[j] else 1 for j in range(0, i)])
            max_len = max(max_len, dp[i])   # may not be end at last

        return max_len