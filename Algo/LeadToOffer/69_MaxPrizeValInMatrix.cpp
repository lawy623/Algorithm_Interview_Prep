// dfs
class Solution {
public:

    int max_val = 0;
    int maxValue(vector<vector<int>>& grid) {
        int val = 0;
        dfs(grid, 0, 0, val);
        return max_val;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& val){
        if(i>=grid.size() || j>=grid[0].size()){
            max_val = max(max_val, val);
            return;
        }

        val += grid[i][j];
        dfs(grid, i+1, j, val);
        dfs(grid, i, j+1, val);
        val -= grid[i][j];
    }
};

//dp
class Solution {
public:

    int max_val = 0;
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) continue;
                else if(j==0) grid[i][j] += grid[i-1][j];
                else if(i==0) grid[i][j] += grid[i][j-1];
                else
                    grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};