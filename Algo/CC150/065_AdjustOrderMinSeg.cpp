// 1. Use two vecotrs to store the max's from left, and min's from right.
class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        vector<int> min_right;
        vector<int> max_left;
        max_left.push_back(A[0]);
        min_right.push_back(A[n-1]);
        for(int i=1; i<n ;i++)
            max_left.push_back( max(max_left[max_left.size()-1], A[i]) );
        for(int i=n-1; i>0; i--)
            min_right.push_back( min(min_right[min_right.size()-1], A[i]) );
        int l=0;
        int r=0;
        reverse(min_right.begin(),min_right.end());
        for(int i=0; i<n; i++){
            if (min_right[i]<A[i]){
                l=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if (max_left[i]>A[i]){
                r=i;
                break;
            }
        }
        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};

// 2. Use single values to store the result from two side, rather than using vectors.
class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        int max_left = A[0];
        int min_right = A[n-1];
        int l=0;
        int r=0;
        for(int i=1; i<n ;i++) {
            if (max_left>A[i]) {
                r=i;
            } else {
                max_left = A[i];
            }
        }
        for(int i=n-1; i>0; i--) {
            if (min_right<A[i]) {
                l=i;
            } else {
                min_right = A[i];
            }
        }

        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};
