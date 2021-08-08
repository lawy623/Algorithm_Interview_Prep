// 从后往前dp。会超时O(nk)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return true;
        vector<bool> dp(n, false);
        dp[n-1] = true;
        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=nums[i]; j++){
                if(i+j<nums.size()) dp[i] = (dp[i] || dp[i+j]);
            }
        }
        return dp[0];
    }
};

// 从前往后dp，只要贪心记录当前最右能够到的位置即可
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return true;
        int r = 0;
        for(int i=0; i<n; i++){
            if(i<=r) r = max(r, i+nums[i]);
            if(r >= n-1) return true;
        }
        return false;
    }
};