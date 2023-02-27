class Node(object):

    def __init__(self, v=''):
        self.v = v
        self.ptr = [None] * 26
        self.left = None
        self.right = None
        self.endNode = False


class Trie(object):

    def __init__(self):
        self.root = Node()

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        return self.insertNode(self.root, str(word))

    def insertNode(self, node, word):
        if len(word) == 0 and node is not None:
            node.endNode = True
            return None

        c = word[0]
        idx = self.ord(c)
        if node.ptr[idx] is None:
            node.ptr[idx] = Node(c)

        self.insertNode(node.ptr[idx], word[1:])
        return None

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        return self.searchNode(self.root, str(word))

    def searchNode(self, node, word):
        if len(word) == 0:
            if node.endNode:
                return True
            else:
                return False

        if node is None:
            return False

        c = word[0]
        idx = self.ord(c)
        if node.ptr[idx] is None:
            return False

        return self.searchNode(node.ptr[idx], word[1:])

    def startsWith(self, prefix):
        """
        :type prefix: str
        :rtype: bool
        """
        return self.startsWithNode(self.root, str(prefix))

    def startsWithNode(self, node, prefix):
        if len(prefix) == 0:  # no need to be leaf node
            return True

        c = prefix[0]
        idx = self.ord(c)
        if node.ptr[idx] is None:
            return False

        return self.startsWithNode(node.ptr[idx], prefix[1:])

    def ord(self, c):
        return ord(c) - ord('a')

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)