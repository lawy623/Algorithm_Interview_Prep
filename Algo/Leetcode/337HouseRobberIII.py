# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        # do not take two child, max value
        v = root.val
        if root.left:
            v += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            v += self.rob(root.right.left) + self.rob(root.right.right)

        # take two child, not root
        _v = self.rob(root.left) + self.rob(root.right)

        return max(v, _v)


# dp
class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        res = self.dfs(root)
        return max(res[0], res[1])

    def dfs(self, root):
        res = [0, 0]
        if root is None:
            return res

        l = self.dfs(root.left)
        r = self.dfs(root.right)
        res[0] = max(l[0], l[1]) + max(r[0], r[1])
        res[1] = l[0] + r[0] + root.val

        return res