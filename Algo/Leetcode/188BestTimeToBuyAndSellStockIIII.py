class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        buy = [-2**31] * k
        sell = [0] * k

        for p in prices:
            for i in range(k):
                buy[i] = max(buy[i], -p if i == 0 else sell[i-1]-p)
                sell[i] = max(sell[i], buy[i]+p)

        return sell[-1]