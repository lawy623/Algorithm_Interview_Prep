class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target) pos++;
            else if(nums[i]==target) return i;
        }
        return pos;
    }
};