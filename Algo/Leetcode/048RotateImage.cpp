// Flip over r(t)-l(b) cross. Then flip over midder cross.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<n-j-1){
                    int temp = matrix[n-j-1][n-i-1];
                    matrix[n-j-1][n-i-1] = matrix[i][j];
                    matrix[i][j] = temp;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i<n/2){
                    int temp = matrix[n-i-1][j];
                    matrix[n-i-1][j] = matrix[i][j];
                    matrix[i][j] = temp;
                }
            }
        }
    }
};

//Better version
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                    swap(matrix[n-j-1][n-i-1],matrix[i][j]);
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                    swap(matrix[n-i-1][j], matrix[i][j]);
            }
        }
    }
};