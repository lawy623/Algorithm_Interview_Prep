class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = str(num)
        n = len(s)
        dp = [1] * (n+1)
        dp[1] = 1
        if n == 1:
            return 1

        dp[2] = 1 if int(s[:2]) > 25 else 2
        for i in range(3, n+1):     # must consider 02 case
            dp[i] = dp[i-1] + dp[i-2] if 10 <= int(s[i-2:i]) <= 25 else dp[i-1]

        return dp[-1]