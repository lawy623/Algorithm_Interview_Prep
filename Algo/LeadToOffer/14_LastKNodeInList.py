# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        move = head
        while head and k > 0:
            head = head.next
            k -= 1

        while head:
            head = head.next
            move = move.next

        return move