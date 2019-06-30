//1. search in acsending matrix
//First try to start from left top but not work.
//For right top is then ok

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
