# Moore Count
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        elem = None
        for n in nums:
            if count == 0:
                elem = n
            count += 1 if elem == n else -1

        return elem