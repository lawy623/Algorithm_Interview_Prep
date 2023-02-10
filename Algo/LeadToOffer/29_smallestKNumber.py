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
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k == 0:
            return []
        l = 0
        r = len(arr) - 1
        pivot = partition(arr, l, r)
        while (pivot != k - 1):  # remember it is k + 1
            if pivot > k - 1:
                r = pivot - 1
            else:
                l = pivot + 1
            pivot = partition(arr, l, r)

        return arr[:k]


def partition(arr, start, end):
    if start >= end:
        return start

    pivot = arr[end]
    idx = start
    for i in range(start, end):
        if arr[i] <= pivot:
            swap(arr, i, idx)
            idx += 1
    swap(arr, idx, end)

    return idx


def swap(arr, l, r):
    tmp = arr[l]
    arr[l] = arr[r]
    arr[r] = tmp