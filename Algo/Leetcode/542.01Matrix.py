class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(mat)
        m = len(mat[0])
        res = [[n + m for _ in range(m)] for _ in range(n)]
        visit = [[False for _ in range(m)] for _ in range(n)]

        q = []
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append((i, j))
                    visit[i][j] = True  # in case add into the queue again

        cur_dis = 0
        while len(q) > 0:
            n_rem = len(q)
            while n_rem > 0:
                coord = q[0]
                visit[coord[0]][coord[1]] = True
                res[coord[0]][coord[1]] = min(res[coord[0]][coord[1]], cur_dis)
                for x, y in zip([-1, 1, 0, 0], [0, 0, 1, -1]):
                    if 0 <= (coord[0] + x) < n and 0 <= (coord[1] + y) < m and not visit[coord[0] + x][coord[1] + y]:
                        q.append((coord[0] + x, coord[1] + y))
                q.pop(0)
                n_rem -= 1

            cur_dis += 1

        return res