## Use Queue for level print
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        if root is None:
            return []

        res = []
        queue = []
        queue.append(root)
        while len(queue)>0:
            x = queue[0]
            queue.pop(0)
            res.append(x.val)
            if x.left is not None:
                queue.append(x.left)
            if x.right is not None:
                queue.append(x.right)
        return res
