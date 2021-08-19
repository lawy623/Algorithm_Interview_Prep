// Loop
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target) pos++;
            else if(nums[i]==target) return i;
        }
        return pos;
    }
};

// binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        int l = 0; int r = n-1;
        while(l<=r){
            int m = l + (r-l)/2; // in case overflow
            if(nums[m] == target) return m;
            else if(nums[m] > target) r = m-1;
            else l = m+1;
        }
        return l;
    }
};

// another writing
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        int l = 0; int r = n;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m] >= target) r = m;
            else l = m+1;
        }
        return l;
    }
};