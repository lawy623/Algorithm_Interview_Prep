// 1. Still need O(n) for worst case. But can skip a lot.
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        if (A.size()==0)
            return false;
        for(int i=0; i<n; i++){
            if (A[i]==i)
                return true;
            else if (A[i]>i)
                i = A[i];
        }
        return false;
    }
};
