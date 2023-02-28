class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        n = len(board)
        m = len(board[0])

        for i in range(n):
            for j in range(m):
                if board[i][j] != '.':
                    k = board[i][j]

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
                    if not valid:
                        return False

        return True

