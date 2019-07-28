class Solution:
    def IsPopOrder(self, pushV, popV):
        if len(pushV)!=len(popV):
            return False
        if len(pushV)==0 and len(popV)==0:
            return False

        res = []
        i,j = 0,0
        while i<len(pushV):
            res.append(pushV[i])
            while len(res)!=0 and res[-1]==popV[j]:
                res.pop()
                j += 1
            i += 1

        return len(res)==0
