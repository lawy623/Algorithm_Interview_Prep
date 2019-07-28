## 1. Directly using string slice.
class Solution:
    def LeftRotateString(self, s, n):
        if n==0:
            return s
        return s[n:]+ s[:n]
