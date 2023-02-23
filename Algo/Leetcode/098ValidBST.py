# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.last_min = None
        self.bst = True

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        self.dfs(root)

        return self.bst

    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        if self.last_min is not None and root.val <= self.last_min:
            self.bst = False
        self.last_min = root.val
        self.dfs(root.right)