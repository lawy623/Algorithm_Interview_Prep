# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.sum = 0
        self.path = ""

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return

        self.path += str(root.val)
        if root.left is None and root.right is None:
            self.sum += int(self.path)

        self.sumNumbers(root.left)
        self.sumNumbers(root.right)
        self.path = self.path[:-1]

        return self.sum