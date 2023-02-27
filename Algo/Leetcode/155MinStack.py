class MinStack(object):

    def __init__(self):
        self.stack = []
        self.min_s = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        if len(self.min_s) == 0:
            self.min_s.append(val)
        else:
            if self.min_s[-1] <= val:
                self.min_s.append(self.min_s[-1])
            else:
                self.min_s.append(val)

    def pop(self):
        """
        :rtype: None
        """
        self.min_s.pop()
        return self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_s[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()