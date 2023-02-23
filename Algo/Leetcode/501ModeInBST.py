# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def __init__(self):
        self.prev = None
        self.mode = []
        self.count = 0
        self.max_count = 0

    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return

        self.dfs(root)

        return self.mode

    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)

        val = root.val
        if self.prev is None:
            self.prev = val
            self.count = 1
        else:
            if val == self.prev:
                self.count += 1
            else:
                self.count = 1
                self.prev = val
        # update
        if self.count > self.max_count:
            self.max_count = self.count
            self.mode = [val]
        elif self.count == self.max_count:
            self.mode.append(val)

        self.dfs(root.right)
