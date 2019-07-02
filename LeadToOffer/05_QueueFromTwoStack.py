## python version.
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        while len(self.stack1) != 0:
            self.stack2.append(self.stack1.pop())
        res = self.stack2.pop()
        while len(self.stack2) != 0:
            self.stack1.append(self.stack2.pop())
        return res

## No need to pop every time
    def pop(self):
        if len(self.stack2) == 0:
            while len(self.stack1) != 0:
                self.stack2.append(self.stack1.pop())
        res = self.stack2.pop()

        return res
