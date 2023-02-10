# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        out = ListNode()
        res = out
        add_on = 0
        while(l1 is not None or l2 is not None or add_on > 0):
            v_1 = l1.val if l1 is not None else 0
            v_2 = l2.val if l2 is not None else 0
            v = v_1 + v_2 + add_on
            add_on = v / 10
            v = v % 10
            out.next = ListNode(v)
            out = out.next
            l1 = l1.next if l1 is not None else l1
            l2 = l2.next if l2 is not None else l2

        return res.next