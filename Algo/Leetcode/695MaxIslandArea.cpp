class Solution {
public:
    void dfs(vector<vector<int> >& grid, int i, int j, int rows, int cols, int& area){
        grid[i][j] = 0;
        area++;
        if (i+1>=0 && i+1<rows && grid[i+1][j]==1)
            dfs(grid, i+1, j, rows, cols, area);
        if (i-1>=0 && i-1<rows && grid[i-1][j]==1)
            dfs(grid, i-1, j, rows, cols, area);
        if (j+1>=0 && j+1<cols && grid[i][j+1]==1)
            dfs(grid, i, j+1, rows, cols, area);
        if (j-1>=0 && j-1<cols && grid[i][j-1]==1)
            dfs(grid, i, j-1, rows, cols, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows==0) return 0;
        int cols = grid[0].size();
        if (cols==0) return 0;

        int max_area = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==1) {
                    int max_area_single = 0;
                    dfs(grid, i, j, rows, cols, max_area_single);
                    if (max_area_single>max_area)
                        max_area = max_area_single;
                }
            }
        }
        return max_area;
    }
};
