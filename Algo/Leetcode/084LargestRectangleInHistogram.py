class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        st = []
        n = len(heights)
        l = [-1] * n
        r = [n] * n

        for i, h in enumerate(heights):
            while len(st) > 0 and heights[st[-1]] > h:
                r[st[-1]] = i       # keep lower right side as cur
                st.pop()
            if len(st) > 0:
                l[i] = st[-1]      # keep lower left side as next top
            st.append(i)

        res = 0
        for i, h in enumerate(heights):
            res = max((r[i]-l[i]-1) * h, res)

        return res