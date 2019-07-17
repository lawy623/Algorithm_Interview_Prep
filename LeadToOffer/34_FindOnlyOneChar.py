## 1. Use map. Store the appearance time. O(n) time, O(n) space.
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
