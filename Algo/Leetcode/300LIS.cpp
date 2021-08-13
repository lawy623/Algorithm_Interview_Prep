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

// binary search on increasing array. Find the larger or equal num
while(l<r){
    m = (l+r)/2;            // right part all >= k, you only need to go to m as most from right
    if(nums[m] >= k) r=m;  // if find strictly larger than, make it >k
    else l=m+1;
}
return l;

// binary search on increasing array. Find the smaller or equal num
while(l<r){
    m = (l+r)/2;           // left part all <=k, you only need to go to m as most from left
    if(nums[m] <= k) l=m;  // if find strictly smaller than, make it >k
    else r=m-1;
}
return r;