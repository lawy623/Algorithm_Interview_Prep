// 1. Binary search
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int start, int end) {
        if (start>end)
            return false;
        if (start==end)
            return A[start]==start;
        int mid = (start + end) / 2;
        if (A[mid] == mid)
            return true;
        else if (A[mid] > mid)
            return findMagicIndex(A, start, mid-1);
        else
            return findMagicIndex(A, mid+1, end);
    }
    bool findMagicIndex(vector<int> A, int n) {
        if (A.size()==0)
            return false;
        return findMagicIndex(A, 0, A.size()-1);
    }
};
