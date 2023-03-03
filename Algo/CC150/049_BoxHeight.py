class Solution(object):
    def pileBox(self, box):
        """
        :type box: List[List[int]]
        :rtype: int
        """
        n = len(box)
        bbox = sorted(box)
        max_len = bbox[0][2]

        dp = [bbox[i][2] for i in range(n)]
        for i in range(1, n):
            for j in range(i):
                if bbox[j][0] < bbox[i][0] and bbox[j][1] < bbox[i][1] and bbox[j][2] < bbox[i][2]:
                    dp[i] = max(dp[i], dp[j]+bbox[i][2])
                max_len = max(max_len, dp[i])

        return max_len