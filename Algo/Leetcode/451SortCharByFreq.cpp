// O(n + k) space, O(n + klogk) time.
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(auto c:s) m[c]++;
        vector<pair<int, char>> c_list;
        for(auto it=m.begin(); it!=m.end(); it++){
            c_list.push_back(make_pair(it->second, it->first));
        }
        sort(c_list.begin(), c_list.end(), comp);
        string t = "";
        for(auto p:c_list){
            for(int i=0; i<p.first; i++) t+= p.second;
        }
        return t;
    }

    static bool comp(pair<int, char> a, pair<int, char> b){
        if(a.first >= b.first) return true;
        return false;
    }
};

// bucket sort. O(n + k) time and space
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        int max_count = 0;
        for(auto c:s){
            m[c]++;
            max_count = max(max_count, m[c]);
        };

        vector<string> buckets(max_count+1, "");
        for(auto it=m.begin(); it!=m.end(); it++){
            buckets[it->second] += it->first;
        }

        string t = "";
        for(int i=max_count; i>=0; i--){
            for(int k=0; k<buckets[i].length(); k++){
                for(int j=i; j>0; j--) t += buckets[i][k];
            }
        }

        return t;
    }

};