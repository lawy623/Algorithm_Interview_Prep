# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head

        tmp = head.next.next
        f = ListNode()
        f.next = head.next
        f.next.next = head
        f.next.next.next = self.swapPairs(tmp)

        return f.next