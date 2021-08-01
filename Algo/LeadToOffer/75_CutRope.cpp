// dp
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4) return n - 1;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for(int i=4; i<n+1; i++){
            dp[i] = 0;
            for(int k=1; k<=i / 2; k++){ // At least 1. At most k/2 since symmetric.
                dp[i] = max(dp[i], dp[k]*dp[i-k]);
            }
        }
        return dp[n];
    }
};