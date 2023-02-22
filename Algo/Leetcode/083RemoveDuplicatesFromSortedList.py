# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None

        m = head
        while m and m.next and m.val == m.next.val:
            m = m.next

        if m.next is None:
            head.next = None
        else:
            head.next = self.deleteDuplicates(m.next)

        return head