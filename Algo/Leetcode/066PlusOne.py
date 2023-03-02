class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        d = int(''.join([str(s) for s in digits])) + 1
        res = [int(k) for k in str(d)]
        return res