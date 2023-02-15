class Solution(object):
    def isStraight(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums = sorted(nums)
        nonzero = [n for n in nums if n != 0]
        diff = max(nonzero) - min(nonzero)
        for i in range(len(nonzero) - 1):
            if nonzero[i] == nonzero[i+1]:
                return False
        return diff < len(nums)