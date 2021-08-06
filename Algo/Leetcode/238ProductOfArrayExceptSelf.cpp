// O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0) return res;

        for(int i=0; i<n; i++) res.push_back(1);

        for(int i=1; i<n; i++)
            res[i] = res[i-1]*nums[i-1];

        int r = 1;
        for(int i=n-1; i>=0; i--){
            res[i] = res[i]*r;
            r *= nums[i];
        }
        return res;
    }
};

// O(n) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0) return res;

        vector<int> l(n);
        vector<int> r(n);
        l[0] = 1; r[n-1] = 1;

        for(int i=1; i<n; i++){
            l[i] = l[i-1] * nums[i-1];
            r[n-i-1] = r[n-i] * nums[n-i];
        }

        for(int i=0; i<n; i++)
            res.push_back(l[i] * r[i]);

        return res;
    }
};