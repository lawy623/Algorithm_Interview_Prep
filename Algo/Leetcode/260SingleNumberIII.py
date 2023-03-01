class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        v = 0
        for n in nums:
            v ^= n

        # find the bit == 1
        bit = 0
        for i in range(32):
            if v & 1 << i:
                bit = i
                break

        # group xor
        n1 = 0
        n2 = 0
        for n in nums:
            if n & 1 << bit:
                n1 ^= n
            else:
                n2 ^= n

        return [n1, n2]
