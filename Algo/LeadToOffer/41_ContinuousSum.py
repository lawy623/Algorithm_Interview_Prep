class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        i, j = 1, 2
        res = []
        while i < (target + 1) / 2:
            if i == j:
                j += 1

            if calSum(i, j) == target:
                res.append(list(range(i, j+1)))
                j += 1
            elif calSum(i, j) < target:
                j += 1
            else:
                i += 1

        return res

def calSum(i, j):
    return (i + j) * (j - i + 1) / 2