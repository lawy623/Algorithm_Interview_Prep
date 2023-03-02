class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        st = []
        res = 0

        for i, h in enumerate(height):
            while len(st) > 0 and st[-1][1] < h:
                mid = st.pop()
                if len(st) > 0:
                    l_idx, l_h = st[-1][0], st[-1][1]
                    _h = min(l_h, h) - mid[1]
                    res += (i-l_idx-1) * _h         # all the level up

            st.append((i, h))

        return res

# do not use stack
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = [height[0]]
        for h in height[1:]:
            l.append(max(l[-1], h))
        r = [height[-1]]
        for h in height[:-1][::-1]:
            r.append(max(r[-1], h))
        r = r[::-1]

        res = 0
        for n in range(len(height)):
            res += (min(l[n], r[n]) - height[n])

        return res