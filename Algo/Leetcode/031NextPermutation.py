class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1:
            return nums

        # find the first growing pair
        k = n - 1
        while k > 0:
            if nums[k] > nums[k - 1]:
                break
            k -= 1

        # find the larger the lower value from tail
        if k > 0:
            j = n - 1
            while nums[j] <= nums[k - 1]:  # j must be at most go to k
                j -= 1
            swap(nums, j, k - 1)

        nums[k:n] = list(reversed(nums[k:n]))

        return nums


def swap(nums, j, k):
    tmp = nums[j]
    nums[j] = nums[k]
    nums[k] = tmp