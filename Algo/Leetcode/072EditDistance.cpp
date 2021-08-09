// O(mn) space and time
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n==0 && m==0) return 0;
        if(n==0 || m==0) return n==0?m:n;
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = min(dp[i-1][j-1] + (word1[i-1] != word2[j-1]), min(dp[i-1][j], dp[i][j-1]) + 1);
            }
        }
        return dp[n][m];
    }
};