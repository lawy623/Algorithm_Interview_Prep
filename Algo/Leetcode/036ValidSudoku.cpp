//1. Check row/colum/3x3 iteratively. 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> used;
        
        for(int i=0;i<9;i++){
            used.clear();
            
            for(int j=0;j<9;j++){
                if( !check(board[i][j],used) ) return false;
            }
            cout<<endl;
            
            used.clear();
            
            for(int j=0;j<9;j++){
                if( !check(board[j][i],used) ) return false;
            }
        }
        
        
        for(int m=0;m<9;m+=3){
            for(int n=0;n<9;n+=3){
                used.clear();
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                       if( !check(board[i+m][j+n],used) ) return false;
                    }
                }
            }
        }
        return true;        
    }
    
    bool check(char c, set<int>& s){
        if(c=='.') return true;
        int num = c-'0';
        if(s.count(num)) return false;
        else{
            s.insert(num);
            return true;
        } 
    }
};

//Concise Version.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> row(n, vector<int>(9, 0));
        vector<vector<int>> col(n, vector<int>(9, 0));
        vector<vector<int>> box(n, vector<int>(9, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    int k = board[i][j] -'1';
                    if(row[i][k]>0) return false;
                    else row[i][k]++;

                    if(col[j][k]>0) return false;
                    else col[j][k]++;

                    if(box[i/3*3+j/3][k]>0) return false;  // take care of the index here for each 9*9 box
                    else box[i/3*3+j/3][k]++;
                }
            }
        }
        return true;
    }
};