class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = sum(nums)
        n = len(nums)
        if s % 2 != 0:
            return False
        s = s / 2

        dp = [[False for _ in range(s+1)] for _ in range(n+1)] # (n+1, s+1)
        for i in range(n+1):
            dp[i][0] = True     # without any can be sum 0

        for i in range(1, n+1):
            for k in range(1, s+1):
                dp[i][k] = (dp[i-1][k-nums[i-1]] if nums[i-1] <= k else False) or dp[i-1][k]

        return dp[-1][-1]