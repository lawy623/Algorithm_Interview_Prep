// O(n) time, O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            while(nums[i]-1 != i){
                if(nums[i] == nums[nums[i]-1]) return nums[i];
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        return -1;
    }
};