class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = []
        n = len(s)
        dp = [0] * n
        for i, p in enumerate(s):
            if s[i] == '(':
                st.append((i, '('))
            else:
                if len(st) > 0 and st[-1][1] == '(':
                    m = st.pop()
                else:
                    st.append((i, ')'))

        while len(st) > 0:
            m = st.pop()
            dp[m[0]] = 1

        # find the longest 0 seq
        max_count = 0
        count = 0
        for m in dp:
            if m == 0:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 0

        return max_count

