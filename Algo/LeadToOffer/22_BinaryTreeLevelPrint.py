# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        tmp = []
        res = []
        if root is None:
            return tmp

        tmp.append(root)
        while len(tmp) > 0:
            n = tmp[0]
            res.append(n.val)
            if n.left is not None:
                tmp.append(n.left)
            if n.right is not None:
                tmp.append(n.right)
            tmp.pop(0)

        return res