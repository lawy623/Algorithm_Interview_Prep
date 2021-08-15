
//1. Easy Solution. Give O(mn) Time and O(m+n) Space.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        
        vector<bool> row(m,true), col(n,true);
        for(int i=0;i<m*n; i++){
            int r = i/n;
            int c = i%n;
            if(matrix[r][c]==0){row[r]=false;col[c]=false;}
        }
        for(int i=0;i<m*n; i++){
            int r = i/n;
            int c = i%n;
            if(row[r]==false || col[c]==false){matrix[r][c]=0;}
        }
    }
};


//2. Use the first row & first column to store the values. O(1) Space.
//The assumption here is when there is a 0 in the smaller matrix, corresponding place in first row & col will be 0. So you can modify it.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // consider first row and col
        bool row0 = false;
        bool col0 = false;
        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0) col0 = true;
        }
        for(int j=0; j<col; j++){
            if(matrix[0][j] == 0) row0 = true;
        }
        // consider all other rows and col
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // reset all other rows and cols
        for(int i=1; i<row; i++){
            if(matrix[i][0]==0){
                for(int j=1; j<col; j++) matrix[i][j] = 0;
            }
        }

        for(int j=1; j<col; j++){
            if(matrix[0][j] == 0){
                for(int i=1; i<row; i++) matrix[i][j] = 0;
            }
        }
        // reset first row and col
        if(row0){
            for(int j=0; j<col; j++) matrix[0][j] = 0;
        }

        if(col0){
            for(int i=0; i<row; i++) matrix[i][0] = 0;
        }

        return;
    }
};