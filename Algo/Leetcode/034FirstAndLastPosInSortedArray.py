class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(nums) - 1
        mid = self.findMid(l, r, nums, target)
        if mid != -1:
            l = mid
            r = mid
            while l >= 0 and nums[l] == target:
                l -= 1
            while r < len(nums) and nums[r] == target:
                r += 1
            return [l + 1, r - 1]

        return [-1, -1]


    def findMid(self, l, r, nums, target):
        """Binary search"""
        while l <= r:
            mid = (l + r) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1

        return -1