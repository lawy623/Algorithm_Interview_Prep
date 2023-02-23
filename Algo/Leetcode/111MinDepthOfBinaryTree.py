# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        # consider either node is None, must include one
        if root.left is None or root.right is None:
            return self.minDepth(root.right)+1 if root.left is None else self.minDepth(root.left)+1

        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
