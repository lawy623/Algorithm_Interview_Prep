class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        m = {0: 1}
        sum = 0
        count = 0
        for n in nums:
            sum += n
            count += m.get(sum-k, 0)
            m[sum] = m.get(sum, 0) + 1

        return count