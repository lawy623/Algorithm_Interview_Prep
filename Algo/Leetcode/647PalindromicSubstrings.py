class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        count = 0

        for i in range(n):
            count += self.countS(s, i, i, n)
            count += self.countS(s, i, i+1, n)

        return count

    def countS(self, s, l, r, n):
        count = 0
        while l >= 0 and r<n and s[l]==s[r]:
            l-=1
            r+=1
            count+=1

        return count