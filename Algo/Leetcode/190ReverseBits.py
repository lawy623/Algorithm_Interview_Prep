class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        res = 0
        for i in range(32):
            if n & 1<<i:
                res |= 1<<(31-i)

        return res