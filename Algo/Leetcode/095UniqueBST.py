# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        return self.gen(1, n)

    def gen(self, l, r):
        if l == r:
            return [TreeNode(l)]
        if l == r - 1:
            t1 = TreeNode(l)
            t1.right = TreeNode(r)
            t2 = TreeNode(r)
            t2.left = TreeNode(l)
            return [t1, t2]
        if l > r:
            return [None]

        res = []
        for k in range(l, r + 1):
            left_trees = self.gen(l, k - 1)
            right_trees = self.gen(k + 1, r)
            for l_n in left_trees:
                for r_n in right_trees:
                    root = TreeNode(k)
                    root.left = l_n
                    root.right = r_n
                    res.append(root)

        return res