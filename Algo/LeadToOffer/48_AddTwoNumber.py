class Solution(object):
    def add(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        while b > 0:
            sum_no_carry = a ^ b            # actually not correct for python, use c++ instead
            carry =  (a&b) << 1
            a = sum_no_carry
            b = carry

        return a