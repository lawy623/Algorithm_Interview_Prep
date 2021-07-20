class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int start_idx){
        if (start_idx >= word.length())
            return true;
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || word[start_idx]!=board[row][col])
            return false;

        char tmp = board[row][col];
        board[row][col] = '/';
        bool found = dfs(board, row-1, col, word, start_idx+1) ||
                     dfs(board, row+1, col, word, start_idx+1) ||
                     dfs(board, row, col-1, word, start_idx+1) ||
                     dfs(board, row, col+1, word, start_idx+1);
        board[row][col] = tmp;
        return found;
    }
};
