## It is correct but exceed time for batch test
class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n <= 2:
            return 0
        nums = sorted(nums)
        i, j, k = 0, 1, 2
        count = 0
        while i < n-2 and j < n-1 and k < n:
            while k <= n-1 and nums[i] + nums[j] > nums[k]:
                k += 1
            count += k - j - 1

            j += 1
            k = j + 1

            if j == n-1 and k == n:
                i += 1
                j, k = i+1, i+2
                continue

        return count