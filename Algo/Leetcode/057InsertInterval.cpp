// 3 stage
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        int min_interval = newInterval[0];
        int max_interval = newInterval[1];
        while(i < n && intervals[i][0] <= newInterval[1]){ //如果相等 仍可合并
            min_interval = min(min_interval, intervals[i][0]);
            max_interval = max(max_interval, intervals[i][1]);
            i++;
        }
        res.push_back(vector<int>{min_interval, max_interval});

        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};