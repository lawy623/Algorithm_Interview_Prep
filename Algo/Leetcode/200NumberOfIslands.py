import sys
sys.setrecursionlimit(1000000)

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])

        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    count += 1
                    self.dfs(grid, i, j, n, m)

        return count

    def dfs(self, grid, i, j, n, m):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == "0":
            return

        grid[i][j] = "0"
        self.dfs(grid, i+1, j, n, m)
        self.dfs(grid, i-1, j, n, m)
        self.dfs(grid, i, j+1, n, m)
        self.dfs(grid, i, j-1, n, m)