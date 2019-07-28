## 1. Directly reverse
class Solution:
    def ReverseSentence(self, s):
        s = s.split(" ")
        s.reverse()
        return " ".join(s)
