// dp. O(mn) space and time.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n==0 && m==0) return 0;
        if(n==0 || m==0) return n==0?m:n;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m+n - 2*dp[n][m];
    }
};