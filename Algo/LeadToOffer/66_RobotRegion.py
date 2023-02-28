class Solution(object):

    def __init__(self):
        self.count = 0


    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        self.visit = [[0 for _ in range(n)] for _ in range(m)]  # do not repeat by [[0]*n]*m

        self.dfs(m, n, 0, 0, k)
        return self.count

    def dfs(self, m, n, i, j, k):
        if i < 0 or i >= m or j < 0 or j >= n or self.visit[i][j] == 1 or self.sumDigit(i, j) > k:
            return
        self.count += 1
        self.visit[i][j] = 1

        self.dfs(m, n, i + 1, j, k)
        self.dfs(m, n, i - 1, j, k)
        self.dfs(m, n, i, j + 1, k)
        self.dfs(m, n, i, j - 1, k)

    def sumDigit(self, s_i, s_j):
        return self.sumD(s_i) + self.sumD(s_j)

    def sumD(self, s_i):
        res = 0
        while s_i > 0:
            res += s_i % 10
            s_i = s_i / 10

        return res