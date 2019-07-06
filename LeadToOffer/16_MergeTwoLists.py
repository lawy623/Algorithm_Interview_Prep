## recursive
class Solution:
    def Merge(self, pHead1, pHead2):
        if pHead1 is None and pHead2 is None:
            return None
        if pHead1 is None:
            return pHead2
        if pHead2 is None:
            return pHead1

        res = None
        if pHead1.val <= pHead2.val:
            res = pHead1
            pHead1 = pHead1.next
        else:
            res = pHead2
            pHead2 = pHead2.next
        res.next = self.Merge(pHead1, pHead2)

        return res
