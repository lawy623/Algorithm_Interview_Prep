class Solution:
    def VerifySquenceOfBST(self, sequence):
        if len(sequence)==0:
            return False

        return self.verify(sequence, 0, len(sequence)-1)

    def verify(self, seq, start, end):
        if start==end or start==end-1:
            return True

        root = seq[end]
        idx = self.findFirstLarger(seq, start, end, root)
        for i in range(start, idx):
            if seq[i]>root:
                return False
        for i in range(idx, end):
            if seq[i]<root:
                return False
        res = True
        if idx-1 > start:
            res = res and self.verify(seq, start, idx-1)
        if idx < end-1:
            res = res and self.verify(seq, idx, end-1)
        return res

    def findFirstLarger(self, seq, start, end, root):
        for i in range(start, end):
            if seq[i]>root:
                return i
        return end
