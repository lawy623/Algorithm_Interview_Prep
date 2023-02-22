# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        tail = head
        if head is None:
            return head

        while tail.next:
            tmp = tail.next
            tail.next = tail.next.next
            tmp.next = head
            head = tmp

        return head
