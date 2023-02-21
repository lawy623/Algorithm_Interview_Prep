class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        max_len = 0
        idx = 0
        for i in range(n):
            max_len1, idx1 = check(s, i, i, n)
            max_len2, idx2 = check(s, i, i + 1, n)

            if max_len1 > max_len2:
                if max_len1 > max_len:
                    max_len = max_len1
                    idx = idx1
            else:
                if max_len2 > max_len:
                    max_len = max_len2
                    idx = idx2

        return s[idx:idx + max_len]


def check(s, i, j, n):
    while i >= 0 and j < n:
        if s[i] == s[j]:
            i -= 1
            j += 1
        else:
            break

    max_len = j - i - 1
    idx = i + 1

    return max_len, idx