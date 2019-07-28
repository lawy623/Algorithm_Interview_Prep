## DP. But O(1) space, O(n) time.
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        if (len(array)==0):
            return 0

        sum = 0
        res = -float('Inf')
        for i in array:
            if sum <= 0:
                sum = i
            else:
                sum += i

            if sum > res:
                res = sum
        return res
