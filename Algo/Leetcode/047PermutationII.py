class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.dfs(nums)
        res = []
        # remove dup
        for r in self.res:
            if r not in res:
                res.append(r)
        return res

    def dfs(self, nums):
        if len(self.path) == len(nums):
            self.res.append(copy.deepcopy(self.path))
            return

        for i, n in enumerate(nums):
            if n != '#':
                nums[i] = '#'
                self.path.append(n)
                self.dfs(nums)
                self.path.pop()
                nums[i] = n


# Use set and swap
class Solution(object):

    def __init__(self):
        self.res = []

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.dfs(nums, 0)

        return self.res

    def dfs(self, nums, idx):
        if idx == len(nums) - 1:
            self.res.append(copy.deepcopy(nums))
            return

        s = set()
        for i in range(idx, len(nums)):
            n = nums[i]
            if n not in s:      # can not start with the same again
                s.add(n)
                swap(nums, idx, i)  # idx as starter
                self.dfs(nums, idx+1)   # all permutation use the idx as start
                swap(nums, idx, i)

def swap(nums, i, j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp