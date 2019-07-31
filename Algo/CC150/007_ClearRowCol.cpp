class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        if (n==0)
            return mat;
        vector<int> row;
        vector<int> col;
        for(int i=0; i<n; i++) {
            row.push_back(0);
            col.push_back(0);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                if (mat[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                if (row[i]==1 || col[j]==1)
                    mat[i][j]=0;
            }
        }
        return mat;
    }
};
