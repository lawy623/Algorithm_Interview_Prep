class Solution(object):

    def __init__(self):
        self.max_size = 0
        self.size = 0

    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            for j in range(m):
                self.size = 0
                if grid[i][j] == 1:
                    self.dfs(grid, i, j, n, m)
                    self.max_size = max(self.max_size, self.size)

        return self.max_size

    def dfs(self, grid, i, j, n, m):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0:
            return

        grid[i][j] = 0
        self.size += 1

        self.dfs(grid, i + 1, j, n, m)
        self.dfs(grid, i - 1, j, n, m)
        self.dfs(grid, i, j + 1, n, m)
        self.dfs(grid, i, j - 1, n, m)