class Solution(object):
    def dicesProbability(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        res = [1.0 / 6.0] * 6
        while n > 1:
            s = len(res)    # for small to large
            new_res = [0] * (s + 5)

            for i, p in enumerate(res):
                for k in range(6):
                    new_res[i+k] += res[i] * 1.0/6.0

            res = new_res
            n -= 1

        return res