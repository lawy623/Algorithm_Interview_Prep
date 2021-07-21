class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m==0) return res;
        int n = matrix[0].size();
        if (n==0) return res;

        int start=0;
        while(start*2 < m && start*2 < n){
            printMatrixByStart(start, m, n, matrix, res);
            start++;
        }
        return res;
    }

    void printMatrixByStart(int start, int m, int n, vector<vector<int> > matrix, vector<int>& res){
        int end_row = m - start - 1;
        int end_col = n - start - 1;
        for(int i=start; i<=end_col; i++)
            res.push_back(matrix[start][i]);

        for(int i=start+1; i<=end_row; i++)
            res.push_back(matrix[i][end_col]);

        if (end_row > start){
            for(int i=end_col-1; i>=start; i--)
                res.push_back(matrix[end_row][i]);
        }

        if(end_col > start){
            for(int i=end_row-1; i>start; i--)
            res.push_back(matrix[i][start]);
        }
    }
};