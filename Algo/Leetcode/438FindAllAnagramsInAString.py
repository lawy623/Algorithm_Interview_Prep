class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        n = len(s)
        m = len(p)
        if n < m:  # s < p always
            return res

        table = [0] * 26
        for i in range(m):  # init the table
            table[getOrd(p[i])] -= 1
            table[getOrd(s[i])] += 1
        diff = countDiff(table)
        if diff == 0:
            res.append(0)

        for i in range(m, n):  # check in longer p
            if table[getOrd(s[i - m])] == 0:
                diff += 1
            elif table[getOrd(s[i - m])] == 1:
                diff -= 1
            table[getOrd(s[i - m])] -= 1

            if table[getOrd(s[i])] == 0:
                diff += 1
            elif table[getOrd(s[i])] == -1:
                diff -= 1
            table[getOrd(s[i])] += 1

            if diff == 0:
                res.append(i - m + 1)

        return res


def countDiff(table):
    count = 0
    for n in table:
        if n != 0:
            count += 1

    return count


def getOrd(c):
    return ord(c) - ord('a')