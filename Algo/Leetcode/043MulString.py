class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        return str(self._multiply(num1, num2))

    def _multiply(self, num1, num2):
        n1 = len(num1)
        n2 = len(num2)
        if n2 == 0:
            return 0
        return self._multiply(num1, num2[:-1]) * 10 + nToi(num1) * cToi(num2[-1])


def cToi(c):
    return ord(c) - ord('0')

def nToi(s):
    res = 0
    for n in s:
        res = res * 10 + cToi(n)

    return res
