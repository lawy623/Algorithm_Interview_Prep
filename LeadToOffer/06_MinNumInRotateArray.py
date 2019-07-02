## 1. Loop for whole. O(n)
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if len(rotateArray) == 0:
            return 0

        for i in range(len(rotateArray)):
            if rotateArray[i] > rotateArray[i+1]:
                return rotateArray[i+1]
        return rotateArray[-1]

## Binary search
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if len(rotateArray) == 0:
            return 0
        return self.minNum(rotateArray, 0, len(rotateArray)-1 )

    def minNum(self, array, start, end):
        if start == end:
            return array[start]
        if start == end - 1:
            return min(array[start], array[end])
        mid = int( (start+end) /2)
        if array[mid] > array[end]:
            return self.minNum(array, mid+1, end)
        elif array[mid] == array[start] and array[mid] == array[end]:
            return self.minNum(array, start+1, end-1)
        else:
            return self.minNum(array, start, mid)
