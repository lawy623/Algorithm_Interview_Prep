class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0

        dp = [amount+1] * (amount+1)        # amount + 1 means can not reach
        dp[0] = 0
        for i in range(1, amount+1):
            dp[i] = min([dp[i]] + [dp[i-c]+1 if c <= i else amount+1 for c in coins])

        return dp[-1] if dp[-1] != amount+1 else -1