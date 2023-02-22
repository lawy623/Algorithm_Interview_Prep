# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return head

        # get list length
        m = head
        l = 1

        while m.next:
            m = m.next
            l += 1
        # circle
        m.next = head
        k = k % l

        m = head
        i = 0
        while i < l - k - 1:  # be careful on this value
            m = m.next
            i += 1

        res = m.next
        m.next = None

        return res
