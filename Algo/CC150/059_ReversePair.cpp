class AntiOrder {
public:
    int mergeCount(vector<int>& A, int start, int end) {
        if (start>=end)
            return 0;
        int mid = (start+end) / 2;
        int leftCount = mergeCount(A, start, mid);
        int rightCount = mergeCount(A, mid+1, end);
        vector<int> l;
        vector<int> r;
        for(int i=start; i<=mid; i++)
            l.push_back(A[i]);
        for(int i=mid+1; i<=end; i++)
            r.push_back(A[i]);
        int i=0, j=0, count=0;
        while(i<l.size() || j<r.size()){
            if (i==l.size()){
                A[start+i+j] = r[j];
                j++;
            } else if (j==r.size()) {
                A[start+i+j] = l[i];
                i++;
                count+=j;
            } else {
                if (l[i]<=r[j]) {
                    A[start+i+j] = l[i];
                    i++;
                    count += j;
                } else {
                    A[start+i+j] = r[j];
                    j++;
                }
            }
        }
        return leftCount+rightCount+count;
    }
    int count(vector<int> A, int n) {
        return mergeCount(A, 0, n-1);
    }
};
