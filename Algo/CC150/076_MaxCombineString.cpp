class LongestString {
public:
    static bool cmp(string a, string b) {
        return a.length()>b.length();
    }
    bool validCombine(string s, vector<string> str, map<string, bool> m) {
        int n = s.length();
        if (m.find(s)!=m.end())
            return true;
        bool found = false;
        for(int i=1; i<n; i++) {
            string first = s.substr(0,i);
            string second = s.substr(i);
            if (m.find(first)!=m.end())
                found = validCombine(second,str,m);
            if (found) return true;
            if (m.find(second)!=m.end())
                found = validCombine(first,str,m);
            if (found) return true;
        }
        return false;
    }
    int getLongest(vector<string> str, int n) {
        // write code here
        sort(str.begin(), str.end(), cmp);
        map<string, bool> m;
        for(int i=0; i<n; i++) {
            m.clear();
            for(int j=i+1; j<=n-1; j++) {
                if (m.find(str[j])==m.end())
                    m[str[j]]=true;
            }
            if (validCombine(str[i], str, m))
                return str[i].length();
        }
        return 0;
    }
};
