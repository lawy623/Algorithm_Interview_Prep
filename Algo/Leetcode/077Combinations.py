class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = list(range(1, n+1))
        n = len(nums)
        res = []
        # for each valid combination
        for i in range(2**n):
            _res = []
            count = 0
            # check count == k
            for j in range(32):
                count += 1 if i & 1<<j else 0
            # add the nums pos
            if count == k:
                for j in range(32):
                    if i & 1<<j:
                        _res.append(nums[j])

                res.append(_res)

        return res

# dfs
class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []

    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = list(range(1, n + 1))
        n = len(nums)
        self.dfs(nums, 0, n, k)

        return self.res

    def dfs(self, nums, i, n, k):
        if len(self.path) == k:
            self.res.append(copy.deepcopy(self.path))
            return

        if i >= n:
            return

        for j in range(i, n):
            self.path.append(nums[j])
            self.dfs(nums, j + 1, n, k)
            self.path.pop()