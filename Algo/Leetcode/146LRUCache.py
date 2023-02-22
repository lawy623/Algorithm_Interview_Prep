## NOTICE: It does not pass all the testcases, shows the progress only
class DLinkedList(object):
    def __init__(self, key, val=0, prev=None, next=None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.count = 0
        self.kv = {}
        self.front = None
        self.end = None

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.kv.keys():
            return -1
        else:
            node = self.kv[key]
            val = node.val
            self.moveNodeToFront(node)
            return val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if self.front is None:  # init dList, same front and end
            self.front = DLinkedList(key, value)
            self.end = self.front
            self.kv[key] = self.front
            self.count += 1
        else:
            if key in self.kv.keys():  # extract and move to front
                self.kv[key].val = value
                self.moveNodeToFront(self.kv[key])
            else:
                if self.capacity == self.count:
                    self.kv.pop(self.end.key)
                    self.removeNodeFromEnd()
                    self.count -= 1
                self.addNodeToFront(DLinkedList(key, value))
                self.kv[key] = self.front
                self.count += 1

    def moveNodeToFront(self, node):
        """Move the node to Front"""
        if node is None:
            return
        if node.prev is None:
            return
        p = node.prev
        n = node.next
        p.next = n
        if n is not None:
            n.prev = p
        else:
            self.end = p
        # move node to front and update front
        self.addNodeToFront(node)

    def addNodeToFront(self, node):
        if self.front is None:
            self.front = node
            self.end = node
        else:
            node.next = self.front
            self.front.prev = node
            self.front = node

    def removeNodeFromEnd(self):
        """Remove the last Node"""
        if self.end is None:
            return

        last = self.end.prev
        if last is None:
            self.front = None
            self.end = None
        else:
            last.next = None
            self.end = last

    def getList(self):
        res = []
        m = self.front
        while m:
            res.append(m.val)
            m = m.next
        return res