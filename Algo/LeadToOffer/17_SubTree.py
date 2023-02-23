# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        if B is None and A is None:
            return True
        if B is None or A is None:
            return False

        res = False
        if A.val == B.val:
            res = self.isSameTree(A, B)
        if not res:  # you still need to check left and right
            res = self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)

        return res

    def isSameTree(self, A, B):
        if B is None:  # if the parent node are the same
            return True
        if A is None:
            return False

        if A.val != B.val:
            return False

        return self.isSameTree(A.left, B.left) and self.isSameTree(A.right, B.right)


