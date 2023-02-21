class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.dfs(nums)
        return self.res

    def dfs(self, nums):
        if len(self.path) == len(nums):
            self.res.append(copy.deepcopy(self.path))
            return

        for n in nums:
            if n not in self.path:
                self.path.append(n)
                self.dfs(nums)
                self.path.pop()


# Use swap
class Solution(object):

    def __init__(self):
        self.res = []

    def permute(self, nums):
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

        for i in range(idx, len(nums)):
            n = nums[i]
            swap(nums, idx, i)  # idx as starter
            self.dfs(nums, idx + 1)  # all permutation use the idx as start
            swap(nums, idx, i)


def swap(nums, i, j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp