class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m;
        for(char c:p) m[c]++;

        int l=0; int r=0;
        vector<int> res;
        while(r<s.length()){
            char c = s[r++];
            m[c]--;
            while(l<r && m[c]<0) m[s[l++]]++;
            if(r-l==p.size()) res.push_back(l);
        }
        return res;
    }
};