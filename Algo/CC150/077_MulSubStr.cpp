// 1. Use string find for each
class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        vector<bool> res;
        for(int i=0; i<n; i++) {
            if (s.find(p[i])!=-1)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
