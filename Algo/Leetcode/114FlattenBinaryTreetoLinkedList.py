# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        if root.left is None and root.right is None:
            return root

        # inplace
        self.flatten(root.left)
        self.flatten(root.right)

        if root.left is None:
            return

        l_tail = root.left
        while l_tail.right:
            l_tail = l_tail.right
        l_tail.right = root.right

        # reset
        root.right = root.left
        root.left = None
