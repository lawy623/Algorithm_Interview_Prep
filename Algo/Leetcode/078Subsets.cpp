//1. Recurrsion. O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) {
            res.push_back({});
            return res;
        }
        else if(nums.size()==1){
            res.push_back({});
            res.push_back({nums[0]});
            return res;
        }
        else{
            int n = nums[nums.size()-1];
            vector<int> subvector(nums.begin(),nums.end()-1);
            vector<vector<int>> res  = subsets(subvector);
            int len = res.size();
            for(int i=0;i<len;i++){
                vector<int> temp = res[i];
                temp.push_back(n);
                res.push_back(temp);    
            }
            return res;                      
        }
    }
};

//More concise version.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        
        for(int i=0; i < nums.size();i++){
            int size = res.size();
            for(int j=0; j<size;j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

//2. Use a bit map; O(1) Space. For this n<32.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> v;
        
        for(int i =0; i < 1<<n; i++){ // i < 2^n. All bit combination.
            for(int j=0; j <n; j++){
                if(i & 1<<j) v.push_back(nums[j]);  //If i's j-th bit is 1. Insert the j-th number.
            }
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};

// dfs
class Solution {
public:
    vector<vector<int>> res;
    vector<int> r;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int cur){
        if(cur == nums.size()){
            res.push_back(r);
            return;
        }

        r.push_back(nums[cur]);
        dfs(nums, cur+1);
        r.pop_back();
        dfs(nums, cur+1);
    }
};