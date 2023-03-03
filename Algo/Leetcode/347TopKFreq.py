class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        max_count = 0
        d = {}
        for n in nums:
            d[n] = d.get(n, 0)+1
            max_count = max(max_count, d[n])

        vec = [[] for _ in range(max_count+1)]
        for x, v in d.items():
            vec[v].append(x)

        res = []
        n_val = k
        j = max_count
        while k > 0:
            for v in vec[j]:
                res.append(v)
                k -= 1
            j -= 1

        return res[:n_val]