# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        if root is None:
            return res

        if root.left is None and root.right is None:
            return [root.val]
        else:
            res.extend(self.postorderTraversal(root.left))
            res.extend(self.postorderTraversal(root.right))
            res.append(root.val)
            return res