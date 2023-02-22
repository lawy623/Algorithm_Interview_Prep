# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        res = []
        while head:
            res.append(head.val)
            head = head.next

        return res == res[::-1]

# O(1) space
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        f = ListNode()
        f.next = head
        fast = f
        slow = f
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        tmp = slow.next
        slow.next = None
        slow = reverseL(tmp)
        fast = head

        while fast and slow:
            if fast.val != slow.val:
                return False
            fast = fast.next
            slow = slow.next

        return True


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