class Solution(object):
    def countPrimeSetBits(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        count = 0
        for num in range(left, right+1):
            c = 0
            for i in range(32):
                c += 1 if (num & 1<<i) > 0 else 0
            if self.isPrime(c):
                count += 1

        return count

    def isPrime(self, n):
        return n in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]