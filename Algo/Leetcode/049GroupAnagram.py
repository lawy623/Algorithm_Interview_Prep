class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for s in strs:
            s_sort = ''.join(sorted(s))     # sorted string is list
            if d.get(s_sort) is not None:
                d[s_sort].append(s)
            else:
                d[s_sort] = [s]

        res = []
        for v in d.values():
            res.append(v)

        return res