class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = 0
        r = x
        while l <= r:
            mid = (l+r) / 2
            if mid**2 <= x and (mid+1)**2 > x:
                return mid
            elif mid ** 2 > x:
                r = mid-1
            else:
                l = mid+1

        return r
