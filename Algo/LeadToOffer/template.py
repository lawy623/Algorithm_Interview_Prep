class Solution:
    def ReverseSentence(self, s):
        self.Reverse(s, 0, len(s)-1)
        i,j = 0,1
        while(j<len(s)):
            if j==len(s)-1:
                self.Reverse(s, i, j)
                return
            elif s[j]==" ":
                self.Reverse(s, i, j-1)
                j += 2
                i = j-1
            else:
                j += 1
        return
    def Reverse(self, s, start, end):
        for i in range(start, (start+end-1)//2):
            s[i], s[start+end-i] = s[start+end-i], s[i]


if __name__ == '__main__':
    s = Solution()
    input = "I am a student"
    res = s.ReverseSentence(input)
    print(res)
