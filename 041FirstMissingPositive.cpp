//1. Use hashtable. O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) s.insert(nums[i]);
        }
        
        int minV = INT_MAX;
        int lower = INT_MAX;
        for(int k : s){
            if(s.count(k+1)==0) minV = k+1<minV? k+1:minV;
            lower = k<lower? k:lower;
        }
        return lower>1? 1:minV;
    }
};