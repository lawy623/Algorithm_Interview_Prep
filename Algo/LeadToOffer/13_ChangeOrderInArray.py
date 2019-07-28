## method1. O(n) time. O(n) space
class Solution:
    def reOrderArray(self, array):
        if len(array) == 0:
            return array
        new_Array = []
        for x in array:
            if x & 1 == 1:
                new_Array.append(x)
        for x in array:
            if x & 1 == 0:
                new_Array.append(x)
        return new_Array

## method2. O(n^2) time. O(1) Space.
class Solution:
    def reOrderArray(self, array):
        if len(array) == 0:
            return array
        for i in range(len(array)-1):
            for j in range(len(array)-1):
                if array[j]&1==0 and array[j+1]&1==1:
                    array[j],array[j+1] = array[j+1],array[j]
        return array
