//1.Need to consider that elements on the right is not strictly less than nums[l]. O(N)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return true;
            if(nums[l]<nums[mid]){
                if(target>=nums[l] && target<nums[mid]) r=mid-1;
                else l=mid+1;
            }else if(nums[l]>nums[mid]){
                if(target<nums[l] && target>nums[mid]) l=mid+1;
                else r=mid-1;
            }else{. //Now you can not insure mid's location(left?right?) based on the comparison with nums[l].
                l++;
            }
        }
        return false;
    }
};