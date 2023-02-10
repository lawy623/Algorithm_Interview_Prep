class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = {}
        max_count = 0
        last_pos = -1
        for i, n in enumerate(s):
            if m.get(n) is not None:
                last_pos = max(m[n], last_pos)  # The last pos could be larger than m[n]
            m[n] = i
            max_count = max(max_count, i - last_pos)

        return max_count
