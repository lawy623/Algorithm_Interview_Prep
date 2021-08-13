class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int close_sum = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1, k=n-1; j<k;){
                if(j>i+1 && nums[j] == nums[j-1]) j++;
                else if(k<n-1 && nums[k] == nums[k+1]) k--;
                else{
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum-target) < min_diff){
                        min_diff = abs(sum-target);
                        close_sum = sum;
                    }
                    if(sum==target) return target;
                    if(sum<target) j++;
                    else k--;
                }
            }
        }
        return close_sum;
    }
};