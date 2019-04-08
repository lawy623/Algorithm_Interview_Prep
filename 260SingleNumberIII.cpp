//Get A XOR B. Use the different bit. Do XOR in two groups.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int flag = 0;
        for(int i =0;i<nums.size();i++){
            flag ^= nums[i];
        }
        int tmp = 1;
        int n=0;
        while( !(flag & 1) ){
            flag >>= 1;
            n += 1;
        }

        int t1 = 0, t2 = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>>n & 1) t1 ^= nums[i];
            else t2 ^= nums[i];
        }
 
        vector<int> ans = {t1,t2};
        return ans;
    }
};