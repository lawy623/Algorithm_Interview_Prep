# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        head = ListNode()
        res = head
        while list1 or list2:
            if list1 and list2:
                if list1.val <= list2.val:
                    head.next = ListNode(list1.val)
                    list1 = list1.next
                else:
                    head.next = ListNode(list2.val)
                    list2 = list2.next
            elif list1 is None:
                head.next = ListNode(list2.val)
                list2 = list2.next
            else:
                head.next = ListNode(list1.val)
                list1 = list1.next

            head = head.next

        return res.next


# recursive
class Solution(object):
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