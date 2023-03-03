class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy1 = -2**31
        buy2 = -2**31
        sell1 = 0
        sell2 = 0

        for p in prices:
            buy1 = max(buy1, -p)
            sell1 = max(sell1, buy1+p)
            buy2 = max(buy2, sell1-p)
            sell2 = max(sell2, buy2+p)

        return sell2