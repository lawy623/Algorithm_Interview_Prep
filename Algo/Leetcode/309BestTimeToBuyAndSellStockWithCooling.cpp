class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;

        vector<vector<int>> dp(n, vector<int>(2)); // 0 has stock today; 1 not has stock
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(dp[0][0], dp[0][1] - prices[1]); // from yesterday; or buy it today
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]); // from yesterday; or sell it today
        for(int i=2; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-2][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }
        return dp[n-1][1];
    }
};