class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def comp(k1, k2):
            s1 = int(str(k1) + str(k2))
            s2 = int(str(k2) + str(k1))
            if s1 < s2:
                return 1
            else:
                return -1

        nums = sorted(nums, key=functools.cmp_to_key(comp))

        # consider all 0 case
        if nums[0] == nums[-1] == 0:
            return "0"

        return ''.join([str(n) for n in nums])