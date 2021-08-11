// dp O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1)); // consider 1~n-1 and 2~n, get the max
    }

    int rob(vector<int>& nums, int start, int end){
        if(end<start) return 0;
        if(start==end) return nums[start];
        if(start == end-1) return max(nums[start], nums[end]);

        vector<int> dp(end+1);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[end];
    }
};