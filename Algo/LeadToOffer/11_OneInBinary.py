## method 1. Move two times.
class Solution:
    def NumberOf1(self, n):
        count = 0
        for i in range(32):
            count += (n & 1 << i) >> i
        return count

## method 2. Move one time and compare.
class Solution:
    def NumberOf1(self, n):
        count = 0
        for i in range(32):
            if n & 1<<i:
                count += 1
        return count
