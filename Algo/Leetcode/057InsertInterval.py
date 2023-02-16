class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        n = len(intervals)
        res = []
        if n == 0:
            return [newInterval]

        i = 0
        while i < n and intervals[i][1] < newInterval[0]:  # strictly larger
            res.append(intervals[i])
            i += 1

        start_t = newInterval[0]
        end_t = newInterval[1]
        while i <= n - 1 and intervals[i][0] <= newInterval[1]:  # consider the middle ones
            start_t = min(intervals[i][0], start_t)
            end_t = max(intervals[i][1], end_t)
            i += 1

        res.append([start_t, end_t])

        while i < n:
            res.append(intervals[i])
            i += 1

        return res
