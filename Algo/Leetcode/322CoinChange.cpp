// dp. O(nk) time, O(n) space
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            for(auto c:coins){
                if(c<=i)
                    dp[i] = min(dp[i-c]+1, dp[i]);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};