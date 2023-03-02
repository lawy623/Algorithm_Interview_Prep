class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        isPrime = [True] * n

        for i in range(2, n):       # from 2, otherwise all update to False
            if isPrime[i]:
                count += 1
                # update all j's x-times
                j = i * i
                while j < n:
                    isPrime[j] = False
                    j += i

        return count