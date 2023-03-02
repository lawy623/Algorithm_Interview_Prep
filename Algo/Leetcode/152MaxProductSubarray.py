class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        f_max = nums[0]
        f_min = nums[0]
        f = nums[0]
        for n in nums[1:]:
            f_max_tmp = f_max
            f_min_tmp = f_min
            f_max = max(n, f_max_tmp * n, f_min_tmp * n)
            f_min = min(n, f_max_tmp * n, f_min_tmp * n)
            f = max(f, f_max)

        return f