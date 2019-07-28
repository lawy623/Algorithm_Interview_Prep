## 1. Use stack to store the result.
## O(n) time. O(n) space.
class Solution:
    def printListFromTailToHead(self, listNode):
        stack = []
        while listNode is not None:
            stack.append(listNode.val)
            listNode = listNode.next
        stack.reverse()
        return stack

## 2. reverse Linked list.
## O(n) time. O(1) space. But change input.
class Solution:
    def printListFromTailToHead(self, listNode):
        if listNode is None:
            return []
        first_node = listNode
        while listNode.next is not None:
            tempNode = listNode.next
            listNode.next = listNode.next.next
            tempNode.next = first_node
            first_node = tempNode
        res = []
        while first_node is not None:
            res.append(first_node.val)
            first_node = first_node.next
        return res
