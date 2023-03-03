# DFS exceed time limit
class Solution(object):

    def __init__(self):
        self.count = 0
        self.res = None
        self.path = ""

    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = list(range(1, n+1))    # n, n-1, ..., 1

        self.dfs(nums, 0, n, k)
        return self.res

    def dfs(self, nums, i, n, k):
        if i == n:
            self.count += 1
            if self.count == k:
                self.res = self.path
            return

        # add each v
        for p in range(i, n):
            old_nums = copy.deepcopy(nums)
            # move p to i place, other goes down
            v = nums[p]
            nums[i+1:p+1] = nums[i:p]
            nums[i] = v
            self.path += str(nums[i])
            self.dfs(nums, i+1, n, k)
            self.path = self.path[:-1]
            # back
            nums = old_nums
