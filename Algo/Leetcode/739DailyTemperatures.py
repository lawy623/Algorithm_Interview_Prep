class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        d = {}
        for i, n in enumerate(temperatures):
            d[i] = i

        st = []
        for i, n in enumerate(temperatures):
            while len(st) > 0 and st[-1][1] < n:
                top = st.pop()
                d[top[0]] = i
            st.append((i, n))

        res = []
        for i, n in enumerate(temperatures):
            res.append(d[i] - i)

        return res