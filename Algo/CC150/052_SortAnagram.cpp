class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        sort(str.begin(), str.end());
        map<string,int> unique_str;
        vector<string> res;
        for(int i=0; i<n; i++) {
            string s(str[i]);
            sort(s.begin(), s.end());
            if (unique_str.find(s)==unique_str.end()){
                unique_str[s] = 1;
                res.push_back(str[i]);
            }
        }
        return res;
    }
};
