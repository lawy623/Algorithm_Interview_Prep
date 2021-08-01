// O(mn + nlogn) for simple loop and sort
// O(nlogm + n) for binary search and quick selection.
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int> > fight;
        for(int i=0; i<mat.size(); i++){
            int num_sol = calSol(mat[i]);
            fight.push_back(make_pair(num_sol, i));
        }
        sort(fight.begin(), fight.end());  //quick sort can be O(nlogn). Or O(n) for quickSearch

        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(fight[i].second);
        }
        return res;

    }

    int calSol(vector<int> mat){ //binary can save O(m) to O(logm)
        int count = 0;
        for(auto c : mat) count += (c == 1);
        return count;
    }

};