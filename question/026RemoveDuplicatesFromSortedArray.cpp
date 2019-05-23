//1. Move non-duplicates to the front. O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=1) return nums.size();
        
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index-1] != nums[i])
                nums[index++] = nums[i];
            }
        return index;
    }
};


//2. Since sorted. Use unique function. But not remove. Get the iter and calculate the distance.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto endPos = unique(nums.begin(),nums.end());  // Unique doese not remve the elements. But return a pointer. Need to erase if wanted.
        return endPos - nums.begin();
        //return distance(nums.begin(),endPos);
    }    
};