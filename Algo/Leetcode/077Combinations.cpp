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

// 2. bit cal
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for(int i=0; i<pow(2,n); i++){
            if(calSum(i) == k){
                vector<int> r;
                for(int j=0; j<20; j++){
                    if(i&(1<<j)) r.push_back(j+1);
                }
                res.push_back(r);
            }
        }
        return res;
    }

    int calSum(int n){
        int count = 0;
        for(int j=0; j<32; j++)
            if(n&(1<<j)) count++;
        return count;
    }
};