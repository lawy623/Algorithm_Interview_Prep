# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        if root.left is None and root.right is None:
            return True

        return self.isSymmetricPair(root.left, root.right)

    def isSymmetricPair(self, l, r):
        if l is None and r is None:
            return True

        if l is None or r is None:
            return False

        if l.val != r.val:
            return False

        return self.isSymmetricPair(l.left, r.right) and self.isSymmetricPair(l.right, r.left)
