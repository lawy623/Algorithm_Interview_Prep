//Method 1: Sort and use a single pointer. O(nlogn) time.
// But not correct. You can not modify the origin arrat.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l=0;
        while(l<nums.size()){
            if(nums[l]==nums[l+1])
                return nums[l];
            else l++;
        }
        return 0;
    }
};
