class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = {}
        for n in nums:
            m[n] = 1

        max_count = 0
        for n in nums:
            count = 1
            d = n - 1
            if m.get(n+1) is not None:      # Otherwise n^2 time
                continue

            while m.get(d) is not None:
                d -= 1
                count += 1

            max_count = max(max_count, count)

        return max_count