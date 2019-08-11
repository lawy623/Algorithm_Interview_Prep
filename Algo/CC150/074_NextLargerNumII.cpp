// 1. Use set as tree.
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        set<int> tree;
        vector<int> res;
        set<int>::iterator iter;
        for(int i=n-1; i>=0; i--) {
            tree.insert(A[i]);
            iter = tree.upper_bound(A[i]);
            if (iter==tree.end())
                res.insert(res.begin(),-1);
            else
                res.insert(res.begin(),*iter);
        }
        return res;
    }
};
