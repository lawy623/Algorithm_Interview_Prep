// dfs and trace back
class Solution {
public:
    int count = 0;
    vector<string> p;
    int totalNQueens(int n) {
        dfs(0, n);
        return count;
    }

    void dfs(int row, int n){
        if(row == n) {count++; return;}

        for(int col=0; col<n; col++){
            if(!check_valid(col, n)) continue;
            string t = string(n, '.');
            t[col] = 'Q';
            p.push_back(t);
            dfs(row+1, n);
            p.pop_back();
        }
    }

    bool check_valid(int col, int n){
        int cur_row = p.size();
        // for all cols
        for(int i=0; i<cur_row; i++){
            if(p[i][col] == 'Q') return false;
        }

        // left upper
        for(int i=cur_row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(p[i][j] == 'Q') return false;
        }

        // right upper
        for(int i=cur_row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(p[i][j] == 'Q') return false;
        }
        return true;
    }
};