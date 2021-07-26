class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_max = nums[0];
        int f_min = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            int f_max_tmp = f_max; int f_min_tmp = f_min;
            f_max = max(max(f_max_tmp*nums[i], f_min_tmp*nums[i]), nums[i]);
            f_min = min(min(f_max_tmp*nums[i], f_min_tmp*nums[i]), nums[i]);
            res = max(f_max, res);
        }
        return res;
    }
};