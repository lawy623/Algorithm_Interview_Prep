class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_len = 0     # update max len as the most far idx currently can access
        l = len(nums)
        for i, n in enumerate(nums):
            if max_len >= l-1:
                return True
            if max_len < i:
                return False
            max_len = max(max_len, i+n)

        return True