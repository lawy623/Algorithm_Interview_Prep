# Just brute force
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        for i in range(n+1):
            count += calOne(i)

        return count

def calOne(k):
    c = 0
    for i in str(k):
        if i == "1":
            c += 1

    return c

# each digit
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1:
            return 0

        s = str(n)
        return self.calOne(s)

    def calOne(self, s):
        n = len(s)
        if n == 1:
            return 0 if s == '0' else 1
        else:
            if s[0] == "0":  # no one on left most
                return self.calOne(s[1:])
            elif s[0] == "1":  # left most
                return self.calOne(s[1:]) + int(s[1:]) + 1 + 10 ** (n - 2) * (n - 1)
            else:
                return self.calOne(s[1:]) + 10 ** (n - 1) + 10 ** (n - 2) * (n - 1) * int(s[0])