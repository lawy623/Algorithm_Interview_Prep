// O(n) time, O(1) extra space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            nums[abs(nums[i]) - 1] = - abs(nums[abs(nums[i]) - 1]); // must set to negative

        vector<int> res;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] > 0) res.push_back(i+1);

        return res;
    }
};