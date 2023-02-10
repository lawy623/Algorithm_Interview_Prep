# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            head = head.next
            if fast == head:
                return True

        return False