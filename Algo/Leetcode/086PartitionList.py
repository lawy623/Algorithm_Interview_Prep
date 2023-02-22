# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head is None:
            return head

        l = ListNode()
        r = ListNode()
        l_m = l
        r_m = r
        while head:
            if head.val < x:
                l_m.next = head
                l_m = l_m.next
            else:
                r_m.next = head
                r_m = r_m.next
            head = head.next

        # relink and stop
        l_m.next = r.next
        r_m.next = None

        return l.next