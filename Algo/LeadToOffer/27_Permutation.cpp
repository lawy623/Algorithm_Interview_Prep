class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.length()==0)
            return res;
        string s = "";
        s += str[0];
        res.push_back(s);
        if (str.length()==1)
            return res;

        int length = 0;
        string temp, temp2 = "";
        for (int i=1; i<str.length(); i++) {
            string new_val = "";
            new_val += str[i];
            length = res.size();
            for (int j=0; j<length; j++) {
                for (int k=res[0].length(); k>=0; k--) {
                    temp = res[0];
                    temp2 = temp.insert(k, new_val);
                    res.push_back(temp2);
                }
                res.erase(res.begin());
            }
        }

        unordered_map<string, int> res_dict;
        vector<string> res_;
        for (auto x : res) {
            if (res_dict.find(x)==res_dict.end()) {
                res_dict[x] = 1;
                res_.push_back(x);
            }
        }
        sort(res_.begin(), res_.end());
        return res_;
    }
};


// dfs
class Solution {
public:
    vector<string> res;

    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int x){
        if(x == s.length()-1)
            res.push_back(s);

        set<int> st;
        for(int i=x; i<s.length(); i++){
            if(st.find(s[i]) != st.end()) continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x+1);
            swap(s[i], s[x]);
        }
    }
};