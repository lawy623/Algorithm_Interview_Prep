class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n_row = len(matrix)
        n_col = len(matrix[0])
        mat = []
        for i in range(n_row):
            r = []
            for j in range(n_col):
                r.append(int(matrix[i][j]))
            mat.append(r)

        heights = mat[0]

        res = self.largestRectangleArea(heights)
        for i in range(1, n_row):
            new_height = mat[i]
            heights = [heights[j] + new_height[j] if new_height[j] > 0 else 0 for j in range(n_col)]
            res = max(res, self.largestRectangleArea(heights))

        return res

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
                r[st[-1]] = i  # keep lower right side as cur
                st.pop()
            if len(st) > 0:
                l[i] = st[-1]  # keep lower left side as next top
            st.append(i)

        res = 0
        for i, h in enumerate(heights):
            res = max((r[i] - l[i] - 1) * h, res)

        return res