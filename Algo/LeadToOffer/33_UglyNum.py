## Very trickly implementation. Use one vector and 3 indexs to store 3 queues. 
class Solution:
    def GetUglyNumber_Solution(self, index):
        if index < 0:
            return -1;
        if index < 7:
            return index;

        res = []
        p2, p3, p5 = 0, 0, 0
        res.append(1)
        while len(res)<index:
            min_v = min(min(res[p2]*2, res[p3]*3), res[p5]*5)
            if min_v==res[p2]*2:
                p2+=1
            if min_v==res[p3]*3:
                p3+=1
            if min_v==res[p5]*5:
                p5+=1
            res.append(min_v)
        return min_v
