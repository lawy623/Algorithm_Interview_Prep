//1. Similar as get unique. Can be extent to nth.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) return nums.size();
        
        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[index-2] != nums[i])
                nums[index++] = nums[i];
            }
        return index;
    }
};


// Common Template fro n.
class Solution {
public:
    int removeDuplicates(vector<int>& nums, int dup) { //dup is not.
        if (nums.size()<=dup) return nums.size();
        
        int index = dup;   //Use index to keep the current valid length.
        for (int i = dup; i < nums.size(); i++) {
            if (nums[index-dup] != nums[i]) //If still == to index-2(ir. same char len>dup, run i++)
                nums[index++] = nums[i];
            }
        return index;
    }
};