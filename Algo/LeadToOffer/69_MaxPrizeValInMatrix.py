class Solution(object):
    def maxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        for j in range(1, m):
            grid[0][j] += grid[0][j - 1]
        for i in range(1, n):
            grid[i][0] += grid[i - 1][0]

        for i in range(1, n):
            for j in range(1, m):
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]

        return grid[n - 1][m - 1]
