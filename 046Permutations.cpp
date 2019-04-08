//1. Use recursion.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        if(nums.size()==1){
            res.push_back(nums);
            return res;
        }
        
        int d = nums[0];
        vector<int> lastV(nums.begin()+1,nums.end());
        res = permute(lastV);
        int len = res.size();
        for(int i=0;i<len;i++){
            for(int j=0;j<res[0].size()+1;j++){
                vector<int> v = res[0];
                v.insert(v.begin()+j,d);
                res.push_back(v);
            }
            res.erase(res.begin());
        }
        return res; 
    }
};

//2. DFS
class Solution {
public:
    vector<vector<int> > permute(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> path; 
        dfs(num, path, result);
        return result;
    }
private:
    void dfs(const vector<int>& num, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == num.size()) { 
            result.push_back(path);
            return;
        }

        for (auto i : num) {
            auto pos = find(path.begin(), path.end(), i);
            if (pos == path.end()) {
                path.push_back(i);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};