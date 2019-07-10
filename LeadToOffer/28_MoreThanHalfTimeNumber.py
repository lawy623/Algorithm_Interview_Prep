class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        if len(numbers)==0:
            return 0
        half = int( len(numbers)/2 )
        res = self.findKSmallest(numbers, half)
        if self.checkMoreThanHalf(numbers, res):
            return res
        print(res, "not reach half")
        return 0

    def checkMoreThanHalf(self, numbers, res):
        count = 0
        for i in range(len(numbers)):
            if numbers[i] == res:
                count += 1
        if count > len(numbers)/2:
            return True
        return False

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
