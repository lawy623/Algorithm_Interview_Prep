class Solution(object):

    def __init__(self):
        self.res = []
        self.s = ""

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.gen(n, n)
        return self.res

    def gen(self, l, r):
        if l == 0 and r == 0:
            self.res.append(self.s)
        elif l == 0:
            self.s += ')'
            self.gen(l, r - 1)
            self.s = self.s[:-1]
        elif l == r:
            self.s += '('
            self.gen(l - 1, r)
            self.s = self.s[:-1]
        else:
            self.s += '('
            self.gen(l - 1, r)
            self.s = self.s[:-1]
            self.s += ')'
            self.gen(l, r - 1)
            self.s = self.s[:-1]
