// dp. O(mn) space and time.
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n==0 || m==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};