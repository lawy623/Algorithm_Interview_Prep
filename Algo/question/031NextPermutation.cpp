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
