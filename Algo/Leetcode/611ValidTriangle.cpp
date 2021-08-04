// SORT + double pointer
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int k = i;
            for(int j=i+1; j<n; j++){ // incase the j is already too large. k starts from i, we don't count k.
                while(k < n-1 && nums[k+1] < nums[i]+nums[j]){
                    k++;
                }
                count += max(k-j, 0);
            }
        }
        return count;
    }
};