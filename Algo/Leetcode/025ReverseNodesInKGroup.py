# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        i = 0
        f = ListNode()
        f.next = head
        first = f
        # find the first K
        while i < k:
            if first is None:
                return head
            i += 1
            first = first.next
        # goes to None
        if first is None:
            return head

        # disconnect right
        right = first.next
        first.next = None
        # reverse first K
        f.next = self.reverse(f.next)
        # first reverse end
        l = f.next
        while l.next:
            l = l.next
        # reconnect reverse and right
        l.next = self.reverseKGroup(right, k)

        return f.next

    def reverse(self, head):
        tail = head
        if head is None:
            return head

        while tail.next:
            tmp = tail.next
            tail.next = tail.next.next
            tmp.next = head
            head = tmp

        return head
