## 1. Merge and count. O(nlogn) time and O(n) space.
class Solution:
    def InversePairs(self, data):
        if len(data)==0:
            return 0
        count = self.MergeAndCount(data, 0, len(data)-1)
        return count%1000000007

    def MergeAndCount(self, data, start, end):
        if start==end:
            return 0
        if start==end-1:
            if data[start]<=data[end]:
                return 0
            else:
                data[start], data[end] = data[end], data[start]
                return 1
        mid = (start+end) // 2
        count_l = self.MergeAndCount(data, start, mid)
        count_r = self.MergeAndCount(data, mid+1, end)
        p1,p2=0,0
        count=0
        l,r=[],[]
        for i in range(start,mid+1):
            l.append(data[i])
        for i in range(mid+1,end+1):
            r.append(data[i])
        for i in range(start, end+1):
            if p2==len(r):
                data[i] = l[p1]
                count += p2
                p1+=1
            elif p1==len(l):
                data[i] = r[p2]
                p2+=1
            elif l[p1]<=r[p2]:
                data[i] = l[p1]
                count += p2
                p1+=1
            else:
                data[i] = r[p2]
                p2+=1
        return count + count_l + count_r
