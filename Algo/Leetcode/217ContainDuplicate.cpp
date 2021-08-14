// O(n) space and time
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto n:nums){
            if(s.find(n)!=s.end()) return true;
            s.insert(n);
        }
        return false;
    }
};