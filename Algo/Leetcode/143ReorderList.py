# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return head

        f = ListNode()
        f.next = head
        fast = head
        slow = head
        pre = slow  # must get one before
        while fast and fast.next:
            pre = slow
            fast = fast.next.next
            slow = slow.next

        tmp = pre.next
        pre.next = None
        pre = reverseL(tmp)
        fast = head

        # merge slow and fast
        res = ListNode()
        r = res
        while fast:
            res.next = fast
            fast = fast.next
            res.next.next = pre
            pre = pre.next
            res = res.next.next

        return r.next


def reverseL(head):
    tail = head
    if head is None:
        return head

    while tail.next:
        tmp = tail.next
        tail.next = tail.next.next
        tmp.next = head
        head = tmp

    return head