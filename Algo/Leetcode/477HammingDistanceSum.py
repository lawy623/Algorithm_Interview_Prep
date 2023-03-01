class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        diff = 0
        for i in range(32):
            c = 0
            for num in nums:
                c += 1 if (num & 1 << i) > 0 else 0
            diff += (n - c) * c

        return diff
