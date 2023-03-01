class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        w_bit = []
        for w in words:
            b = 0
            for c in w:
                b |= 1 << (ord(c)-ord('a'))
            w_bit.append(b)

        n = len(words)
        max_prod = 0
        for i in range(n):
            for j in range(i+1, n):
                if w_bit[i] & w_bit[j] == 0:
                    max_prod = max(max_prod, len(words[i]) * len(words[j]))

        return max_prod