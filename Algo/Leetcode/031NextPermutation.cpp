//1. O(N)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int pos = nums.size()-1;
        while(nums[pos-1]>= nums[pos] && pos!=0) pos--;
        if(pos==0) fullPermute(nums,pos,nums.size()-1);
        else if(pos==nums.size()-1) fullPermute(nums,pos-1,nums.size()-1);      
        else {
                int k=pos;
                for(;k<=nums.size();k++){
                    if(nums[k]<=nums[pos-1] || k==nums.size()){
                        swap(nums[k-1],nums[pos-1]);
                        break;
                    }
                }
            fullPermute(nums,pos,nums.size()-1);
        }
    }
    
    void fullPermute(vector<int>& nums, int l, int r){
        while(l<r){
            swap(nums[l++],nums[r--]);
        }
    }
};

// more clear O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;

        int l = nums.size() - 2;
        while(l>=0 && nums[l]>=nums[l+1]) l--;  // find the first n[l] < n[r] from right
        if(l>=0){   // l=0 means whole nums going up. Need to reverse all.
            int r = nums.size()-1;
            while(nums[r] <= nums[l]) r--;  // find the first n[r] that > n[l], it will at most goes to l+1
            swap(nums[l], nums[r]);
        }

        reverse(nums.begin() + l + 1, nums.end());
    }
};