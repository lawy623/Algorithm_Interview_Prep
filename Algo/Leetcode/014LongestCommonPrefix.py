class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        n = len(strs)
        i = 0
        con = True
        while con:
            if i >= len(strs[0]):
                con = False
                i += 1
                break

            t = strs[0][i]
            for k in range(1, n):
                if i >= len(strs[k]) or strs[k][i] != t:
                    con = False
                    break
            i += 1

        return strs[0][:max(0, i-1)] 