"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return head

        # add a copy node after each node
        m = head
        while m is not None:
            n = Node(m.val)
            n.next = m.next
            m.next = n
            m = m.next.next

        # add random link
        m = head
        while m is not None:
            if m.random is not None:
                m.next.random = m.random.next
            m = m.next.next

        # seperate two list
        m = head
        res = Node(0)
        f = res
        while m is not None:
            f.next = m.next
            m.next = m.next.next
            f = f.next
            m = m.next

        return res.next