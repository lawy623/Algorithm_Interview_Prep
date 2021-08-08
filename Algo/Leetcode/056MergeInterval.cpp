// Sort and two pointer
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i<intervals.size()){
            int last_end = intervals[i][1];
            int j = i;
            while(j<intervals.size() && intervals[j][0] <= last_end){
                last_end = max(last_end, intervals[j][1]);
                j++;
            }
            res.push_back(vector<int>{intervals[i][0], last_end});
            i = j;
        }
        return res;
    }
};