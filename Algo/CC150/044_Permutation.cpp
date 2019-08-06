// 1. Recursion.
class Permutation {
public:
    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>());
        return res;
    }

    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);
            permutation(A, res, cur+1);
            swap(A[i], A[cur]);
        }
    }
};

// 2. Each time select
class Permutation {
public:

    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.length() == 0) {
            res.push_back("");
            return res;
        }
        for(int i=0; i<A.length(); i++) {
            string s = A.substr(i,1);
            string t = A;
            vector<string> r = getPermutation(t.erase(i, 1));
            for(int j=0; j<r.size(); j++) {
                res.push_back(s + r[j]);
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        return res;
    }
};
