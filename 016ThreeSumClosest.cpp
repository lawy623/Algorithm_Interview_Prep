class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int sum1 = (nums[0]+nums[1]+nums[nums.size()-1]);
        if(sum1==target) return target;
        int minDis = abs(sum1-target);
        int ans = sum1;
        
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1, k=nums.size()-1;j<k;){
                    
                    if(j-1>i && nums[j]==nums[j-1]) j++;
                    else if(k+1<nums.size() && nums[k]==nums[k+1]) k--;
                    else{
                        int newSum = (nums[i]+nums[j]+nums[k]);
                        if( abs(newSum-target)<minDis ) {
                            minDis = abs(newSum-target);
                            ans = newSum;
                        }
                        
                        if(newSum<target) j++;
                        else if(newSum>target) k--;
                        else return target;
                    }
                }
            }
        }
        return ans;
    }
};