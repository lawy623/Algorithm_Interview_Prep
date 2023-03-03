class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        wordSet = set(wordDict)
        n = len(s)
        dp = [[] for _ in range(n + 1)]
        dp[0].append('')
        for i in range(1, n + 1):
            for j in range(0, i):
                if s[j:i] in wordSet:
                    for k in dp[j]:
                        if k != '':
                            dp[i].append(k + ' ' + s[j:i])
                        else:
                            dp[i].append(s[j:i])

        return dp[-1]