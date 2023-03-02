class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [i for i in range(n+1)]

        for i in range(2, n+1):
            dp[i] = min([dp] + [dp[i-j*j] + 1 for j in range(1, int(sqrt(i))+1)])

        return dp[-1]