class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return;
        int p = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0) nums[p++] = nums[i];
        }
        for(int i=p; i<n; i++) nums[i] = 0;
        return;
    }
};