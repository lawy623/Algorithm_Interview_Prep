# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        tmp = []
        res = []
        if root is None:
            return tmp

        tmp.append(root)
        while len(tmp) > 0:
            count = len(tmp)
            level = []
            while count > 0:
                n = tmp[0]
                level.append(n.val)
                if n.left is not None:
                    tmp.append(n.left)
                if n.right is not None:
                    tmp.append(n.right)
                tmp.pop(0)
                count -= 1
            res.append(level)

        return res