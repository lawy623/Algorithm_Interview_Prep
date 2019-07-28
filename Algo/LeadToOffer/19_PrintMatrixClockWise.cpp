// Little bit hard. Consider all the conditions.
class Solution {
public:
    void printMatrixInCircle(int start, int rows, int cols, vector<int> &res, vector<vector<int> > matrix) {
        int end_col = cols - 1 - start;
        int end_row = rows - 1 - start;

        for (int i=start; i<=end_col; i++) {
            res.push_back(matrix[start][i]);
        }

        for (int i=start+1; i<=end_row; i++) {
            res.push_back(matrix[i][end_col]);
        }

        if (end_row>start){
            for (int i=end_col-1; i>=start; i--) {
                res.push_back(matrix[end_row][i]);
            }
        }

        if (end_col>start) {
            for (int i= end_row-1; i>=start+1; i--) {
                res.push_back(matrix[i][start]);
            }
        }

        return;
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size()==0 || matrix[0].size()==0)
            return res;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;

        while (start*2 < rows && start*2 < cols) {
            printMatrixInCircle(start, rows, cols, res, matrix);
            start++;
        }
        return res;
    }
};
