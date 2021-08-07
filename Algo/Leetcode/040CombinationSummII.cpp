// dfs
class Solution {
public:
    vector<vector<int>> res;
    vector<int> r;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return res;
        sort(candidates.begin(), candidates.end());  //sort first
        dfs(candidates, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int sum, int start){
        if(sum == target){
            res.push_back(r);
            return;
        }

        if(sum > target){
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1])  // in case repetitive selection
                continue;
            r.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, sum, i+1);
            r.pop_back();
            sum -= candidates[i];
        }
    }
};