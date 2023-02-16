class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        m = len(matrix[0])
        i = 0
        j = n * m - 1
        while i <= j:
            mid = (i + j) / 2
            u, v = flat_to_uv(mid, n, m)
            if matrix[u][v] == target:
                return True
            elif matrix[u][v] > target:
                j = mid - 1
            else:
                i = mid + 1

        return False

def flat_to_uv(v, n, m):
    return v / m, v % m