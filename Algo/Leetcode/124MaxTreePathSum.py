# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.res = -2 ** 32

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        self.maxSum(root)
        return self.res

    def maxSum(self, root):
        """Return the max sum containing cur root node"""
        if root is None:
            return 0

        # pick left/right or not
        max_l = max(self.maxSum(root.left), 0)
        max_r = max(self.maxSum(root.right), 0)

        # cur node
        self.res = max(self.res, max_l + max_r + root.val)

        return root.val + max(max_l, max_r)

