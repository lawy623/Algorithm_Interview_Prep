// O(n) space and time
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        int sum = 0; int new_sum = 0;
        m[0] = 1;
        for(int i=0; i<n; i++){
            new_sum += nums[i];
            if(m.find(new_sum % k) != m.end())
                if(m[new_sum % k] > ((new_sum % k) == (sum % k))) return true;
            sum += nums[i];
            m[new_sum % k]++;
        }
        return false;
    }
};