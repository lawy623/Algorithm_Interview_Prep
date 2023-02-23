# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.res = True

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        self.dfs(root)

        return self.res

    def dfs(self, root):
        if root is None:
            return 0

        d_l = self.dfs(root.left)
        d_r = self.dfs(root.right)

        if abs(d_l - d_r) > 1:
            self.res = False

        return max(d_r, d_l) + 1