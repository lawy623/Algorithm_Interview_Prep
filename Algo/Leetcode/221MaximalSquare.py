class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        max_len = 0
        n = len(matrix)
        m = len(matrix[0])

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == "0":
                    matrix[i][j] = 0
                else:
                    matrix[i][j] = 1
                    max_len = 1

        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == 1 and matrix[i - 1][j] > 0 and matrix[i][j - 1] > 0 and matrix[i - 1][j - 1] > 0:
                    matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]) + 1        # min of these three
                    max_len = max(max_len, matrix[i][j])

        return max_len ** 2