class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        start, end = 0, n-1

        while (start <= end):
            mid = (start + end) / 2
            if nums[mid] == target:
                return mid
            # only increase
            if nums[start] < nums[end]:
                if nums[mid] > target:
                    end = mid - 1
                else:
                    start = mid + 1

            # in left
            elif nums[start] <= nums[mid]:
                if nums[start] <= target and target < nums[mid]:
                    end = mid - 1
                else:
                    start = mid + 1

            # in right
            else:
                if nums[mid] < target and target <= nums[end]:
                    start = mid + 1
                else:
                    end = mid - 1

        return -1
