class Solution(object):

    def __init__(self):
        self.sol = []

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        board = [[0 for _ in range(n)] for _ in range(n)]
        self.dfs(board, 0, n)

        return self.sol

    def dfs(self, board, i, n):
        if i == n:
            res = []
            for k in range(n):
                res.append(''.join(['Q' if board[k][t] == 1 else '.' for t in range(n)]))
            self.sol.append(res)
            return

        for j in range(n):
            board[i][j] = 1
            if self.checkValid(board, n, i, j):
                self.dfs(board, i + 1, n)
            board[i][j] = 0

    def checkValid(self, board, n, row, col):
        for i in range(row):
            if board[i][col] == 1:
                return False

        i = row - 1
        j = col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1

        i = row - 1
        j = col + 1
        while i >= 0 and j < n:
            if board[i][j] == 1:
                return False
            i -= 1
            j += 1

        return True
