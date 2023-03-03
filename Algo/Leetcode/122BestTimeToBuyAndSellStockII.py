class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        res = 0
        for i in range(n - 1):
            res += max(0, prices[i + 1] - prices[i])

        return res