# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None

        if root == p or root == q:
            return root

        l_a = self.lowestCommonAncestor(root.left, p, q)
        r_a = self.lowestCommonAncestor(root.right, p, q)

        # if this is LCA, each side get returns
        if l_a is not None and r_a is not None:
            return root

        return l_a if l_a is not None else r_a