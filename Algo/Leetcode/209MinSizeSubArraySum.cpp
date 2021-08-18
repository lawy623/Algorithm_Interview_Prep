// two pointer(sliding window)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; int r = 0;
        int sum = 0;
        int min_len = nums.size() + 1;
        while(r < nums.size()){
            sum += nums[r++];
            while(sum >= target){
                min_len = min(min_len, r-l);
                sum -= nums[l++];
            }
        }
        return min_len == nums.size() + 1? 0:min_len;
    }
};