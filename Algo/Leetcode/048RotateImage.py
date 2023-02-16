class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        # diag
        for i in range(0, n):
            for j in range(0, i):
                swap(matrix, (i, j), (j, i))

        # left right
        for i in range(0, n):
            for j in range(0, n / 2):
                swap(matrix, (i, j), (i, n - j - 1))

        return None

def swap(matrix, n1, n2):
    tmp = matrix[n1[0]][n1[1]]
    matrix[n1[0]][n1[1]] = matrix[n2[0]][n2[1]]
    matrix[n2[0]][n2[1]] = tmp