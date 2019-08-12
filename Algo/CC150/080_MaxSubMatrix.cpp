// 1.brute force. O(n^3)
class SubMatrix {
    public:
    bool checkRec(vector<vector<int>>& mat, int x, int y, int len)
    {
        int digit = mat[x][y];
        for (int i = 0; i < len; ++i) if (mat[x + i][y] != digit || mat[x + i][y + len - 1] != digit) return false;
        for (int j = 0; j < len; ++j) if (mat[x][y + j] != digit || mat[x + len - 1][y + j] != digit) return false;
        return true;
    }
    int maxSubMatrix(vector<vector<int>> mat, int n)
    {
        int maxLen = 1;
        for (int i = 0; i < n - maxLen; ++i){
            for (int j = 0; j < n - maxLen; ++j){
                for (int k = maxLen + 1; max(i, j) + k - 1 < n; ++k)
                    if (checkRec(mat, i, j, k)) maxLen = max(maxLen, k);
            }
        }

        return maxLen;
    }
};


// 2. dp. Less than O(n^3)
class SubMatrix {
    public:
    int maxSubMatrix(vector<vector<int>> mat, int n) {
        int** left = new int*[n];
        int** up = new int*[n];
        for(int i=0;i<n;i++) {
            left[i] = new int[n];
            up[i] = new int[n];
        }
        left[0][0]=1;
        up[0][0]=1;
        for(int i=1;i<n;i++) {
            left[0][i] = (mat[0][i]==mat[0][i-1])?left[0][i-1]+1:1;
            left[i][0] = 1;
            up[i][0] = (mat[i][0]==mat[i-1][0])?up[i-1][0]+1:1;
            up[0][i] = 1;
        }
        int max_len = 1;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if (mat[i][j]!=mat[i-1][j] || mat[i][j]!=mat[i][j-1]) {
                    if (mat[i][j]!=mat[i-1][j] && mat[i][j]!=mat[i][j-1]) {
                        left[i][j] = 1;
                        up[i][j] = 1;
                    } else if (mat[i][j]!=mat[i-1][j]) {
                        left[i][j] = left[i][j-1]+1;
                        up[i][j] = 1;
                    } else {
                        left[i][j] = 1;
                        up[i][j] = up[i-1][j]+1;
                    }
                } else {
                    left[i][j] = left[i][j-1]+1;
                    up[i][j] = up[i-1][j]+1;
                    int min_len = min(left[i][j], up[i][j]);
                    for(int k=min_len; k>=max_len; k--) {
                        if(up[i][j-k+1]>=min_len && left[i-k+1][j]>=min_len)
                            max_len = k;
                    }
                }
            }
        }
        return max_len;
    }
};
