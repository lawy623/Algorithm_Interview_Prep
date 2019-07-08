## Recursively exchange left and right subtree of a non-leaf node.
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if root is None:
            return

        temp = root.left
        root.left = root.right
        root.right = temp

        self.Mirror(root.left)
        self.Mirror(root.right)
        return
