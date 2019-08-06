// 1. Using Bit. O(n) time.
class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        int cell = pow(2, n);
        vector<vector<int> > res;
        for(int i=cell-1; i>0; i--){
            vector<int> set;
            for(int j=31; j>=0; j--){
                if ( i & (1<<j) )
                    set.push_back(A[j]);
            }
            res.push_back(set);
        }
        return res;
    }
};
