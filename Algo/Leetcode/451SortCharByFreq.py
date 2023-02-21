class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = {}
        max_count = 0
        for n in s:
            d[n] = d.get(n, 0) + 1
            max_count = max(max_count, d[n])

        tmp = [""] * (max_count + 1)
        for k, v in d.items():
            tmp[v] = tmp[v] + k * v

        return ''.join(tmp[::-1])