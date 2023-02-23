# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []

        self.dfs(root)
        return self.res

    def dfs(self, root):
        if root is None:
            return

        self.path.append(str(root.val))
        if root.left is None and root.right is None:
            self.res.append('->'.join(self.path))
        self.dfs(root.left)
        self.dfs(root.right)
        self.path.pop()