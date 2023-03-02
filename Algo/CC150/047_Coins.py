class Solution(object):
    def waysToChange(self, n):
        """
        :type n: int
        :rtype: int
        """
        coins = [1, 5, 10, 25]

        dp = [[1 for _ in range(n+1)] for _ in range(4)]
        for s in range(n+1):
            dp[0][s] = 1

        for i in range(1, 4):
            for j in range(0, n+1):
                dp[i][j] = dp[i-1][j] if j < coins[i] else dp[i-1][j] + dp[i][j-coins[i]]       # actually you can repeatly use d[j] to represent d[i-1][j]

        return dp[3][n] % 1000000007



class Solution(object):
    def waysToChange(self, n):
        """
        :type n: int
        :rtype: int
        """
        coins = [1, 5, 10, 25]

        dp = [1 for _ in range(n+1)]

        for i in range(1, 4):
            for j in range(0, n+1):
                dp[j] = dp[j] if j < coins[i] else dp[j] + dp[j-coins[i]]

        return dp[n] % 1000000007

