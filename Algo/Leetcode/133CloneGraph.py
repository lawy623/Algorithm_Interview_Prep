"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution(object):

    def __init__(self):
        self.visit = {}  # old node to new node

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        return self.dfs(node)

    def dfs(self, node):
        if node is None:
            return node

        if node in self.visit:
            return self.visit[node]  # incase dfs repeatly

        clone_node = Node(node.val, [])
        self.visit[node] = clone_node
        for n in node.neighbors:
            clone_node.neighbors.append(self.dfs(n))

        return clone_node
