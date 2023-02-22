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
        if head is None or head.next is None:
            return head

        f = ListNode()
        f.next = head
        if head.val == head.next.val:
            while head and head.next and head.val == head.next.val:
                head = head.next
            f.next = self.deleteDuplicates(head.next)
        else:
            head.next = self.deleteDuplicates(head.next)

        return f.next