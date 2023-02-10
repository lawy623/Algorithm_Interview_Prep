class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        return self._findMin(nums, 0, n-1)

    def _findMin(self, nums, start, end):
        if start == end:
            return nums[start]

        if start == end - 1:
            return nums[start] if nums[start] < nums[end] else nums[end]

        if nums[end] > nums[start]:
            return nums[start]  # increase only

        mid = (start + end) / 2

        if nums[mid] > nums[start]:
            return self._findMin(nums, mid+1, end)
        else:
            return self._findMin(nums, start, mid)


# Less code. only compare the mid and the right, The case will be simple.
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        start, end = 0, n-1
        while(start < end):
            mid = (start + end) / 2
            if (nums[mid] < nums[end]):
                end = mid
            else:
                start = mid + 1

        return nums[start]