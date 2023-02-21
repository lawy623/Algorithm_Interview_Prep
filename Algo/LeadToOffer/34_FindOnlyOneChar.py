## 1. Use map. Store the appearance time. O(n) time, O(1) space.
class Solution:
    def FirstNotRepeatingChar(self, s):
        if len(s)==0:
            return -1
        dict_v = {}
        for c in s:
            if c in dict_v:
                dict_v[c]+=1
            else:
                dict_v[c]=1
        for i, c in enumerate(s):
            if c in dict_v and dict_v[c]==1:
                return i
        return -1

# more clear
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: str
        """

        d = {}
        for n in s:
            d[n] = d.get(n, 0) + 1

        for n in s:
            if d[n] == 1:
                return n

        return " "