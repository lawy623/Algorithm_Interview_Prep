class ListNode:
    def __init__(self, x=0):
        self.val = x
        self.next = None


def buildList(n):
    i = 0
    f = ListNode()
    h = f
    while i < n:
        f.next = ListNode(i)
        i += 1
        f = f.next
    return h.next


class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        l = buildList(n)
        # get last node
        circle = l
        while circle.next:
            circle = circle.next
        start = circle
        # get loop
        circle.next = l
        while start.next != start:
            i = 1
            t = start
            while i < m:
                t = t.next
                i += 1
            t.next = t.next.next
            start = t

        return start.val


class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n <= 0 or m <= 0:
            return -1

        if m == 1:
            return n-1

        f_n_m = 0
        for i in range(2, n+1):
            f_n_m = (f_n_m + m) % i

        return f_n_m
