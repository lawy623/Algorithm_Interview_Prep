// Sort and two pointer
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n  = intervals.size();
        vector<vector<int>> res;
        int i = 0; int j = 0;
        while(i<n){
            j = i+1;
            int newBegin = intervals[i][0];
            int newEnd = intervals[i][1];
            while(j < n && intervals[j][0] <= newEnd){
                newEnd = max(newEnd, intervals[j][1]);
                j++;
            }
            res.push_back({newBegin, newEnd});
            i = j;
        }
        return res;
    }
};