# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.minV = 0
        self.res = sys.maxint
        self.find = False

    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return -1
        self.minV = root.val
        self.dfs(root)

        return self.res if self.find else -1

    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        if root.val > self.minV and root.val < self.res:
            self.find = True
            self.res = root.val
        self.dfs(root.right)