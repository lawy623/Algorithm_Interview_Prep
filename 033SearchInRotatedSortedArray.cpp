//1. Binary search. Need to consider edge conditions. O(logN).
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        
        int l = 0, r = nums.size()-1;
        
        while(l<=r){
            int mid = (r+l)/2;
            if(nums[mid] == target) return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<nums[mid]) r=mid-1;
                else l=mid+1;
            }
            else{
                if(nums[l]>target && nums[mid]<target) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};