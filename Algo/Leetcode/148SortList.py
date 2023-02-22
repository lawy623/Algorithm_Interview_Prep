# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        if head.next is None:
            return head
        if head.next.next is None:
            if head.val < head.next.val:
                return head
            else:
                head.next.next = head
                tmp = head.next
                head.next = None
                return tmp

        # merge sort
        f = ListNode()
        f.next = head
        fast = f
        slow = f
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        l2 = slow.next
        slow.next = None

        return self.mergeTwoLists(self.sortList(f.next), self.sortList(l2))


    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        head = ListNode()
        if list1 and list2:
            if list1.val <= list2.val:
                head.val = list1.val
                list1 = list1.next
            else:
                head.val = list2.val
                list2 = list2.next
            head.next = self.mergeTwoLists(list1, list2)
        elif list1 is None:
            return list2
        else:
            return list1

        return head
