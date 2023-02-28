class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height) - 1

        max_v = 0
        while l < r:
            v = min(height[l], height[r]) * (r-l)
            max_v = max(max_v, v)
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1

        return max_v