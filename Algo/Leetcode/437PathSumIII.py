# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.count = 0
        self.sum = 0
        self.d = {0: 1}

    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        if root is None:
            return 0

        self.dfs(root, targetSum)
        return self.count

    def dfs(self, root, targetSum):
        if root is None:
            return 0

        # record
        self.sum += root.val

        if self.d.get(self.sum - targetSum, 0) > 0:
            self.count += self.d.get(self.sum - targetSum)
        self.d[self.sum] = self.d.get(self.sum, 0) + 1

        self.pathSum(root.left, targetSum)
        self.pathSum(root.right, targetSum)

        self.d[self.sum] -= 1
        self.sum -= root.val

        return self.count