class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num >= 10:
            num = addSum(num)

        return num

def addSum(num):
    return sum([int(n) for n in str(num)])


# Most simple
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        return (num-1)%9 + 1 if num else 0