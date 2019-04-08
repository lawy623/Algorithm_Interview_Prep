
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
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        
        
        bool rowZero=true, colZero=true;
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0) rowZero=false;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) colZero=false;
        }
        
        for(int i=0;i<(m-1)*(n-1);i++){
            int r = i/(n-1);
            int c = i%(n-1);
            if(matrix[r+1][c+1]==0) {matrix[r+1][0]=0;matrix[0][c+1]=0;}
        }
        
        for(int i=0;i<(m-1)*(n-1);i++){
            int r = i/(n-1);
            int c = i%(n-1);
            if(matrix[r+1][0]==0 || matrix[0][c+1]==0) matrix[r+1][c+1]=0;
        }
        
        if(rowZero==false){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(colZero==false){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};