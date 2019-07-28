## a sorting. require O(nlogn) time.
class Solution:
    def PrintMinNumber(self, numbers):
        numbers = list(map(str, numbers))
        numbers.sort(cmp=lambda a,b: cmp(a+b, b+a))
        res = "".join(numbers)
        return res
