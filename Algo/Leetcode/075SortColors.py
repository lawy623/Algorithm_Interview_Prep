class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i, j, k = 0, 0, n - 1
        while j <= k:
            y = nums[j]
            if y == 0:
                swap(nums, i, j)
                i += 1
                j += 1
            elif y == 2:
                swap(nums, k, j)
                k -= 1
            else:
                j += 1

        return nums


def swap(nums, i, j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp 