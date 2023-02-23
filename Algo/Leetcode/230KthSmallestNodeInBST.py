# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.count = 0
        self.res = 0

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        if root is None:
            return -1

        self.dfs(root, k)
        return self.res

    def dfs(self, root, k):
        if root is None:
            return

        self.dfs(root.left, k)
        self.count += 1
        if self.count == k:
            self.res = root.val
        self.dfs(root.right, k)
