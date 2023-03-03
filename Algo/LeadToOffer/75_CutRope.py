class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        if n == 2:
            return 1
        if n == 3:
            return 2

        dp = [0] * (n+1)
        dp[1] = 1
        dp[2] = 2       # max single 2
        dp[3] = 3       # max single 3

        for i in range(4, n+1):
            dp[i] = max([dp[i-k]*dp[k] for k in range(1, i/2+1)])

        return dp[-1]