//1. Binary search. Need to consider edge conditions. O(logN).
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0; int r = nums.size()-1;

        while(l <= r){
            int mid = (l+r) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[l]){ //consider edge
                if(nums[mid] > target && target >= nums[l]) r = mid-1; //consider edge
                else l = mid+1;
            } else{
                if(nums[mid] < target && target <= nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};