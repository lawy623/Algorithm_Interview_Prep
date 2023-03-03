class Solution(object):
    def numRollsToTarget(self, n, k, target):
        """
        :type n: int
        :type k: int
        :type target: int
        :rtype: int
        """
        dp = [[0 for _ in range(target+1)] for _ in range(n)]
        for j in range(1, target+1):        # one roll
            dp[0][j] = 1 if j <= k else 0   # notice condition

        for i in range(1, n):
            for j in range(1, target+1):
                for t in range(1, k+1):
                    dp[i][j] = (dp[i][j] + dp[i-1][j-t] if t <= j else dp[i][j]) % (10**9 + 7)

        return dp[n-1][target]