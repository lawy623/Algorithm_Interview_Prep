class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        m = {0: -1}
        sum = 0
        for i, n in enumerate(nums):
            sum += n
            d = m.get(sum%k, i)
            if d == i:
                m[sum%k] = d
            elif d <= i - 2:
                return True

        return False