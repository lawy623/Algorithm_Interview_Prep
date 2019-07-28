//1. Use a hashmap to store the values. Calculate sum*2 - original sum. O(N) time. O(N) space.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map.insert(make_pair(nums[i],i));
        }
        int sum = 0;
        for(auto i = map.begin();i !=map.end();i++) sum+= i->first;
        return 2*sum - accumulate(nums.begin(),nums.end(),0);
    }
};
//Or use set.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int sum = 0;
        for(auto i = set.begin();i !=set.end();i++) sum+= *i;
        return 2*sum - accumulate(nums.begin(),nums.end(),0);
    }
};

// Use XOR. Know that a^a=0. So can find the only odd num case. O(1) Space.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }
        
        return x;
    }
};