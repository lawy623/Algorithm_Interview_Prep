// dfs and trace back
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        int n = board.size();

        for(int i=0; i<n; i++){
            if(board[i][col]==c) return false;
        }

        for(int j=0; j<n; j++){
            if(board[row][j]==c) return false;
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i+row/3*3][j+col/3*3]==c) return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
          dfs(board);
    }

    bool dfs(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.') continue;
                for(int k=1; k<=9; k++){
                    char c = k+'0';
                    if(!isValid(board, i, j, c)) continue; // just check whether the intended input is correct
                    board[i][j] = c;
                    if(dfs(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
};