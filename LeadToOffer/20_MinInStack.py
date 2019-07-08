## min array always keep the min up to now.
class Solution:
    def __init__(self):
        self.vals = []
        self.mins = []

    def push(self, node):
        self.vals.append(node)
        if len(self.mins)==0 or node<self.mins[-1]:
            self.mins.append(node)
        else:
            self.mins.append(self.mins[-1])

    def pop(self):
        self.vals.pop()
        self.mins.pop()

    def top(self):
        return self.vals[-1]

    def min(self):
        return self.mins[-1]
