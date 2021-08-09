//300. longest-increasing-subsequence.

//1.DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};


//2. DP with Binary Search.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<dp[0])
                dp[0] = nums[i];
            else if(nums[i]>dp[dp.size()-1])
                dp.push_back(nums[i]);
            else{
                int l=0, r=dp.size();
                while(l<r){
                    int m = l + (r-l)/2;
                    if(dp[m]>=nums[i]) r=m;
                    else l=m+1; //Skip all since left side are less than nums[i].
                }
                dp[l] = nums[i];  
            }
        }
        return dp.size();
    }   
};