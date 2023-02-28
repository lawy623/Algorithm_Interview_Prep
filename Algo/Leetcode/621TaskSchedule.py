class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        tmp = [0] * 26
        for t in tasks:
            tmp[self.ord(t)] += 1

        n_iden_task = 0
        max_task = 0
        for i in range(26):
            if tmp[i] > 0:
                n_iden_task += 1
                max_task = max(max_task, tmp[i])

        same_max = 0
        for i in range(26):
            if tmp[i] == max_task:
                same_max += 1

        res = (max_task - 1) * (n+1)        # exclude last row
        res += same_max     # add back last row

        return max(len(tasks), res)     # must consider n = 0

    def ord(self, c):
        return ord(c) - ord('A')