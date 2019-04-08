//1. Two pointer. Move to center. O(N)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int i = 0;
        while(i<=r){
            if(nums[i]==0){swap(nums[l++],nums[i++]);}. //Should notice here. Otherwise deadlck.
            else if(nums[i]==2){swap(nums[r--],nums[i]);}
            else i++;
        }
    }
};


//2. Sort 0 to left first. Then sort 1 to left in the remaining array.
class Solution {
public:
    void sortColors(vector<int>& nums){
        int m = sortC(nums,0,0);
        m = sortC(nums,1,m);
    }
    
    int sortC(vector<int>& nums, int k, int start){
        int l=start;
        for(int i=start;i<nums.size();i++){
            if(nums[i]==k) swap(nums[l++],nums[i]);
        }
        return l;
    }
};