//1. O(n^2) time, O(1) space.
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if (A.size()<=1)
            return res;
        int n = A.size();
        for (int i = 0; i < n; i++)
            res.push_back(1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j] *= A[ (j+i)%n ];
            }
        }
        return res;
    }
};


//2. Use two array to store the prod from left and from right. DP.
// O(n) space, O(n) time.
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if (A.size()<=1)
            return res;
        int n = A.size();
        vector<int> left;
        vector<int> right;
        left.push_back(1);
        right.push_back(1);
        for (int i = 0; i < n-1; i++) {
            left.push_back(left[i]*A[i]);
            right.push_back(right[i]*A[n-i-1]);
        }
        for (int i = 0; i < n; i++) {
                res.push_back(left[i]*right[n-i-1]);
        }
        return res;
    }
};
