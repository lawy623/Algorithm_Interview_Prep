//1. Double screen
class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> nums(n,0);
        for(int i=1; i<n;i++){
            if(ratings[i]>ratings[i-1]) nums[i]=nums[i-1]+1; //Make this work if right>left
        }
        for(int i =n-1;i>0;i--){
            if(ratings[i-1]>ratings[i] && nums[i-1]<nums[i]+1 )nums[i-1] = nums[i]+1;  //Make left>right works. But also keep right>left works.
        }
        
        return accumulate(nums.begin(),nums.end(),n);  //Can use accumulate to get sum.
        
    }
};