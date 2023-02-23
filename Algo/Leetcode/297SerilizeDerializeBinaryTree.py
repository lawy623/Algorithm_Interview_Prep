# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        res = ""
        if root is None:
            return "NULL"
        q = [root]
        while len(q) > 0:
            level_count = len(q)
            level_str = ""
            while level_count > 0:
                node = q[0]
                if node is None:
                    level_str += "NULL "
                else:
                    val = str(node.val) + " "
                    level_str += val
                    q.append(node.left)
                    q.append(node.right)
                q.pop(0)
                level_count -= 1
            # append each level
            level_str = level_str[:-1]  # remove last
            res += level_str
            res += "#"

        return res[:-1]  # remove last

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        levels = data.split('#')
        root = self.buildNode(levels[0])
        q = [root]
        levels.pop(0)
        while len(levels) > 0:
            nodes = levels[0].split()
            n_nodes = len(nodes)
            while n_nodes > 0:
                if q[0] is None:
                    q.pop(0)
                else:
                    q[0].left = self.buildNode(nodes[0])
                    nodes.pop(0)
                    q[0].right = self.buildNode(nodes[0])
                    nodes.pop(0)
                    q.append(q[0].left)
                    q.append(q[0].right)
                    q.pop(0)
                    n_nodes -= 2
            levels.pop(0)

        return root

    def buildNode(self, s):
        if s == 'NULL':
            return None
        return TreeNode(int(s))

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))