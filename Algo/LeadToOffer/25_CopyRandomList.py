## 1. Use map. O(n) time. O(n) space. keep track of the two lists' position.
    def Clone(self, pHead):
        move_head = pHead
        if pHead is None:
            return None
        list_to_list = {}

        result_head = RandomListNode(move_head.label)
        result_move_head = result_head
        list_to_list[move_head] = result_head

        move_head = move_head.next
        while move_head is not None:
            result_move_head.next = RandomListNode(move_head.label)
            result_move_head = result_move_head.next
            list_to_list[move_head] = result_move_head
            move_head = move_head.next

        move_head = pHead
        result_move_head = result_head
        while move_head is not None:
            if move_head.random is not None:
                result_move_head.random = list_to_list[move_head.random]
            move_head = move_head.next
            result_move_head = result_move_head.next

        return result_head

## 2. Copy first then split. O(n) time, o(1) extra space
class Solution:
    def Clone(self, pHead):
        move_head = pHead
        if pHead is None:
            return None

        while move_head is not None:
            temp = move_head.next
            move_head.next = RandomListNode(move_head.label)
            move_head.next.next = temp
            move_head = move_head.next.next

        move_head = pHead
        while move_head is not None:
            if move_head.random is not None:
                move_head.next.random = move_head.random.next
            move_head = move_head.next.next

        move_head = pHead
        result_head = move_head.next
        result_move_head = result_head
        move_head.next = move_head.next.next
        move_head = move_head.next
        while move_head is not None:
            result_move_head.next = move_head.next
            result_move_head = result_move_head.next
            move_head.next = move_head.next.next
            move_head = move_head.next

        return result_head
