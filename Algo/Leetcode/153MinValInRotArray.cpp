// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = (start+end)/2;
            if(nums[mid] < nums[end]) end = mid;
            else start = mid+1;
        }
        return nums[start];
    }
};