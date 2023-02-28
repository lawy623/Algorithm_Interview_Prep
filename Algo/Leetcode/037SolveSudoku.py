class Solution(object):

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.dfs(board)
        return board

    def dfs(self, board):
        n = len(board)
        m = len(board[0])

        for i in range(n):
            for j in range(m):
                if board[i][j] == '.':
                    for k in range(1, 10):
                        if self.checkValid(board, str(k), i, j, n, m):
                            board[i][j] = str(k)
                            res = self.dfs(board)
                            if res:
                                return True
                            board[i][j] = '.'
                    return False  # can not find any match this

        return True

    def checkValid(self, board, k, i, j, n, m):
        valid = True
        # check in col
        for t in range(n):
            if t != i:
                if board[t][j] == k:
                    valid = False
        if not valid:
            return False
        # check in row
        for t in range(m):
            if t != j:
                if board[i][t] == k:
                    valid = False
        if not valid:
            return False
        # check in small square
        start_i = i / 3
        start_j = j / 3
        for q in range(start_i * 3, start_i * 3 + 3):
            for w in range(start_j * 3, start_j * 3 + 3):
                if q != i and w != j:
                    if board[q][w] == k:
                        valid = False

        return valid
