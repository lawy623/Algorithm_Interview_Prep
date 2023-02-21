class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) < len(t):
            return self.isAnagram(t, s)

        d = {}
        for n in t:
            d[n] = d.get(n, 0) + 1

        for n in s:
            if d.get(n, 0) == 0:
                return False
            else:
                d[n] -= 1

        return True