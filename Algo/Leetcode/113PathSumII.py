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

    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: List[List[int]]
        """
        if root is None:
            return

        self.path.append(root.val)
        if root.val == targetSum and root.left is None and root.right is None:
            self.res.append(copy.deepcopy(self.path))

        self.pathSum(root.left, targetSum - root.val)
        self.pathSum(root.right, targetSum - root.val)
        self.path.pop()

        return self.res
