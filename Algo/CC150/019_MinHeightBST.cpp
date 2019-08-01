// 1. Return log2N.
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int size = vals.size();
        int h = 0;
        while(size) {
            h++;
            size /= 2;
        }
        return h;
    }
};

// 2. Build it recursively.
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals, int start, int end) {
        if (start>end)
            return 0;
        if (start==end)
            return 1;
        int mid = (end-start) / 2 + start;
        int left_h = buildMinimalBST(vals, start, mid-1);
        int right_h = buildMinimalBST(vals, mid+1, end);
        return max(left_h, right_h) + 1;
    }

    int buildMinimalBST(vector<int> vals) {
        if (vals.size()==0)
            return 0;
        return buildMinimalBST(vals, 0, vals.size()-1);
    }
};
