//1. 递增二维数组中查找
//一开始使用左上角开始，并不work
//从右上角开始则可
class Solution:
    def Find(self, target, array):
        n = len(array)
        if n == 0 or len(array[0]) == 0:
            return False
        i, j = 0, n-1
        while i < n and j >= 0:
            if array[i][j] == target:
                return True
            elif array[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
