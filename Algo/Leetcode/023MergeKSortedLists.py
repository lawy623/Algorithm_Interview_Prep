# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        k = len(lists)
        if k == 0:
            return None
        while k > 1:
            _lists = []
            if k % 2 == 0:
                i = 0
                while i < k:
                    _lists.append(self.merge2Lists(lists[i], lists[i+1]))
                    i += 2
                k = k / 2
            else:
                i = 0
                while i < k-1:
                    _lists.append(self.merge2Lists(lists[i], lists[i+1]))
                    i += 2
                _lists.append(lists[i])
                k = (k + 1) / 2

            lists = _lists

        return lists[0]

    def merge2Lists(self, list1, list2):
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
