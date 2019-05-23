//1. Sort first. Then consider duplicate. O(N^2). 104ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        if(nums.size()<=2) return v;
        
        sort(nums.begin(),nums.end());
        
        for (int i = 0; i < (nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated. This is important.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                        --k;
                    } else {
                        int sum = nums[i] + nums[j] + nums[k];
                        if (sum > 0) {  // Should decrease sum.
                            --k;
                        } else if (sum < 0) {  // Should increase sum.
                            ++j;
                        } else {
                            v.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;   //Dont forget this one!!!!
                        }
                    }
                }
            }
        }
        return v;
    }
};

//2.hard to compare same pair. Use map does not cover existing ones.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        if(nums.size()<=2) return v;
        
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int target = -nums[i];
                map<int,int> temp;
                for(int j=i+1; j<nums.size();j++){
                    int targ = target - nums[j];
                    temp.insert(pair<int,int>(nums[j],j));
                    map<int,int>::iterator iter = temp.find(targ);
                    if(iter!=temp.end()&&iter->second!=j){
                        vector<int> res = {nums[i],iter->first,nums[j]};
                        v.push_back(res);
                    }  
                }
            }    
        }
        v.sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        return v;
    }
};