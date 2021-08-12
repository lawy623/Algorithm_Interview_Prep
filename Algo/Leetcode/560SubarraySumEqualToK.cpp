// O(n^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j>=0; j--){
                sum += nums[j];
                if(sum == k)
                    count ++;
            }
        }
        return count;
    }
};

// O(n). Use a dict to store the sum from before array
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        int n = nums.size();
        map<int, int> m;
        int sum = 0;
        m[sum] = 1;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(m.find(sum - k) != m.end()) count += m[sum-k];
            m[sum] ++;
        }

        return count;
    }
};