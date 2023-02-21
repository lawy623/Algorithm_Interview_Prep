MAX_INT = 2 ** 31 - 1
MIN_INT = -2 ** 31

class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        n = len(s)
        while i < n and s[i] == ' ':
            i += 1

        # eol
        if i == n:
            return 0

        sign = 1
        # +-
        if s[i] == '+':
            i += 1
        elif s[i] == '-':
            sign = -1
            i += 1

        # read char
        x = ""
        while i < n and ischar(s[i]):
            x += s[i]
            i += 1
        if x == "":
            return 0

        return sToi(x, sign)


def ischar(c):
    return cToi(c) >= 0 and cToi(c) <= 9

def cToi(c):
    return ord(c) - ord('0')

def sToi(s, sign):
    """The str must be pos int"""
    res = 0
    for c in s:
        if res > int(MAX_INT / 10) or (res == int(MAX_INT / 10) and cToi(c) > 7):
            return MAX_INT
        if res < int(MIN_INT / 10) or (res == int(MIN_INT / 10) and cToi(c) > 8):
            return MIN_INT
        res = res * 10 + sign * cToi(c)

    return res
