class Solution(object):

    def __init__(self):
        self.valid = True
        self.visit = None
        self.edge = None

    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        n = numCourses
        self.visit = [0] * n
        self.edge = [[] for _ in range(n)]
        for p in prerequisites:
            self.edge[p[1]].append(p[0])

        for i in range(n):
            if self.visit[i] == 0:
                self.dfs(i)
            if not self.valid:
                return False

        return True

    def dfs(self, i):
        self.visit[i] = 1
        for e in self.edge[i]:
            if self.visit[e] == 0:  # not loop, dfs
                self.dfs(e)
                if not self.valid:      # early stop
                    return
            elif self.visit[e] == 1:
                self.valid = False
                return

        self.visit[i] = 2