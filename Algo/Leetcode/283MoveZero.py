class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l = 0
        for i in range(n):
            if nums[i] != 0:
                swap(nums, i, l)
                l += 1
        for i in range(l, n):
            nums[i] = 0

        return nums


def swap(nums, i, j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp