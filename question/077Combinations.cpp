//1. DFS. O(N!)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        
        dfs(n,k,1,0,path,res);
        return res;
    }
    
    void dfs(int n, int k, int start, int cur, vector<int>& path, vector<vector<int>>& res){
        if(cur == k) res.push_back(path);
        for(int i=start;i<=n;i++){
            path.push_back(i);
            dfs(n,k,i+1,cur+1,path,res);
            path.pop_back();
        }
    }
};