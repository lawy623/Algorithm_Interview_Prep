class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [0]
        for i in range(1, n + 1):
            if i % 2 == 0:          # even
                res.append(res[i / 2])
            else:                   # odd
                res.append(res[i - 1] + 1)

        return res
