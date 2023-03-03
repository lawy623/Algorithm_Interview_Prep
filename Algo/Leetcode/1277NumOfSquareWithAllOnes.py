class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        max_len = 0
        n = len(matrix)
        m = len(matrix[0])

        res = 0

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 1 and i > 0 and j > 0 and matrix[i-1][j] > 0 and matrix[i][j-1] > 0 and matrix[i-1][j-1] > 0:
                    matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + 1
                res += matrix[i][j]

        return res