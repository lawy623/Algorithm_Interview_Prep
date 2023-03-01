class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []
        self.sum = 0

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        nums = list(range(1, 10))
        l = len(nums)
        self.dfs(nums, 0, l, n, k)

        return self.res

    def dfs(self, nums, i, n, target, n_v):
        if len(self.path) == n_v and self.sum == target:
            self.res.append(copy.deepcopy(self.path))
            return

        if i >= n:
            return

        for j in range(i, n):
            self.sum += nums[j]
            self.path.append(nums[j])
            self.dfs(nums, j + 1, n, target, n_v)
            self.path.pop()
            self.sum -= nums[j]