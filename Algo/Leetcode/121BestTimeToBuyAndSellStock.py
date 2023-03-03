class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_r = [prices[-1]]
        for n in prices[:-1][::-1]:
            max_r.append(max(max_r[-1], n))
        max_r = max_r[::-1]

        diff = [max_r[i] - prices[i] for i in range(len(prices))]
        return max(max(diff), 0)


# just stop max profit
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        min_v = prices[0]
        for p in prices[1:]:
            min_v = min(min_v, p)
            max_profit = max(max_profit, p - min_v)

        return max_profit