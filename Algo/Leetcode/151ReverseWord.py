# Don't waste time with python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        x = s.strip().split()
        return ' '.join(x[::-1])
