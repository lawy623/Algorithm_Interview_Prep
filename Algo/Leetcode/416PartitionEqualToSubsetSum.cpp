// dp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto c:nums) sum+=c;
        if(sum%2) return false;
        sum /= 2;

        int n = nums.size();
        vector<bool> dp(sum+1);
        dp[0] = true;
        for(auto i:nums){
            for(int j=sum; j>=i; j--)
                dp[j] = dp[j] || dp[j-i];
        }
        return dp[sum];
    }
};