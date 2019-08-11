class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        int row = 0;
        int col = m-1;
        vector<int> pos;
        while(row<n && col>=0) {
            if (mat[row][col]==x){
                pos.push_back(row);
                pos.push_back(col);
                return pos;
            } else if (mat[row][col]<x)
                row++;
            else
                col--;
        }
        return pos;
    }
};
