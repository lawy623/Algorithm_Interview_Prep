class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<n+1; i++){
            dp[i] = 0;
            for(int k=1; k<i; k++){
                dp[i] = max(dp[i], max(k*(i-k), k*dp[i-k]));
            }
        }
        return dp[n];
    }
};