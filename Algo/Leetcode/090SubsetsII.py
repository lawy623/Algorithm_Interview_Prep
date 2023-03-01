class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        dup = set()
        nums = sorted(nums)
        n = len(nums)
        res = []
        for i in range(2 ** n):
            count = 0
            _res = []
            for j in range(32):
                if i & 1 << j:
                    _res.append(nums[j])

            idx = ''.join([str(k) for k in _res])
            if idx not in dup:
                res.append(_res)
                dup.add(idx)

        return res