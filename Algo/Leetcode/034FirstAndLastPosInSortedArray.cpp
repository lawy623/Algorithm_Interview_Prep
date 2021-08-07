class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return vector<int>{-1, -1};

        int mid = findMid(nums, target);
        if(mid != -1){
            int l = mid;
            int r = mid;
            while(l>=0 && nums[l] == target) l--;
            while(r<nums.size() && nums[r] == target) r++;
            return vector<int>{l+1, r-1};
        }
        return vector<int>{-1, -1};

    }

    int findMid(vector<int>& nums, int target){
        int l = 0; int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};