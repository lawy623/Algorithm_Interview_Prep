# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        f = ListNode()
        f.next = head
        res = f
        t = ListNode()
        t.next = head
        # get the left end
        while left > 1:  # correct place
            f = f.next
            left -= 1
        # get the right end
        while right > 0:  # correct place
            t = t.next
            right -= 1
        # cut right
        _t = t.next
        t.next = None
        # direct connect
        if f.next is None:
            f.next = _t
            return head
        # reverse middle
        tmp = self.reverse(f.next)
        # get middle last
        last = tmp
        while last.next:
            last = last.next
        # connect middle last to right
        last.next = _t
        f.next = tmp

        return res.next

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
