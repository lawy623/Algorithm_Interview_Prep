# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.res = []

    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root is None:
            return

        self.dfs(root)

        n = len(self.res)
        i = 0
        while i < n and self.res[i].val < self.res[i + 1].val:
            i += 1
        j = n - 1
        while j > 0 and self.res[j].val > self.res[j - 1].val:
            j -= 1

        tmp = self.res[i].val
        self.res[i].val = self.res[j].val
        self.res[j].val = tmp

    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        self.res.append(root)  # push the node
        self.dfs(root.right)