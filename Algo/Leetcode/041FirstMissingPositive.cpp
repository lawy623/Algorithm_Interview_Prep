//1 brute force
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(auto n:nums){
            if(n>0) s.insert(n);
        }

        int i = 1;
        while(true){
            if(s.find(i)==s.end()) return i;
            i++;
        }
        return -1;
    }
};

//2. Use nums as a hash table. Consider those negative value.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            if(nums[i] <= 0) nums[i] = n+1;

        for(int i=0; i<n; i++)
            if(abs(nums[i]) < n+1) nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);

        for(int i=0; i<n; i++)
            if(nums[i] > 0) return i+1;

        return n+1;
    }
};