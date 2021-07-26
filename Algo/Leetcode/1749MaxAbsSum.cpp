class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int f_max = nums[0];
        int f_min = nums[0];
        int res = abs(nums[0]);
        for(int i=1; i<nums.size(); i++){
            f_max = max(f_max+nums[i], nums[i]);
            f_min = min(f_min+nums[i], nums[i]);
            res = max(max(abs(f_max), abs(f_min)), res);
        }
        return res;
    }
};