class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        res = []
        for i in range(2**n):
            count = 0
            _res = []
            for j in range(32):
                if i & 1<<j:
                    _res.append(nums[j])

            res.append(_res)

        return res