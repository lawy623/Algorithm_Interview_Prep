# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        l1 = 0
        l2 = 0
        f = headA
        while f:
            l1 += 1
            f = f.next
        f = headB
        while f:
            l2 += 1
            f = f.next

        if l1 > l2:
            d = l1 - l2
            while d > 0:
                headA = headA.next
                d -= 1
        else:
            d = l2 - l1
            while d > 0:
                headB = headB.next
                d -= 1

        while headA != headB and headA is not None and headB is not None:
            headA = headA.next
            headB = headB.next

        return headA
