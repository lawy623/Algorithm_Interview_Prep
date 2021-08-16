// advanced moore
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0; int val1 = 0;
        int count2 = 0; int val2 = 0;
        for(auto n:nums){
            if(count1 > 0 && val1 == n) count1++;
            else if(count2 > 0 && val2 == n) count2++;
            else if(count1==0) {val1 = n; count1=1;}
            else if(count2==0) {val2 = n; count2=1;}
            else{count1--; count2--;}
        }

        count1 = 0;
        count2 = 0;
        for(auto n:nums){
            if(n==val1) count1++;
            if(n==val2) count2++;
        }

        vector<int> res;
        if(count1>nums.size()/3) res.push_back(val1);
        if(count2>nums.size()/3 && val1!=val2) res.push_back(val2);
        return res;
    }
};