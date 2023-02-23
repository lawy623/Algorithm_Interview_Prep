# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        move = head
        fast = head
        while fast and n > 0:
            fast = fast.next
            n -= 1

        while fast:
            fast = fast.next
            move = move.next

        # first
        if head == move:
            return head.next

        # remove
        if move.next is None:  # last
            fast = head
            while fast.next.next:
                fast = fast.next
            fast.next = None
        else:   # not last
            move.val = move.next.val
            move.next = move.next.next

        return head
