//1, Just ignore the new part if duplicated num get out again. 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
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
            int n_1 = nums[nums.size()-2];
            vector<int> subvector(nums.begin(),nums.end()-1);
            vector<int> subvector2(nums.begin(),nums.end()-2);   //Consume too much memory.
            vector<vector<int>> res  = subsetsWithDup(subvector);
            vector<vector<int>> res2  = subsetsWithDup(subvector2);
            int len = res.size();
            int i = (n==n_1)? res2.size() : 0;   //Get the newly generated part from n-1.
            for(;i<len;i++){
                vector<int> temp = res[i];
                temp.push_back(n);
                res.push_back(temp);    
            }
            return res;                      
        }
    }
};

//More concise version
class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            sort(S.begin(), S.end());   //Sort here is important.
            vector<vector<int> > result(1);  //Here now result is {[]}.
            size_t previous_size = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                const size_t size = result.size();
                for (size_t j = 0; j < size; ++j) {
                    if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
                        result.push_back(result[j]);
                        result.back().push_back(S[i]);
                    }
                }
                previous_size = size;  //Previous size is the size before expansion for S[i].
            }
        return result;
        }
};


//2. Use bit map. And a set to remove duplicates.v Actually it take O(n) space.
class Solution {
public:
    vector<vector<int>> res;
    vector<int> p;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int x){
        res.push_back(p);
        if(x==nums.size()){
            return;
        }

        for(int i=x; i<nums.size(); i++){
            if(i>x && nums[i]==nums[i-1])  // in case repetitive selection
                continue;
            p.push_back(nums[i]);
            dfs(nums, i+1);
            p.pop_back();
        }
    }
};