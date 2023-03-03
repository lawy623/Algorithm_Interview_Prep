class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wordSet = set(wordDict)
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1, n+1):
            for j in range(0, i):
                if s[j:i] in wordSet:
                    dp[i] = dp[i] or dp[j]  # either is fine

        return dp[-1]