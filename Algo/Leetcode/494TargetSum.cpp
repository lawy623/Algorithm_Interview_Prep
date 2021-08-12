// dfs. O(2^n) time
class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        dfs(nums, 0, 0, target);
        return count;
    }

    void dfs(vector<int>& nums, int x, int sum, int target){
        if(x == nums.size()) {
            if(sum == target) count++;
            return;
        }

        dfs(nums, x+1, sum+nums[x], target);
        dfs(nums, x+1, sum-nums[x], target);
    }
};

// dp.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto c:nums) sum+=c;
        sum = sum+target;
        if(sum<0 || sum%2) return 0;
        sum /= 2;

        vector<int> dp(sum+1);
        dp[0] = 1;
        for(auto i:nums){
            for(int j=sum; j>=i; j--)
                dp[j] += dp[j-i];
        }
        return dp[sum];
    }
};