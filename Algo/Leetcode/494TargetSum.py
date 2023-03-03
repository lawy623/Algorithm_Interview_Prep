class Solution(object):

    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        s = sum(nums) + target
        if s < 0 or s % 2 != 0:     # sum must be pos
            return 0
        s = s / 2

        dp = [[0 for _ in range(s+1)] for _ in range(n+1)] # (n+1, s+1)
        dp[0][0] = 1    # not choose anyone, and sum 0

        for i in range(1, n+1):
            for j in range(0, s+1):
                dp[i][j] = (dp[i-1][j-nums[i-1]] if nums[i-1] <= j else 0) + dp[i-1][j]

        return dp[-1][-1]