## 1. using heap. O(1) space and O(n+klogn) time.
import heapq
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        if k<=0 or len(tinput)==0 or k>len(tinput):
            return []

        res = []
        heapq.heapify(tinput)
        while (k>0):
            res.append(heapq.heappop(tinput))
            k -= 1

        return res
## 2. find k-th smallest and loop.  Total O(n) time.
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        if k<=0 or len(tinput)==0 or k>len(tinput):
            return []

        res = []
        kth = self.findKSmallest(tinput, k)
        for x in tinput:
            if x < kth:
                res.append(x)
        while len(res)<k:
            res.append(kth)
        res.sort()
        return res

    def findKSmallest(self, numbers, k):
        left, right = 0, len(numbers)-1
        while True:
            idx = self.partition(numbers, left, right)
            if idx == k-1:
                return numbers[idx]
            elif idx > k-1:
                right = idx - 1
            else:
                left = idx + 1

    def partition(self, numbers, left, right):
        pivot = numbers[right]
        pos = left-1
        for i in range(left, right):
            if numbers[i] <= pivot:
                pos += 1
                numbers[pos], numbers[i] = numbers[i], numbers[pos]
        pos += 1
        numbers[pos], numbers[right] = numbers[right], numbers[pos]
        return pos
