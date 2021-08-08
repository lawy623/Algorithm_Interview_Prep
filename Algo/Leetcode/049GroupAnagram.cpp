// Use a dict with key-vec(string)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()==0) return res;
        map<string, vector<string>> m;
        for(auto s:strs){
            string k(s.begin(), s.end());
            sort(k.begin(), k.end());
            if(m.find(k) == m.end()) m[k] = vector<string>{s};
            else m[k].push_back(s);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};