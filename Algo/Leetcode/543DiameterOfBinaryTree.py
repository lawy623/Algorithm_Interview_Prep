# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.res = 0

    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        self.dfs(root)

        return self.res - 1

    def dfs(self, root):
        if root is None:
            return 0

        v_l = self.dfs(root.left)
        v_r = self.dfs(root.right)

        self.res = max(self.res, v_l + v_r + 1)

        return max(v_l, v_r) + 1
