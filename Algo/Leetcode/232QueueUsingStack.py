class MyQueue(object):

    def __init__(self):
        self.s_in = []
        self.s_out = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.s_in.append(x)

    def pop(self):
        """
        :rtype: int
        """
        if len(self.s_out) == 0:
            self.move_s_in_to_s_out()

        return self.s_out.pop()

    def move_s_in_to_s_out(self):
        while len(self.s_in) > 0:
            self.s_out.append(self.s_in.pop())

    def peek(self):
        """
        :rtype: int
        """
        if len(self.s_out) == 0:
            self.move_s_in_to_s_out()
        return self.s_out[-1] if len(self.s_out) > 0 else None

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.s_in) == 0 and len(self.s_out) == 0



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()