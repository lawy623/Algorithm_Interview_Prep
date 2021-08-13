// O(n + k) space, O(n + klogk) time.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int n:nums) m[n]++;
        vector<pair<int, int>> res;
        for(auto it=m.begin(); it!=m.end(); it++)
            res.push_back(make_pair(it->second, it->first));
        sort(res.begin(), res.end(), comp);
        vector<int> t;
        for(int i=0; i<k; i++) t.push_back(res[i].second);
        return t;
    }

    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }
};


// bucket sort. O(n + k) time and space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int max_count = 0;
        for(int n:nums){
            m[n]++;
            max_count = max(max_count, m[n]);
        }

       vector<vector<int>> buckets(max_count+1);
        for(auto it=m.begin(); it!=m.end(); it++)
            buckets[it->second].push_back(it->first);

        vector<int> t;
        for(int i=max_count; i>=0; i--){
            for(int j=buckets[i].size()-1; j>=0; j--){
                t.push_back(buckets[i][j]);
                if(t.size()==k) return t;
            }
        }
        return t;
    }
};