class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        n = len(a)
        l, r = [1], [1]
        for i in range(0, n-1):
            l.append(l[i] * a[i])
            r.append(r[i] * a[n-1-i])

        res = []
        for i in range(0, n):
            res.append(l[i] * r[n - 1 - i])

        return res


# O(1) space
class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        n = len(a)
        res = [1 for i in range(n)]
        for i in range(0, n-1):
            res[i+1] = res[i] * a[i]

        fac = 1
        for i in range(0, n):
            res[n-1-i] = res[n-1-i] * fac
            fac *= a[n-1-i]

        return res