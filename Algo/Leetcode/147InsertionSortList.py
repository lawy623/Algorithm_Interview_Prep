# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        f = ListNode()

        while head is not None:
            tmp = head.next
            head.next = None
            self.insert(f, head)
            head = tmp

        return f.next

    def insert(self, f, head):
        m = f
        while m.next and m.next.val < head.val:
            m = m.next

        head.next = m.next
        m.next = head
