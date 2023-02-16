class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(intervals)
        if n == 1:
            return intervals

        res = []
        intervals = sorted(intervals)   # sort by start
        i, j = 0, 0
        while i < n:
            j = i + 1
            start_t = intervals[i][0]
            end_t = intervals[i][1]
            while j < n and intervals[j][0] <= end_t:
                end_t = max(intervals[j][1], end_t)     # in case the former one ends later
                j += 1
            res.append([start_t, end_t])
            i = j

        return res