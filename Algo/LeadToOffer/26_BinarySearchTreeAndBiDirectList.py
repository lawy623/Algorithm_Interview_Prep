"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if root is None:
            return None

        # To the head of each node
        list_l_head = self.treeToDoublyList(root.left)
        list_r_head = self.treeToDoublyList(root.right)

        # merge left and root
        if list_l_head is None:
            root.left = root
            root.right = root
            list_l_head = root
        else:
            list_l_tail = list_l_head
            while list_l_tail.right != list_l_head:
                list_l_tail = list_l_tail.right
            list_l_tail.right = root
            list_l_head.left = root
            root.right = list_l_head
            root.left = list_l_tail

        # merge left and right
        if list_r_head is not None:
            list_r_tail = list_r_head
            while list_r_tail.right != list_r_head:
                list_r_tail = list_r_tail.right
            list_r_tail.right = list_l_head
            list_l_head.left = list_r_tail
            root.right = list_r_head
            list_r_head.left = root

        return list_l_head