//1. Use a last index to track the end. O(N)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        
        int last = nums.size()-1;
        
        while(nums[last]==val) last--;   //Important to check at the beginning.
        for(int i=0; i<=last;i++ ){
            if(nums[i]==val){
                int temp = nums[last];
                nums[last] = nums[i];
                nums[i] = temp;
            }
            while(nums[last]==val) last--;   //Important to check here as well.
        }
        return last+1;
    }
};

//More easy version. Move the not equal ones to the front. Keep the last index.
class Solution {
    public:
        int removeElement(vector<int>& nums, int target) {
            int index = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != target) {
                    nums[index++] = nums[i];
                }
            }
        return index;
        }
};

//2.Use vector remove function.
class Solution {
    public:
        int removeElement(vector<int>& nums, int target) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
    }
};