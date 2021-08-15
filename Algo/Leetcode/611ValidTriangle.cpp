// SORT + double pointer
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int k = i+2;
            for(int j=i+1; j<n; j++){
                while(k < n && nums[k] < nums[i]+nums[j]){
                    k++;
                }
                count += max(k-j+1, 0);
            }
        }
        return count;
    }
};