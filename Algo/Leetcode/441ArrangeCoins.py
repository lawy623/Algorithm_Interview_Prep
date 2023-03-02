class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 0
        r = n
        while l <= r:
            mid = (l + r) / 2
            s1 = (1 + mid) * mid / 2
            s2 = (mid - 1) * mid / 2
            if s1 == n:
                return mid
            if s2 == n:
                return mid - 1
            if s2 < n < s1:
                return mid - 1

            if n < s2:
                r = mid - 1
            else:
                l = mid + 1

        return l