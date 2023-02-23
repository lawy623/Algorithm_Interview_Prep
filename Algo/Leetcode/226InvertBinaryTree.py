# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return root

        left = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(left)

        return root


# Use queue
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return root

        q = []
        q.append(root)
        while len(q) > 0:
            t = q[0]
            swap(t)         # r->l change, push new l then r
            if t.left:
                q.append(t.left)
            if t.right:
                q.append(t.right)
            q.pop(0)

        return root

def swap(t):
    tmp = t.left
    t.left = t.right
    t.right = tmp