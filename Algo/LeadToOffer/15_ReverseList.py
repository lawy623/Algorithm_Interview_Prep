## O(n) time.
class Solution:
    def ReverseList(self, pHead):
        if pHead is None:
            return None

        pFirst = pHead
        while pHead.next is not None:
            temp = pHead.next
            pHead.next = temp.next
            temp.next = pFirst
            pFirst = temp
        return pFirst
