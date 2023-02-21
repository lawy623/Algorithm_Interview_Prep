class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        d = {
            'I': 1,
            'IV': 4,
            'V': 5,
            'IX': 9,
            'X': 10,
            'XL': 40,
            'L': 50,
            'XC': 90,
            'C': 100,
            'CD': 400,
            'D': 500,
            'CM': 900,
            'M': 1000
        }
        d_l = sorted(list(d.values()))[::-1]  # 1000, 900, 500,...., 1
        _d = {}
        for k, v in d.items():
            _d[v] = k

        res = ""
        i = 0
        while num > 0:
            while num >= d_l[i]:
                res += str(_d[d_l[i]])
                num -= d_l[i]
            i += 1

        return res