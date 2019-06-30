## Use python str package for easy replace.
class Solution:
    def replaceSpace(self, s):
        words = s.split(' ')
        if len(words) == 0:
            return s
        res = words[0]
        for w in words[1:]:
            res += '%20' + w
        return res
