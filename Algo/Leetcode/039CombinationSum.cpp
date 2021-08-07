class Solution {
public:
    vector<vector<int>> res;
    vector<int> r;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return res;
        dfs(candidates, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int sum, int start){
        if(sum == target){
            res.push_back(r);
            return;
        }

        if(sum > target){  // need this to stop the search. Since all candidates are positive.
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            r.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, sum, i); //repeatable
            r.pop_back();
            sum -= candidates[i];
        }
    }
};