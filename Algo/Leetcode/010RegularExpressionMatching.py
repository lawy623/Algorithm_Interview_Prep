# do not waste time in hard problem
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        res = re.search(p,s)
        if res and res.group() == s:
            return True
        return False


# ok recursion
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        n = len(s)
        m = len(p)
        if m == 0:
            return n == 0

        firstMat = n != 0 and (s[0] == p[0] or p[0] == '.')

        if (m >= 2 and p[1] == '*'):
            return self.isMatch(s, p[2:]) or (firstMat and self.isMatch(s[1:], p))
        else:
            return firstMat and self.isMatch(s[1:], p[1:])