class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        return self.check(s2, s1)

    def check(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        n = len(s)
        m = len(p)
        if n < m:  # s < p always
            return False

        table = [0] * 26
        for i in range(m):  # init the table
            table[getOrd(p[i])] -= 1
            table[getOrd(s[i])] += 1
        diff = countDiff(table)
        if diff == 0:
            return True

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
                return True

        return False


def countDiff(table):
    count = 0
    for n in table:
        if n != 0:
            count += 1

    return count

def getOrd(c):
    return ord(c) - ord('a')