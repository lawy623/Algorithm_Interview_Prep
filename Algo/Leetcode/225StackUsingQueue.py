class MyStack(object):

    def __init__(self):
        self.q1 = []  # tmp
        self.q2 = []  # contain value

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.q1.append(x)
        self.move_q(self.q2, self.q1)
        self.move_q(self.q1, self.q2)

    def move_q(self, q1, q2):
        """Move all val from q1 to q2"""
        while len(q1) > 0:
            q2.append(q1.pop(0))

    def pop(self):
        """
        :rtype: int
        """
        if self.empty():
            return None

        return self.q2.pop(0)

    def top(self):
        """
        :rtype: int
        """
        if self.empty():
            return None

        return self.q2[0]

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.q2) == 0

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()