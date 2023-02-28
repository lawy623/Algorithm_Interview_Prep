class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_len = 0     # update max len as the most far idx currently can access
        end = 0
        count = 0
        for i, n in enumerate(nums[:-1]):       # do not run the last
            max_len = max(max_len, i+n)
            if i == end:
                end = max_len
                count += 1

        return count