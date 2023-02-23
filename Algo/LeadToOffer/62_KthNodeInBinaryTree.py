# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def __init__(self):
        self.count = 0
        self.res = 0

    def kthLargest(self, root, k):
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

        self.dfs(root.right, k)
        self.count += 1
        if self.count == k:
            self.res = root.val
        self.dfs(root.left, k)
