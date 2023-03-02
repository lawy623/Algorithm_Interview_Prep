class Solution(object):

    def __init__(self):
        self.res = []
        self.path = ""

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        d = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        n = len(digits)
        if n == 0:
            return self.res

        self.dfs(digits, d, 0, n)
        return self.res

    def dfs(self, digits, d, i, n):
        if i >= n:
            self.res.append(copy.deepcopy(self.path))
            return

        digit = d[digits[i]]
        for dig in digit:
            self.path += dig
            self.dfs(digits, d, i + 1, n)
            self.path = self.path[:-1]
