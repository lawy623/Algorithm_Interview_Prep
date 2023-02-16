class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        n = len(matrix)
        m = len(matrix[0])
        l, r, u, d = 0, m-1, 0, n-1
        res = []
        while l <= r and u <= d:
            if l == r:
                res.extend(printHorizontal(matrix, u, l, r))
                if u < d:
                    res.extend(printVetical(matrix, l, u+1, d))
                return res
            else:
                res.extend(printHorizontal(matrix, u, l, r))
                if u < d:
                    res.extend(printVetical(matrix, r, u+1, d))
                    res.extend(printHorizontal(matrix, d, r-1, l))
                    if u < d-1:
                        res.extend(printVetical(matrix, l, d-1, u+1))
                    l, r, u, d = l+1, r-1, u+1, d-1
                else:
                    return res

        return res

def printHorizontal(mat, i, j1, j2):
    if j2 >= j1:
        return [mat[i][k] for k in range(j1, j2+1)]
    else:
        return [mat[i][k] for k in range(j1, j2-1, -1)]

def printVetical(mat, j, i1, i2):
    if i2 >= i1:
        return [mat[k][j] for k in range(i1, i2+1)]
    else:
        return [mat[k][j] for k in range(i1, i2-1, -1)]