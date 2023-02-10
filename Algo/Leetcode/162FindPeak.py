# You only need to find one. Peak must be there
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        start, end = 0, n-1
        while(start < end):
            mid = (start + end) / 2
            if (nums[mid] > nums[mid+1]):
                end = mid
            else:
                start = mid + 1

        return start