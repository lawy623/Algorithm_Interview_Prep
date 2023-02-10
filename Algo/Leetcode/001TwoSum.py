class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp = {}
        for i, n in enumerate(nums):
            if tmp.get(target - n) is not None:
                return [i, tmp.get(target-n)]
            tmp[n] = i

        return []