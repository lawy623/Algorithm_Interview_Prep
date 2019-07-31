// 1. Directly copy using 2 for loops. O(n^2) time. O(n^2) space
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        vector<vector<int> > res;
        if (n==0)
            return res;
        for(int i=0; i<n; i++) {
            vector<int> col;
            for(int j=n-1; j>=0; j--) {
                col.push_back(mat[j][i]);
            }
            res.push_back(col);
        }
        return res;
    }
};

// 2. Inplace replace. First swap diagonally, then swap y-axis.
class Transform {
public:
    void swap(vector<vector<int> > &mat, int i1, int j1, int i2, int j2) {
        int temp = mat[i1][j1];
        mat[i1][j1] = mat[i2][j2];
        mat[i2][j2] = temp;
        return;
    }
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        if (n==0)
            return mat;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                swap(mat, i, j, n-1-j, n-1-i);
            }
        }
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<n; j++) {
                swap(mat, i, j, n-1-i, j);
            }
        }
        return mat;
    }
};
