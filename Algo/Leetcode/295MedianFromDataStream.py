from heapq import *


class MedianFinder:
    def __init__(self):
        self.max_h = []
        self.min_h = []
        heapify(self.max_h)
        heapify(self.min_h)

    def addNum(self, num):
        heappush(self.min_h, num)
        heappush(self.max_h, -heappop(self.min_h))
        if len(self.min_h) < len(self.max_h):
            heappush(self.min_h, -heappop(self.max_h))

    def findMedian(self):
        max_len = len(self.max_h)
        min_len = len(self.min_h)
        return self.min_h[0] * 1. if max_len != min_len else (-self.max_h[0] + self.min_h[0]) / 2.