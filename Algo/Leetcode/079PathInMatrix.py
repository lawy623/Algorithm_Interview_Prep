class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if len(word) == 0:
            return True

        n_row = len(board)
        n_col = len(board[0])
        for i in range(n_row):
            for j in range(n_col):
                if self.dfs(i, j, board, word):
                    return True

        return False

    def dfs(self, i, j, board, word):
        if len(word) == 0:
            return True

        n_row = len(board)
        n_col = len(board[0])
        if i >= n_row or i < 0 or j < 0 or j >= n_col:
            return False

        if board[i][j] == word[0]:
            tmp = word[0]
            board[i][j] = '#'
            find = self.dfs(i + 1, j, board, word[1:])
            if not find:
                find = self.dfs(i - 1, j, board, word[1:])
            if not find:
                find = self.dfs(i, j + 1, board, word[1:])
            if not find:
                find = self.dfs(i, j - 1, board, word[1:])
            board[i][j] = tmp
            return find
        else:
            return False

