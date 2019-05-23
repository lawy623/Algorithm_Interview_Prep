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
        bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {}; //First 9 is the num of row/col/box. Second 9 is num 1-9.
        for (int i = 0; i < 81; ++i) {
            int r = i / 9;
            int c = i % 9;
            int b = (r / 3) * 3 + (c / 3);
            if (board[r][c] == '.') continue;
            int n = board[r][c] - '1';
            if (row[r][n]++) return false; //Meaning that this number n appear once in row r.
            if (col[c][n]++) return false;
            if (box[b][n]++) return false;
        }
        return true;
    }
};