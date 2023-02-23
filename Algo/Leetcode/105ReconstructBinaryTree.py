# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None

        val = preorder[0]
        i = 0
        n = len(preorder)

        while i < n and val != inorder[i]:
            i += 1

        root = TreeNode(val)
        root.left = self.buildTree(preorder[1:1 + i], inorder[:i])
        root.right = self.buildTree(preorder[1 + i:], inorder[i + 1:])

        return root