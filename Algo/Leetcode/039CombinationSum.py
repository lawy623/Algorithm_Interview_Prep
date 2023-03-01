class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []
        self.sum = 0

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n = len(candidates)
        self.dfs(candidates, 0, n, target)

        return self.res

    def dfs(self, candidates, i, n, target):
        if self.sum == target:
            self.res.append(copy.deepcopy(self.path))
            return

        if i >= n or self.sum > target:
            return

        for j in range(i, n):
            self.sum += candidates[j]
            self.path.append(candidates[j])
            self.dfs(candidates, j, n, target)
            self.path.pop()
            self.sum -= candidates[j]