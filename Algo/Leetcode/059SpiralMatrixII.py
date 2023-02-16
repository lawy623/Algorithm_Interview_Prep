class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        m = n ** 2
        k = 1
        l, r, u, d = 0, n-1, 0, n-1
        mat = [[1 for _ in range(n)] for _ in range(n)]
        if n == 1:
            return mat

        while k <= m:
            if l == r:
                if u == d:
                    mat[u][l] = k
                    return mat
                else:
                    for i in range(u, d+1):
                        mat[i][l] = k
                        k += 1
                    return mat
            else:
                if u == d:
                    for i in range(l, r+1):
                        mat[u][l] = k
                        k += 1
                    return mat
                else:
                    for j in range(l, r+1):
                        mat[u][j] = k
                        k += 1
                    for j in range(u+1, d+1):
                        mat[j][r] = k
                        k += 1
                    for j in range(r-1, l-1, -1):
                        mat[d][j] = k
                        k += 1
                    for j in range(d-1, u, -1):
                        mat[j][l] = k
                        k += 1

                    l, r, u, d = l+1, r-1, u+1, d-1

        return mat
