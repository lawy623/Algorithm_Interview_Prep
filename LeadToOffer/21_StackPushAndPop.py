class Solution:
    def IsPopOrder(self, pushV, popV):
        if len(pushV)!=len(popV):
            return False
        if len(pushV)==0 and len(popV)==0:
            return False

        res = []
        i,j = 0,0
        while i<len(pushV):
            if len(res)!=0 and res[-1]==popV[j]:
                res.pop()
                j += 1
            else:
                res.append(pushV[i])
                i += 1
        while len(res)>0:
            if res[-1]!= popV[j]:
                return False
            res.pop()
            j += 1
        return True
